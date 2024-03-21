#include<stdio.h>
                 
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
/*0,1,1,2,3,5,8
  0 1 2 3 4 5 6*///if num=6 then fib=8

int gcd(int num1,int num2){
    if(num1==0){
        return num2;
    }else if(num2==0){
        return num1;
    }else{
        return gcd(num2,num1%num2);
    }
}

void printFun(int test) {
    if (test < 1)
        return;
    else {
        printf("%d\n", test); // corrected quote
        printFun(test - 1); // statement 
        printf("\n%d", test); // corrected quote
        return;
    }
}

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main(){
    int n=6;
    printf("sumofN: %d\tfactorial: %d\tfibonacci: %d\t",sum_of_n(n),fact(n),fib(n));
    printf("gcd: %d\n",gcd(8,12));

    int test = 3;
    printFun(test);

    int i;
    // Input number of disks
    printf("\nEnter the number of disks: ");
    scanf("%d", &i);
    // Function call
    towerOfHanoi(i, 'A', 'B', 'C');
    return 0;
}