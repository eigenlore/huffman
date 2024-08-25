#define MAIN_PROGRAM
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include "huffman.h"

int main()
{
    int q, Q, r, i, steps;
    Node **tree;

    printf("Enter the number of symbols: ");
    assert(scanf("%d", &q) > 0);
    printf("Enter the alphabet size: ");
    assert(scanf("%d", &r) > 0);

    /*Calculate the total number of symbols and
    the number of columns required for the algorithm*/
    Q = total_symbols(q, r);
    steps = (Q - 1) / (r - 1);

    /*Allocate memory for the tree*/
    tree = malloc(steps * sizeof(Node *));
    for (i = 0; i < steps; i++)
        tree[i] = malloc((Q - i * (r - 1)) * sizeof(Node));

    /*Initialize the initial probabilities*/
    printf("Enter the probabilities: \n");

    for (i = 0; i < q; i++)
    {
        printf("The probability of s%d is: ", i);
        assert(scanf("%lf", &(tree[0][i].prob)) > 0);
    }

    for (i = q; i < Q; i++)
        tree[0][i].prob = 0;

    /*Create the entire tree by iterating the sweep function*/
    for (i = 0; i < steps - 1; i++)
        sweep(tree[i], tree[i + 1], Q - i * (r - 1), r);

    /*Generate codewords using encode*/
    encode(tree, r, steps);

    /*Print the codewords to the screen*/
    for (i = 0; i < q; i++)
        printf("The codeword of s%d is %s\n", i + 1, tree[0][i].codeword);

    return 0;
}
