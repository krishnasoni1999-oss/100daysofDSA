#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Pair structure
struct pair {
    int num;
    int freq;
};

// Min Heap
struct pair heap[MAX];
int size = 0;

// Swap
void swap(struct pair *a, struct pair *b) {
    struct pair temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up
void heapifyUp(int i) {
    while (i > 0 && heap[(i-1)/2].freq > heap[i].freq) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Heapify Down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left].freq < heap[smallest].freq)
        smallest = left;

    if (right < size && heap[right].freq < heap[smallest].freq)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert into heap
void insert(struct pair p) {
    heap[size] = p;
    heapifyUp(size);
    size++;
}

// Remove min
void removeMin() {
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}
int* topKFrequent(int nums[], int n, int k, int* returnSize) {
    static int result[100];

    int freq[1000] = {0};

    // Count frequency
    for (int i = 0; i < n; i++)
        freq[nums[i]]++;

    // Build heap
    for (int i = 0; i < 1000; i++) {
        if (freq[i] > 0) {
            struct pair p = {i, freq[i]};
            insert(p);

            if (size > k)
                removeMin();
        }
    }

    // Extract result
    *returnSize = size;
    for (int i = 0; i < size; i++)
        result[i] = heap[i].num;

    return result;
}