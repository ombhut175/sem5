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
        return;
    }
    struct Node * temp = head;
    
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    
    temp->link = newNode;
}

void delete(int n){
    if (head == NULL)
    {
        printf("LL is empty\n");
        return; 
    }

    if (head->info == n)
    {
        head = head->link;
        return;
    }
    

    struct Node* temp = head;
    struct Node* pred = temp;

    while (temp->link != NULL && temp->info != n )
    {
        pred = temp;
        temp = temp->link;
    }

    if (temp->info!=n && temp->link == NULL)
    {
        printf("Node not found\n");

        return;
    }
    
    
    struct Node* deletedNode = temp;
    pred->link = deletedNode->link;
    printf("deleted node %d\n",deletedNode->info);

    free(deletedNode);
}


void displayLinkedList(){
    struct Node * temp = head;
    
    while (temp != NULL)
    {
        printf("%d ",temp->info);
        temp = temp->link;
    }
}


void main(){

    delete(4);

    insert(5);
    insert(6);
    insert(7);

    delete(6);
    delete(9);
    displayLinkedList();
}