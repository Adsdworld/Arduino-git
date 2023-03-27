/*Commentaire:

*/


//déclaration des define


//déclaration des librairies


//déclaration des variables
int Pin_RougeV = 5;
int Pin_OrangeV = 6;
int Pin_VerteP = 7;
int Pin_RougeP = 8;

float time=0;
int Pin_Potentiometre = A0;
int Pin_bouton = 10;


//déclaration des fonctions
f_led_managment (Led_RougeV, Led_OrangeV, Led_VerteV, Led_RougeP, Led_VerteP)
  digitalWrite(Pin_RougeV, Led_RougeV);
  digitalWrite(Pin_OrangeV, Led_OrangeV);
  digitalWrite(Pin_VerteV, Led_VerteV);
  digitalWrite(Pin_RougeP, Led_RougeP);
  digitalWrite(Pin_VerteP, Led_VerteP);

temps_attente ()
  time=millis();
  while ((time+f_potentiomètre)>millis());

f_potentiomètre ()
  temps=10*analogRead(Pin_Potentiometre);
  return temps;

f_temps_attente_plus_bouton ()
  time=millis();
  while ((time+f_potentiomètre)>millis())
    if (1==digitalRead(Pin_bouton))
      break;

void setup() 
{


}


void loop() 
{
  temps_attente()
  f_led_managment(HIGH, LOW, LOW, HIGH, LOW)
  temps_attente()
  f_led_managment(LOW, LOW, HIGH, HIGH, LOW)
  f_temps_attente_plus_bouton()
  f_led_managment(LOW, HIGH, LOW, HIGH, LOW)
  temps_attente()
  f_led_managment(HIGH, LOW, LOW, LOW, HIGH)


}
