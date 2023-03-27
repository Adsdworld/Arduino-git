/*commentaire :
branchement : 
envoyer 5v sur la première patte du potentiomètre
mettre la masse sur l'autre patte
mettre la gpio qui va lire la valeur sur la patte isolée
*/


//déclaration des defines


//déclaration des librairies


//déclaration des variables
int analoge_input=A0;                    //on se sert de la A0 pour savoir si le courant passe où non
int Prev_AnalogRead = 0;                 


//déclaration des fonctions


void setup() {
  pinMode(analoge_input, INPUT);           //entrée numérique
  Serial.begin(9600);                      //ceci dit à l'arduino d'intéragir avec la console à une vitesse de 9600 bauds, on peut ouvrir la console avec la loupe en haut à droite sur arduino, la console apparaitra vide si vôtre arduino n'y à rien écris, plus loin on va écrire des choses sur la console
}


void loop() {

  Serial.print("Valeur entre 0 et 1023 du courant 5V qui passe");          //arduino affiche sur la console "etat du bouton"
  Serial.print("\t");                      //permet de mettre une tabulation (rajoute un gros espace)

  Serial.print(analogRead(analoge_input)); //on rajoute la valeur lue sur la gpio 9 : 0 ou 1
  Serial.print("\t");

  Prev_AnalogRead = analogRead(analoge_input);
  delay(10);
  while (analogRead(analoge_input)==Prev_AnalogRead){    //tant que la valeur reste la même, on ne fait rien, ça permet d'éviter de polluer la console
    delay(10);
    }
  Serial.print("\n");                      //permet de faire un retour à la ligne

}
