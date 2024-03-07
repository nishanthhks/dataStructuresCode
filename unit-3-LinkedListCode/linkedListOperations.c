#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;

struct node *createNode(){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    return newNode;
}

void insertBeg(int value){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;
    head=newNode;
}

void insertLast(int value){
    struct node *newNode = malloc(sizeof(struct node));
    struct node *temp;
    newNode->data = value;
    if(head==NULL){
    //check for no node
        newNode->next = head;
        head=newNode;
    }else{
    //if there are atleast one node    
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->next=NULL;
    }
}

int insertRandom(int value,int loc){
    struct node *newNode = malloc(sizeof(struct node));
    struct node *temp;
    newNode->data = value;
    temp=head;
    for(int i = 1; i<loc; i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}

void deleteBeg(){
    struct node *temp;
    if(head==NULL){
        printf("\nempty list\n");
    }else{
        temp=head;
        head=head->next;
        free(temp);
    }
}

void deleteLast(){
    struct node *temp,*temp1;
    //no node
    if(head==NULL){
        printf("\nempty list\n");
    }else if(head->next==NULL){
    //for only one node
        temp=head;
        head=NULL;
        free(temp);   
    }else{
    // for more nodes
        temp=head;
        while(temp->next!=NULL){
            temp1=temp;
            temp=temp->next;
        }    
        temp1->next=NULL;
        free(temp);
    }   
}

void deleteRandom(int loc){
    struct node *temp,*temp1;
    temp=head;
    for(int i = 1; i < loc; i++){
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next=temp->next;
    free(temp);
}

void traversal(){
    struct node *temp = head;
    printf("\nElements: \n");
    while(temp!=NULL){
        printf("%d-->",temp->data);
        temp = temp->next;
    }
}
 
void search(int value){
    struct node *temp;
    temp=head;
    int flag=0;
    while(temp!=NULL){
        if(temp->data==value){
            printf("element found");
            flag=1;
        }else{
            flag=0;
        }
        temp=temp->next;
    }
    if(flag==0){
        printf("element not found");
    }
} 

struct node* concatenate(struct node *list1,struct node *list2){

}

void sort(struct node *ptr){
    struct node *i,j;
    int temp;
    for(i=0; i)
}

int main(){
    return 0;
}