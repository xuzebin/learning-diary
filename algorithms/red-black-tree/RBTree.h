/**
 * Header only implementation of Red black tree.
 * Support insertion, deletion, and search.
 * Height of the tree is balanced (shortest height * 2 > largest height of the tree)
 * 
 * Created by Zebin Xu on 11/03/2017
 */
#ifndef RBTREE_H
#define RBTREE_H

#include <cmath>
#include <cassert>

#define RED true
#define BLACK false

template <typename T>
struct RBNode {
    bool color : 1;
    T key;
    RBNode* left;
    RBNode* right;
    RBNode* p;

    RBNode(T key) : key(key), left(nullptr), right(nullptr), p(nullptr), color(RED) {}
};

template <typename T>
struct RBTree {
    RBNode<T>* root;
    size_t size;
    RBTree() : root(nullptr), size(0){}

    void insert(RBNode<T>* z);
    RBNode<T>* search(T key);
    bool remove(T key);
    void remove(RBNode<T>* z);
    RBNode<T>* successor(RBNode<T>* node);

    void clear();
    bool isRBTBalanced();
    int shortestDepth(RBNode<T>* node);
    int depth(RBNode<T>* node);
    bool isBalanced(RBNode<T>* node = nullptr);

    void DFS();
    bool isBlack(RBNode<T>* node);
    bool isRed(RBNode<T>* node);
    RBNode<T>* minimum(RBNode<T>* node);

private:
    void insertFixup(RBNode<T>* z);
    void leftRotate(RBNode<T>* x);
    void rightRotate(RBNode<T>* x);
    void transplant(RBNode<T>* u, RBNode<T>* v);
    void deleteFixup(RBNode<T>* x, RBNode<T>* xParent, bool xLeft);

    bool balanced(RBNode<T>* node);
    void recurseDFS(RBNode<T>* node);
};


/**
 *    x                 y
 *   / \               / \
 *  a   y      ->     x   r
 *     / \           / \
 *    b   r         a   b
 */
template <typename T>
void RBTree<T>::leftRotate(RBNode<T>* x) {
    RBNode<T>* y = x->right;
    x->right = y->left;
    if (y->left != nullptr) {
        y->left->p = x;
    }
    y->p = x->p;
    if (x->p == nullptr) {
        root = y;
    } else if (x == x->p->left) { // x was left child of its parent
        x->p->left = y;
    } else {
        x->p->right = y;
    }
    y->left = x;
    x->p = y;
}

/**
 *     x                 y
 *    / \               / \
 *   y   r      ->     a   x
 *  / \                   / \
 * a   b                 b   r
 */
template <typename T>
void RBTree<T>::rightRotate(RBNode<T>* x) {
    RBNode<T>* y = x->left;
    x->left = y->right;
    if (y->right != nullptr) {
        y->right->p = x;
    }
    y->p = x->p;
    if (x->p == nullptr) {
        root = y;
    } else if (x == x->p->left) {
        x->p->left = y;
    } else {
        x->p->right = y;
    }
    y->right = x;
    x->p = y;
}

template <typename T>
void RBTree<T>::insert(RBNode<T>* z) {
    RBNode<T>* y = nullptr;
    RBNode<T>* x = root;
    while (x != nullptr) {
        y = x;
        x = z->key < x->key ? x->left : x->right;
    }
    z->p = y;
    if (y == nullptr) {
        root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
    z->left = nullptr;
    z->right = nullptr;
    z->color = RED;
    insertFixup(z);
    size++;
}

template <typename T>
void RBTree<T>::insertFixup(RBNode<T>* z) {
    while (z != root && z->color == RED && z->p->color == RED) {// while z is not root or z's parent is not BLACK
        if (z->p == z->p->p->left) {
            RBNode<T>* y = z->p->p->right;
            // case 1: z's uncle is RED.
            // 1. Color parent and uncle as BLACK.
            // 2. Color grandparent as RED
            // 3. let z = z's grandparent
            if (isRed(y)) {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            } else { // case 2: z's uncle is BLACK.
                // case 2.1 left right (z is a right child) case: turn it into a left left case
                if (z == z->p->right) {
                    z = z->p;
                    leftRotate(z);
                }
                //case 2.2 left left case: z is a left child
                z->p->color = BLACK;
                z->p->p->color = RED;
                rightRotate(z->p->p);
            }
        } else {
            RBNode<T>* y = z->p->p->left;
            if (isRed(y)) {
                z->p->color = BLACK;
                y->color = BLACK;
                z->p->p->color = RED;
                z = z->p->p;
            } else { // case 2: z's uncle is BLACK.
                // case 2.1 right left (z is a left child) case: turn it into a right right case
                if (z == z->p->left) {
                    z = z->p;
                    rightRotate(z);
                }
                //case 2.2 right right case: z is a right child
                z->p->color = BLACK;
                z->p->p->color = RED;
                leftRotate(z->p->p);
            }
        }
    }
    root->color = BLACK;
}

template <typename T>
RBNode<T>* RBTree<T>::search(T key) {
    RBNode<T>* node = root;
    while (node != nullptr && node->key != key) {
        node = key < node->key ? node->left : node->right;
    }
    return node;
}

template <typename T>
void RBTree<T>::transplant(RBNode<T>* u, RBNode<T>* v) {
    if (u->p == nullptr) {
        root = v;
    } else if (u == u->p->left) {
        u->p->left = v;
    } else {
        u->p->right = v;
    }
    if (v != nullptr) {
        v->p = u->p;
    }
}

template <typename T>
bool RBTree<T>::remove(T key) {
    RBNode<T>* result = search(key);
    if (result == nullptr) {
        return false;
    }
    remove(result);
    return true;
}

template <typename T>
RBNode<T>* RBTree<T>::successor(RBNode<T>* node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->right != nullptr) {
        return minimum(node->right);
    }
    RBNode<T>* parent = node->p;
    while (parent != nullptr && node == parent->right) {
        node = parent;
        parent = node->p;
    }
    return parent;
}

