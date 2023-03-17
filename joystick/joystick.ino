/*Commentaire:
L'objectif est de d'allumer 4 leds selon la position du joystick, je ségmante en 4 zones mon joystick, zone 1 en haut à gauche, zone 2 en haut à droite, zone 3 en bas à droite, zone 4 en bas à gauche. 
Une fois que j'ai ces zones je sais que je dois allumer une des 2 leds de la zone. Pour déterminer laquelle, je fais un produit scalaire pour obtenir l'"angle", j'obtiens une valeur qui pass par 1 - 0 - 1, ça couvre une distance de 180°.

Tout d'abord je regarde si mon joystick est vers le bas ou vers le haut
je calcule l'angle
si l'angle est <0.5 on est dans la zone basse
si l'angle est >0.5 on est soit à droite soit à gauche (je rappel que la valeur de l'angle qui m'est retournée est comprise entre 1 (0.5) 0 (0.5) 1  de 1 à 1 je couvre 180°)
Pour savoir si j'allume la led droite ou gauche, je regarde les coordonnées en les comparant au centre

ça me fais un jolie script qui change l'allumage des leds dé que l'on arrive à un angle de 45°, c'est beaucoup mieux qu'un joystick qui allume les leds qu'en tenant compte des 4 zones*/


//déclaration des define
#define joyX A0     
#define joyY A1
#define PI 3.14


//déclaration des librairies


//déclaration des variables
int X_centre=528;
int Y_centre=518;
int bas=8;
int haut=7;
int droite=5;
int gauche=6;
int xValue = analogRead(joyX);
int yValue = analogRead(joyY);
float angle=0;
int angle_degre=0;
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
Serial.begin(1200);
}


void loop() {

xValue = analogRead(joyX);
yValue = analogRead(joyY);


if (xValue>=(X_centre-1) && xValue<=(X_centre+1) && yValue>=(Y_centre-1) && yValue<=(Y_centre+1)){     //jostick au "0"  xValue==526 && yValue==518

  digitalWrite(bas, LOW);   //extenction des leds
  digitalWrite(haut, LOW);
  digitalWrite(droite, LOW);
  digitalWrite(gauche, LOW);

  Serial.print(xValue);     //on affiche les coordonnées et on rajoute que le joystick est au centre
  Serial.print("\t");
  Serial.print(yValue);
  Serial.print("\t");
  Serial.print("joystick au centre");
  Serial.print("\n");

}else{
  if (xValue>(X_centre+1)){       //joystick vers le bas

    Ux=xValue-X_centre;           //on fait le calcul de l'angle avec le produit scalaire
    Uy=yValue-Y_centre;
    Vy=yValue-Y_centre;
    Ud=sq(Ux)+sq(Uy);
    Ud=sqrt(Ud);
    Vd=sq(Vy);
    Vd=sqrt(Vd);
    angle=(((Ux*0)+(Uy*Vy))/(Vd*Ud));
    angle_degre=(180*angle)/PI;

    Serial.print(xValue);         //on affiche les coordonnées + l'angle + les degré
    Serial.print("\t");
    Serial.print(yValue);
    Serial.print("\t");
    Serial.print(angle);
    Serial.print("\t");
    Serial.print(angle_degre);
    Serial.print("\n");

    if (angle<0.5){                       //joystick dans la zone basse
      digitalWrite(bas, HIGH);
      digitalWrite(haut, LOW);
      digitalWrite(droite, LOW);
      digitalWrite(gauche, LOW);}else{

      if (Vy<=0){           //joystick vers la droite
        if (angle>=0.5){
            digitalWrite(droite, HIGH);
            digitalWrite(bas, LOW); 
            digitalWrite(haut, LOW);
            digitalWrite(gauche, LOW);
          }  
      }else{                              //joystick vers la gauche
        if (angle>=0.5){
            digitalWrite(gauche, HIGH);
            digitalWrite(bas, LOW);       //extenction des leds
            digitalWrite(haut, LOW);
            digitalWrite(droite, LOW);
          }
        }
      }
    }

  else{
    if (xValue<(X_centre-1)){        //joystick vers le haut

      Ux=xValue-X_centre;
      Uy=yValue-Y_centre;
      Vy=yValue-Y_centre;
      Ud=sq(Ux)+sq(Uy);
      Ud=sqrt(Ud);
      Vd=sq(Vy);
      Vd=sqrt(Vd);
      angle=(((Ux*0)+(Uy*Vy))/(Vd*Ud));
      angle_degre=(180*angle)/PI;

      Serial.print(xValue);
      Serial.print("\t");
      Serial.print(yValue);
      Serial.print("\t");
      Serial.print(angle);
      Serial.print("\t");
      Serial.print(angle_degre);
      Serial.print("\n");}

      if (angle<0.5){                       //joystick dans la zone haute
      digitalWrite(haut, HIGH);
      digitalWrite(bas, LOW);
      digitalWrite(droite, LOW);
      digitalWrite(gauche, LOW);}else{

      if (Vy<=0){             //joystick vers la droite
        if (angle>=0.5){
            digitalWrite(droite, HIGH);
            digitalWrite(bas, LOW); 
            digitalWrite(haut, LOW);
            digitalWrite(gauche, LOW);
          }  
      }else{                                //joystick vers la gauche
        if (angle>=0.5){
            digitalWrite(gauche, HIGH);
            digitalWrite(bas, LOW);         //extenction des leds
            digitalWrite(haut, LOW);
            digitalWrite(droite, LOW);
          }
        }
      }
    }
  }
}
