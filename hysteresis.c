#include "hysteresis.h"
#include <stdio.h>

unsigned int hysteresis(unsigned int input_percent){
    static unsigned int hysteresis_state=0;
    unsigned int valuetoconvert= input_percent*10;
    unsigned int threshold1 = 125;
    unsigned int threshold2 = 375;
    unsigned int threshold3 = 625;
    unsigned int threshold4 = 875;
    
    unsigned int percentincr = 25;
    unsigned int percentdecr = 25;
    
    switch (hysteresis_state)
    {
        case 0://0
            if((valuetoconvert)>=(threshold4+percentincr)){
                hysteresis_state =4;
            }else if ((input_percent*10)>=(threshold3+percentincr)){
                hysteresis_state =3;            
            }else if ((input_percent*10)>=(threshold2+percentincr)){
                hysteresis_state =2;               
            }else if ((input_percent*10)>=(threshold1+percentincr)){
                hysteresis_state =1;
            }   
            break;
        case 1: //1
            if((valuetoconvert)>=(threshold4+percentincr)){
                hysteresis_state =4;
            }else if ((valuetoconvert)>=(threshold3+percentincr)){
                hysteresis_state =3;            
            }else if ((valuetoconvert)>=(threshold2+percentincr)){
                hysteresis_state =2;            
            }else if ((valuetoconvert)<=(threshold1-percentdecr)){
                hysteresis_state =0;
            }   
            break;                  
        case 2: //2
            if((valuetoconvert)>=(threshold4+percentincr)){
                hysteresis_state =4;
            }else if ((valuetoconvert)>=(threshold3+percentincr)){
                hysteresis_state =3;
            }else if ((valuetoconvert)<=(threshold1-percentdecr)){
                hysteresis_state =0;
            }else if ((valuetoconvert)<=(threshold2-percentdecr)){
                hysteresis_state =1;
            }   
            break;
        case 3: //3
            if((valuetoconvert)>=(threshold4+percentincr)){
                hysteresis_state =4;
            }else if ((valuetoconvert)<=(threshold1-percentdecr)){
                hysteresis_state =0;
            }else if ((valuetoconvert)<=(threshold2-percentdecr)){
                hysteresis_state =1;
            }else if ((valuetoconvert)<=(threshold3-percentdecr)){
                hysteresis_state =2;
            }   
            break;
        case 4: //3
            if((valuetoconvert)<=(threshold1-percentdecr)){
                hysteresis_state =0;
            }else if ((valuetoconvert)<=(threshold2-percentdecr)){
                hysteresis_state =1;
            }else if ((valuetoconvert)<=(threshold3-percentdecr)){
                hysteresis_state =2;
            }else if ((valuetoconvert)<=(threshold4-percentdecr)){
                hysteresis_state =3;
            }   
            break;        
    }
    
    return hysteresis_state;
}
