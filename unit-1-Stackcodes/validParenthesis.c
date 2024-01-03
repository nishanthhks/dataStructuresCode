#include<stdio.h>
int isopeningParenthesis(char p);
int isClosingParenthesis(char p);
int isBalanced(char expression[]);
int isValidPair(char opening,char closing);
char stack[100];
int top = -1;
int main(){
    char str[100] = "{[()]({}[]{()})}";
    if(isBalanced(str)){
        printf("balenced");
    }else{
        printf("not balenced");
    }
}
int isopeningParenthesis(char p){
    return (p == '(' || p == '[' || p == '{');
}
int isClosingParenthesis(char p){
    return (p == ')' || p == ']' || p == '}');
}
int isValidPair(char opening , char closing){
    return((opening=='(' && closing==')')||(opening=='[' && closing==']')||(opening=='{' && closing=='}'));
}

int isBalanced(char expression[]){
    for(int i = 0 ; expression[i]!='\0' ; i++){
        if(isopeningParenthesis(expression[i])){
            top++;
            stack[top] = expression[i];
        }
        if(isClosingParenthesis(expression[i])){
            if(isValidPair(stack[top],expression[i])){
                top--;
            }else{
                return 0;
            }
        }
    }
    return (top==-1);
}