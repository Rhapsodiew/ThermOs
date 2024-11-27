//CAPTEUR

#include "DHT.h"
// Definit la broche de l'Arduino sur laquelle la 
// broche DATA du capteur est reliee 
#define DHTPIN 10
#define DHTTYPE DHT11
// Declare un objet de type DHT
// Il faut passer en parametre du constructeur 
// de l'objet la broche et le type de capteur
DHT dht(DHTPIN, DHTTYPE);


// ECRAN LCD

#include <LiquidCrystal_I2C.h>

#include  <Wire.h>


//initialize the liquid crystal library
//the first parameter is  the I2C address
//the second parameter is how many rows are on your screen
//the  third parameter is how many columns are on your screen
LiquidCrystal_I2C lcd(0x27,  16, 3);

// LED DETECTOR
#define Led_blue 2
#define Led_yellow 3
#define Led_red 4

// LED CHENIL
#define Led_1 5
#define Led_2 6
#define Led_3 7
#define Led_4 8
#define Led_5 9

// LED MINUTEUR
#define Led_min_blu 11
#define Led_min_yel 12
#define Led_min_red 13

// int reset_timer = 10000;
int pause_on = 200;
int pause_off = 50;

int fade = 1;
int bright = 0;
int del ;
int same_temperature = 0;
int same_humidity = 0;

int minuteur = 0;


//ANIMATION
int i=0;
int j=0;
byte customChar1[] = {
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18,
  0x18
};

byte customChar2[] = {
  0x03,
  0x03,
  0x03,
  0x03,
  0x03,
  0x03,
  0x03,
  0x03
};

//TITLE
char tab[] = "EtnaTHERMOS";
int tab_len =  11;

void setup() {
  // Initialise la capteur DHT11
  dht.begin();

  //initialize lcd screen
  lcd.init();
  // turn on the backlight
  lcd.backlight();

  // LED DETECTOR
  pinMode(Led_blue, OUTPUT);
  pinMode(Led_yellow, OUTPUT);
  pinMode(Led_red, OUTPUT);

  // LED CHENIL
  pinMode(Led_1, OUTPUT);
  pinMode(Led_2, OUTPUT);
  pinMode(Led_3, OUTPUT);
  pinMode(Led_4, OUTPUT);
  pinMode(Led_5, OUTPUT);

  // LED MINUTEUR
  pinMode(Led_min_blu, OUTPUT);
  pinMode(Led_min_yel, OUTPUT);
  pinMode(Led_min_red, OUTPUT);

  //ANIMATION
  lcd.createChar(0, customChar1);
  lcd.createChar(1, customChar2);
  lcd.clear();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int humidity_int =  (int)humidity;
  int temperature_int = (int)temperature;

  
  if (minuteur == 0){
    looptitle();
    loop3();
    for (int anime=0;anime<16;anime++){
    loopanim();
    }
    minuteur = minuteur +1;
  }

  // BREATHING LED NOT WORKING

  //  analogWrite(Led_blue, bright);
  //   bright = bright + fade;
  //   if (bright <= 0 || bright >= 255){
  //     fade = -fade;
  //   }
  //   del = map(bright,0,255,10,1);
  //   delay(20);

  // TEMPERATURE

  if (humidity_int == same_humidity && same_temperature == temperature_int) {
    lcd.noBacklight();
    digitalWrite(Led_blue, LOW);
    digitalWrite(Led_yellow, LOW);
    digitalWrite(Led_red,LOW);
    digitalWrite(Led_min_blu, LOW);
    digitalWrite(Led_min_yel, LOW);
    digitalWrite(Led_min_red,LOW);
    delay(10000);
    
  }else{
    lcd.backlight();
    lcd.setCursor(0,0);

    if (temperature_int<18){
      lcd.print("Temp. Basse !");
      digitalWrite(Led_blue,HIGH);
      digitalWrite(Led_yellow,LOW);
      digitalWrite(Led_red,LOW);
      delay(3000);
    } else if (temperature_int > 24) {
      lcd.print("Temp. Eleve !");
      
      if (temperature_int > 25) {
        for (int i =0;i<5;i++){
          digitalWrite(Led_blue, HIGH);
          digitalWrite(Led_yellow, HIGH);
          digitalWrite(Led_red, HIGH);
          delay(pause_on);
          digitalWrite(Led_blue, LOW);
          digitalWrite(Led_yellow, LOW);
          digitalWrite(Led_red, LOW);
          delay(pause_off);
          // reset_timer = 0;
        }
      }
      digitalWrite(Led_blue, HIGH);
      digitalWrite(Led_yellow, HIGH);
      digitalWrite(Led_red, HIGH);
      // delay(3000);

    } else {
      digitalWrite(Led_blue, HIGH);
      digitalWrite(Led_yellow, HIGH);
      digitalWrite(Led_red,LOW);
      lcd.print("Temp. = " + String(temperature_int)+"C     ");
    }


    
    // HUMIDITE

    lcd.setCursor(0,1);
    if (humidity_int<18){
      lcd.print("Hum. Basse !");
      digitalWrite(Led_min_blu,HIGH);
      digitalWrite(Led_min_yel,LOW);
      digitalWrite(Led_min_red,LOW);
      delay(3000);
    } else if (humidity_int > 60) {
      lcd.print("Hum. Eleve !");
      
      if (humidity_int > 70) {
        for (int i =0;i<5;i++){
          digitalWrite(Led_min_blu, HIGH);
          digitalWrite(Led_min_yel, HIGH);
          digitalWrite(Led_min_red, HIGH);
          delay(pause_on);
          digitalWrite(Led_min_blu, LOW);
          digitalWrite(Led_min_yel, LOW);
          digitalWrite(Led_min_red, LOW);
          delay(pause_off);
          // reset_timer = 0;
        }
      }
      digitalWrite(Led_min_blu, HIGH);
      digitalWrite(Led_min_yel, HIGH);
      digitalWrite(Led_min_red, HIGH);
      // delay(3000);

    } else {
      digitalWrite(Led_min_blu, HIGH);
      digitalWrite(Led_min_yel, HIGH);
      digitalWrite(Led_min_red,LOW);
      lcd.print("Hum. = " + String(humidity_int)+"%     ");
    }

    // if (humidity_int < 30){
    //   lcd.setCursor(0,1);
    //   lcd.print("Humidite Basse !");
    // } else if (humidity_int > 60){
    //   lcd.setCursor(0,1);
    //   lcd.print("Humidite Eleve !");
    // }else {
    //   lcd.setCursor(0,1);
    //   lcd.print("Humidite = " + String(humidity_int)+"%  ");
    // }

    loop2();
  }
  

  same_temperature = temperature_int;
  same_humidity = humidity_int;

  
  
}
void loop2(){
  for (int a = 0; a < 5;a++){

  digitalWrite(Led_1,HIGH); //Place le pin digital 13 à l'état HAUT (5V) -> Led allumée
  delay(200); //Met en pause le programme pendant la valeur de PAUSEON en m 
  digitalWrite(Led_1,LOW); //Place le pin digital 13 à l'état BAS (0V) -> Led éteinte
  delay(0); //Met en pause le programme pendant la valeur de PAUSEOFF en ms


  digitalWrite(Led_2,HIGH); //Place le pin digital 12 à l'état HAUT (5V) -> Led allumée
  delay(200); //Met en pause le programme pendant la valeur de PAUSEON en ms
  digitalWrite(Led_2,LOW); //Place le pin digital 12 à l'état BAS (0V) -> Led éteinte
  delay(0); //Met en pause le programme pendant la valeur de PAUSEOFF en ms


  digitalWrite(Led_3,HIGH); //Place le pin digital 11 à l'état HAUT (5V) -> Led allumée
  delay(200); //Met en pause le programme pendant la valeur de PAUSEON en ms
  digitalWrite(Led_3,LOW); //Place le pin digital 11 à l'état BAS (0V) -> Led éteinte
  delay(0); //Met en pause le programme pendant la valeur de PAUSEOFF en ms


  digitalWrite(Led_4,HIGH); //Place le pin digital 10 à l'état HAUT (5V) -> Led allumée
  delay(200); //Met en pause le programme pendant la valeur de PAUSEON en ms
  digitalWrite(Led_4,LOW); //Place le pin digital 10 à l'état BAS (0V) -> Led éteinte
  delay(0); //Met en pause le programme pendant la valeur de PAUSEOFF en ms


  digitalWrite(Led_5,HIGH); //Place le pin digital 10 à l'état HAUT (5V) -> Led allumée
  delay(200); //Met en pause le programme pendant la valeur de PAUSEON en ms
  digitalWrite(Led_5,LOW); //Place le pin digital 10 à l'état BAS (0V) -> Led éteinte
  delay(0); //Met en pause le programme pendant la valeur de PAUSEOFF en ms
  }
}

