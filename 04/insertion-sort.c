/**
 * Anton Charapov COSC 242
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 30000
/**Insertion sort takes an array and its size
 * and creates a key that goes through the whole array
 * until it finds an array with a value bigger than key
 * and puts it at the beginning.
 */
void insertion_sort(int *a, int n){
    int i, j, key;
    for(i = 1; i<n; i++){
        key = a[i];
        j = i - 1;
        while(j>=0 && key < a[j]){
            a[j+1] = a[j];
            j = j -1;
        }
        a[j+1] = key;
    }   
}
/**Creates an array of size count, inputting data from a file.
 * Calls insertion sort and prints out a sorted array.
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
    insertion_sort(my_array, count);
    end = clock();
    
    for(i = 0; i < count; i++) {
        printf("%d\n", my_array[i]);
    }
    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
