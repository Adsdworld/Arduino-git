/*
Description : Controller une voiture avec 2 moteurs sur son téléphone

app "Bluetooth RC controller" disponible sur le Play store
*/


//définition des variables
char t;                           //stocke les actions dans le buffer de l'arduino

int Current_C=0;                  //stocke la puissance du moteur au cours du temps
int Current_D=0;
int Current_E=0;
int Current_F=0;

int Forward_and_Back_Power=255;   //définitions des puissances pour les mouvements
int Right_and_Left_Power=150;
int Other_directions=100;
int Turning_Forward_and_Back_Power=Other_directions/3;

int AC=5;                         //définition de la pin du moteur droit
int AD=6;                         //définition de la pin du moteur gauche
int BC=9;                         //définition de la pin du moteur droit
int BD=10;                        //définition de la pin du moteur gauche


//définition des fonctions
void f_vitesse(char A, char B, int C, int D, int E, int F){              //cette fonction ajuste la puissance voulue sur les 2 moteurs
  while (C!=Current_C || D!=Current_D || E!=Current_E || F!=Current_F){
    if (C<Current_C){analogWrite(AC, --Current_C);}
    if (C>Current_C){analogWrite(AC, ++Current_C);}
    if (D<Current_D){analogWrite(AD, --Current_D);}
    if (D>Current_D){analogWrite(AD, ++Current_D);}
    if (E<Current_E){analogWrite(BC, --Current_E);}
    if (E>Current_E){analogWrite(BC, ++Current_E);}
    if (F<Current_F){analogWrite(BD, --Current_F);}
    if (F>Current_F){analogWrite(BD, ++Current_F);}
    delay(1);
  }
}


void setup() {
pinMode(AC,OUTPUT); 
pinMode(AD,OUTPUT);
pinMode(BC,OUTPUT);
pinMode(BD,OUTPUT); 
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
        f_vitesse(HIGH, LOW, 0, Right_and_Left_Power, 0, 0);
      }else{  
        if(t == 'R'){
          f_vitesse(LOW, HIGH, 0, 0, 0, Right_and_Left_Power);
        }else{ 
          if(t ==  'H'){
            f_vitesse(HIGH, HIGH, Other_directions, 0, Turning_Forward_and_Back_Power, 0);
          }else{ 
            if(t == 'J'){
              f_vitesse(HIGH, HIGH, Turning_Forward_and_Back_Power, 0, Other_directions, 0);
            }else{
              if(t ==  'I'){
                f_vitesse(HIGH, HIGH, 0, Turning_Forward_and_Back_Power, 0, Other_directions);
              }else{ 
                if(t == 'G'){
                  f_vitesse(HIGH, HIGH, 0, Other_directions, 0, Turning_Forward_and_Back_Power);
                }else{
                f_vitesse(LOW, LOW, 0, 0, 0, 0); //dans ce cas T est égal à S ou null, mais pour éviter tout problème on ne vérifie pas t
                }}}}}}}}

}
