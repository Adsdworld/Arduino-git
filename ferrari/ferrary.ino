/*commentaire :
Description : Controller une voiture avec 2 moteurs sur son téléphone
Etat : En cours
Schéma : indisponible

app "Bluetooth RC controller" disponible sur le Play store
*/


//définition des variables
char t;

char Current_A='LOW';
char Current_B='LOW';
int Current_C=0;          //stocke la puissance du moteur au cours du temps
int Current_D=0;
int Current_E=0;
int Current_F=0;

int Forward_and_Back_Power=255;  //définitions des puissances pour les mouvements
int Right_and_Left_Power=150;
int Other_directions=20;

int EnableA=13;
int AC=10;             //définition de la pin du moteur droit
int AD=9;             //définition de la pin du moteur gauche
int EnableB=12;
int BC=6;             //définition de la pin du moteur droit
int BD=5;             //définition de la pin du moteur gauche


//définition des fonctions
void f_vitesse(char A, char B, int C, int D, int E, int F){              //cette foinction ajuste la puissance voulue sur les 2 moteurs
  if (A!=Current_A){Current_A=A;digitalWrite(EnableA, Current_A);}
  if (B!=Current_B){Current_B=B;digitalWrite(EnableB, Current_B);}
  while (C!=Current_C || D!=Current_D || E!=Current_E || F!=Current_F){
    if (C<Current_C){analogWrite(AC, --Current_C);}
    if (C>Current_C){analogWrite(AC, ++Current_C);}
    if (D<Current_D){analogWrite(AD, --Current_D);}
    if (D>Current_D){analogWrite(AD, ++Current_D);}
    if (E<Current_E){analogWrite(BC, --Current_E);}
    if (E>Current_E){analogWrite(BC, ++Current_E);}
    if (F<Current_F){analogWrite(BD, --Current_F);}
    if (F>Current_F){analogWrite(BD, ++Current_F);}
    delay(5);
  }
}


void setup() {
pinMode(EnableA,OUTPUT);
pinMode(AC,OUTPUT); 
pinMode(AD,OUTPUT);
pinMode(EnableB,OUTPUT); 
pinMode(BC,OUTPUT);
pinMode(BD,OUTPUT); 
Serial.begin(9600);  //le Serial.begin(9600) doit être activé pour récupérer les données du blutooth, le baud est-il ajustable ?
}
 
void loop() {
  if(Serial.available()){
    t = Serial.read();
    }

  if(t == 'F'){
  f_vitesse(HIGH, HIGH, 0, Forward_and_Back_Power, 0, Forward_and_Back_Power);
  }else{
    if(t == 'B'){
      f_vitesse(HIGH, HIGH, Forward_and_Back_Power, 0, Forward_and_Back_Power, 0);
    }else{
      if(t == 'L'){
        f_vitesse(LOW, HIGH, 0, 0, 0, Right_and_Left_Power);
      }else{  
        if(t == 'R'){
          f_vitesse(HIGH, LOW, 0, Right_and_Left_Power, 0, 0);
        }else{ 
          if(t ==  'H'){
            //analogWrite(Left_Motor,100);
            f_vitesse(HIGH, LOW, Other_directions, 0, 0, 0);
          }else{ 
            if(t == 'J'){
              //analogWrite(Right_Motor,100);   //-
              f_vitesse(LOW, HIGH, 0, 0, Other_directions, 0);
            }else{
              if(t ==  'I'){
                //analogWrite(Left_Motor,100);
                f_vitesse(HIGH, LOW, 0, Other_directions, 0, 0);
              }else{ 
                if(t == 'G'){
                  //analogWrite(Right_Motor,100);
                  f_vitesse(LOW, HIGH, 0, 0, 0, Other_directions);
                }else{
                f_vitesse(LOW, LOW, 0, 0, 0, 0);
                }}}}}}}}

}
