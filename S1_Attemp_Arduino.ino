//The arduino version of color sensor Step_1
# define S0 A1
# define S1 A2
# define S2 A3
# define S3 A4
# define OUT A5

int count=0;
long time = 0;
long timeold = 0,timenew = 0;
long Freq=0;

void setup()
{
  Serial.begin(9600);
  
  pinMode(S0,INPUT);
  pinMode(S1,INPUT);
  pinMode(S2,INPUT);
  pinMode(S3,INPUT);
  pinMode(OUT,OUTPUT);
  
  digitalWrite(S0,0);   //0,0 PD; 1,0 2%; 0,1 20%; 1,1 100%
  digitalWrite(S1,1);
  digitalWrite(S2,1);   //ONLY RED
  digitalWrite(S3,1);
  
  attachInterrupt(0,Control,FALLING);  //Interrupt Code, Function, Interrupt Mode
}

void loop()
{
  Serial.println(Freq);
  Serial.println('\n');
}

void Control()
{
  count++;
  if(count==10){ 
    detachInterrupt(0);
    timenew=micros();    //micros(): osillator freq=16MHz--->4us; freq=8MHz--->8us ; Overflow time:70min
    time=timenew-timeold;
    Freq=count/time;
    timeold=timenew;
    count=0; 
    attachInterrupt(0,Control,FALLING);
  }
}
