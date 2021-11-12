//    2021-11-11
//    final.ino
//    Diego Sarceño (dsarceno68@gmail.com)

//    Programa simulación 3 Electrónica Digital (Arduino)

//    Codificación del texto: UTF8 y Arduino
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
// LEDS DEL DISPLAY D4 -> D10
#define ALARM 11
#define UNIDADES 12
#define DECENAS 13
#define POT A0
#define PUSH_NEUTRO A1
#define PUSH_DRIVE_MANUAL A2
#define PUSH_DRIVE_AUTO A3


// MATRICES 
bool display[10][7] = {{0,0,0,0,0,0,1}, // 0
			{1,0,0,1,1,1,1}, // 1
			{1,1,0,1,1,0,1}, // 2
			{0,0,0,0,1,1,0}, // 3
			{1,0,0,1,1,0,0}, // 4
			{0,1,0,0,1,0,0}, // 5
			{0,1,0,0,0,0,0}, // 6
			{0,0,0,1,1,1,1}, // 7
			{0,0,0,0,0,0,0}, // 8 
			{0,0,0,0,1,0,0}}; // 9

// VARIABLES ÚTILES
bool estado_neutro = 0;
bool estado_drive_manual = 0;
bool estado_drive_auto = 0;
bool estado = 0;
int pot = 0;


// INCIALIZAMOS VOID SETUP

void setup() {
	//pinmode(#de pin, tipo entrada o salida)
	pinMode(DERECHA, OUTPUT);
	pinMode(PWM, OUTPUT);
	for (int l = 4; l < 11; l++){
		pinMode(l, OUTPUT);
	}
	pinMode(UNIDADES, OUTPUT);
	pinMode(DECENAS, OUTPUT);
	pinMode(POT, INPUT);
	pinMode(PUSH_NEUTRO, INPUT);
	pinMode(PUSH_DRIVE_MANUAL, INPUT);
	pinMode(PUSH_DRIVE_AUTO, INPUT);	
	// INICIAR PROGRAMA
	Serial.begin(9600);
	Serial.println("Iniciar Programa");
}

void loop() {
	// estado inicial
	neutro();
	// lectura de los push bottoms
	estado_neutro = digitalRead(PUSH_NEUTRO);
	estado_drive_manual = digitalRead(PUSH_DRIVE_MANUAL);
	estado_drive_auto = digitalRead(PUSH_DRIVE_AUTO);
	// condicionales
	delay(500); // LECTURA DE ESTADOS
	if (estado_neutro == 1) {
		Serial.println("Neutro");
		neutro();
	} else if (estado_drive_manual == 1) {
		Serial.println("Manual");
		drive_manual();
	} else if (estado_drive_auto == 1) {
		Serial.println("Automatico");
		drive_auto();
	}
	delay(100);
}


// FUNCIONES A UTILIZAR

void neutro() {
	digitalWrite(DERECHA,0);
	while (estado == 0) {
		digitalWrite(UNIDADES,HIGH);
		digitalWrite(DECENAS,LOW);
		digitoU(0);
		delay(100);
		digitalWrite(UNIDADES,LOW);
		digitalWrite(DECENAS,HIGH);
		digitoD(0);
		delay(100);
		if (digitalRead(PUSH_DRIVE_MANUAL) == 1) {
			estado = digitalRead(PUSH_DRIVE_MANUAL);
		} else if (digitalRead(PUSH_DRIVE_AUTO) == 1) {
			estado = digitalRead(PUSH_DRIVE_AUTO);
		}
	}
	estado = 0;
}

