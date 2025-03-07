// Motor pinleri
const int motorLeftForward = 3;  // Sol motor ileri
const int motorLeftBackward = 4; // Sol motor geri
const int motorRightForward = 5; // Sağ motor ileri
const int motorRightBackward = 6; // Sağ motor geri

// Sensör pinleri
const int leftSensor = 8;   // Sol engel sensörü
const int rightSensor = 9;  // Sağ engel sensörü

void setup() {
  // Motor pinlerini çıkış olarak ayarla
  pinMode(motorLeftForward, OUTPUT);
  pinMode(motorLeftBackward, OUTPUT);
  pinMode(motorRightForward, OUTPUT);
  pinMode(motorRightBackward, OUTPUT);

  // Sensör pinlerini giriş olarak ayarla
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
}

void loop() {
  // Engelleri tespit et
  int leftSensorValue = digitalRead(leftSensor);
  int rightSensorValue = digitalRead(rightSensor);

  // Eğer her iki sensör de engel tespit ediyorsa, robot geri gitmeli
  if (leftSensorValue == HIGH && rightSensorValue == HIGH) {
    moveBackward();
    delay(1000);  // 1 saniye geri git
  } 
  // Eğer sol sensör engel tespit ediyorsa, sola dön
  else if (leftSensorValue == HIGH) {
    turnLeft();
    delay(500);  // 0.5 saniye sola dön
  } 
  // Eğer sağ sensör engel tespit ediyorsa, sağa dön
  else if (rightSensorValue == HIGH) {
    turnRight();
    delay(500);  // 0.5 saniye sağa dön
  } 
  // Hiçbir sensör engel tespit etmiyorsa, ileri git
  else {
    moveForward();
  }
}

// Motorları ileriye hareket ettir
void moveForward() {
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
}

// Motorları geri hareket ettir
void moveBackward() {
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftBackward, HIGH);
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightBackward, HIGH);
}

// Sol motoru döndür
void turnLeft() {
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftBackward, HIGH);
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
}

// Sağ motoru döndür
void turnRight() {
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightBackward, HIGH);
}
