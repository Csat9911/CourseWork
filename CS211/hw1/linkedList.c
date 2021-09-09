#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
 int data;
 struct node*next;
}node;


void add(node**head,int num){
    node*temp;
    if(*head==NULL||num<(*head)->data){
        temp = malloc(sizeof(node)); //here
        temp->data=num;
        temp->next=*head;
        *head=temp;
    }
    else{
        temp=*head;
        while(temp!=NULL){
            if(temp->data<=num&&(temp->next==NULL || temp->next->data>num)){
                node*temp1 = malloc(sizeof(node)); //here
                temp1->data=num;
                temp1->next=temp->next;
                temp->next=temp1;
                return;
            }
        temp=temp->next;
        }
    }

}

void printList(node *head){
    node *temp = head;
    while(temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
void countList(node *head){
    node *temp = head;
    int count=0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    printf("%d\n",count);
}

void removeDups(node *head){
    node *curr = head;
    node *nextVal;

    if(curr == NULL){
        return;
    }
    while(curr->next != NULL){
        if(curr->data == curr->next->data){
            nextVal = curr->next->next;
            free(curr->next);
            curr->next = nextVal;
        }
        else{
            curr = curr->next;
        }
    }
}
void freeList(node *head){
    node *pNode = head, *pNext;
    while(NULL != pNode){
        pNext = pNode->next;
        free(pNode);
        pNode = pNext;
    }
}

void delete(node **head, int key){
    if(*head == NULL){
        return;
    }
    node* temp = *head, *prev;

    if (temp != NULL && temp->data == key){
        *head= temp->next;
        free(temp); 
        return;
    }

    while (temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
        //free(temp); random free
    }

    if (temp == NULL) return;
    prev->next = temp->next;
        free(temp); 
}




int main(int argc, char *argv[]){
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

    FILE *fp;
    fp = fopen(argv[1], "r");
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
    node* head = NULL;
    while(fscanf(fp, "%s%d", op, &value) == 2){
        if (strcmp(op, "i") == 0){
            add(&head, value);
    }
    else if (strcmp(op, "d") == 0){
            delete(&head, value);
        }

    }
        countList(head);
        removeDups(head);
        printList(head);

        freeList(head);

        fclose(fp);

        return 0;

    }
