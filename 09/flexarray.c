#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"
#include "flexarray.h"

struct flexarrayrec {
    int capacity;
    int itemcount;
    int *items;
};

flexarray flexarray_new() {
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}

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

static void merge_sort(int *a, int *w, int n) {
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


void flexarray_append(flexarray f, int num) {
    if(f->itemcount == f->capacity) {
        f-> capacity += f->capacity;
        f->items = erealloc(f->items, f->capacity * sizeof f->items[0]);
    }
    f->items[f->itemcount++] = num;
}

void flexarray_print(flexarray f) {
    int i;

    for(i = 0; i < f->itemcount; i++) {
        printf("%d\n", f->items[i]); //print each item
    }
}

void flexarray_sort(flexarray f) {
    
    int *w = emalloc(f->itemcount * sizeof f->items[0]);
    merge_sort(f->items, w, f->itemcount);                
    free(w);
}
void flexarray_free(flexarray f) {
    free(f->items);
    free(f);

}
