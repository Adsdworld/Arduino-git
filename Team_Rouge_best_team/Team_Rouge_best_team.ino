/*Commentaire:

*/


//déclaration des define


//déclaration des librairies


//déclaration des variables
pin_1 = 5
pin_2 = 6
pin_3 = 7
pin_4 = 8
pin_5 = 9
pin_6 = 10
time=0
pin_11


//déclaration des fonctions
f_led_managment (Led_RougeV, Led_OrangeV, Led_VerteV, Led_RougeP, Led_VerteP)
  digitalWrite(pin1, Led_RougeV);
  digitalWrite(pin2, Led_OrangeV);
  digitalWrite(pin3, Led_VerteV);
  digitalWrite(pin4, Led_RougeP);
  digitalWrite(pin5, Led_VerteP);

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
