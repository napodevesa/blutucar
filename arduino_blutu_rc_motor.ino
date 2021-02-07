//speed of motors betwen 0 and 255, if you like you can change it
int pwm_speedA = 255;
int pwm_speedB = 240;
char command;

void setup() {
  Serial.begin(9600);
  //pins for motor controller
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);

}

void loop() {

  if(Serial.available() > 0){
    command = Serial.read();
    motors_stop();
    switch(command){
      case 'F':
      forward();
      break;
      case 'B':
      backward();
      break;
      case 'L':
      left();
      break;
      case 'R':
      right();
      break;
    }
  }

}

// function for driving straight
void forward(){
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);

  digitalWrite(9, HIGH);
  digitalWrite(6, LOW);

  analogWrite(5, pwm_speedA);
  analogWrite(3, pwm_speedB);
}

//function for reversing
void backward(){
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);

  digitalWrite(9, LOW);
  digitalWrite(6, HIGH);

  analogWrite(5, pwm_speedA);
  analogWrite(3, pwm_speedB);
}

//function for turning left
void left(){
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);

  digitalWrite(9, HIGH);
  digitalWrite(6, LOW);

  analogWrite(3, 0);
  analogWrite(5, pwm_speedA);
}

//function for turning right
void right(){
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);

  digitalWrite(9, LOW);
  digitalWrite(6, LOW);

  analogWrite(3, pwm_speedB);
  analogWrite(5, 0);
}

//function for stopping motors
void motors_stop(){
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);

  digitalWrite(9,LOW);
  digitalWrite(6, LOW);

  analogWrite(5, 0);
  analogWrite(3, 0);
}
