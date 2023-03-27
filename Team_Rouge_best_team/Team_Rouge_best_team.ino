/*Commentaire:

*/


//déclaration des define


//déclaration des librairies


//déclaration des variables
Pin_RougeV = 5
Pin_OrangeV = 6
Pin_VerteP = 7
Pin_RougeP = 8

time=0
pin_11


//déclaration des fonctions
f_led_managment (Led_RougeV, Led_OrangeV, Led_VerteV, Led_RougeP, Led_VerteP)
  digitalWrite(Pin_RougeV, Led_RougeV);
  digitalWrite(Pin_OrangeV, Led_OrangeV);
  digitalWrite(Pin_VerteV, Led_VerteV);
  digitalWrite(Pin_RougeP, Led_RougeP);
  digitalWrite(Pin_VerteP, Led_VerteP);

temps_attente ()
  time=millis()
  while ((time+f_potentiomètre)>millis())

f_potentiomètre ()
  temps=10*analogRead(pin_11)
  return temps;

f_temps_attente_plus_bouton ()
  time=millis()
  while ((time+f_potentiomètre)>millis())
    if (1==digitalRead(pin_12))
      break

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
