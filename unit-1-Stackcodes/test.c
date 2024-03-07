#include <stdio.h>

void printFun(int test) {
    if (test < 1)
        return;
    else {
        printf("%d", test); // corrected quote
        printFun(test - 1); // statement 2
        printf("%d", test); // corrected quote
        return;
    }
}

int main() {
    int test = 3;
    printFun(test);
    return 0;
}
