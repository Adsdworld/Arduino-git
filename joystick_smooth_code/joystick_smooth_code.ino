/*Commentaire:
Description : Permet d'allumer 4 leds en fonction de la position d'un joystick bas de gamme
Etat : Fonctionnel
Schéma : Disponible, le cablage du joystick n'est pas fait.

Un code plus léger à executer
*/


//déclaration des define
#define joyX A0     
#define joyY A1


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


if (xValue>=(X_centre-1) && xValue<=(X_centre+1) && yValue>=(Y_centre-1) && yValue<=(Y_centre+1)){ 

  digitalWrite(bas, LOW);  
  digitalWrite(haut, LOW);
  digitalWrite(droite, LOW);
  digitalWrite(gauche, LOW);

}else{
  if (xValue>(X_centre+1)){     

    digitalWrite(haut, LOW);

    Ux=xValue-X_centre;        
    Uy=yValue-Y_centre;
    Vy=yValue-Y_centre;
    Ud=sq(Ux)+sq(Uy);
    Ud=sqrt(Ud);
    Vd=sq(Vy);
    Vd=sqrt(Vd);
    angle=(((Ux*0)+(Uy*Vy))/(Vd*Ud));

    if (angle<0.5){                 
      digitalWrite(bas, HIGH);
      digitalWrite(droite, LOW);
      digitalWrite(gauche, LOW);}else{

      if (Vy<=0){         
        if (angle>=0.5){
            digitalWrite(droite, HIGH);
            digitalWrite(bas, LOW); 
            digitalWrite(gauche, LOW);
          }  
      }else{                         
        if (angle>=0.5){
            digitalWrite(gauche, HIGH);
            digitalWrite(bas, LOW);      
            digitalWrite(droite, LOW);
          }
        }
      }
    }

  else{
    if (xValue<(X_centre-1)){     

      digitalWrite(bas, LOW);

      Ux=xValue-X_centre;
      Uy=yValue-Y_centre;
      Vy=yValue-Y_centre;
      Ud=sq(Ux)+sq(Uy);
      Ud=sqrt(Ud);
      Vd=sq(Vy);
      Vd=sqrt(Vd);
      angle=(((Ux*0)+(Uy*Vy))/(Vd*Ud));

      if (angle<0.5){                   
      digitalWrite(haut, HIGH);
      digitalWrite(droite, LOW);
      digitalWrite(gauche, LOW);}else{

      if (Vy<=0){          
        if (angle>=0.5){
            digitalWrite(droite, HIGH);
            digitalWrite(haut, LOW);
            digitalWrite(gauche, LOW);
          }  
      }else{                            
        if (angle>=0.5){
            digitalWrite(gauche, HIGH);       
            digitalWrite(haut, LOW);
            digitalWrite(droite, LOW);
          }
        }
      }
    }
  }
}
}
