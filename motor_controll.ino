#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600); 
  Serial.println("Motor test!");
  motor1.setSpeed(255);
  motor1.run(RELEASE);
  
  motor2.setSpeed(255);
  motor2.run(RELEASE);

  motor3.setSpeed(255);
  motor3.run(RELEASE);

  motor4.setSpeed(255);
  motor4.run(RELEASE);
  
}

void loop() {
  // Serial.println("from arduino to raspbery pi using print function only");
  if (Serial.available()>0){
    String data = Serial.readStringUntil('\n');
    if(data == "forward"){
      straight_forward();
    }
    else if(data == "backward"){
      straight_backward();
    }
    else if(data == "left"){
      left_side(180);
    }
    else if(data == "right"){
      right_side(180);
    }
    else if(data == "stop"){
      stop_();
    }
  }

}

void stop_(){
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void right_side(int t){ //right
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  delay(t);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void left_side(int t){ // left
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(t);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void straight_forward(){ //forward
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void straight_backward(){ //backward
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}
