#define trigPin1 1
#define echoPin1 5
#define trigPin2 2
#define echoPin2 6
#define trigPin3 3
#define echoPin3 7
#define trigPin4 4
#define echoPin4 8
#define red 11
#define green 10
#define blue 9

long duration, distance,FirstSensor, SecondSensor, ThirdSensor, FourthSensor;
void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
pinMode(trigPin4, OUTPUT);
pinMode(echoPin4, INPUT);
pinMode(red, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(green, OUTPUT);
}
void loop() {
int seatcounter=0;
RunSensor(trigPin1, echoPin1);
FirstSensor = distance;
  if(FirstSensor <= 50){
    seatcounter++;
  }
RunSensor(trigPin2, echoPin2);
SecondSensor = distance;
  if(SecondSensor <= 50){
    seatcounter++;
  }
RunSensor(trigPin3, echoPin3);
ThirdSensor = distance;
  if(ThirdSensor <= 50){
    seatcounter++;
  }
RunSensor(trigPin4, echoPin4);
FourthSensor = distance;
  if(FourthSensor <= 50){
    seatcounter++;
  }
  Serial.println(seatcounter);
  if(seatcounter < 2){
    digitalWrite(green, HIGH);
  }
  else if(seatcounter >=2 && seatcounter <=3){
  	digitalWrite(blue, HIGH);
  }
  else if(seatcounter > 3){
    digitalWrite(red, HIGH);
  }
  
}

void RunSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

}
