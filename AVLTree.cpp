#include <iostream>
#include <algorithm> // For std::max

// Using Templates to make the library generic (works with int, float, etc.)
template <typename T>
class AVLTree {
private:
    struct Node {
        T key;
        Node* left;
        Node* right;
        int height;

        Node(T k) : key(k), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    // Helper function to safely get the height of a node
    int height(Node* n) {
        if (n == nullptr) return 0;
        return n->height;
    }

    // Helper function to get the balance factor of a node
    int getBalance(Node* n) {
        if (n == nullptr) return 0;
        return height(n->left) - height(n->right);
    }

    // Right Rotation: Fixes Left-Left case
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = std::max(height(y->left), height(y->right)) + 1;
        x->height = std::max(height(x->left), height(x->right)) + 1;

        // Return new root
        return x;
    }

    // Left Rotation: Fixes Right-Right case
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = std::max(height(x->left), height(x->right)) + 1;
        y->height = std::max(height(y->left), height(y->right)) + 1;

        // Return new root
        return y;
    }

    // Recursive insert function
    Node* insert(Node* node, T key) {
        // 1. Perform standard BST insert
        if (node == nullptr) return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node; // Duplicate keys are not allowed in this implementation

        // 2. Update height of this ancestor node
        node->height = 1 + std::max(height(node->left), height(node->right));

        // 3. Get the balance factor to check whether this node became unbalanced
        int balance = getBalance(node);

        // 4. If unbalanced, there are 4 cases:

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // Return the (unchanged) node pointer
        return node;
    }

    // Helper for in-order traversal
    void inOrder(Node* root) {
        if (root != nullptr) {
            inOrder(root->left);
            std::cout << root->key << " ";
            inOrder(root->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    // Public API to insert a key
    void insert(T key) {
        root = insert(root, key);
    }

    // Display the tree (In-order traversal yields sorted values)
    void display() {
        inOrder(root);
        std::cout << std::endl;
    }
};

// Driver code to test the implementation
int main() {
    AVLTree<int> tree;
    
    std::cout << "Adding elements to AVL Tree: 10, 20, 30, 40, 50, 25" << std::endl;
    
    /* Constructing the tree. 
       Without balancing, this would form a skewed tree (like a linked list).
       AVL rotation logic will ensure it remains balanced with O(log n) height.
    */
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    std::cout << "In-order traversal (Sorted): ";
    tree.display();

    return 0;
}
