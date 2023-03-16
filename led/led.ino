/*Commentaire
Faire clignoter 3 leds à intervals régulier*/


//déclaration des define


//déclaration des librairies


//déclaration des variables
int time_to_wait=1000;        //temps d'attente entre chaque allumage/extinction en ms

//déclaration des fonctions

void setup() {
  pinMode(8, OUTPUT);         //sortie numérique
  pinMode(7, OUTPUT);         //sortie numérique
  pinMode(6, OUTPUT);         //sortie numérique
  }


void loop() {

  digitalWrite(8, HIGH);               //allumer la rouge
  delay(time_to_wait);
  digitalWrite(8, LOW);                //éteindre la rouge

  
  digitalWrite(7, HIGH);               //allumer la jaune
  delay(time_to_wait);
  digitalWrite(7, LOW);                //éteindre la jaune


  digitalWrite(6, HIGH);               //allumer la verte
  delay(time_to_wait);
  digitalWrite(6, LOW);                //éteindre la verte

}
