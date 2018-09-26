#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n;
    double a, b, c;
    double next;
    double prev = 0.0;
    int winner;

    while(4 ==  scanf("%d%lg%lg%lg", &n, &a, &b, &c)){
        next = (a+b+c)/3;
        if(next>prev){
            prev = next;
            winner = n;
        }
        
    }
    printf("%d\n", winner);
    
    return EXIT_SUCCESS;
}
