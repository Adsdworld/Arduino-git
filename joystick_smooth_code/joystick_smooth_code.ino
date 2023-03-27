/*Commentaire:
Un code plus léger à executer*/


//déclaration des define
#define joyX A0     
#define joyY A1


//déclaration des librairies


//déclaration des variables
int X_centre=528;
int Y_centre=518;
int bas=6;
int haut=7;
int droite=5;
int gauche=8;
int xValue = analogRead(joyX);
int yValue = analogRead(joyY);
float angle=0;
float Ux=0;
float Uy=0;
float Vy=0;
float Ud=0;
float Vd=0;


//déclaration des fonctions


void setup() 
{
pinMode(bas,OUTPUT);
pinMode(haut,OUTPUT);
pinMode(droite,OUTPUT);
pinMode(gauche,OUTPUT);
}


void loop() {

xValue = analogRead(joyX);
yValue = analogRead(joyY);


if (xValue>=(X_centre-1) && xValue<=(X_centre+1) && yValue>=(Y_centre-1) && yValue<=(Y_centre+1)){     //jostick au "0"  xValue==526 && yValue==518

  digitalWrite(bas, LOW);   //extenction des leds
  digitalWrite(haut, LOW);
  digitalWrite(droite, LOW);
  digitalWrite(gauche, LOW);

}else{
  if (xValue>(X_centre+1)){       //joystick vers le bas

    digitalWrite(haut, LOW);

    Ux=xValue-X_centre;           //on fait le calcul de l'angle avec le produit scalaire
    Uy=yValue-Y_centre;
    Vy=yValue-Y_centre;
    Ud=sq(Ux)+sq(Uy);
    Ud=sqrt(Ud);
    Vd=sq(Vy);
    Vd=sqrt(Vd);
    angle=(((Ux*0)+(Uy*Vy))/(Vd*Ud));

    if (angle<0.5){                       //joystick dans la zone basse
      digitalWrite(bas, HIGH);
      digitalWrite(droite, LOW);
      digitalWrite(gauche, LOW);}else{

      if (Vy<=0){           //joystick vers la droite
        if (angle>=0.5){
            digitalWrite(droite, HIGH);
            digitalWrite(bas, LOW); 
            digitalWrite(gauche, LOW);
          }  
      }else{                              //joystick vers la gauche
        if (angle>=0.5){
            digitalWrite(gauche, HIGH);
            digitalWrite(bas, LOW);       //extenction des leds
            digitalWrite(droite, LOW);
          }
        }
      }
    }

  else{
    if (xValue<(X_centre-1)){        //joystick vers le haut

      digitalWrite(bas, LOW);

      Ux=xValue-X_centre;
      Uy=yValue-Y_centre;
      Vy=yValue-Y_centre;
      Ud=sq(Ux)+sq(Uy);
      Ud=sqrt(Ud);
      Vd=sq(Vy);
      Vd=sqrt(Vd);
      angle=(((Ux*0)+(Uy*Vy))/(Vd*Ud));

      if (angle<0.5){                       //joystick dans la zone haute
      digitalWrite(haut, HIGH);
      digitalWrite(droite, LOW);
      digitalWrite(gauche, LOW);}else{

      if (Vy<=0){             //joystick vers la droite
        if (angle>=0.5){
            digitalWrite(droite, HIGH);
            digitalWrite(haut, LOW);
            digitalWrite(gauche, LOW);
          }  
      }else{                                //joystick vers la gauche
        if (angle>=0.5){
            digitalWrite(gauche, HIGH);        //extenction des leds
            digitalWrite(haut, LOW);
            digitalWrite(droite, LOW);
          }
        }
      }
    }
  }
}
}
