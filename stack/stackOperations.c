#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
int stack[SIZE];
int top = -1;

void push(int val){
    if(top==SIZE-1){
        printf("\nstack is full\n");
    }else{
        stack[++top] = val;
        printf("\n%d inserted\n",val);
    }
}

int pop(){
    int val = -1;
    if(top==-1){
        printf("\nstack is empty\n");
    }else{
        val = stack[top--];
    }
    return val;
}

void diaplay(){
    if(top==-1){
        printf("\nstack is empty\n");
    }else{
        for (int i = 0; i <= top; i++){
            printf("%d ",stack[i]);
        }
    }
}

int main(){
    int choice;
    int val;
    while(1){ 
        printf("\n1.push\t2.pop\t3.display\t4.exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1 :{
                
                printf("\nEnter number to insert : ");
                scanf("%d",&val);
                push(val);
                break;
            } 
            case 2 :{
                printf("\nRemoved element is = %d",pop());
                break;
            } 
            case 3 :{
                printf("\nElements are\n");
                diaplay();
                break;
            } 
            case 4 :{
                exit(0);
                break;
            } 
            default : printf("invalid number");             
        }
    }
    return 0;
}