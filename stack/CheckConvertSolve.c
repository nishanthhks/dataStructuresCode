#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char stack[10];
int top = -1;

void push(char ch){
    stack[++top] = ch;    
}

char pop(){
    return stack[top--];
}

void displayPostfix(char exp[]){
    for(int i = 0 ; i<10 ; i++){
        printf("%c",exp[i]);
    }
}

int isOpening(char bracket){
    return ((bracket=='(') 
         || (bracket=='{')
         || (bracket=='['));
}

int isClosing(char bracket){
    return ((bracket==')') 
         || (bracket=='}')
         || (bracket==']'));
}

int isOperator(char ch){
    return(ch=='+'|| ch=='-'|| ch=='*' || ch=='/');
}

int isValidPair(char open,char close){
    return ((open == '{' && close == '}')
         || (open == '(' && close == ')')
         || (open == '[' && close == ']'));
}

int precedence(char ch){
    if (ch == '*' || ch == '/'){
        return 2;
    }else if (ch == '+' || ch == '-'){
        return 1;
    }else{
        return 0;
    }
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

int compute(int a,char op,int b){
    int res;
    switch(op){
        case '*' : res = a * b;break;
        case '+' : res = a + b;break;
        case '-' : res = b - a;break;
        case '/' : res = a / b;break;
    }
    return res;
}

int solvePostfix(char exp[]){
    int i = 0;
    int res;
    while(exp[i] != '\0'){
        if(isdigit(exp[i])){
            push((exp[i] - '0'));
        }else{
            int a = pop();
            int b = pop();
            int res = compute(a,exp[i],b);
            push(res);
        }
        i++;
    }
    return stack[top--];
}

void infixToPostfix_and_solve(char infix[]){
    char postfix[20] = "";
    int i = 0;
    int j = 0;
    while(infix[i] != '\0'){
        if (isalnum(infix[i])) {
            postfix[j] = infix[i];  //add to postfix
            j++;
        } else if (isOpening(infix[i])) {
            push(infix[i]);  // push to stack
        } else if (isClosing(infix[i])){
            while (stack[top] != '(' && stack[top] != '[' && stack[top] != '{') { // remove operator
                postfix[j] = pop();
                j++;
            }
            pop();    //remove "(" from stack
        } else if (isOperator(infix[i])){
            while(precedence(infix[i]) <= precedence(stack[top])){
                postfix[j] = pop();
                j++;
            }
            push(infix[i]); // push the latest scanned operator 
        }
        i++;
    }

    while(top != -1){
        postfix[j] = pop();
        j++;
    }
    
    displayPostfix(postfix);
    printf("\n%d",solvePostfix(postfix));

}

int main(){
    // char infix[20] = "a*b+c*d-e";  //to convert
    char infix[20] = "1*2+3*4-6";     // to convert and solve
    char postfix[20] = "";
    int j = 0;
    int i = 0;

    if(isBalancedParentheses(infix)){
        printf("its a balanced parentheses\n");
        infixToPostfix_and_solve(infix);
    }else{
        printf("its not a balanced parentheses");
    }
    return 0;
}