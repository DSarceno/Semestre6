//    2021-10-26
//    simulacion4cod.ino
//    Diego Sarceño (dsarceno68@gmail.com)

//    Programa simulación 3 Electrónica Digital (Arduino)

//    Codificación del texto: UTF8
//    Compiladores probados: TinkerCad
//    Instrucciones de compilación: no requere nada mas
//    

//    Copyright (C) 2021
//    D. R. Sarceño Ramírez
//    dsarceno68@gmail.com
//
//    This program is free software: you can redistribute it and/or
//    modify it under the terms of the GNU General Public License as
//    published by the Free Software Foundation, either version 3 of
//    the License, or (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see
//    <http://www.gnu.org/licenses/>.

// PROGRAM
// Definir leds del display de 7 segmentos

#define DERECHA 2
#define PWM 3
#define IZQUIERDA 4
#define A7S 5
#define B7S 6
#define C7S 7
#define D7S 8
#define E7S 9
#define F7S 10
#define G7S 11
#define POT A0
#define PUSH_NEUTRO A1
#define PUSH_DRIVE A2
#define PUSH_REV A3


// VARIABLES ÚTILES
bool estado_neutro = 0;
bool estado_drive = 0;
bool estado_rev = 0;
bool estado = 0;
int pot = 0;


// INCIALIZAMOS VOID SETUP

void setup() {
	//pinmode(#de pin, tipo entrada o salida)
	pinMode(DERECHA, OUTPUT);
	pinMode(PWM, OUTPUT);
	pinMode(IZQUIERDA, OUTPUT);
	pinMode(A7S, OUTPUT);
	pinMode(B7S, OUTPUT);
	pinMode(C7S, OUTPUT);
	pinMode(D7S, OUTPUT);
	pinMode(E7S, OUTPUT);
	pinMode(F7S, OUTPUT);
	pinMode(G7S, OUTPUT);
	pinMode(POT, INPUT);
	pinMode(PUSH_NEUTRO, INPUT);
	pinMode(PUSH_DRIVE, INPUT);
	pinMode(PUSH_REV, INPUT);	
	// INICIAR PROGRAMA
	Serial.begin(9600);
	Serial.println("Iniciar Programa");
}

void loop() {
	// estado inicial
	neutro();
	// lectura de los push bottoms
	estado_neutro = digitalRead(PUSH_NEUTRO);
	estado_drive = digitalRead(PUSH_DRIVE);
	estado_rev = digitalRead(PUSH_REV);
	// condicionales
	delay(500);
	if (estado_neutro == 1) {
		Serial.println("Neutro");
		neutro();
	} else if (estado_drive == 1) {
		Serial.println("Drive");
		drive();
	} else if (estado_rev == 1) {
		Serial.println("Reversa");
		reversa();
	}
	delay(100);
}


// NÚMEROS Y LETRAS EN EL DISPLAY DE 7 SEGMENTOS

void displayNeutro() {
	digitalWrite(A7S,0);
	digitalWrite(B7S,1);
	digitalWrite(C7S,1);
	digitalWrite(D7S,0);
	digitalWrite(E7S,1);
	digitalWrite(F7S,1);
	digitalWrite(G7S,1);
}

void display1() {
	digitalWrite(A7S,0);
	digitalWrite(B7S,1);
	digitalWrite(C7S,1);
	digitalWrite(D7S,0);
	digitalWrite(E7S,0);
	digitalWrite(F7S,0);
	digitalWrite(G7S,0);
}

void display2() {
	digitalWrite(A7S,1);
	digitalWrite(B7S,1);
	digitalWrite(C7S,0);
	digitalWrite(D7S,1);
	digitalWrite(E7S,1);
	digitalWrite(F7S,0);
	digitalWrite(G7S,1);
}

void display3() {
	digitalWrite(A7S,1);
	digitalWrite(B7S,1);
	digitalWrite(C7S,1);
	digitalWrite(D7S,1);
	digitalWrite(E7S,0);
	digitalWrite(F7S,0);
	digitalWrite(G7S,1);
}

void display4() {
	digitalWrite(A7S,0);
	digitalWrite(B7S,1);
	digitalWrite(C7S,1);
	digitalWrite(D7S,0);
	digitalWrite(E7S,0);
	digitalWrite(F7S,1);
	digitalWrite(G7S,1);
}


void displayA() {
	digitalWrite(A7S,1);
	digitalWrite(B7S,1);
	digitalWrite(C7S,1);
	digitalWrite(D7S,0);
	digitalWrite(E7S,1);
	digitalWrite(F7S,1);
	digitalWrite(G7S,1);
}


// FUNCIONES NECESARIAS (BUCLES)

void neutro() {
	displayNeutro();
	while (estado == 0){
		if (digitalRead(PUSH_DRIVE) == 1) {
			estado = digitalRead(PUSH_DRIVE);
		} else if (digitalRead(PUSH_REV) == 1) {
			estado = digitalRead(PUSH_REV);
		}
	}
	estado = 0;
}

void reversa() {
	displayA();
	digitalWrite(DERECHA,0);
	digitalWrite(IZQUIERDA,1);
	analogWrite(PWM,510);
	while (estado == 0) {
		estado = digitalRead(PUSH_NEUTRO);
	}
	estado = 0;
	analogWrite(PWM,0);
}

void drive() {
	digitalWrite(DERECHA,1);
	digitalWrite(IZQUIERDA,0);
	while (estado == 0) {
			pot = analogRead(POT);
			Serial.println(pot);
			analogWrite(PWM,pot/2);
			if (pot <= 255) {
				Serial.println("Vel 1");
				display1();
			} else if (pot > 255 && pot <= 510) {
				Serial.println("Vel 2");
				display2();
			} else if (pot > 510 && pot <= 765) {
				Serial.println("Vel 3");
				display3();
			} else if (pot > 765) {
				Serial.println("Vel 4");
				display4();
			}
			estado = digitalRead(PUSH_NEUTRO);
		}
		estado = 0;
		analogWrite(PWM,0);
}










































