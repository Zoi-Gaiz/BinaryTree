#include <stdlib.h>
#include <stdio.h>

typedef struct node { //树的结点
    int data;
    struct node *left;
    struct node *right;
} Node;

typedef struct { //树根
    Node *root;
} Tree;

void insert(Tree *tree, int value) {//创建树
    Node *node = (Node *) malloc(sizeof(Node));//创建一个节点
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    if (tree->root == NULL) {//判断树是不是空树
        tree->root = node;
    } else {//不是空树
        Node *temp = tree->root;//从树根开始
        while (temp != NULL) {
            if (value < temp->data) {//小于就进左儿子
                if (temp->left == NULL) {
                    temp->left = node;
                    return;
                } else {//继续判断
                    temp = temp->left;
                }
            } else {//否则进右儿子
                if (temp->right == NULL) {
                    temp->right = node;
                    return;
                } else {//继续判断
                    temp = temp->right;
                }
            }
        }
    }
    return;
}

void inorder(Node *node) {//树的中序遍历
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

int main(void) {
    Tree tree;
    tree.root = NULL;//创建一个空树
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {//输入n个数并创建这个树
        int temp;
        scanf("%d", &temp);
        insert(&tree, temp);
    }
    inorder(tree.root);//中序遍历
    return 0;
}
/*
6
1
36
8
9
11
9
*/