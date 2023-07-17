#include <stdio.h>
#include <stdlib.h>

// Enum to identify the type of operation or function to be performed
typedef enum TypeTag {
    VALUE, ADD, MUL, SUB, FIB
} TypeTag;

// Node structure to hold the operation type, value, and pointers to child nodes
typedef struct Node {
    TypeTag type;
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* makeNode(TypeTag type, int value, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}

// Dynamic Programming approach to calculate Fibonacci sequence
int fibonacci(int n) {
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

// Function to perform the calculation based on the operation type of the node
int calc(Node* node) {
    switch(node->type) {
        case VALUE:
            // Value type node, return the value directly
            return node->value;
        case ADD:
            // Addition operation
            return calc(node->left) + calc(node->right);
        case MUL:
            // Multiplication operation
            return calc(node->left) * calc(node->right);
        case SUB:
            // Subtraction operation
            return calc(node->left) - calc(node->right);
        case FIB:
            // Fibonacci sequence
            return fibonacci(node->value);
        default:
            return 0;
    }
}

int main() {
    // Create 'add' node to perform addition of 10 and 6
    Node* add = makeNode(ADD, 0, makeNode(VALUE, 10, NULL, NULL), makeNode(VALUE, 6, NULL, NULL));
    // Create 'mul' node to perform multiplication of 5 and 4
    Node* mul = makeNode(MUL, 0, makeNode(VALUE, 5, NULL, NULL), makeNode(VALUE, 4, NULL, NULL));
    // Create 'sub' node to subtract the result of 'mul' from 'add'
    Node* sub = makeNode(SUB, 0, add, mul);
    // Create 'fibo' node to get the 4th Fibonacci number
    Node* fibo = makeNode(FIB, SUB, NULL, NULL);
    
    // Print the results of the calculations
    printf("add : %d\n", calc(add));
    printf("mul : %d\n", calc(mul));
    printf("sub : %d\n", calc(sub));
    printf("fibo : %d\n", calc(fibo));

    /**
     * Expected Output:
     * add: 16
     * mul: 20
     * sub: -4 
     * fibo: 2
    */

    return 0;
}
