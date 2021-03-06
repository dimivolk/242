/**
 * Anton Charapov COSC 242
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


#define STRING_LEN 80
#define ARRAY_LEN 10000

void *emalloc(size_t s) {
    void *result = malloc(s);
    if(NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}
/**Selection sort takes an array and its size
 * and compares the first element with the subsequent smallest element
 * and swaps them until the array is sorted.
 */
void selection_sort(char **a, int n){
    int  i, j;
    int min;
    char *temp;
    
    for(i = 0; i < n; i++) {

        min = i;
        
        for(j = i+1; j < n; j++) {
            if(strcasecmp(a[j], a[min]) < 0) {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
/**Creates an array of size count, inputting data from a file.


  Calls selection sort and prints out a sorted array.
 * Checks time efficiency.
 */
int main(void) {
    char word[STRING_LEN];
    char *wordlist[ARRAY_LEN];
    int num_words;
    int i;

    num_words = 0;
    while (num_words < ARRAY_LEN && 1 == scanf("%79s", word)) {
        wordlist[num_words] = emalloc((strlen(word) + 1) * sizeof wordlist[0][0]);
        strcpy(wordlist[num_words], word);
        num_words++;
    }
    selection_sort(wordlist, num_words);

    for(i = 0; i < num_words; i++) {
        printf("%s\n", wordlist[i]);
    }

    for(i = 0; i < num_words; i++) {
        free(wordlist[i]);
    }
    return EXIT_SUCCESS;
}
