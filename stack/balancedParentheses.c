#include<stdio.h>
#include<stdlib.h>

char stack[10];
int top = -1;

void push(char val){
    stack[++top] = val;    
}

void pop(){
    stack[top--];
}

int isValidPair(char open,char close){
    return ((open == '{' && close == '}')
         || (open == '(' && close == ')')
         || (open == '[' && close == ']'));
}

int isBalancedParentheses(char exp[]){
    int i=0;
    while(exp[i]!='\0'){
        if((exp[i] == '{') || (exp[i] =='[') || (exp[i] =='(')){
            push(exp[i]);
        }else if ((exp[i] == '}') || (exp[i] ==']') || (exp[i] ==')')){
            if(top==-1){    //to check if top is not empty if we encounter a closing at starting
                return 0;
            }
            if(isValidPair(stack[top],exp[i])){
                pop();
            }
        }
        i++;
    }
    return (top==-1);
}

int main(){
    char exp[10] = "{[({})]}";
    if(isBalancedParentheses(exp)){
        printf("its a balanced parentheses");
    }else{
        printf("its not a balanced parentheses");
    }
    return 0;
}