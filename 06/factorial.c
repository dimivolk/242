#include <stdio.h>
#include <stdlib.h>

int factorial(int num) {
    int result;
    
    if(num == 0){
        return 1;
    }else{
        result = num * factorial(num-1);
    }
    
    return result;
    
}

int main() {
    int num;

    while(1 == scanf("%d", &num)) {
        printf("%d\n", factorial(num));
    }

    return EXIT_SUCCESS;
}

    
