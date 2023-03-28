/*commentaire :
Description : Permet de récupérer une valeur entre 0 et 1023 à partir d'un potentiomètre connecté à du 5v
Etat : Fonctionnel
Schéma : Disponible
*/


//déclaration des variables
int analoge_input=A0;                                             //on se sert de la A0 pour savoir si le courant passe où non
int Prev_AnalogRead = 0;                 


void setup() {
  pinMode(analoge_input, INPUT);                                  //entrée analogique
  Serial.begin(9600);                                             //ceci dit à l'arduino d'intéragir avec la console à une vitesse de 9600 bauds, on peut ouvrir la console avec la loupe en haut à droite sur arduino, la console apparaitra vide si vôtre arduino n'y à rien écris, plus loin on va écrire des choses sur la console
}


void loop() {

  Serial.print("Valeur entre 0 et 1023 du courant 5V qui passe"); //arduino affiche sur la console "Valeur entre 0 et 1023 du courant 5V qui passe"
  Serial.print("\t");                                             //permet de mettre une tabulation (rajoute un gros espace)

  Serial.print(analogRead(analoge_input));                        //on rajoute la valeur lu sur la gpio A0 entre 0 et 1023
  Serial.print("\t");

  Prev_AnalogRead = analogRead(analoge_input);                    //on utilise cette variable pour stocker la valeur actuel qui devient la valeur précédante dans 10ms
  delay(10);
  while (analogRead(analoge_input)==Prev_AnalogRead){             //tant que la valeur reste la même, on ne fait rien, ça permet d'éviter de polluer la console
    delay(10);
    }
  Serial.print("\n");                                             //permet de faire un retour à la ligne (équivalent à pressé entré)

}
