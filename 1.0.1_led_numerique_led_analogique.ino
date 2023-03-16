//déclaration des librairies


//déclaration des variables
  int fade=5;             //valeur de l'effet de fondue
  int time_to_wait=10;    //temps d'attente entre chaque fade
  int brightness=255;     //intensité entre 0 (brightness_min) et 255 (brightness_max) envoyé à la led
  int brightness_max=255; 
  int brightness_min=0;
//ici j'ai mis des variables (brightness_min & brightness_max) car j'utilise 9 fois 255 et 0 dans mon script, donc plus simple de mettre une variable et ça me permet de modifier la brightness max & min facilement au besoin


void setup() {
  pinMode(9, OUTPUT);  //analogique
  pinMode(8, OUTPUT); //numérique
  pinMode(7, OUTPUT);  //numérique
  pinMode(6, OUTPUT);   //numérique
}


void loop() {

  digitalWrite(8, HIGH);                //allumer la rouge

                                        //par rapport au premier programme, ici j'ai remplacé le delay par une led 9 qui s'allume puis s'éteind
  while(brightness<brightness_max) {    //allumer progressivement la led 9 en ajoutant l'effet fade tant que brightness est < à brightness_max avec un delay de time_to_wait à chaque itérations
    delay(time_to_wait);
    brightness=brightness+fade;
    if (brightness>brightness_max){     //la fonction if, on la retrouve dans chaque block, elle sert à vérifier que l'on allume pas une led avec une brightness > brightness_max. Même si brightness est supérieur à 255, l'arduino allume la led à 255, donc mon if sert à rien
      brightness=brightness_max;}
      analogWrite(9, brightness);}

  while(brightness>brightness_min) {    //éteindre progressivement la led 9 en ajoutant l'effet fade tant que brightness est < à brightness_max avec un delay de time_to_wait à chaque itérations
    delay(time_to_wait);
    brightness=brightness-fade*2;       //ici il y a un petit multiplicateur pour que la led s'éteigne 2 fois plus rapidement
    if (brightness<brightness_min){brightness=brightness_min;}
    analogWrite(9, brightness);}

  digitalWrite(8, LOW);                //éteindre la rouge
  


  digitalWrite(7, HIGH);               //allumer la jaune

  while(brightness<brightness_max) {
    delay(time_to_wait);
    brightness=brightness+fade;
    if (brightness>brightness_max){brightness=brightness_max;}
    analogWrite(9, brightness);}

  while(brightness>brightness_min) {
    delay(time_to_wait);
    brightness=brightness-fade*2;
    if (brightness<brightness_min){brightness=brightness_min;}
    analogWrite(9, brightness);}

  digitalWrite(7, LOW);               //éteindre la jaune



  digitalWrite(6, HIGH);               //allumer la verte

  while(brightness<brightness_max) {
    delay(time_to_wait);
    brightness=brightness+fade;
    if (brightness>brightness_max){brightness=brightness_max;}
    analogWrite(9, brightness);}

  while(brightness>brightness_min) {
    delay(time_to_wait);
    brightness=brightness-fade*2;
    if (brightness<brightness_min){brightness=brightness_min;}
    analogWrite(9, brightness);}

  digitalWrite(6, LOW);               //éteindre la verte
}
