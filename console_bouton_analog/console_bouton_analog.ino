/*commentaire :
branchement : 
envoyer du 3,3v ou 5v
mettre la résistance 10k Ohm
mettre la gpio qui va lire la valeur (on peut placer la résistance, l'alimentation et la analoge sur la même lignt)
placer le bouton au milieu de la plaque, la résistance doit arriver sur un coté du bouton
Sur l'autre coté du bouton, placer la masse relier au gnd
*/


//déclaration des defines


//déclaration des librairies


//déclaration des variables
float analoge_input=A5;                    //on se sert de la 9 pour savoir si le courant passe où non


//déclaration des fonctions


void setup() {
  pinMode(analoge_input, INPUT);           //entrée numérique
  Serial.begin(1200);                      //ceci dit à l'arduino d'intéragir avec la console à une vitesse de 9600 bauds, on peut ouvrir la console avec la loupe en haut à droite sur arduino, la console apparaitra vide si vôtre arduino n'y à rien écris, plus loin on va écrire des choses sur la console
}


void loop() {

  Serial.print("etat du bouton");          //arduino affiche sur la console "etat du bouton"
  Serial.print("\t");                      //permet de mettre une tabulation (rajoute un gros espace)


  Serial.print(analogRead(analoge_input)); //on rajoute la valeur lue sur la gpio 9 : 0 ou 1
  Serial.print("\t");


  if (analogRead(analoge_input)==1){       //j'ai rajouté ça pour que l'on update la console que quand la valeur change, ça sert à rien d'afficher 1000 x "etat du bouton 1", autant afficher 1 fois le message et remettre un nouveau message quand la valeur aura changée
    Serial.print("le courant passe");
    while (analogRead(analoge_input)==1){
      delay(10);
    }
  }else{
    Serial.print("le courant ne passe pas");
    while (analogRead(analoge_input)==0){
      delay(10);
    }
  }
  Serial.print("\n");                      //permet de faire un retour à la ligne

}
