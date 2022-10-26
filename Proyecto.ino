//LIBRERIAS PANTALLA LCD
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
//VARIABLES DE SENSOR
const int Trigger = 2;
const int Echo = 3;
long t;
long d;
//BOTON 
int buttonPin = A5;
int buttonOld = 1;
int buttonNew;
int estado = 0;
//VARIABLES DE LEDS
int ledR = 12;
int ledB = 11;
int ledG = 10;
//VARIABLES DE BUZZER
int buzzer = 13;

void setup() { 
  //SENSOR
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT); 
  pinMode(Echo, INPUT);  
  digitalWrite(Trigger, LOW);
  //BOTON
  pinMode(buttonPin, INPUT);
  //PANTALLA
  lcd.begin(16, 2);
  //LEDS
  pinMode(ledR, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledG, OUTPUT);
  //BUZZER
  pinMode(buzzer, OUTPUT);
}

void loop()
{	
  /*buttonNew = digitalRead(buttonPin);
  delay(100);
  if(buttonNew == 0 && buttonOld ==1){
    if(estado ==0){  	
      	estado = 1;
    }else{
      	estado = 0;
      	comienzo();
    }
  }
  buttonOld = buttonNew;
  Serial.println(estado);*/
  comienzo();
}
void comienzo(){
	calculos();
      /*if (d >= 300) {
        inicio();
      }*/
      if (d <= 50) {
        ledC();
        delay(d * 4);
        apagar();
        delay(d * 4);
        buzz();
        lcd.clear();
        lcd.setCursor(2, 0);
        lcd.print("Vas A Chocar");
        lcd.setCursor(5, 1);
        lcd.print(d);
        lcd.setCursor(8, 1);
        lcd.print("Cm");
      }
      else if (d <= 150) {
        ledA();
        delay(d * 4);
        apagar();
        delay(d * 4);
        buzz();
        lcd.clear();
        lcd.setCursor(3, 0);
        lcd.print("Aceptable");
        lcd.setCursor(5, 1);
        lcd.print(d);
        lcd.setCursor(8, 1);
        lcd.print("Cm");
        }
      else{
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(" Retrocediendo");
        delay(500);
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("Vas Bien");
        lcd.setCursor(5, 1);
        lcd.print(d);
        lcd.setCursor(8, 1);
        lcd.print("Cm");
        ledL();
        delay(d * 4);
        apagar();
        delay(d * 4);
        buzz();
      }
}
void calculos() {
  //CALCULOS DE DISTANCIAS SENSOR
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  t = pulseIn(Echo, HIGH);
  d = t / 59;
}
void inicio() {
  //BIENVENIDA
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("ELECTROSEN");
  lcd.setCursor(3, 1);
  lcd.print("BIENVENIDO");
  delay(3000);
}

void ledL() {
  //AMARILLO
  digitalWrite(ledR, 0);
  digitalWrite(ledG, 255);
  digitalWrite(ledB, 0);
}
void ledC() {
  //ROJO
  digitalWrite(ledR, 255);
  digitalWrite(ledG, 0);
  digitalWrite(ledB, 0);
}
void ledA() {
  //AMARILLO
  digitalWrite(ledR, 0);
  digitalWrite(ledG, 0);
  digitalWrite(ledB, 255);

}
void ledE() {
  //VERDE
  digitalWrite(ledR, 129);
  digitalWrite(ledG, 216);
  digitalWrite(ledB, 208);

}
void apagar() {
  //APAGAR LEDS
  digitalWrite(ledR, 0);
  digitalWrite(ledG, 0);
  digitalWrite(ledB, 0);
}
void buzz() {
  calculos();
  digitalWrite(buzzer, HIGH);
  delayMicroseconds(d);
  digitalWrite(buzzer, LOW);
  if (d <= 50) {
    digitalWrite(buzzer, HIGH);
  }
}
  void off(){
  	digitalWrite(ledR, 0);
  	digitalWrite(ledG, 0);
  	digitalWrite(ledB, 0);
    lcd.clear();
  }
