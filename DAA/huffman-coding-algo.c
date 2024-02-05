// huffman-coding-algo using greedy method and min heap implementation using array

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// a huffman tree node
struct MinHeapNode {
    char data; // one of the input characters
    unsigned freq; // frequency of the character
    struct MinHeapNode *left, *right; // left and right child of this node
};

void printArr(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

// utility function to check if this node is leaf
int isLeaf(struct MinHeapNode *root) {
    return !(root->left) && !(root->right);
}

// creates a min heap of capacity size
struct MinHeapNode **createMinHeap(int size) {
    struct MinHeapNode **minHeap = (struct MinHeapNode **) malloc(size * sizeof(struct MinHeapNode *));
    return minHeap;
}

// swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b) {
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

// min heapify
void minHeapify(struct MinHeapNode **minHeap, int idx, int size) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && minHeap[left]->freq < minHeap[smallest]->freq) {
        smallest = left;
    }

    if (right < size && minHeap[right]->freq < minHeap[smallest]->freq) {
        smallest = right;
    }

    if (smallest != idx) {
        swapMinHeapNode(&minHeap[smallest], &minHeap[idx]);
        minHeapify(minHeap, smallest, size);
    }
}

// a utility function to check if size of heap is 1 or not
int isSizeOne(int size) {
    return size == 1;
}

// a standard function to build min heap
void buildMinHeap(struct MinHeapNode **minHeap, int size) {
    int i;
    for (i = (size - 2) / 2; i >= 0; --i) {
        minHeapify(minHeap, i, size);
    }
}

// function to create a min heap of capacity equal to size and inserts all character of data[] in min heap.
struct MinHeapNode **createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeapNode **minHeap = createMinHeap(size);
    int i;
    for (i = 0; i < size; ++i) {
        minHeap[i] = newNode(data[i], freq[i]);
    }
    buildMinHeap(minHeap, size);
    return minHeap;
}

// the main function that builds Huffman tree
struct MinHeapNode *buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;

    // step 1: create a min heap of capacity equal to size. initially, there are modes equal to size
    struct MinHeapNode **minHeap = createAndBuildMinHeap(data, freq, size);

    // iterate while size of heap doesn't become 1
    while (!isSizeOne(size)) {
        // step 2: extract the two minimum freq items from min heap
        left = extractMin(minHeap, size--);
        right = extractMin(minHeap, size--);

        // step 3: create a new internal node with frequency equal to the sum of the two nodes frequencies. make the two extracted node as left and right children of this new node. add this node to the min heap
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, size++, top);
    }

    // step 4: the remaining node is the root node and the tree is complete
    return extractMin(minHeap, size);
}