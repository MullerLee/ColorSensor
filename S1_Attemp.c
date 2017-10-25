/*-------------------------------
We don`t really need to get an accurate RGB data.
We only need a relative data to judge if the color of objects we detect is red.
  1. USE RED DETECT MODE ONLY.
  2. CHOOSE STC89C52RC AS MCU.
  3. ONLY DETECT ---> RED APPEARS.
  
The standard of relative data remains to be found.
TUse Rela_Dat to name it.
INT0 is on P3^2
---------------------------------*/

#include <reg52.h>

sbit OE  = P1^0 ;
sbit S1  = P1^1 ;
sbit S0  = P1^2 ;
sbit S3  = P1^4 ;
sbit S4  = P1^5 ;

sbit OUT = P3^5 ;

 //Global Parameters
int count = 0;
int time  = 0;

//Function Prototypes
void Color_Detect_Init ( );
void OUT_Frequency_Init ( );
void Int_Init ( );
void Timer_Init ( );
void Int0_Interrupt ( );


//Main
void main()
{
  //STC89C52RC doesn`t have WTD
  OE = 1 ;  //CS Signal
  Color_Detect_Init ( );
  OUT_Frequency_Init ( );
  Int_Init ( ) ;
  
  EA = 1;    //Enable Global Interrupt
  TR0 = 1;   //Enable Timer0
   
  while(1)
  {
    //Output Frequency has liner relation with I.
    printf ( %d , Freq );
  }
}


//Function Defination
void Color_Detect_Init ( ) { //Set Mode as ONLY RED
  if( S2!=1 )
    S2 = 1;
  if( S3!=1 )
    S3 = 1;
}

void OUT_Frequency_Init ( ) { //Set standard output frequency
  S0 = 0 ; S1 = 0 ;  //Power Down
  //S0 = 1 ; S1 = 0 ;  //2%
  //S0 = 0 ; S1 = 1 ;  //20%
  //S0 = 1 ; S1 = 1 ;  //100%
}

void Int_Init ( ) { //Init Interrupt & Timer
  EX0=1;           //Enable Interrupt 0
  IT0=1;          //Drop Init
}

void Timer_Init ( ) {  //Timer0 init as time counter
  TMOD = 0x01;
  TH0 = 0x00;
  TL0 = 0x00;
}

void Int0_Interrupt ( ) interrupt 0
{
  EA = 0;
  count ++;
  if( count == 10 ){
   EA = 0;
   TR0 = 0;
   time = TH0 * 256 + TL0;
   Freq = count / time ; 
   count = 0;
   TH0 = 0x00;
   TL0 = 0x00;
   EA = 1;
   TR0 = 1;
  }
}
}
