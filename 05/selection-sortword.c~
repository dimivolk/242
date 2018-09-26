/**
 * Anton Charapov COSC 242
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000
/**Selection sort takes an array and its size
 * and compares the first element with the subsequent smallest element
 * and swaps them until the array is sorted.
 */
void selection_sort(int *a, int n){
    int temp, i, j;
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(a[i]>a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
/**Creates an array of size count, inputting data from a file.
 * Calls selection sort and prints out a sorted array.
 * Checks time efficiency.
 */
int main(void) {
    int my_array[ARRAY_MAX];
    clock_t start, end;
    int i, count = 0;

    while(count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }

    start = clock();
    selection_sort(my_array, count);
    end = clock();
    
    for(i = 0; i < count; i++) {
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
