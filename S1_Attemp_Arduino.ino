# define S1 1
# define S2 2
# define S3 3
# define S4 4
# define OUT 5

int count,time

setup()
{
  digitalWrite(S1,INPUT);
  digitalWrite(S2,INPUT);
  digitalWrite(S3,INPUT);
  digitalWrite(S4,INPUT);
  digitalWrite(OUT,OUTPUT);
  attachInterrupt(0,Control,FALLING);  //Interrupt Code, Function, Interrupt Mode
}

loop()
{
  
  
}

void Control()
{
 
  count++;
  if(count==10){ detachInterrupt(0);
  }
  attachInterrupt(0,Control,FALLING);
}
