#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include "huffman.h"

/*Find Q such that Q is congruent to 1 mod r-1*/
int total_symbols(int q, int r)
{
    int Q;

    for (Q = q; Q < q + r; Q++)
        if ((Q - 1) % (r - 1) == 0)
            return Q;

    return -1;
}

void sweep(Node *start, Node *dest, int size, int r)
{

    int i, j;
    double sum = 0, temp;

    /*Copy the first values and assign pointers*/
    for (i = 0; i < size - r; i++)
    {
        dest[i].prob = start[i].prob;
        start[i].branch = &dest[i];
    }

    /*Collapse the last r values and assign pointers*/
    for (i = size - r; i < size; i++)
    {
        sum += start[i].prob;
        start[i].branch = &dest[size - r];
    }
    dest[size - r].prob = sum;

    /*Reorder the probabilities of the second column as required
    by the algorithm. If the upper value is strictly smaller, perform
    a switch, making sure to properly reassign the pointers*/
    for (i = size - r; i > 0; i--)
    {

        if (dest[i - 1].prob - dest[i].prob < EPS)
        {
            temp = dest[i].prob;
            dest[i].prob = dest[i - 1].prob;
            dest[i - 1].prob = temp;
            start[i - 1].branch = &dest[i];
            for (j = size - r; j < size; j++)
                start[j].branch = &dest[i - 1];
        }

        else
            break;
    }
}

void encode(Node **tree, int r, int steps)
{
    int i, j;
    char temp[11];

    /*Assign codewords in the last column with values from 0 to r-1*/
    for (i = 0; i < r; i++)
    {
        tree[steps - 1][i].codeword = malloc(11 * sizeof(char));
        sprintf(tree[steps - 1][i].codeword, "%d", i);
    }

    /*Traverse the tree backward to the first column*/
    for (i = 1; i < steps; i++)
    {

        /*For the first values, copy the codeword of the pointed node*/
        for (j = 0; j < i * (r - 1); j++)
        {
            tree[steps - i - 1][j].codeword = malloc((i + 1) * sizeof(char));
            strcat(tree[steps - i - 1][j].codeword, tree[steps - i - 1][j].branch->codeword);
        }

        /*For the last r values, copy the pointed codeword,
        then add a new digit from 0 to r-1 at the end*/
        for (j = i * (r - 1); j < r + i * (r - 1); j++)
        {
            tree[steps - i - 1][j].codeword = malloc((i + 1) * sizeof(char));
            strcat(tree[steps - i - 1][j].codeword, tree[steps - i - 1][j].branch->codeword);
            sprintf(temp, "%d", j - i * (r - 1));
            strcat(tree[steps - i - 1][j].codeword, temp);
        }
    }
}