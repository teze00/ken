#include<Stepper.h>
int blue = 12;
int pink =11;
int yellow = 10;
int orange = 9;
int steps = 2038;
Stepper stepper (steps,blue,yellow,pink,orange);
int direct = 1;
int revTime;
float secs,revs;

void setup(){
  Serial.begin(9600);
  Serial.println("rpm tim(s) revs");
}
void loop(){
  for (int i = 2; i<19; i=i+2){
    stepper.setSpeed(i);
    direct = -direct;
    revTime = millis();
    stepper.step(direct* steps/2);
    revTime = millis()-revTime;
    delay(500);
    secs =revTime/1000.0;
    revs=i*secs/60.0;
    Serial.print(i);
    Serial.print("\t");
    Serial.print(secs);
    Serial.print("\t");
    Serial.println(revs,3);
  }
}

