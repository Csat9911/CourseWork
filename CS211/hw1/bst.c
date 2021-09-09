#include<stdio.h>
#include <stdlib.h> 

struct Node{
    int value;
    struct Node *left, *right;
};

struct Node *newNode(int data){
    struct Node *newN =  (struct Node *)malloc(sizeof(struct Node));
    newN->value = data;
    newN->left = newN->right = NULL;
    return newN;
}

struct Node *insert(struct Node* node, int data){
    if (node == NULL){
        node = newNode(data);
        return node;
    }

    if(node->value == data){
        return node;
    }

    if (data < node->value){
        // go left, val smaller
        node->left  = insert(node->left, data);
    }
    else if (data > node->value){
        //go right, val larger
        node->right = insert(node->right, data);    
    }
  
    return node;
}
void postFree(struct Node *head){
    struct Node *temp = head;
    if (head != NULL){
        //postOrder Trav to free all nodes
        postFree(temp->left);
        postFree(temp->right);
        free(temp);
        
    }
}
void inorder(struct Node *head){
    if (head != NULL){
        //inorder traversal lNr to print
        inorder(head->left);
        printf("%d\t", head->value);
        inorder(head->right);
    }
}

int main(int argc, char **argv)
{
    
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
    struct Node *head = NULL;
    int value;
    FILE *fp;
    fp = fopen(argv[1], "r");

//empty file check
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

    while(fscanf(fp, "%*c%*c%d", &value) == 1)
    {
        head = insert(head,value);
    }

    inorder(head);
    fclose(fp);
    postFree(head);
    
    return 0;
}

