//    2021-10-23
//    simulacion7cod.ino
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

#define A7S 2
#define B7S 3
#define C7S 4
#define D7S 5
#define E7S 6
#define F7S 7
#define G7S 8
#define LED_R 9
#define LED_G 10
#define LED_B 11
#define PUSH_LED 12
#define PUSH_DIS 13


// VARIABLES ÚTILES
bool estado_led = 0;
bool estado_display = 0;
bool estado_general = 0;



// INCIALIZAMOS VOID SETUP

void setup() {
	//pinmode(#de pin, tipo entrada o salida)
	pinMode(A7S, OUTPUT);
	pinMode(B7S, OUTPUT);
	pinMode(C7S, OUTPUT);
	pinMode(D7S, OUTPUT);
	pinMode(E7S, OUTPUT);
	pinMode(F7S, OUTPUT);
	pinMode(G7S, OUTPUT);
	pinMode(LED_R, OUTPUT);
	pinMode(LED_G, OUTPUT);
	pinMode(LED_B, OUTPUT);
	pinMode(PUSH_LED, INPUT);
	pinMode(PUSH_DIS, INPUT);	
	// INICIAR PROGRAMA
	Serial.begin(9600);
	Serial.println("Iniciar Programa");
}

void loop() {
	// estado inicial
	led_rojo();
	// lectura de los push bottoms
	estado_led = digitalRead(PUSH_LED);
	estado_display = digitalRead(PUSH_DIS);
	// condicionales
	if (estado_led == 1){
		delay(500);
		led_apagado();
		delay(500);
		secuenciaLED();
		estado_led = 0;
		delay(100);
	}else if (estado_display == 1){
		delay(500);
		led_apagado();
		delay(500);
		secuenciaNL();
		apagado();
		estado_display = 0;
		delay(100);
	}
}


// NÚMEROS Y LETRAS EN EL DISPLAY DE 7 SEGMENTOS

void display0() {
	digitalWrite(A7S,1);
	digitalWrite(B7S,1);
	digitalWrite(C7S,1);
	digitalWrite(D7S,1);
	digitalWrite(E7S,1);
	digitalWrite(F7S,1);
	digitalWrite(G7S,0);
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

void display5() {
	digitalWrite(A7S,1);
	digitalWrite(B7S,0);
	digitalWrite(C7S,1);
	digitalWrite(D7S,1);
	digitalWrite(E7S,0);
	digitalWrite(F7S,1);
	digitalWrite(G7S,1);
}

void display6() {
	digitalWrite(A7S,1);
	digitalWrite(B7S,0);
	digitalWrite(C7S,1);
	digitalWrite(D7S,1);
	digitalWrite(E7S,1);
	digitalWrite(F7S,1);
	digitalWrite(G7S,1);
}

void display7() {
	digitalWrite(A7S,1);
	digitalWrite(B7S,1);
	digitalWrite(C7S,1);
	digitalWrite(D7S,0);
	digitalWrite(E7S,0);
	digitalWrite(F7S,0);
	digitalWrite(G7S,0);
}

void display8() {
	digitalWrite(A7S,1);
	digitalWrite(B7S,1);
	digitalWrite(C7S,1);
	digitalWrite(D7S,1);
	digitalWrite(E7S,1);
	digitalWrite(F7S,1);
	digitalWrite(G7S,1);
}

void display9() {
	digitalWrite(A7S,1);
	digitalWrite(B7S,1);
	digitalWrite(C7S,1);
	digitalWrite(D7S,1);
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

void displayC() {
	digitalWrite(A7S,1);
	digitalWrite(B7S,0);
	digitalWrite(C7S,0);
	digitalWrite(D7S,1);
	digitalWrite(E7S,1);
	digitalWrite(F7S,1);
	digitalWrite(G7S,0);
}

void displayE() {
	digitalWrite(A7S,1);
	digitalWrite(B7S,0);
	digitalWrite(C7S,0);
	digitalWrite(D7S,1);
	digitalWrite(E7S,1);
	digitalWrite(F7S,1);
	digitalWrite(G7S,1);
}

void displayF() {
	digitalWrite(A7S,1);
	digitalWrite(B7S,0);
	digitalWrite(C7S,0);
	digitalWrite(D7S,0);
	digitalWrite(E7S,1);
	digitalWrite(F7S,1);
	digitalWrite(G7S,1);
}

void apagado() {
	digitalWrite(A7S,0);
	digitalWrite(B7S,0);
	digitalWrite(C7S,0);
	digitalWrite(D7S,0);
	digitalWrite(E7S,0);
	digitalWrite(F7S,0);
	digitalWrite(G7S,0);
}



// SECUENCIA DE NÚMEROS Y LETRAS

void secuenciaNL(){
	delay(500);
	display0();
	delay(1000);
	display1();
	delay(1000);
	display2();
	delay(1000);
	display3();
	delay(1000);
	display4();
	delay(1000);
	display5();
	delay(1000);
	display6();
	delay(1000);
	display7();
	delay(1000);
	display8();
	delay(1000);
	display9();
	delay(1000);
	displayA();
	delay(1000);
	displayC();
	delay(1000);
	displayE();
	delay(1000);
	displayF();
	delay(1000);
}

// LEDS

void led_rojo(){
	analogWrite(LED_R,1023);
	analogWrite(LED_G,0);
	analogWrite(LED_B,0);
}

void led_verde(){
	analogWrite(LED_R,0);
	analogWrite(LED_G,1023);
	analogWrite(LED_B,0);
}

void led_amarillo(){
	analogWrite(LED_R,1023);
	analogWrite(LED_G,955);
	analogWrite(LED_B,0);
}

void led_azul(){
	analogWrite(LED_R,0);
	analogWrite(LED_G,0);
	analogWrite(LED_B,1023);
}

void led_apagado(){
	analogWrite(LED_R,0);
	analogWrite(LED_G,0);
	analogWrite(LED_B,0);
}


void secuenciaLED(){
	delay(500);
	led_rojo();
	delay(1000);
	led_verde();
	delay(1000);
	led_amarillo();
	delay(1000);
	led_azul();
	delay(1000);
}









































