#include<stdio.h>
#include<ctype.h>
#define size 50
char stack[size];
int top = -1;
void push (char ch);
int pop(char ch);
int precedence(char ch);
void display(char arr[]);
int isOperator(char ch);
int main(){
    char infix[50]="a*b+c*d-e", postfix[50],ch,ele;
    int i=0,j=0;
    for(i=0;infix[i]!='\0';i++){
        if(isalnum(infix[i])){
            postfix[j] = infix[i];
            j++;
        }else if(infix[i]=='('){
            top++;
            stack[top] = infix[i];
            // push(infix[i]);
        }else if(infix[i]==')'){
            while(top!=-1 && stack[top] != ')'){
                postfix[j]=stack[top];
                j++;
                top--;
                //postfix[j]=pop();
            }
            if(top!=-1 && stack[top]=='('){
                top--;
                //pop();
            }else{
                printf("invalid expression");
                return 0;
            }
        }else if(isOperator(infix[i])){
            while(top!=-1 && precedence(infix[i])<=precedence(stack[top])){
                postfix[j]=stack[top];
                j++;
                top--;
                //postfix[j]=pop();
            }
            top++;
            stack[top]=infix[i];
            //push(infix[i]);
        }
    }
    while(top!=-1){
        if(stack[top]=='('){
            printf("invalid expression");
            return 0;
        }
        postfix[j]=stack[top];
        j++;
        top--;
        //postfix[j]=pop();
    }
    postfix[j]='\0';
    display(postfix);
    return 0;
}


int precedence(char ch){
    if(ch=='^'){
        return 3;
    }else if(ch=='/' || ch=='*'){
        return 2;
    }else if(ch=='+' || ch=='-'){
        return 1;
    }else{
        return 0;
    }
}

int pop(char ch){
    if(top==-1){
        printf("stack is empty");
        return -1;
    }else{
        return stack[top--];
    }
}
void push(char ch){
    if(stack[top]=size-1){
        printf("stack is full");
    }else{
        stack[++top]=ch;
    }
}
void display(char arr[]){
        for(int i = 0 ; i<10 ; i++){
             printf("%c\t",arr[i]);
        }
   
}
int isOperator(char ch){
    return(ch=='+'||'-'||'*');
}