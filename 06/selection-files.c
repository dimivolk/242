/**
 * Anton Charapov COSC 242
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 3000

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

int intsearch(int *a, int x, int low, int high) {
    if(low > high){
        return 0;
    }else{
        int m = (low+high)/2;
        if(x == a[m]) {
            return x;
        }else if(x < a[m]) {
            return intsearch(a, x, low, m-1);
        }else {
            return intsearch(a, x, m+1, high);
        }
    }
}
        
    
  
/**Creates an array of size count, inputting data from a file.
 * Calls selection sort and prints out a sorted array.
 * Checks time efficiency.
 */
int main(int argc, char **argv) {
    FILE *infile;
    int my_array[ARRAY_SIZE];
    
    clock_t start, end;
    int num_items, x;

    
    if(NULL == (infile = fopen(argv[1], "r"))) {
        fprintf(stderr, "%s: can't find file %s\n", argv[0], argv[1]);
        return EXIT_FAILURE;
    }

    num_items = 0;
    while(num_items < ARRAY_SIZE &&
          1 == fscanf(infile, "%d", &my_array[num_items])) {
        num_items++;
    }


    start = clock();
    selection_sort(my_array, num_items);

    while(1 == scanf("%d", &x)) {
        if(x ==  intsearch(my_array, x, 0, num_items-1)){
            printf("%c\n", '+');
        }else {
            printf("%c\n", '-');
        }  
    }

    end = clock();

    fclose(infile);

    
    fprintf(stderr, "%d %f\n", num_items, (end - start) / (double)CLOCKS_PER_SEC);
    return EXIT_SUCCESS;
}
