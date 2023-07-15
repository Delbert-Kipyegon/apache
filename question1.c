#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag
{
    ADD,
    MUL,
    SUB,
    DIV,
    FIBO
} TypeTag;

typedef struct Node
{
    TypeTag type;
    int val;
    struct Node *left;
    struct Node *right;
} Node;

Node *makeFunc(TypeTag type, Node *left, int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->type = type;
    node->val = val;
    node->left = left;
    node->right = NULL;
    return node;
}

Node *makeFuncWithNodes(TypeTag type, Node *left, Node *right)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->type = type;
    node->left = left;
    node->right = right;
    return node;
}

int fibo(int n)
{
    int a = 0, b = 1, c, i;
    if (n == 0)
        return a;
    for (i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int calc(Node *node)
{
    switch (node->type)
    {
    case ADD:
        return (node->right == NULL) ? node->left->val + node->val : node->left->val + node->right->val;
    case MUL:
        return (node->right == NULL) ? node->left->val * node->val : node->left->val * node->right->val;
    case SUB:
        return (node->right == NULL) ? node->left->val - node->val : node->left->val - node->right->val;
    case DIV:
        if ((node->right == NULL && node->val != 0) || (node->right != NULL && node->right->val != 0))
            return (node->right == NULL) ? node->left->val / node->val : node->left->val / node->right->val;
        else
            return 0; // In case of division by zero, returns 0. You might want to add some error handling here.
    case FIBO:
        return fibo(node->left->val);
    default:
        return 0; // In case of invalid operation, returns 0. You might want to add some error handling here.
    }
}

int main()
{
    Node *add = makeFunc(ADD, makeFunc(ADD, NULL, 10), 6);
    Node *mul = makeFunc(MUL, makeFunc(MUL, NULL, 5), 4);
    Node *sub = makeFuncWithNodes(SUB, mul, add);
    Node *fibo = makeFunc(FIBO, sub, 0);

    printf("add : %d\n", calc(add));
    printf("mul : %d\n", calc(mul));
    printf("sub : %d\n", calc(sub));
    printf("fibo : %d\n", calc(fibo));

    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}
