/*commentaire :
branchement : 
envoyer du 3,3v ou 5v
mettre la résistance 10k Ohm
mettre la gpio qui va lire la valeur (on peut placer la résistance, l'alimentation et la gpio sur la même ligne)
placer le bouton au milieu de la plaque, la résistance doit arriver sur un coté du bouton
Sur l'autre coté du bouton, placer la masse relier au gnd


                                                           ------ (on envoie du 5V ici)
                                                             XX
(on récupère notre courant ici quand le bouton sera pressé)------
Schéma d'un bouton, les pattes en faces sont reliés entre elles, si vous reliez 2 pattes reliées entre elles, le courant passera forcément, il faut donc définir la patte qui reçoit le courant puis prendre l'autre patte pour récupérer le courant quand le bouton est pressé
*/


//déclaration des defines


//déclaration des librairies


//déclaration des variables
int gpio_input=9;       //on se sert de la 9 pour savoir si le courant passe où non


//déclaration des fonctions


void setup() {
  pinMode(gpio_input, INPUT);    //entrée numérique
  Serial.begin(9600);            //ceci dit à l'arduino d'intéragir avec la console à une vitesse de 9600 bauds, on peut ouvrir la console avec la loupe en haut à droite sur arduino, la console apparaitra vide si vôtre arduino n'y à rien écris, plus loin on va écrire des choses sur la console
}


void loop() {

  Serial.print("etat du bouton");        //arduino affiche sur la console "etat du bouton"
  Serial.print("\t");                    //permet de mettre une tabulation (rajoute un gros espace)


  Serial.print(digitalRead(gpio_input)); //on rajoute la valeur lue sur la gpio 9 : 0 ou 1
  Serial.print("\t");


  if (digitalRead(gpio_input)==1){       //j'ai rajouté ça pour que l'on update la console que quand la valeur change, ça sert à rien d'afficher 1000 x "etat du bouton 1", autant afficher 1 fois le message et remettre un nouveau message quand la valeur aura changée
    Serial.print("le courant passe");
    while (digitalRead(gpio_input)==1){
      delay(10);
    }
  }else{
    Serial.print("le courant ne passe pas");
    while (digitalRead(gpio_input)==0){
      delay(10);
    }
  }
  Serial.print("\n");                     //permet de faire un retour à la ligne

}
