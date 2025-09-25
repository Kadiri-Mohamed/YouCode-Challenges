#include<stdbool.h>
#include<stdio.h>
int main (){
    bool digit_seen[10]={false}; 
    
    int digit ;
    long n ;

printf("Entrer un nombre :");
scanf("%ld",&n);

while (n>0){
    digit =n % 10;
    if (digit_seen[digit])
    printf("%d ",digit);
    digit_seen[digit]=true;
    n/=10;
}

    return 0 ;
}