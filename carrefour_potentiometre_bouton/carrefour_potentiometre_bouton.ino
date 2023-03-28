/*Commentaire:
Description : Permet de simuler un carrefour Voiture Piétons, un potentiomètre permet de régler la durée des passages de couleurs et un bouton permet de basculer au orange pour les voitures quand elles sont au vert pour faire passer les piétons 
Etat : Fonctionnel
Schéma : Disponible

Un changement possible serait de définir une durée fixe d'attente entre le orange et le rouge
*/


//déclaration des variables
int Pin_RougeV = 5;
int Pin_OrangeV = 6;
int Pin_VerteV = 7;
int Pin_RougeP = 8;
int Pin_VerteP = 9;
int Pin_Potentiometre = A0;
int Pin_Bouton = 10;
int Pin_Fade = 11;


float time=0.00;                                                                                                //sert à récupérer le millis() à un moment donné
float temps=0.00;                                                                                               //temps d'attente lu sur le potentiomètre                                                                                                    


//déclaration des fonctions
void f_led_managment (char Led_RougeV, char Led_OrangeV, char Led_VerteV, char Led_RougeP, char Led_VerteP, int Led_Fade) {   //cette fonction permet de gérer toutes les leds
  digitalWrite(Pin_RougeV, Led_RougeV);
  digitalWrite(Pin_OrangeV, Led_OrangeV);
  digitalWrite(Pin_VerteV, Led_VerteV);
  digitalWrite(Pin_RougeP, Led_RougeP);
  digitalWrite(Pin_VerteP, Led_VerteP);
  analogWrite(Pin_Fade, Led_Fade);}

void temps_attente (){                                                                                          //une fonction void ne renvoie rien, une fonction float renvoie un floatant, une fonction int renvoie un entier, une fonction bool renvoie soit true soir false, on utilise return "truc que l'on renvoie"; pour void pas besoin de return;
  time=millis();
  while ((float)(time+5000.00+5*analogRead(Pin_Potentiometre))>millis()){
    //ne rien faire
    }}

float f_potentiometre (){
  temps=5000.00+5*analogRead(Pin_Potentiometre);
  return temps;}


void setup() { 
  pinMode(Pin_RougeV, OUTPUT);
  pinMode(Pin_OrangeV, OUTPUT);
  pinMode(Pin_VerteV, OUTPUT);
  pinMode(Pin_RougeP, OUTPUT);
  pinMode(Pin_VerteP, OUTPUT);

  pinMode(Pin_Potentiometre, INPUT);
  pinMode(Pin_Bouton, INPUT);}


void loop() 
{
  temps_attente();
  //char Led_RougeV, char Led_OrangeV, char Led_VerteV, char Led_RougeP, char Led_VerteP, int Led_Fade
  f_led_managment(HIGH, LOW, LOW, HIGH, LOW, 255);

  temps_attente();
  f_led_managment(LOW, LOW, HIGH, HIGH, LOW, 0);

  time=millis();                                                                                                //avant ici, j'avais définit une fonction pour tout ce bout de code mais je ne l'appel qu'une seule fois, donc j'ais supprimé ma fonction et déplacé le bout de code ici, car ça fait plus de ligne en définissant une fonction.
  //test= float(time)+float(5000.00+5*analogRead(Pin_Potentiometre));
  while ((float)(time+5000.00+5*analogRead(Pin_Potentiometre))>millis()){
    if (0==digitalRead(Pin_Bouton)){
      break;}}

  f_led_managment(LOW, HIGH, LOW, HIGH, LOW, 100);
  temps_attente();

  f_led_managment(HIGH, LOW, LOW, LOW, HIGH, 0);


}
