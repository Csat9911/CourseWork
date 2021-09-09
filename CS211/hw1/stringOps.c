#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
    //dont need to error check
    for(int i=1;i<argc;i++){
        for(int x=0;x<strlen(argv[i]);x++){
        if(argv[i][x]=='a' || argv[i][x]=='e' || argv[i][x]=='i' || argv[i][x]=='o' || argv[i][x]=='u' || argv[i][x]=='A' || argv[i][x]=='E' || argv[i][x]=='I' || argv[i][x]=='O' || argv[i][x]=='U'){
            printf("%c",argv[i][x]);
        }
    }
    }
    printf("\n");



return 0;

}
