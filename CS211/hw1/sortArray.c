#include <stdio.h>
#include <stdlib.h>

 void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 

void reverse(int arr[], int start, int end){
    int temp;
    while(start < end){
        temp = arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}
   
  void EvenOdd(int arr[], int size) 
{ 
    int lastEvenIndex = 0;
    int oddNumberSize =0;
    int i;
    int index = 0;
    int evenInd =0;
    int oddInd = 0;
    int retEven = 0;
    int retOdd = 0;
    int evenarr[100];
    int oddarr[100];
    int retarr[100];

    for(i=0;i<size;i++){
    if(arr[i]%2==0){
        lastEvenIndex++;
    }
    }
    oddNumberSize = size-lastEvenIndex;

   for(i=0;i<size;i++){
       if(arr[i]%2==0){
           evenarr[evenInd] = arr[i];
           evenInd++;
       }
       else{
           oddarr[oddInd] = arr[i];
           oddInd++;
       }
       }

    bubbleSort(evenarr,lastEvenIndex);
    bubbleSort(oddarr,oddNumberSize);
   //make call to reverse array
    reverse(oddarr,0,oddNumberSize-1);
     for (i = 0; i < lastEvenIndex; i++) {
        printf("%d\t", evenarr[i]);
     }
     for (i = 0; i < oddNumberSize; i++) {
        printf("%d\t", oddarr[i]);
     }

}

int main(int argc, char* argv[]){
    //check if user gave correct input
    if(argc < 2){
        printf("error\n");
        return 1;
    }
    //check if file can be read
    if(fopen(argv[1],"r") == NULL){
        printf("error\n");
        return 1;
    }

    int arr[100];
    int size,i;
    FILE* fp = fopen(argv[1],"r");
    
    if(NULL != fp){
        int size = 0;
        fseek(fp,0,SEEK_END);
        size = ftell(fp);
        if(0 == size){
            printf("\n");
            return 0;
        }
        else{
            fseek(fp,0,SEEK_SET);
        }
    }

    fscanf(fp,"%d",&size);
    for(i=0;i<size;i++){
        fscanf(fp,"%d",&arr[i]);
    }
    fclose(fp);
    EvenOdd(arr,size);

    return 0;
}
