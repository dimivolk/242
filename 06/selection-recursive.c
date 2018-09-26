/**
 * Anton Charapov COSC 242
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 3000

void selection_sort(int *a, int n){
    int  i, j;
    int min;
    int temp;
    
    for(i = 0; i < n; i++) {

        min = i;
        
        for(j = i+1; j < n; j++) {
            if(a[j] < a[min]) {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void print_array(int*a, int n) {
    if(n > 0) {
        printf("%d\n", a[0]);
        print_array(a + 1, n - 1);
    }
}
/**Creates an array of size count, inputting data from a file.
 * Calls selection sort and prints out a sorted array.
 * Checks time efficiency.
 */
int main(void) {
    int my_array[ARRAY_MAX];
    clock_t start, end;
    int count = 0;

    while(count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }

    start = clock();
    selection_sort(my_array, count);
    end = clock();

    print_array(my_array, count);
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
