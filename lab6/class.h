#pragma once

template<typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(const T& value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* findPredecessor(const T& value) const;
    Node* findSuccessor(const T& value) const;
    void destroyTree(Node* node);

public:
    BinaryTree();
    ~BinaryTree();

    void processBinaryTree();
    void printTree(BinaryTree<T>& tree);
    void insert(const T& value);
    bool isEmpty() const;
    int getSize() const;
    void inorderTraversal() const;

    class Iterator {
    private:
        Node* current;
        BinaryTree<T>* tree;

    public:
        Iterator(Node* node, BinaryTree<T>* binaryTree);

        T operator*() const;
        T getRoot();
        Iterator& operator++();
        Iterator& operator--();
        void modify(const T& newValue);
    };

    Iterator begin();
};