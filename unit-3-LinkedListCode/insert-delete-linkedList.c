#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
size = 0;

void insert_begin(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted at begining : ");
    scanf("%d",&newNode->data);
    newNode->next = head;
    head=newNode;
    size++;
}

void insert_end(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted at begining : ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        size++;
        return;
    }
    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    size++;
}

void insert_position(){
    int position;
    printf("Enter the position to insert : ");
    scanf("%d",&position);
    if(position<0 || position>size){
        printf("invalid position,Enter correct number.\n");
        return;
    }
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the value to be inserted at begining : ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    if(position==0){
        newNode->next=head;
        head = newNode;
        printf("Element inserted at position 0 successfully.\n");
        size++;
        return;
    }
    

}

int main (){
    printf("h");
    return 0;
}