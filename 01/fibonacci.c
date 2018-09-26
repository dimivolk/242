#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    /*variable declarations*/
    int f = 0;
    int g = 1;
    
    /*maintenance variables*/
    int j = 0;
    int i = 0;
    int counter = 5;

    /*a familiar "for loop"*/
    for(i = 0; i<40; i++){
        printf("%d, ", g);
        j = g;
        g += f;
        f = j;
        if(i == counter){
            printf("\n");
            counter += 5;
        }
    }

    return EXIT_SUCCESS;/*defined in stdlib.h*/
}
