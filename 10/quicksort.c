#include <stdio.h>
#include <stdlib.h>

public void quicksort( int *a, int n) {
    if(n < 2) {
        return;
    }
    int pivot = a[0];
    int i  = -1;
    int j = n + 1;

    for(;;) {
        do{
            i++;
        }while(a[i] < pivot);
        do{
            j--;
        } while(a[j] > pivot);
        if(i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }else{
            break;
        }
    }
    quick_sort(a, j+1);
    quick_sort(j+1, n-j-1);
}
        
