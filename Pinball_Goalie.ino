#include<Servo.h>

#define in1 6


Servo x, y;
int width = 640, height = 480;
int xpos = 90, ypos = 55;
int i, j;

void setup() {

  Serial.begin(9600);
  x.attach(9);
  y.attach(10);

  x.write(xpos);
  y.write(ypos);

  pinMode(8, OUTPUT);
  pinMode(in1, OUTPUT);
  digitalWrite(in1, LOW);
  
}
const int angle = 2;


void loop() {
  if (Serial.available() > 0)
  {
    int x_mid, y_mid;
    if (Serial.read() == 'X')
    {
      x_mid = Serial.parseInt();
      if (Serial.parseInt() > 95) {
        x_mid = Serial.parseInt() + 5;
      } else if (Serial.parseInt() < 89) {
        x_mid = Serial.parseInt() - 5;
      }
      digitalWrite(8, HIGH);
      digitalWrite(in1, HIGH);
      i = 1;

      if (Serial.read() == 'Y')
        y_mid = Serial.parseInt();
        j = 1;
    } else {
      digitalWrite(6, LOW);    
    } 


    x.write(x_mid);
    y.write(y_mid);

//    if (i == 1 && j ==1) {
//      digitalWrite(6, HIGH);
//    } else {
//      digitalWrite(6, LOW);    
//    }


  } else {
    digitalWrite(8, LOW);
  }
}
