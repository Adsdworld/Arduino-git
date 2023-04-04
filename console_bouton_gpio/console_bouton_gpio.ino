/*commentaire :
Description : Permet de récupérer 0 ou 1 à partir d'un bouton connecté à du 5v
Etat : Fonctionnel
Schéma : Disponible

Attention à bien respecté le schéma de branchement du bouton, certaines branches du bouton sont connectés entre elles.
*/


//déclaration des variables
int gpio_input=10;                             //on se sert de la 9 pour savoir si le courant passe où non


void setup() {
  pinMode(gpio_input, INPUT);                 //entrée numérique
  Serial.begin(9600);                         //ceci dit à l'arduino d'intéragir avec la console à une vitesse de 9600 bauds, on peut ouvrir la console avec la loupe en haut à droite sur arduino, la console apparaitra vide si vôtre arduino n'y à rien écris, plus loin on va écrire des choses sur la console
}


void loop() {

  Serial.print("etat du bouton");             //arduino affiche sur la console "etat du bouton"
  Serial.print("\t");                         //permet de mettre une tabulation (rajoute un gros espace)


  Serial.print(digitalRead(gpio_input));      //on rajoute la valeur lu sur la gpio 9 : 0 ou 1
  Serial.print("\t");


  if (digitalRead(gpio_input)==1){            //j'ai rajouté ça pour que l'on update la console que quand la valeur change
    Serial.print("le courant ne passe pas");
    while (digitalRead(gpio_input)==1){
      delay(10);
    }
  }else{
    Serial.print("le courant passe");
    while (digitalRead(gpio_input)==0){
      delay(10);
    }
  }
  Serial.print("\n");                         //permet de faire un retour à la ligne

}