template <typename T>
void RBTree<T>::remove(RBNode<T>* z) {
    assert(z != nullptr);
    RBNode<T>* y(nullptr);
    if (z->left == nullptr || z->right == nullptr) {
        y = z;
    } else  {
        y = successor(z);
    }

    RBNode<T>* x(nullptr);
    if (y->left != nullptr) {
        x = y->left;
    } else {
        x = y->right;
    }
    if (x != nullptr) {
        x->p = y->p;
    }
    RBNode<T>* xParent = y->p;
    bool yLeft = false;
    if (y->p == nullptr) {
        root = x;
    } else if (y == y->p->left) {
        y->p->left = x;
        yLeft = true;
    } else {
        y->p->right = x;
        yLeft = false;
    }

    if (y != z) {
        z->key = y->key;
    }
        
    if (y->color == BLACK) {
        deleteFixup(x, xParent, yLeft);
    }
    size--;
}

template <typename T>    
void RBTree<T>::deleteFixup(RBNode<T>* x, RBNode<T>* xParent, bool xLeft) {
    while (x != root && isBlack(x)) {
        if (xLeft) {
            RBNode<T>* w = xParent->right;
            if (isRed(w)) {
                w->color = BLACK;
                xParent->color = RED;
                leftRotate(xParent);
                w = xParent->right;
            }
            if (isBlack(w->right) && isBlack(w->left)) {
                w->color = RED;
                x = xParent;
                xParent = x->p;
                xLeft = (xParent != nullptr && x == xParent->left);
            } else {
                if (isBlack(w->right)) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(w);
                    w = xParent->right;
                }
                w->color = xParent->color;
                xParent->color = BLACK;
                if (w->right != nullptr) {
                    w->right->color = BLACK;
                }
                leftRotate(xParent);
                x = root;
                xParent = nullptr;
            }
        } else {
            RBNode<T>* w = xParent->left;
            if (isRed(w)) {
                w->color = BLACK;
                xParent->color = RED;
                rightRotate(xParent);
                w = xParent->left;
            }
            if (isBlack(w->right) && isBlack(w->left)) {
                w->color = RED;
                x = xParent;
                xParent = x->p;
                xLeft = (xParent != nullptr && x == xParent->left);
            } else {
                if (isBlack(w->left)) {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = xParent->left;
                }
                w->color = xParent->color;
                xParent->color = BLACK;
                if (w->left != nullptr) {
                    w->left->color = BLACK;
                }
                rightRotate(xParent);
                x = root;
                xParent = nullptr;
            }
        }
    }
    if (x != nullptr) {
        x->color = BLACK;
    }
}

template <typename T>
bool RBTree<T>::isBlack(RBNode<T>* node) {
    return (node == nullptr) || (node->color == BLACK);
}

template <typename T>
bool RBTree<T>::isRed(RBNode<T>* node) {
    return (node != nullptr) && (node->color == RED);
}

template <typename T>
RBNode<T>* RBTree<T>::minimum(RBNode<T>* node) {
    if (node == nullptr) {
        return nullptr;
    }
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

template <typename T>
void RBTree<T>::clear() {
    while (root != nullptr) {
        assert(root != nullptr);
        T key = root->key;
        bool suc = remove(key);
        std::cout << "node " << key << " removed" << std::endl;
    }
}

template <typename T>
bool RBTree<T>::isRBTBalanced() {
    RBNode<T>* node = root;
    int shortest =  shortestDepth(node);
    int longest = depth(node);
    std::cout << "shortest: " << shortest << std::endl;
    std::cout << "longest: " << longest << std::endl;
    return (shortest * 2 >= longest);
}

template <typename T>
int RBTree<T>::shortestDepth(RBNode<T>* node) {
    if (node == nullptr) {
        return 0;
    }
    return std::min(shortestDepth(node->left), shortestDepth(node->right)) + 1;
}

template <typename T>
bool RBTree<T>::isBalanced(RBNode<T>* node) {
    if (node == nullptr) {
        node = root;
    }
    return balanced(node);
}

template <typename T>
bool RBTree<T>::balanced(RBNode<T>* node) {
    if (node == nullptr) {
        return true;
    }
    int left = depth(node->left);
    int right = depth(node->right);
    return (std::abs(left - right) < 2 && balanced(node->left) && balanced(node->right));
}

template <typename T>
int RBTree<T>::depth(RBNode<T>* node) {
    if (node == nullptr) {
        return 0;
    }

    int left = depth(node->left);
    int right = depth(node->right);
    return std::max(left, right) + 1;
}

template <typename T>
void RBTree<T>::DFS() {
    RBNode<T>* cur = root;
    recurseDFS(cur);
    std::cout << std::endl;
}

template <typename T>
void RBTree<T>::recurseDFS(RBNode<T>* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->key << ": " << (node->color == RED ? "RED" : "BLACK") << std::endl;
    recurseDFS(node->left);
    recurseDFS(node->right);
}

#endif
