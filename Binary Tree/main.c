#include <stdio.h>
#include "Binary Tree.h"

int main() {
    NodePtr root = NULL;

    Product item1 = {"Mouse", 20.0, 10, {15, 12, 2022}};
    Product item2 = {"Keyboard", 30.0, 20, {20, 1, 2023}};
    Product item3 = {"Monitor", 100.0, 5, {1, 2, 2024}};
    Product item4 = {"CPU", 500.0, 3, {15, 3, 2025}};
    Product item5 = {"RAM", 50.0, 10, {20, 4, 2026}};
    Product item6 = {"Headset", 15.0, 30, {24, 8, 2024}};

    addNode(&root, item1);
    addNode(&root, item2);
    addNode(&root, item3);
    addNode(&root, item4);
    addNode(&root, item5);
    addNode(&root, item6);

    printf("DFS Preorder Traversal:\n");
    dfsPreorderTraversal(root);

    printf("\nDFS Inorder Traversal:\n");
    dfsInorderTraversal(root);

    printf("\nDFS Postorder Traversal:\n");
    dfsPostorderTraversal(root);

    printf("\nBFS Traversal:\n");
    bfsTraversal(root);

    deleteNode(&root, "Keyboard");

    printf("\nAfter deleting 'Keyboard':\n");
    dfsPreorderTraversal(root);

    return 0;
}
