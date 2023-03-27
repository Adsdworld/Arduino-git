/*Commentaire:

*/


//déclaration des define


//déclaration des librairies


//déclaration des variables
int Pin_RougeV = 5;
int Pin_OrangeV = 6;
int Pin_VerteV = 7;
int Pin_RougeP = 8;
int Pin_VerteP = 9;

float time=0.00;     //sert à récupérer le millis() à un moment donné
float temps=0.00;    //temps d'attente lu sur le potentiomètre
int Pin_Potentiometre = A0;
int Pin_bouton = 10;



//déclaration des fonctions
bool f_led_managment (char Led_RougeV, char Led_OrangeV, char Led_VerteV, char Led_RougeP, char Led_VerteP) {
  digitalWrite(Pin_RougeV, Led_RougeV);
  digitalWrite(Pin_OrangeV, Led_OrangeV);
  digitalWrite(Pin_VerteV, Led_VerteV);
  digitalWrite(Pin_RougeP, Led_RougeP);
  digitalWrite(Pin_VerteP, Led_VerteP);
  return true;}

void temps_attente (){
  time=millis();
  while ((time+f_potentiometre)>millis());}

float f_potentiometre (){
  temps=5000+5*analogRead(Pin_Potentiometre);
  return temps;}


void setup() { 
  pinMode(Pin_RougeV, OUTPUT);
  pinMode(Pin_OrangeV, OUTPUT);
  pinMode(Pin_VerteV, OUTPUT);
  pinMode(Pin_RougeP, OUTPUT);
  pinMode(Pin_VerteP, OUTPUT);

  pinMode(Pin_Potentiometre, INPUT);
  pinMode(Pin_bouton, INPUT);}


void loop() 
{
  temps_attente();
  f_led_managment(HIGH, LOW, LOW, HIGH, LOW);

  temps_attente();
  f_led_managment(LOW, LOW, HIGH, HIGH, LOW);

  time=millis();
  while ((time+f_potentiometre)>millis());
    if (0==digitalRead(Pin_bouton)){
      break;}

  f_led_managment(LOW, HIGH, LOW, HIGH, LOW);
  temps_attente();

  f_led_managment(HIGH, LOW, LOW, LOW, HIGH);


}
