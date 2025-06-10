#include <stdio.h>

#define SIZE 2

struct Stack
{
   int top;
   int arr[SIZE];
} s;


void push(int n){
    
    if (s.top >= SIZE )
    {
        printf("Stack is full\n");
        return;
    }
    
    s.arr[s.top++] = n;
}

void printTop(){
    printf("%d \n",s.top);
}

int pop(){

    if(s.top < 0){
        printf("Stack is empty");
        return -1;
    }

    s.top--;
    return s.arr[s.top];
}

int peep(int index){

    int change = s.top - index -1;
    if (change <0 )
    {
        return -1;
    }

    return s.arr[change];
    
}

void printStack(){
    for(int i = 0 ;i<SIZE ; i++){
        printf("%d ",s.arr[i]);
    }
}

void main(){
    push(5);
    push(6);

    // printStack();

    // for(int i = 0;i<SIZE + 1 ;i++){
    //     printf("%d ",pop());
    // }

    
    printf("%d ",peep(1));
    printf("%d ",peep(2));
    
}