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
LiquidCrystal_I2C lcd(0x27,  16, 2);

void setup() {
  // Initialise la capteur DHT11
  dht.begin();

  //initialize lcd screen
  lcd.init();
  // turn on the backlight
  lcd.backlight();
}
void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int humidity_int =  (int)humidity;
  int temperature_int = (int)temperature;

  lcd.setCursor(0,0);
  lcd.print("Temperature= " + String(temperature_int)+"C");

  lcd.setCursor(0,1);
  lcd.print("Humidite= " + String(humidity_int)+"%");

  //Restart after 10 sec
  delay(10000);
}
