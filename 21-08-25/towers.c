#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    char from, to, aux;
    int state;
} Frame;

typedef struct {
    Frame arr[100];
    int top;
} Stack;

void push(Stack* s, Frame f) {
    s->arr[++s->top] = f;
}

Frame pop(Stack* s) {
    return s->arr[s->top--];
}

int empty(Stack* s) {
    return s->top == -1;
}

int main() {
    int n = 3;
    Stack s;
    s.top = -1;

    Frame f = {n, 'A', 'C', 'B', 0};
    push(&s, f);

    while (!empty(&s)) {
        f = pop(&s);

        if (f.n == 0) continue;

        if (f.state == 0) {
            f.state = 1;
            push(&s, f); 
            Frame newF = {f.n - 1, f.from, f.aux, f.to, 0};
            push(&s, newF);
        } else if (f.state == 1) {
            printf("Move disk %d from %c to %c\n", f.n, f.from, f.to);

            f.state = 2;
            push(&s, f);
            Frame newF = {f.n - 1, f.aux, f.to, f.from, 0};
            push(&s, newF);
        }
    }

    return 0;
}
