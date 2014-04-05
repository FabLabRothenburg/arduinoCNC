
int pin_refX = 11;
int pin_dirX = 12;//low == vom motor wech
int pin_clkX = 13;

int pin_refY = 8;
int pin_dirY = 9;//low == zum motor hi // we switch this in our program to match the others!
int pin_clkY = 10;

int pin_refZ = 5;
int pin_dirZ = 6;//low == vom motor wech
int pin_clkZ = 7;

int pin_refT = 2;
int pin_dirT = 3;//low == vom motor ausgehend gesehen im uhrzeigersin
int pin_clkT = 4;

int pin_anaX = 0;
int pin_anaY = 1;
int pin_anaZ = 2;
int pin_anaT = 3;

void setup() {
  pinMode(pin_refX, INPUT_PULLUP);
  pinMode(pin_refY, INPUT_PULLUP);
  pinMode(pin_refZ, INPUT_PULLUP);
  pinMode(pin_refT, INPUT_PULLUP);
  
  pinMode(pin_dirX, OUTPUT);
  pinMode(pin_dirY, OUTPUT);
  pinMode(pin_dirZ, OUTPUT);
  pinMode(pin_dirT, OUTPUT);
  
  pinMode(pin_clkX, OUTPUT);
  pinMode(pin_clkY, OUTPUT);
  pinMode(pin_clkZ, OUTPUT);
  pinMode(pin_clkT, OUTPUT);
}

void driveX(int dir) {
  digitalWrite(pin_dirX, dir);
  digitalWrite(pin_clkX, HIGH);
  delayMicroseconds(1);
  digitalWrite(pin_clkX, LOW);
}

void driveY(int dir) {
  digitalWrite(pin_dirY, dir);
  digitalWrite(pin_clkY, HIGH);
  delayMicroseconds(1);
  digitalWrite(pin_clkY, LOW);
}

void driveZ(int dir) {
  digitalWrite(pin_dirZ, !dir); //NOT
  digitalWrite(pin_clkZ, HIGH);
  delayMicroseconds(1);
  digitalWrite(pin_clkZ, LOW);
}

void driveT(int dir) {
  digitalWrite(pin_dirT, dir);
  digitalWrite(pin_clkT, HIGH);
  delayMicroseconds(1);
  digitalWrite(pin_clkT, LOW);
}

void loop() {
  analogReference(DEFAULT);
  int anaX = analogRead(pin_anaX);
  int anaY = analogRead(pin_anaY);
  int anaZ = analogRead(pin_anaZ);
  int anaT = analogRead(pin_anaT);
  
  
  
//  Serial.println(anaX);
//  Serial.println(anaY);
//  Serial.println(anaZ);
//  Serial.println(anaT);
//  Serial.println("-------------------");
//  delay(1000);
  if(anaX < 340) { driveX( LOW); } else if(anaX > 680) { driveX(HIGH); }
  if(anaY < 340) { driveY( LOW); } else if(anaY > 680) { driveY(HIGH); }
  if(anaZ < 340) { driveZ( LOW); } else if(anaZ > 680) { driveZ(HIGH); }
  if(anaT < 340) { driveT(HIGH); } else if(anaT > 680) { driveT( LOW); }
        
  delayMicroseconds(50); //1000 is not too fast but moving
}
