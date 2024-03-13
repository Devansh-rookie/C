#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int exp;
    int coeff;
    struct Node *next;
} Node;

Node *first = NULL;
Node *second = NULL;
Node *result = NULL;
Node *lastf = NULL;
Node *lasts = NULL;
Node *lastr = NULL;

void insert_last(Node **head, Node **last, int coeff, int exp) {
    Node *t = (Node*)malloc(sizeof(Node));
    t->coeff = coeff;
    t->exp = exp;
    t->next = NULL;

    if (*head == NULL) {
        *head = *last = t;
    } else {
        (*last)->next = t;
        *last = t;
    }
}

void addition(Node *p, Node *q, Node *r) {
    while (p != NULL) {
        int found = 0;
        Node *t = q;
        while (t != NULL) {
            if (p->exp == t->exp) {
                insert_last(&r, &lastr, p->coeff + t->coeff, p->exp);
                found = 1;
                break;
            }
            t = t->next;
        }
        if (!found)
            insert_last(&r, &lastr, p->coeff, p->exp);
        p = p->next;
    }

    while (q != NULL) {
        insert_last(&r, &lastr, q->coeff, q->exp);
        q = q->next;
    }
}

void display(Node *p) {
    while (p != NULL) {
        printf("(%d)x^%d", p->coeff, p->exp);
        if (p->next != NULL)
            printf(" + ");
        p = p->next;
    }
    printf("\n");
}

int main() {
    insert_last(&first, &lastf, 10, 0);
    insert_last(&first, &lastf, 10, 1);
    insert_last(&first, &lastf, 10, 2);
    insert_last(&first, &lastf, 10, 3);

    insert_last(&second, &lasts, 5, 0);
    insert_last(&second, &lasts, 5, 1);
    insert_last(&second, &lasts, 5, 2);
    insert_last(&second, &lasts, 5, 3);

    printf("First polynomial: ");
    display(first);

    printf("Second polynomial: ");
    display(second);

    addition(first, second, result);

    printf("Resultant polynomial: ");
    display(result);

    return 0;
}
