/*Commentaire:
*/


//déclaration des define


//déclaration des librairies


//déclaration des variables
float time_to_wait=1000;                  //1000 correspond aux temsp de cuisson de mes pates 
float time=0;

//déclaration des fonctions


void setup() 
{
  Serial.begin(1200);

}


void loop() 
{
  time=int(millis());                   //je regarde ma montre pour savoir quand j'ai mis mes pates dans la casserole
  while ((time+time_to_wait)>millis()){
    Serial.print("mes pates ne sont pas cuites donc je regarde netflix et en même temps mon arduino fais de la couture\n");
  }
  Serial.print("Mes pates sont cuites :)\n");

}