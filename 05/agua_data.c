#include <stdio.h>
#include <stdlib.h>

#define OCEAN_MAX 41981

struct ocean_datum {
    int x;       /* grid-reference east-west                             */   
    int y;       /* grid-refernce north-south                            */
    double conc; /* concentration of O_2 in mL/L found at grid-ref (x,y) */
};

void print_ocean_datum(struct ocean_datum *o) {
    printf("%d %d %.4f\n", o->x, o->y, o->conc);
}

int read_ocean_datum(struct ocean_datum *o) {
    return 3 == scanf("%d %d %lg", &o->x, &o->y, &o->conc);
}

int compare_ocean_oxy(struct ocean_datum *s, struct ocean_datum *t) {
    
    if(s->conc < t->conc) {
        return -1;
    }else if(s->conc > t->conc) {
        return 1;
    }else{
        return 0;
    }  
}

void selection_sort(struct ocean_datum *a, int n){
    int  i, j;
    int min;
    struct ocean_datum temp;
    
    for(i = 0; i < n; i++) {

        min = i;
        
        for(j = i+1; j < n; j++) {
            if(compare_ocean_oxy(&a[j],&a[min]) < 0) {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main(void) {
    struct ocean_datum ocean_data[OCEAN_MAX];
    int num_items;
    int i;

    num_items = 0;
    while (num_items < OCEAN_MAX && read_ocean_datum(&ocean_data[num_items])) {
        num_items++;
    }

    /*sort the data here*/
    selection_sort(ocean_data, num_items);

    /*print out the array of structs*/
    for(i = 0; i < num_items; i++) {
        print_ocean_datum(&ocean_data[i]);
    }

    return EXIT_SUCCESS;
}
