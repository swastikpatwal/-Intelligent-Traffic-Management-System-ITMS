#define ech 10
#define trig 11
#define RED 8
#define GREEN 9

long time;
int dist;
int ini;

void setup()
{
  pinMode(ech,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  
  Serial.begin(9600);
  Serial.println("DISTANCE: ");

  digitalWrite(trig,LOW);
  delay(100);
  digitalWrite(trig,HIGH);
  delay(100);
  digitalWrite(trig,LOW);
  
  //ini=pulseIn(ech,HIGH);
  //ini=ini*0.034/2;
  ini=2140;
  Serial.println("INITIAL: ");
  Serial.print(ini);
}

void loop()
{
    digitalWrite(trig, LOW);
    delay(20);
    digitalWrite(trig, HIGH);
    delay(1000);
    digitalWrite(trig, LOW);

    time=pulseIn(ech,HIGH);
    dist= time *0.034/2;

    Serial.print(dist);
    Serial.print("\n");

    if (dist>=ini)
    {
      digitalWrite(GREEN, HIGH);
      digitalWrite(RED, LOW);
    }else{
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
    }
}