void loop3(){
  lcd.setCursor(7,1);
  lcd.print("3 !");
  digitalWrite(Led_min_blu,HIGH); //Place le pin digital 10 à l'état HAUT (5V) -> Led allumée
  delay(1000); //Met en pause le programme pendant la valeur de PAUSEON en ms
  lcd.setCursor(7,1);
  lcd.print("2 !");
  digitalWrite(Led_min_yel,HIGH); //Place le pin digital 10 à l'état HAUT (5V) -> Led allumée
  delay(1000); //Met en pause le programme pendant la valeur de PAUSEON en ms
  lcd.setCursor(7,1);
  lcd.print("1 !");
  digitalWrite(Led_min_red,HIGH); //Place le pin digital 10 à l'état HAUT (5V) -> Led allumée
  delay(1000);
  lcd.setCursor(5,1);
  lcd.print("START !");
  for (int i =0; i<5; i++){
    digitalWrite(Led_min_blu,LOW);
    digitalWrite(Led_min_yel,LOW);
    digitalWrite(Led_min_red,LOW);
    delay(200);
    digitalWrite(Led_min_blu,HIGH);
    digitalWrite(Led_min_yel,HIGH);
    digitalWrite(Led_min_red,HIGH);
    delay(200);
  }
  digitalWrite(Led_min_blu,LOW);
  digitalWrite(Led_min_yel,LOW);
  digitalWrite(Led_min_red,LOW);
}




void loopanim() { 
    lcd.clear();
    lcd.setCursor(i,0);
    lcd.write(0);
    lcd.setCursor(i,1);
    lcd.write(0);
    delay(50);
    lcd.clear();
    lcd.setCursor(i,0);
    lcd.write(1);
    lcd.setCursor(i,1);
    lcd.write(1);
    delay(50);  
    lcd.clear();
    i++;
    if(i==16)
    i=0;
    }


void looptitle(){

  lcd.setCursor(3, 0);
  for (int i = 0; i< sizeof(tab); i++) {
    lcd.print(tab[i]);
    delay(100);
  }
}

