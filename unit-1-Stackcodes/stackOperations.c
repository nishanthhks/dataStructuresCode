#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void push(int element);
int pop();
void display();
int peep();
int top = -1;
int stack[MAX];
int main(){
do
{
    printf("Enter options to perform operations\n1.push\n2.pop\n3.peep\n4.dispaly\n5.exit\n");
    int option;
    scanf("%d",&option);
    switch (option)
    {
        case 1 : printf("Enter the number to push : ");
                 int num;
                 scanf("%d",&num);
                 push(num);
                 break;
        case 2 : printf("The popped element is =  %d\n",pop());
                 break;
        case 3 : printf("the top element is = %d\n",peep());
                 break;
        case 4 : printf("The array is : \n");
                 display();
                 break;
        case 5 : exit(0);
                 break;
        default : printf("enter a valid number");                                             
    }
} while (1);    
}

void push(int element){
    if(top == MAX-1){
        printf("stack is full");
    }else{
        top++;
        stack[top] = element;
        printf("element pushed");
    }
}
int pop(){
    if(top == -1){
        printf("stack is empty");
        return -1;
    }else{
        int poppedEle = stack[top];
        top--;
        return poppedEle;
    }
}
int peep(){
    if(top == -1){
        printf("stack is empty");
        return -1;
    }else{
        return stack[top];
    }
}
void display(){
    if(top == -1){
        printf("stack is empty");
    }else{
        for(int i = 0 ; i<MAX ; i++){
             printf("%d\t",stack[i]);
        }
    }
   
}