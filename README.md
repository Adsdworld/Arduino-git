Adruino-git by @Asdworld


logiciel arduino : 
    https://www.arduino.cc/en/software 

liens de téléchargement direct windows 64bits : 
    https://downloads.arduino.cc/arduino-ide/arduino-ide_2.0.4_Windows_64bit.exe

Documentation : 
    https://www.arduino.cc/reference/en/ 

Drivers à installer si le bouton port reste grisé : 
    https://sparks.gogo.co.nz/ch340.html (brancher l'arduino pendant l'installation), si vous obtenez un "failed to install", cliquer sur unistal
attendez le success, puis ré-essayer une installation cela devrait fonctionner. Relancer votre Arduino

Logiciel de schéma : 
    https://arduinofactory.fr/telecharger-fritzing-gratuitement-et-legalement/#Telecharger_Fritzing_093b_GRATUITEMENT 
    je vous conseil la version 0.9.3b, en 64bits, dé le lancement il vous proposera d'installer la dernière version 
    Ce logiciel est payant en passant par le site officiel



Pin numérique : 
    digitalWrite(X, HIGH/LOW);
    digitalRead(X);               
	
    pinMode(X, OUTPUT);
    pinMode(X, INPUT);
	
    X=2/3/4/5/6/7/8/9/10/11/12/13
    HIGH signifie 1
    LOW signifie 0

Placement PWN : 
    analogWrite(X, 0 à 255);
    analogRead(X);
	
    pinMode(X, OUTPUT);
    pinMode(X, INPUT);
    
    X=3/5/6/9/10/11
    256 valeurs possibles de 0 à 255
    //vous pouvez utiliser une variable char ma_variable pour faire une comparaison avec un digitalRead(X)

Placement analogique : 
    analogWrite(X, 0 à 1023);
    analogRead(X);
	
    pinMode(X, OUTPUT);
    pinMode(X, INPUT);
    
    X=A0/A1/A2/A3/A4/A5
    1024 valeurs de 0 à 1023