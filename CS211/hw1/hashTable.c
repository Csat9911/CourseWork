#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct node{
 int data;
 struct node*next;
}node;


//global vars
int searchCount = 0;
int collCount = 0;

int hashCode(int value){
    int hashIndex;
    if(value > 0){
        //positive
        hashIndex = value % 10000;
    }
    else if(value < 0){
        //fix negative index
        hashIndex = (value % 10000)+10000;
    }
    return hashIndex;
}
//*****************************************************
void insertNewNode (node** head, int value){
    node* newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
    }
    else{
        node* curr = *head;
    
    while(curr->next != NULL){
        curr = curr->next;
    }

    curr->next = newNode;
}
}
//*********************************************************
void inserttoHash(node** hashTable, int newVal){
    int index = hashCode(newVal);  
    //no head at index, create one
    if(hashTable[index] == NULL){
        //printf("enterting null\n");
        //hashTable[index] = malloc(sizeof(node*));
        node* head = NULL;
        //call insert new which will create a new node
        insertNewNode(&head, newVal);
        //insert that into hashtable
        hashTable[index] = head;

    }
    else{
        //printf("Hit\n");
        collCount++;
        //locate head
        node* head = hashTable[index];
        //create new node
        insertNewNode(&head,newVal);
        //link to head
        hashTable[index] = head;
    }


}


void displayTable(node** hashTable){
    for(int i=0;i<10000;i++){
        node* head = hashTable[i];
        printf("%d: ",i);

    if(head ==NULL){
        printf("Null");
    }
    else{
        node* curr = head;
        while(curr != NULL){
            printf("%d ", curr->data);
            curr=curr->next;
        }
    }
    printf("\n");
    }
}
//**********************************************************
void search (node** hashTable, int value){
//search
    int i;
    int index = hashCode(value); 
    node* head = hashTable[index];
    if(head == NULL){
        return;
    }
    else{
        node* curr = head;
        while(curr != NULL){
            if(curr->data == value){
                //success
                searchCount++;
                break;
            }
            else{
                curr = curr->next;
            }
        }
    }
}
void collCountPrint(){
    printf("%d\n", collCount);
}
//**********************************************************
node** initTable(){
    node** hashTable = calloc(10000,sizeof(node*));
    return hashTable;
}

void freeList(node *head){
    node *pNode = head, *pNext;
    while(NULL != pNode){
        //printf("%d <----freeing\n",pNode->data);
        pNext = pNode->next;
        free(pNode);
        pNode = pNext;
    }
}

void freeHash(node** hashTable){
    for(int i=0;i<10000;i++){
        //node* head = hashTable[i];
        freeList(hashTable[i]);
    }
    free(hashTable);

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

    FILE *fp = fopen(argv[1], "r");
    char op[100];
    int value;
    
    //empty file check
    if(NULL != fp){
        int size = 0;
        fseek(fp,0,SEEK_END);
        size = ftell(fp);
        if(0 == size){
            printf("\n");
            printf("\n");
            return 0;
        }
        else{
            fseek(fp,0,SEEK_SET);
        }
    }
    node** table = initTable();

    while(fscanf(fp, "%s%d", op, &value) == 2){
        if (strcmp(op, "i") == 0){
            //insert
            inserttoHash(table,value);
    }
    else if (strcmp(op, "s") == 0){
            //search
           search(table,value);
           
        }
    else{
        printf("error");
    }
    }

    //displayTable(table);
    //printf("\n");
    collCountPrint();
    
    printf("%d\n",searchCount);

    freeHash(table); // freeing indiviudal nodes
    fclose(fp);
    return 0;
}
