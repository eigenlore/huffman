# Huffman Coding Implementation

This repository implements a r-ary Huffman coding algorithm in C, which is a lossless data compression algorithm. The program prompts the user to input the number of symbols and their respective probabilities, then generates the Huffman tree and calculates the corresponding Huffman codes.

### How It Works

The algorithm operates by building a tree with nodes organized in columns. Each node in the tree contains:

   - Probability: The probability of the corresponding symbol.
   - Pointer: A pointer to the node in the next column.
   - Codeword: The Huffman code generated for that symbol.

###   Usage

Compile the code using GCC with the `make` command and run with `./main`. Clean executables with `make clean`. Run the program and input the number of symbols and the alphabet size. Then, provide the probabilities for each symbol. The program will output the Huffman code for each symbol.

### Example
```
Enter the number of symbols: 4
Enter the alphabet size: 2
Enter the probabilities: 
The probability of s0 is: 0.4
The probability of s1 is: 0.3
The probability of s2 is: 0.2
The probability of s3 is: 0.1

The codeword of s1 is 1
The codeword of s2 is 01
The codeword of s3 is 000
The codeword of s4 is 001
```