void drive_manual() {
	digitalWrite(DERECHA,1);
	while (estado == 0) {
			pot = analogRead(POT);
			Serial.println(pot);
			analogWrite(PWM,pot/2);  // CAMBIO DE VELOCIDAD DEL MOTOR MEDIANTE LAS LECTURAS DEL POTENCIOMETRO
			if (pot <= 205) {
				noTone(ALARM);
				// 01
				digitalWrite(UNIDADES,HIGH);
				digitalWrite(DECENAS,LOW);
				digitoU(1);
				delay(100);
				digitalWrite(UNIDADES,LOW);
				digitalWrite(DECENAS,HIGH);
				digitoD(0);
				delay(100);
			} else if (pot > 205 && pot <= 409) {
				noTone(ALARM);
				// 02
				digitalWrite(UNIDADES,HIGH);
				digitalWrite(DECENAS,LOW);
				digitoU(2);
				delay(100);
				digitalWrite(UNIDADES,LOW);
				digitalWrite(DECENAS,HIGH);
				digitoD(0);
				delay(100);
			} else if (pot > 409 && pot <= 614) {
				noTone(ALARM);
				// 03
				digitalWrite(UNIDADES,HIGH);
				digitalWrite(DECENAS,LOW);
				digitoU(3);
				delay(100);
				digitalWrite(UNIDADES,LOW);
				digitalWrite(DECENAS,HIGH);
				digitoD(0);
				delay(100);
			} else if (pot > 614 && pot <= 818) {
				noTone(ALARM);
				// 04
				digitalWrite(UNIDADES,HIGH);
				digitalWrite(DECENAS,LOW);
				digitoU(4);
				delay(100);
				digitalWrite(UNIDADES,LOW);
				digitalWrite(DECENAS,HIGH);
				digitoD(0);
				delay(100);
			} else if (pot > 818) {
				tone(ALARM,2000);
				// 05
				digitalWrite(UNIDADES,HIGH);
				digitalWrite(DECENAS,LOW);
				digitoU(5);
				delay(100);
				digitalWrite(UNIDADES,LOW);
				digitalWrite(DECENAS,HIGH);
				digitoD(0);
				delay(100);
			}
			// cambio de estado
			if (digitalRead(PUSH_NEUTRO) == 1) {
				estado = digitalRead(PUSH_NEUTRO);
			} else if (digitalRead(PUSH_DRIVE_AUTO) == 1) {
				estado = digitalRead(PUSH_DRIVE_AUTO);
			}
		}
		estado = 0;
		analogWrite(PWM,0);
}

void drive_auto() {
	digitalWrite(DERECHA,1);
	while (estado == 0) {
		for (int d = 0; d < 10; d++) {
			for (int u = 0; u < 10; u++) {
				Serial.println(d*10 + u);
				for (int c = 1; c < 11; c++) {
					digitalWrite(UNIDADES,HIGH);
					digitalWrite(DECENAS,LOW);
					digitoU(u);
					delay(100);
					digitalWrite(UNIDADES,LOW);
					digitalWrite(DECENAS,HIGH);
					digitoD(d);
					delay(100);
					// cambio de estado
					if (digitalRead(PUSH_NEUTRO) == 1 || digitalRead(PUSH_DRIVE_MANUAL) == 1) {
						break;
					}
				}
				analogWrite(PWM, ((100*d) + (10*u))/2);
				if ((d*10 + u) >= 85) {
					tone(ALARM,2000);
				}
				if (digitalRead(PUSH_NEUTRO) == 1 || digitalRead(PUSH_DRIVE_MANUAL) == 1) {
					break;
				}
			}
			if (digitalRead(PUSH_NEUTRO) == 1 || digitalRead(PUSH_DRIVE_MANUAL) == 1) {
				break;
			}	
		}
		// cambio de estado
		if (digitalRead(PUSH_NEUTRO) == 1) {
			estado = digitalRead(PUSH_NEUTRO);
		} else if (digitalRead(PUSH_DRIVE_MANUAL) == 1) {
			estado = digitalRead(PUSH_DRIVE_MANUAL);
		}
	}
	estado = 0;
	analogWrite(PWM,0);
}



// FUNCIONES EXTRAS
void digitoU(int x) {
	for (int a = 0; a < 8; a++) {
		digitalWrite(a + 4, display[x][a]);
	}
}

void digitoD(int y) {
	for (int b = 0; b < 8; b++) {
		digitalWrite(b + 4, display[y][b]);
	}
}




































