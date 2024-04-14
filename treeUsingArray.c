#include <stdio.h>
#include <stdlib.h>

#define SIZE 100


struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* buildTreeFromArray(int arr[], int index, int size) {
    struct TreeNode* root = NULL;

    if (index < size) {
        struct TreeNode* temp = createNode(arr[index]);
        root = temp;

        root->left = buildTreeFromArray(arr, 2 * index + 1, size);
        root->right = buildTreeFromArray(arr, 2 * index + 2, size);
    }

    return root;
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
int size;
   printf("Enter the size of array : ");
   scanf("%d",&size);
    int arr[size];
   printf("\nEnter elements of the array \n");
   for(int i=0;i<size;i++)
   scanf("%d",&arr[i]);
    struct TreeNode* root = buildTreeFromArray(arr, 0, size);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    return 0;
}
