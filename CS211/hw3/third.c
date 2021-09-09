#include <stdio.h>
#include <stdlib.h>
unsigned short x;
int get(unsigned short n);
int main(int argc, char* argv[])
{
    if(argc<=1){
        printf("error\n");
        return 1;
    }
    x = atoi(argv[1]);
    int start=0;
    int end=15;
    int boo=0;
    while(start<end){
        if(get(start)!=get(end)){
            //terminate once it finds first error
            boo=1;
            break;
        }
        else{
            start++;
            end--;
        }
    }
   if(boo==1){
       printf("Not-Palindrome\n");
   }
   else{
       printf("Is-Palindrome\n");
   }
   
}

int get(unsigned short n){
    //n is the nth bit
    //x is the first val of file
    n =(x>>n)&1;
    return n;
}