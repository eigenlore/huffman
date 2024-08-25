#ifndef HUFFMAN_H
#define HUFFMAN_H

#define EPS 0.00001

typedef struct node Node;
struct node
{

    double prob;
    Node *branch;
    char *codeword;
};

int total_symbols(int q, int r);
void sweep(Node *start, Node *dest, int size, int r);
void encode(Node **tree, int r, int steps);

#endif