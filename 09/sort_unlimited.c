#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"

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

static void array_print(int *a, int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}

int main(void) {
    int capacity = 2;
    int itemcount = 0;
    int item;
    int *my_array = malloc(capacity * sizeof my_array[0]);

    while (1 == scanf("%d", &item)) {
        if (itemcount == capacity) {
            capacity += capacity;
            my_array = realloc(my_array, capacity * sizeof my_array[0]);   
        }
        my_array[itemcount++] = item;
    }
    selection_sort(my_array, itemcount);
    array_print(my_array, itemcount);
    free(my_array);

    return EXIT_SUCCESS;
}
