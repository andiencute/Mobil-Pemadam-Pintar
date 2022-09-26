//setting pin sensor jarak
const int trigPin = A2; // kanan
const int echoPin = A3; // kanan
const int trigPin1 = 3; //kiri
const int echoPin1 = 2; //kiri
const int trigPin2 = A0; //depan
const int echoPin2 = A1; //depan
int sensor = A4;
int pompa = 13;
int nilaisensor;   
int en1 = 11;
int en2 = 10;
int Motor1 = 7;//ka1
int Motor2 = 6;//ka2
int Motor3 = 9;//ka1
int Motor4 = 8;//ka2
void setup() {
  Serial.begin(9600);
  pinMode(pompa, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(Motor1,OUTPUT);
  pinMode(Motor2,OUTPUT);
  pinMode(Motor3,OUTPUT);
  pinMode(Motor4,OUTPUT);
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
}

 void loop(){
  long duration, cm;
  long duration1, cm1;
  long duration2, cm2;
  pinMode(trigPin, OUTPUT);  
  digitalWrite(trigPin, LOW);     
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);  
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);  
  duration = pulseIn(echoPin, HIGH);
  pinMode(trigPin1, OUTPUT);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin1, LOW);
  pinMode(echoPin1, INPUT);
  duration1 = pulseIn(echoPin1, HIGH);
  pinMode(trigPin2, OUTPUT);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin2, LOW);
  pinMode(echoPin2, INPUT);
  duration2 = pulseIn(echoPin2, HIGH);
 
  cm = microsecondsToCentimeters(duration); //kanan
  cm1  = microsecondsToCentimeters(duration1); //kiri
  cm2 = microsecondsToCentimeters(duration2); //depan

  Serial.print("Kanan cm:   ");
  Serial.print(cm);
  Serial.print(" Kiri cm1:   ");
  Serial.print(cm1);
  Serial.print(" Depan cm2:   ");
  Serial.print(cm2);
  Serial.print("   ");
  
  nilaisensor = analogRead(sensor);
  Serial.print("Data yang terbaca :");
  Serial.println(nilaisensor);
    if (cm2>10)
    { 
    digitalWrite(pompa, LOW);
    digitalWrite(Motor1, LOW);
      digitalWrite(Motor2, HIGH);
      digitalWrite(Motor3, LOW);
      digitalWrite(Motor4, HIGH);
      digitalWrite(en1, 255);
      digitalWrite(en2, 255);
     Serial.println("Maju");
     }
    if (cm2<10 && cm1 < cm)
    {
      digitalWrite(Motor1, HIGH);
      digitalWrite(Motor2, LOW);
      digitalWrite(Motor3, HIGH);
      digitalWrite(Motor4, LOW);
      digitalWrite(en1, 255);
      digitalWrite(en2, 255);
      delay (150);
      digitalWrite(pompa, LOW);
      digitalWrite(Motor1, HIGH);
      digitalWrite(Motor2, LOW);
      digitalWrite(Motor3, LOW);
      digitalWrite(Motor4, HIGH);
       digitalWrite(en1, 255);
      digitalWrite(en2, 255);
      Serial.println("ROBOT BELOK KANAN");
      delay(150);
      }
if (cm1<5) /////////////////////////////////////////////
    {
      digitalWrite(pompa, LOW);
      digitalWrite(Motor1, HIGH);
      digitalWrite(Motor2, LOW);
      digitalWrite(Motor3, LOW);
      digitalWrite(Motor4, HIGH);
       digitalWrite(en1, 255);
      digitalWrite(en2, 255);
      Serial.println("ROBOT BELOK KANAN dikit");
      delay(200);
      digitalWrite(Motor1, LOW);
      digitalWrite(Motor2, HIGH);
      digitalWrite(Motor3, LOW);
      digitalWrite(Motor4, HIGH);
      digitalWrite(en1, 255);
      digitalWrite(en2, 255);
      delay(200);
    }
      if (cm2<10 && cm1 > cm)
    {
    //kiri
      digitalWrite(Motor1, HIGH);
      digitalWrite(Motor2, LOW);
      digitalWrite(Motor3, HIGH);
      digitalWrite(Motor4, LOW);
      digitalWrite(en1, 255);
      digitalWrite(en2, 255);
      delay (150); 
      digitalWrite(pompa, LOW);
      digitalWrite(Motor1, LOW);
      digitalWrite(Motor2, HIGH);
      digitalWrite(Motor3, HIGH);
      digitalWrite(Motor4, LOW);
      digitalWrite(en1, 255);
      digitalWrite(en2, 255);
      Serial.println("ROBOT BELOK KIRI");
      delay (150);
     }
     if (cm<5) //////////////////////
    {
    //kiri
      digitalWrite(pompa, LOW);
      digitalWrite(Motor1, LOW);
      digitalWrite(Motor2, HIGH);
      digitalWrite(Motor3, HIGH);
      digitalWrite(Motor4, LOW);
      digitalWrite(en1, 255);
      digitalWrite(en2, 255);
      Serial.println("ROBOT BELOK KIRI dikit");
      delay(200);
      digitalWrite(pompa, LOW);
      digitalWrite(Motor1, LOW);
      digitalWrite(Motor2, HIGH);
      digitalWrite(Motor3, LOW);
      digitalWrite(Motor4, HIGH);
      digitalWrite(en1, 255);
      digitalWrite(en2, 255);   
      delay(200);
      }
     if (cm2<10 && cm1==cm)
    {
      digitalWrite(pompa, LOW);
      digitalWrite(Motor1, LOW);
      digitalWrite(Motor2, LOW);
      digitalWrite(Motor3, LOW);
      digitalWrite(Motor4, LOW);
      digitalWrite(en1, 255);
      digitalWrite(en2, 255);
      Serial.println("ROBOT STOP");
      delay(1000);
      }
    if (nilaisensor<300)
    {
      digitalWrite(pompa, LOW);
    digitalWrite(Motor1, LOW);
      digitalWrite(Motor2, HIGH);
      digitalWrite(Motor3, LOW);
      digitalWrite(Motor4, HIGH);
      digitalWrite(en1, 255);
      digitalWrite(en2, 255);
//      delay(300);
      digitalWrite(pompa, LOW);
      digitalWrite(Motor1, LOW);
      digitalWrite(Motor2, HIGH);
      digitalWrite(Motor3, LOW);
      digitalWrite(Motor4, HIGH);
      digitalWrite(en1, 255);
      digitalWrite(en2, 255);
       digitalWrite(pompa, LOW);
    digitalWrite(Motor1, LOW);
      digitalWrite(Motor2, HIGH);
      digitalWrite(Motor3, LOW);
      digitalWrite(Motor4, HIGH);
      digitalWrite(en1, 255);
      digitalWrite(en2, 255);
      digitalWrite(pompa, HIGH);
      digitalWrite(Motor1, LOW);
      digitalWrite(Motor2, LOW);
      digitalWrite(Motor3, LOW);
      digitalWrite(Motor4, LOW);
//      digitalWrite(en1, 255);
//      digitalWrite(en2, 255);
      delay(2000);
      Serial.println("ROBOT Memadamkan");          
    }
  }
long microsecondsToCentimeters(long microseconds){
  return microseconds/29/2;
}
