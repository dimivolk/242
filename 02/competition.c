#include <stdio.h>
#include <stdlib.h>

int main(void){
    double s1, s2, s3;

    printf("Input first score: ");
    scanf("%lg", &s1);
    printf("Input 2nd score: ");
    scanf("%lg", &s2);
    printf("Input 3rd score: ");
    scanf("%lg", &s3);

    if(s1<s2 && s1<s3){
        printf("%f\n", (s2+s3)/2);
    }else if(s2<s1 && s2<s3){
        printf("%f\n", (s1+s3)/2);
    }else{
        printf("%f\n", (s1+s2)/2);
    }
    return EXIT_SUCCESS;
}

    
