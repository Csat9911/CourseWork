#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void get(int n);
void comp(int n);
void set(int n, int v);
//make x global to add changes as we set and comp
unsigned short x;

int main(int argc, char* argv[]){
    FILE* fp = fopen(argv[1], "r");

    if(fp == NULL){
        printf("error");
    }
    //read in first value 
    fscanf(fp, "%hu", &x);
    //convert value
    char c[5];
    int a;
    int b;

    while(fscanf(fp,"%s%d%d",c, &a, &b)==3){
        //printf("%s\n",c);
        if(strcmp(c,"set")==0){
            set(a,b);
        }
        else if(strcmp(c,"get")==0){
            get(a);
        }
        else if(strcmp(c,"comp")==0){
            comp(a);
        }
    }
    fclose(fp);
    return 0;
}

void get(int n){
    //n is the nth bit
    //x is the first val of file
    n =(x >>n)&1;
    printf("%d\n",n);
}
void set(int n, int v){
    if(v!=0){
        x=x|(1<<n);
        }
    else if(v==0){
        x=x&(~(1<<n));
    }
    printf("%hu\n",x);
        }

void comp(int n){
    x=x^(1<<n); 
    printf("%hu\n",x);
}