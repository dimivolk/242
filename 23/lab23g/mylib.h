/**
 * H file for emalloc and getword.
 * @author Anton Charapov, Tiaan Stevenson-Brunt, Joe Madsen.
 */
#ifndef MYLIB_H_
#define MYLIB_H_

#include <stddef.h>
#include <assert.h>
#include <ctype.h>
#include <stdio.h>

extern void *emalloc(size_t);
extern int  getword(char *s, int limit, FILE *stream);

#endif
