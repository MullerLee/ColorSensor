/*-------------------------------
  1. USE RED DETECT MODE ONLY.
  2. CHOOSE STC89C52RC AS MCU.
  3. ONLY DETECT ---> RED APPEARS.
---------------------------------*/

#include <reg52.h>

sbit OE  = P1^0 ;
sbit S1  = P1^1 ;
sbit S0  = P1^2 ;
sbit S3  = P1^4 ;
sbit S4  = P1^5 ;

sbit OUT = P3^5 ;

//Function Prototypes
void Color_Detect_Init ( );
void OUT_Frequency_Init ( );


//Main
void main()
{
  //STC89C52RC doesn`t have WTD
  

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

