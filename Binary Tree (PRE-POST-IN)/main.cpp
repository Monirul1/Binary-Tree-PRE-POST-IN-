#include <iostream>

using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        value = data;
        left = right = NULL;
    }
};

int height(TreeNode* root) {
    if (root == NULL) // The binary tree is empty
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

TreeNode* add(TreeNode* root, int data) {
    TreeNode* resNode;
    if (root == NULL) {
        resNode = new TreeNode(data);
        return resNode;
    }
    
    if (height(root->left) > height(root->right)) {
        root->right = add(root->right, data);
    }
    else {
        root->left = add(root->left, data);
    }
    return root;
}

void preorder(TreeNode* root) {
    if (root != NULL) {
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}

void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
    }
}

int treeSize(TreeNode* root) {
    if (root == NULL)
        return 0;
    return treeSize(root->left) + 1 + treeSize(root->right);
}

void clear(TreeNode* root) {
    if (root != NULL) {
        clear(root->left);
        clear(root->right);
        delete root;
    }
}

int main() {
    TreeNode* root = new TreeNode(2);
    add(root, 3);
    add(root, 1);
    add(root, 4);
    add(root, 6);
    add(root, 8);
    add(root, 9);
    
    preorder(root);
    cout << endl;
    
    inorder(root);
    cout << endl;
    
    postorder(root);
    cout << endl;
    
    cout << "Number of nodes in a binary tree " << treeSize(root) << endl;
    
    clear(root);
    root = NULL;
    
}