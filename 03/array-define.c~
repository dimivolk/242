#include <stdio.h>
#include <stdlib.h>

void display_repeats(int *a, int size){
    int i, j, n;
    int array[size];

    for(i = 1; i < size; i++){
        for(j = 1; j < size-1; j++){
            if(a[i] == a[j]){
                array[i] += 1;
                
            }
        }
        array[i] = n;
        
    }
    printf("%d", array[0]);
    
}

int main(void) {
    int array_size = 0;
    int *my_dynamic_array;
    int i = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &array_size);

    /*initialise the array to the appropriate size */
    my_dynamic_array = malloc(array_size * sizeof my_dynamic_array[0]);
    if (NULL == my_dynamic_array) {
        fprintf(stderr, "memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    for (i=0; i< array_size; i++){
        my_dynamic_array[i] = rand() % array_size;
    }
    printf("What's in the array:\n");
    for (i = 0; i < array_size; i++) {
        printf("%d ", my_dynamic_array[i]);
    }
    printf("\n");
    display_repeats(my_dynamic_array, array_size);

    /* release the memory asociated with the array */
    free(my_dynamic_array);

    return EXIT_SUCCESS;

}
