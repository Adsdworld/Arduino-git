/*Commentaire:
Description : Permet d'attendre time_to_wait tout en faisant une action pendant que l'on attends
Etat : Fonctionnel
Schéma : Indisponible
*/


//déclaration des variables
float time_to_wait=1000;                                          //1000ms correspond au temps pendant lequel je veux attendre
float time=0;


void setup() 
{
  Serial.begin(1200);

}


void loop() 
{
  time=int(millis());                                             //Permet de récupérer dans time l'heure "actuelle", millis() commence à 0 quand l'arduino démarre, il prends 1s toutes les 1s, durée max de millis() 50d avant de revenir à 0
  while ((time+time_to_wait)>millis()){
    Serial.print("Hacking FBI.\n");
    delay(20);
    Serial.print("Hacking FBI..\n");
    delay(20);
    Serial.print("Hacking FBI...\n");
    delay(20);
  }
  Serial.print((String)"Il s'est écoulé "+time_to_wait+" ms\n");

}