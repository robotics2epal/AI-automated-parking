#include <Servo.h>

Servo serv1;  // lift
Servo serv2;  //catch car
Servo serv3;  //catch car


int ENA = 16;
int IN1 = 5;
int IN2 = 4;
int ENB = 14;
int IN3 = 0;
int IN4 = 2;
int ldr_init_value;

void servos_move(int move_up){
if   (move_up == 1) {

      for (int i = 0; i <= 180; i++) {
        serv2.write(i);
        serv3.write(180-i);
        delay(20);
    }
 }
 else{
      for (int i = 180; i >= 0; i--) {
        serv2.write(i);
        serv3.write(180-i);
        delay(20);
    }
  }
}

void servo_car_up(int move_up){     // lift
 if   (move_up == 1) {

        for (int i = 0; i <= 150; i++) {
        serv1.write(i);
        delay(20);
    }
 }
 else{
        for (int i = 150; i>= 0; i--) {
        serv1.write(i);
        delay(20);
    }
  }
  
}



void setup() {
        Serial.begin(9600);
        
        // set all the motor control pins to outputs
        pinMode(ENA, OUTPUT);
        pinMode(IN1, OUTPUT);
        pinMode(IN2, OUTPUT);
        pinMode(ENB, OUTPUT);
        pinMode(IN3, OUTPUT);
        pinMode(IN4, OUTPUT);
        analogWrite(ENA, 90);  // speed
        analogWrite(ENB, 90);  // speed

        serv1.attach(15);  // lift
        serv2.attach(13);  
        serv3.attach(12);  
    
        serv1.write(0);     // lift
        serv2.write(0);     // left bracket in
        serv3.write(180);   // right bracket in
        
        ldr_init_value = analogRead(A0);
        delay(2000);

        
        
}


void loop() {

    int sensorValue = analogRead(A0);   // read the input on analog pin 0
    Serial.println(sensorValue);   // print out the value you read
    Serial.println(sensorValue);   // print out the value you read

    if (sensorValue == 1024)  {
      
       servos_move(1);   // catch car
       delay(2000);
       servo_car_up(1);   // lift UP
       delay(4000);

       digitalWrite(IN1, HIGH);      // move AI forward
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, HIGH);
       digitalWrite(IN4, LOW);
       delay(2000);  
       
       digitalWrite(IN1, LOW);      // move AI stop
       digitalWrite(IN2, LOW);
       digitalWrite(IN3, LOW);
       digitalWrite(IN4, LOW);
       delay(4000);  

       servo_car_up(0);   // lift down
       delay(2000);
       servos_move(0);    // free car
       delay(2000);  
    }
    
    
    delay(100);
}
