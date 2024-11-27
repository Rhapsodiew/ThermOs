
#define LEDPIN13 13 //Associe le nb au mot " LEDPIN " dans le programme 
#define LEDPIN12 12 //Associe le nb au mot " LEDPIN " dans le programme 
#define LEDPIN11 11 //Associe le nb au mot " LEDPIN " dans le programme 
#define LEDPIN10 10 //Associe le nb au mot " LEDPIN " dans le programme 

//ce qui a pour conséquence de tout simplement remplacer tout les LEDPIN dans le programme par  13.


#define PAUSEON 200 //Associe 500 à PAUSEON.

#define PAUSEOFF 0// Associe 500 à PAUSEOFF

void setup() { 

pinMode(LEDPIN13, OUTPUT); //Déclare le numéro de pin associé à LEDPIN comme une sortie = pinMode(13, OUTPUT);
pinMode(LEDPIN12, OUTPUT); //Déclare le numéro de pin associé à LEDPIN comme une sortie = pinMode(12, OUTPUT);
pinMode(LEDPIN11, OUTPUT); //Déclare le numéro de pin associé à LEDPIN comme une sortie = pinMode(11, OUTPUT);
pinMode(LEDPIN10, OUTPUT); //Déclare le numéro de pin associé à LEDPIN comme une sortie = pinMode(10, OUTPUT);

} 

void loop() { 

digitalWrite(LEDPIN13,HIGH); //Place le pin digital 13 à l'état HAUT (5V) -> Led allumée
delay(PAUSEON); //Met en pause le programme pendant la valeur de PAUSEON en ms

digitalWrite(LEDPIN13,LOW); //Place le pin digital 13 à l'état BAS (0V) -> Led éteinte
delay(PAUSEOFF); //Met en pause le programme pendant la valeur de PAUSEOFF en ms


digitalWrite(LEDPIN12,HIGH); //Place le pin digital 12 à l'état HAUT (5V) -> Led allumée
delay(PAUSEON); //Met en pause le programme pendant la valeur de PAUSEON en ms

digitalWrite(LEDPIN12,LOW); //Place le pin digital 12 à l'état BAS (0V) -> Led éteinte
delay(PAUSEOFF); //Met en pause le programme pendant la valeur de PAUSEOFF en ms


digitalWrite(LEDPIN11,HIGH); //Place le pin digital 11 à l'état HAUT (5V) -> Led allumée
delay(PAUSEON); //Met en pause le programme pendant la valeur de PAUSEON en ms

digitalWrite(LEDPIN11,LOW); //Place le pin digital 11 à l'état BAS (0V) -> Led éteinte
delay(PAUSEOFF); //Met en pause le programme pendant la valeur de PAUSEOFF en ms


digitalWrite(LEDPIN10,HIGH); //Place le pin digital 10 à l'état HAUT (5V) -> Led allumée
delay(PAUSEON); //Met en pause le programme pendant la valeur de PAUSEON en ms

digitalWrite(LEDPIN10,LOW); //Place le pin digital 10 à l'état BAS (0V) -> Led éteinte
delay(PAUSEOFF); //Met en pause le programme pendant la valeur de PAUSEOFF en ms
}