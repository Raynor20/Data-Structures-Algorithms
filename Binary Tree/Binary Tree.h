#ifndef TREES
#define TREES

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char prodName[20];
    float prodPrice;
    int prodQty;
    Date expDate;
} Product;

typedef struct node {
    Product item;
    struct node *left, *right;
} NodeType, *NodePtr;

void addNode(NodePtr *root, Product item);
void deleteNode(NodePtr *root, char *prodName);
void dfsPreorderTraversal(NodePtr root);
void dfsInorderTraversal(NodePtr root);
void dfsPostorderTraversal(NodePtr root);
void bfsTraversal(NodePtr root);

#endif
