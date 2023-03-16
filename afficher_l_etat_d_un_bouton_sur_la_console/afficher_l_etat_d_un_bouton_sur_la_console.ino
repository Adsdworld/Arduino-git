/*commentaire :
Le programme me semble bon mais peut être incomplet, seulement j'ai l'impression que quand il detecte que la pin 9 reçoit un tout petit peu de courant il la passe à 1 
J'ai remarqué que pour recevoir du courant, passer pas le 3,3v ou le 5v ça ne marche pas en revanche mettre en contact la 9 et la 5 ça marche.
Le bouton que l'on as, je ne saurais dire comment ils fonctionnent, le couant passe tout le temps quoiqu'il arrive
*/


//déclaration des defines


//déclaration des librairies


//déclaration des variables
int gpio_output=5;      //on se sert de la 5 pour envoyer du courant qui se dirigera vers la 9
int gpio_input=9;       //on se sert de la 9 pour savoir si le courant passe où non


//déclaration des fonctions


void setup() {
  pinMode(gpio_input, INPUT);    //entrée numérique
  pinMode(gpio_output, OUTPUT);  //sortie numérique
  Serial.begin(9600);            //ceci dit à l'arduino d'intéragir avec la console à une vitesse de 9600 bauds, on peut ouvrir la console avec la loupe en haut à droite sur arduino, la console apparaitra vide si vôtre arduino n'y à rien écris, plus loin on va écrire des choses sur la console
}


void loop() {

  digitalWrite(gpio_output, HIGH);       //on envoie du courant

  Serial.print("etat du bouton");        //arduino affiche sur la console "etat du bouton"
  Serial.print("\t");                    //permet de mettre une tabulation (rajoute un gros espace)


  Serial.print(digitalRead(gpio_input)); //on rajoute la valeur lue sur la gpio 9 : 0 ou 1


  if (digitalRead(gpio_input)==1){       //j'ai rajouté ça pour que l'on update la console que quand la valeur change, ça sert à rien d'afficher 1000 x "etat du bouton 1", autant afficher 1 fois le message et remettre un nouveau message quand la valeur aura changée
    while (digitalRead(gpio_input)==1){
      delay(10);
    }
  }else{
    while (digitalRead(gpio_input)==0){
      delay(10);
    }
  }
  Serial.print("\n");                     //permet de faire un retour à la ligne

}
