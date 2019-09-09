int rm1 = 2; //Right motor ground pin
int rm2 = 1; //Right motor VS pin
int lm1 = 4; //Left motor ground pin
int lm2 = 3; //Left motor VS pin
int en1 = 9; //Left motor enable
int en2 = 10; //Right motor enable

int l, r; //naming the sensors
int i;

void Stop()                          //stop
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,0);
}
void forward()                        //forward
{
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
} 

void right()                        //right
{
  digitalWrite(lm1,1);
  digitalWrite(lm2,0);
  digitalWrite(rm1,0);
  digitalWrite(rm2,1);
}
void left()                          //left
{
  digitalWrite(lm1,0);
  digitalWrite(lm2,1);
  digitalWrite(rm1,1);
  digitalWrite(rm2,0);
}


void readsens()                      //reading sensors
{
  l = digitalRead(A0); //left IR Sensor
  r = digitalRead(A1); //Right IR Sensor
} 



void setup()
{
 //Motor pins as Output 
  pinMode(lm1, OUTPUT); 
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);
 //Enable pins as input
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  //Sensors as input
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  
}


void loop()
{

 //Read Sensor data
  readsens();

 if((l==1)&&(c1==1)) //Forward condition
  {
    forward();
  }

  else if((l==0)&&(c1==1)) //Left condition 
  {
    left();
  }

  else if((l==1)&&(c1==0)) //Right condition
  {
    right();
  }

  else if((l==1)&&(c1==1))
  {
    forward();
    digitalWrite(buzz,1); //Buzz sound when there is a marker
    delay(700);
  }

  
 
  
}
 
