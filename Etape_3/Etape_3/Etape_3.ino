// CAPTEUR

#include "DHT.h"
// Definit la broche de l'Arduino sur laquelle la 
// broche DATA du capteur est reliee 
#define DHTPIN 10
#define DHTTYPE DHT11
// Declare un objet de type DHT
// Il faut passer en parametre du constructeur 
// de l'objet la broche et le type de capteur
DHT dht(DHTPIN, DHTTYPE);

// DEFINE PIN TO LED
#define LEDPIN5 5 //Associe le nb au mot " LEDPIN " dans le programme 
#define LEDPIN6 6 //Associe le nb au mot " LEDPIN " dans le programme 
#define LEDPIN7 7 //Associe le nb au mot " LEDPIN " dans le programme 

#define PAUSEON 200 //Associe 500 à PAUSEON
#define PAUSEOFF 0// Associe 500 à PAUSEOFF


void setup() {
  // Initialise la capteur DHT11
  dht.begin();



  pinMode(LEDPIN5, OUTPUT); //Déclare le numéro de pin associé à LEDPIN comme une sortie = pinMode(12, OUTPUT);
  pinMode(LEDPIN6, OUTPUT); //Déclare le numéro de pin associé à LEDPIN comme une sortie = pinMode(11, OUTPUT);
  pinMode(LEDPIN7, OUTPUT); //Déclare le numéro de pin associé à LEDPIN comme une sortie = pinMode(10, OUTPUT);

}
void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int humidity_int =  (int)humidity;
  int temperature_int = (int)temperature;

  humidity_int = 70;
  if (humidity_int < 30) {
    digitalWrite(LEDPIN5, HIGH);
  } else if (humidity_int >= 30 && humidity_int <=60){
    digitalWrite(LEDPIN6, HIGH);
  }else {
    digitalWrite(LEDPIN7, HIGH);
  }
}
