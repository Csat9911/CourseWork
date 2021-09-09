#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void parityCounter(unsigned short x);
int EvenorOdd();
unsigned short x;
int countPairs;


int main(int argc, char* argv[])
{
    if(argc<=1){
        printf("error\n");
        return 1;
    }
    x = atoi(argv[1]);
    
    parityCounter(x);
    int EvenOddCount = EvenorOdd();
    
    //printf("%d: ",EvenOddCount);
    if(EvenOddCount%2 == 0){
        //there are pairtys
        if(x==0){
            //fix error here
            printf("Even-Parity\t%d\n",countPairs);
        }
        else{
        printf("Even-Parity\t%d\n",countPairs);
        }

    }
        else{
            printf("Odd-Parity\t%d\n",countPairs);
        }
    
    return 0;
    
   
}

void parityCounter(unsigned short x){
    //call this function before so x isnt modified
    int visted = 0;
    int holdLast =0;
    int maxLength = 16;
    //keep track of last bit to compare to new bit
   for(int i=0;i<maxLength;i++){
       if(visted==0){
            holdLast = (x>>i)&1;
            visted++;
       }
       else{
       int holdCurr = (x>>i)&1;
       //bit and to check if both are set, increment count if they are
       if(holdCurr != holdLast){
           holdLast=holdCurr;
       }
       else if(holdCurr & holdLast){
           countPairs++;
           visted=0;
       }
   }
   }
}

int EvenorOdd(){
    //function will just count all ones in x
    int y=0;
    while(x){
        y+=x&1;
        x>>=1;
    }
    return y;
}