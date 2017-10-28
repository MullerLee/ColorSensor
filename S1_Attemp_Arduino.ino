//The arduino version of color sensor Step_1
# define S0 1
# define S1 2
# define S2 3
# define S3 4
# define OUT 5

int count;
long time = 0;
long timeold = 0,timenew = 0;
long Freq;

setup()
{
  Serial.begin(9600);
  
  pinMode(S0,INPUT);
  pinMode(S1,INPUT);
  pinMode(S2,INPUT);
  pinMode(S3,INPUT);
  pinMode(OUT,OUTPUT);
  
  digitalWrite(S0,0);   //0,0 PD; 1,0 2%; 0,1 20%; 1,1 100%
  digitalWrite(S1,0);
  digitalWrite(S2,1);   //ONLY RED
  digitalWrite(S3,1);
  
  attachInterrupt(0,Control,FALLING);  //Interrupt Code, Function, Interrupt Mode
}

loop()
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
  }
  attachInterrupt(0,Control,FALLING);
}
