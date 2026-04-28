#include <stdio.h>
#include <stdlib.h>

// Queue implementation (array-based)
#define MAX 100

struct Queue {
    int arr[MAX];
    int front, rear;
};

// Stack implementation
struct Stack {
    int arr[MAX];
    int top;
};

// Queue functions
void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isQueueEmpty(struct Queue* q) {
    return q->rear < q->front;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) return;
    q->arr[++q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isQueueEmpty(q)) return -1;
    return q->arr[q->front++];
}

// Stack functions
void initStack(struct Stack* s) {
    s->top = -1;
}

int isStackEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int value) {
    if (s->top == MAX - 1) return;
    s->arr[++s->top] = value;
}

int pop(struct Stack* s) {
    if (isStackEmpty(s)) return -1;
    return s->arr[s->top--];
}

// Function to reverse queue
void reverseQueue(struct Queue* q) {
    struct Stack s;
    initStack(&s);

    // Step 1: Dequeue and push into stack
    while (!isQueueEmpty(q)) {
        push(&s, dequeue(q));
    }

    // Step 2: Pop from stack and enqueue back
    while (!isStackEmpty(&s)) {
        enqueue(q, pop(&s));
    }
}

// Display queue
void display(struct Queue* q) {
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);

    printf("Original Queue: ");
    display(&q);

    reverseQueue(&q);

    printf("Reversed Queue: ");
    display(&q);

    return 0;
}