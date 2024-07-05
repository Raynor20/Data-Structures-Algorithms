#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Binary Tree.h"

void addNode(NodePtr *root, Product item) {
    NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
    newNode->item = item;
    newNode->left = newNode->right = NULL;

    if (*root == NULL) {
        *root = newNode;
    } else {
        NodePtr current = *root;
        NodePtr parent;

        while (1) {
            parent = current;
            if (strcmp(item.prodName, current->item.prodName) < 0) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    break;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    break;
                }
            }
        }
    }
}

void deleteNode(NodePtr *root, char *prodName) {
    NodePtr current = *root;
    NodePtr parent = NULL;

    while (current != NULL && strcmp(current->item.prodName, prodName) != 0) {
        parent = current;
        if (strcmp(prodName, current->item.prodName) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == NULL) {
        printf("Product not found\n");
        return;
    }

    if (current->left == NULL && current->right == NULL) {
        if (parent == NULL) {
            *root = NULL;
        } else if (parent->left == current) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(current);
    } else if (current->left == NULL) {
        if (parent == NULL) {
            *root = current->right;
        } else if (parent->left == current) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
        free(current);
    } else if (current->right == NULL) {
        if (parent == NULL) {
            *root = current->left;
        } else if (parent->left == current) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
        free(current);
    } else {
        NodePtr minParent = current;
        NodePtr minNode = current->right;

        while (minNode->left != NULL) {
            minParent = minNode;
            minNode = minNode->left;
        }

        current->item = minNode->item;
        if (minParent->left == minNode) {
            minParent->left = NULL;
        } else {
            minParent->right = NULL;
        }
        free(minNode);
    }
}

void dfsPreorderTraversal(NodePtr root) {
    if (root == NULL) {
        return;
    }

    printf("Product Name: %s, Price: %.2f, Quantity: %d, Expiration Date: %d-%d-%d\n",
           root->item.prodName, root->item.prodPrice, root->item.prodQty,
           root->item.expDate.day, root->item.expDate.month, root->item.expDate.year);

    dfsPreorderTraversal(root->left);
    dfsPreorderTraversal(root->right);
}

void dfsInorderTraversal(NodePtr root) {
    if (root == NULL) {
        return;
    }

    dfsInorderTraversal(root->left);

    printf("Product Name: %s, Price: %.2f, Quantity: %d, Expiration Date: %d-%d-%d\n",
           root->item.prodName, root->item.prodPrice, root->item.prodQty,
           root->item.expDate.day, root->item.expDate.month, root->item.expDate.year);

    dfsInorderTraversal(root->right);
}

void dfsPostorderTraversal(NodePtr root) {
    if (root == NULL) {
        return;
    }

    dfsPostorderTraversal(root->left);
    dfsPostorderTraversal(root->right);

    printf("Product Name: %s, Price: %.2f, Quantity: %d, Expiration Date: %d-%d-%d\n",
           root->item.prodName, root->item.prodPrice, root->item.prodQty,
           root->item.expDate.day, root->item.expDate.month, root->item.expDate.year);
}

void bfsTraversal(NodePtr root) {
    if (root == NULL) {
        return;
    }

    NodePtr queue[100];
    int front = 0, rear = 0;
    NodePtr current;

    queue[rear++] = root;

    while (front < rear) {
        current = queue[front++];
        printf("Product Name: %s, Price: %.2f, Quantity: %d, Expiration Date: %d-%d-%d\n",
               current->item.prodName, current->item.prodPrice, current->item.prodQty,
               current->item.expDate.day, current->item.expDate.month, current->item.expDate.year);
        if (current->left!= NULL) {
            queue[rear++] = current->left;
        }
        if (current->right!= NULL) {
            queue[rear++] = current->right;
        }
    }
}

