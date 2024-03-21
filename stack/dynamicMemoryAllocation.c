#include<stdio.h>
#include<stdlib.h>
int main(){
    int *m_ptr = (int*)malloc(5*sizeof(int));   //malloc default value = random;
    int *c_ptr = (int*)calloc(6,sizeof(int));   //calloc default value = 0;
    int sum=0;

    for(int i = 0; i<5; i++){
        c_ptr = m_ptr+i;    // storing address in another ptr variable
        scanf("%d",c_ptr);
            //(or) scanf("%d",(m_ptr+i));
        sum=sum+(*(m_ptr+i));
    }

    printf("\nsum = %d\n",sum);

    c_ptr = m_ptr;    // re-initialize to point to array starting
    for(int i = 0; i<5; i++){
        printf("%d\t",*(c_ptr+i));
        
    }  
    
    c_ptr = realloc(c_ptr,7*sizeof(int)); 
    printf("\nrealloc : \n"); 
    for(int i = 0; i<7; i++){
        printf("%d\t",*(c_ptr+i));
                    //   printf("%d\t",*(m_ptr+i));
    }                

    free(c_ptr);
    free(m_ptr);

    return 0;
}