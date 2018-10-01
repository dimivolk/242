/**
 * Functions defined for allocating memory and getting words from a file.
 *
 * @author Anton Charapov, Tiaan Stevenson-Brunt, Joe Madsen.
 */
#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
/**
 * Allocates size bytes of memory.
 * @param s the amount of memory that needs to be allocated.
 */
void *emalloc(size_t s) {
    void *result = malloc(s);
    if(NULL == result) {
        fprintf(stderr, "memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}
/**
 * A function that gets words from a file.
 * @param s the word that gets read.
 * @param limit the amount of words we need to read in.
 * @param stream the file we are going to read the words from.
 */
int getword(char *s, int limit, FILE *stream) {
    int c;
    char *w = s;
    assert(limit > 0 && s != NULL && stream != NULL);
    /* skip to the start of the word */
    while (!isalnum(c = getc(stream)) && EOF != c)
        ;
    if (EOF == c) {
        return EOF;
    } else if (--limit > 0) { /* reduce limit by 1 to allow for the \0 */
        *w++ = tolower(c);
    }
    while (--limit > 0) {
        if (isalnum(c = getc(stream))) {
            *w++ = tolower(c);
        } else if ('\'' == c) {
            limit++;
        } else {
            break;
        }
    }
    *w = '\0';
    return w - s;
}
