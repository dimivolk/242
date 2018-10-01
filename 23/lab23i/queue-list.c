#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"

typedef struct q_item *q_item;

struct q_item {
    double item;
    q_item next;
};

struct queue {
    q_item first;
    q_item last;
    int length;
};

queue queue_new() {
    queue result;

    result = emalloc(sizeof *result);

    result->length = 0;
    result->first = NULL;
    result->last = result->first;

    return result;
}

void enqueue(queue q, double item) {
    q_item i = emalloc(sizeof *i);
    i->item = item;
    i->next = NULL;
    if (q->length == 0) {
        q->first = i;
    } else {
        q->last->next = i;
    }
    q->last = i;
    q->length++;
}

double dequeue(queue q) {
    double item;
    q_item temp;

    if(q->length > 0) {
        item = q->first->item;
        temp = q->first;
        q->first = temp->next;
        q->length--;
        if (q->length == 0) {
            q->last = NULL;
        }
        free(temp);
        return item;
    }else{
        printf("Queue is empty\n");
        return 0;
    }
}

void queue_print(queue q) {
    /* print queue contents one per line to 2 decimal places */
    q_item current = NULL;

    if (q->length > 0) {
        current = q->first;
        while (current->next != NULL) {
            printf("%.2f\n", current->item);
            current = current->next;
        }
        printf("%.2f\n", current->item);
    }
}

void queue_print_info(queue q) {
    if (q->length == 0) {
        printf("The queue is empty\n");
    } else {
        printf("first %.2f, last %.2f, length %d\n", q->first->item,
               q->last->item, q->length);
    }
}

int queue_size(queue q) {
    return q->length;
}

void queue_free_aux(q_item i) {
    free(i);
}

queue queue_free(queue q) {
    q_item current;
    q_item next;

    if (q->length > 0) {
        current = q->first;

        while (current->next != NULL) {
            next = current->next;
            queue_free_aux(current);
            current = next;
        }
        queue_free_aux(current);
    }
    free(q);
    return q;
}
