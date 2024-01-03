#include<stdio.h>
int sum_of_n(int num);
int fact(int num);
int fib(int num);/*0,1,1,2,3,5,8
                   0 1 2 3 4 5 6*///if num=6 then fib=8
int gcd(int num1,int num2);                   
int main(){
    int n=6;
    printf("%d\t%d\t%d\t",sum_of_n(n),fact(n),fib(n));
    printf("%d",gcd(8,12));
}
int sum_of_n(int num){
    if(num==1 || num==0){
        return num;
    }else{
        return num+sum_of_n(num-1);
    }
}
int fact(int num){
    if(num==0){
        return 1;
    }else{
        return num*fact(num-1);
    }
}
int fib(int num){
    if(num==0 || num==1){
        return num;
    }else{
        return fib(num-1)+fib(num-2);
    }
}
int gcd(int num1,int num2){
    if(num1==0){
        return num2;
    }else if(num2==0){
        return num1;
    }else{
        return gcd(num2,num1%num2);
    }
}