#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void enqueue(int element);
int dequeue();
void display();
int peep();
int front = -1;
int rear = -1;
int queue[MAX];
int main(){
do
{
    printf("\nEnter options to perform operations\n1.enqueue\n2.dequeue\n3.peep\n4.dispaly\n5.exit\n");
    int option;
    scanf("%d",&option);
    switch (option)
    {
        case 1 : printf("\nEnter the number to add : ");
                 int num;
                 scanf("%d",&num);
                 enqueue(num);
                 break;
        case 2 : printf("The deleted element is =  %d\n",dequeue());
                 break;
        case 3 : printf("the front element is = %d\n",peep());
                 break;
        case 4 : printf("The queue is : \n");
                 display();
                 break;
        case 5 : exit(0);
                 break;
        default : printf("\nenter a valid number");                                             
    }
} while (1);    
}

void enqueue(int element){
    if((rear+1)%MAX==front){
        printf("queue is full");
    }else if(front==-1||rear==-1){
        front=rear=0;
        queue[rear]=element;
    }else{
        rear=(rear+1)%MAX;
        queue[rear]=element;
        printf("\nelement added\n");
    }
}
int dequeue(){
    if(front==-1||rear==-1){
        printf("\nqueue is empty\n");
        return -1;
    }else if(front==rear){
        int element = queue[front];
        front=rear=-1;
        return element;
    }else{
        int element = queue[front];
        front=(front+1)%MAX;
        return element;
    }
}
int peep(){
    if(front==-1||rear==-1){
        printf("\nque is empty\n");
        return -1;
    }else{
        return queue[front];
    }
}
void display(){
    int i;
    if(front==-1||rear==-1){
        printf("\nqueue is empty\n");
    }else{
        for(i = front ; i!=rear/*||i==rear*/ ; i=(i+1)%MAX){
             printf("%d\t",queue[i]);
        }
        printf("%d\t",queue[i]);
    }
   
}