/*Commentaire:
Description : Permet de simuler un carrefour Voiture Piétons, un potentiomètre permet de régler la durée des passages de couleurs et un bouton permet de basculer au orange pour les voitures quand elles sont au vert pour faire passer les piétons 
Etat : Fonctionnel
Schéma : Disponible

Oups, le code à été corronpu, certaines parties du code ont disparues et sont irrécupérable, à vous de reconstruire un code fonctionnel, avec une led daltonien, une maquette fonctionnel et le schéma de montage peuvent vous aider
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

  }

void temps_attente (){                                                                                          //une fonction void ne renvoie rien, une fonction float renvoie un floatant, une fonction int renvoie un entier, une fonction bool renvoie soit true soir false, on utilise return "truc que l'on renvoie"; pour void pas besoin de return;

  }

float f_potentiometre (){

  }


void setup() { 

  }


void loop() 
{
  temps_attente();
  //char Led_RougeV, char Led_OrangeV, char Led_VerteV, char Led_RougeP, char Led_VerteP, int Led_Fade


}
