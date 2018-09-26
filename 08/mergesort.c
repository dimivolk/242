#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 100000

void merge(int *array, int *workspace, int len) {
    int i, j, mid, pos;
    i = 0;
    mid = len / 2;
    j = mid;
    pos = 0;
    while(i < mid && j < len) {
        if(array[i] < array[j]) {
            workspace[pos++] = array[i++];
        }else{
            workspace[pos++] = array[j++];
        }
    }

    while(i < mid) {
        workspace[pos++] = array[i++];
    }
    while(j < len) {
        workspace[pos++] = array[j++];
    }
}

void merge_sort(int *a, int *w, int n) {
    int i = 0;
    if(n < 2) {
        return;
    }
    merge_sort(a, w, (n/2));
    merge_sort((a+(n/2)), w,(n-(n/2)));

    merge(a, w, n);

    for(i = 0; i < n; i++) {
        a[i] = w[i];
    }
    
}


            
int main(void) {
    int my_array[ARRAY_MAX], workspace[ARRAY_MAX];
    clock_t start, end;
    int i, count = 0;
    while (count < ARRAY_MAX && 1 == scanf("%d", &my_array[count])) {
        count++;
    }

    start = clock();
    merge_sort(my_array, workspace, count);
    end = clock();

    for (i = 0; i < count; i++) {
        printf("%d\n", my_array[i]);
    }

    fprintf(stderr, "%d %f\n", count, (end - start) / (double)CLOCKS_PER_SEC);

    return EXIT_SUCCESS;
}
