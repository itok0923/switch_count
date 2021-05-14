#define SWITCH_PIN PA0
#define HIGH_VALUE 980 //通電時1020~1023
#define LOW_VALUE 50 //非通電時0~1

int switchstat[2];
int count[2]={0,0}; //{on,off}回数

void setup() {
  Serial.begin(115200UL);
  Serial.println("switch count");
  pinMode(SWITCH_PIN,INPUT);
  switchstat[1]=analogRead(SWITCH_PIN);
}

void loop() {
  switch_change();
}
void switch_change(){
  //OFF→ON  = HIGH→LOW
  // ON→OFF =  LOW→HIGH
  switchstat[0]=analogRead(SWITCH_PIN);
  if((switchstat[0] < LOW_VALUE) && (switchstat[1] > HIGH_VALUE)){ //ON_COUNT
    count[0]++;
    count_print();
  }else if((switchstat[0] > HIGH_VALUE) && (switchstat[1] < LOW_VALUE)){ //OFF_COUNT
    count[1]++;
    count_print();
  }else{
  }
  switchstat[1]=switchstat[0];
  delay(50);
}
void count_print(){
  Serial.print(" on count:");
  Serial.println(count[0]);
  Serial.print("off count:");
  Serial.println(count[1]);
//  Serial.println(analogRead(SWITCH_PIN));
  Serial.println("------");
}
