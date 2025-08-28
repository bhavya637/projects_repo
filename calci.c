#include<stdio.h>
int main(){
    int a,b,n;
    printf("Enter value of a: ");
    scanf("%d",&a);

    printf("Enter value of b: ");
    scanf("%d",&b);

    printf("Enter value of n: ");
    scanf("%d",&n);


    switch(n){
        case 1:
            printf("Sum: %d",a+b);
            break;
        case 2:
            printf("Sub: %d",a-b);
            break;
        case 3:
            printf("Mul: %d",a*b);
            break;
        case 4:
            printf("Div: %d",a/b);
            break;
    }

    return 0;
}