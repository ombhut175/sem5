#include<stdio.h>

struct Node
{
    int info;
    struct Node* link;
} *head = NULL;



void insert(int n){
    struct Node * newNode = (struct Node *) malloc(sizeof (struct Node));
    newNode->link = NULL;
    newNode->info = n;
    
    if (head == NULL)
    {
        head = newNode;
        head->link = head;
        return;
    }
    struct Node * temp = head;
    
    do{
        temp = temp->link;
    }while (temp->link != head);
    
    
    temp->link = newNode;
    newNode->link = head;
}

void delete(int n){
    if (head == NULL)
    {
        printf("CLL is empty");
        return;
    }
    
     
}


void displayLinkedList(){
    struct Node * temp = head;
    
    do{
        printf("%d ",temp->info);
        temp = temp->link;
    }while (temp != head);
}


void main(){
    insert(5);
    insert(6);
    insert(7);

    displayLinkedList();
}