#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "RBTree.h"

void test(int num) {
    RBTree<int> tree;
    for (int i = 0; i < num; ++i) {
        tree.insert(new RBNode<int>(rand() % num));
    }
    tree.DFS();
    //    std::cout << "balanced? " << tree.isBalanced() << std::endl;
    bool bal = tree.isRBTBalanced();
    std::cout << "RBT balanced? " << bal << std::endl;
    std::cout << "tree depth: " << tree.depth(tree.root) << std::endl;

    int count = num;
    while (count-- > 0) {
        bool success = tree.remove(rand() % num);
        if (success) {
            std::cout << "node key = " << count << " removed" << std::endl;
        } else {
            std::cout << "node key = " << count << " not existed" << std::endl;
        }
    }

    tree.DFS();
    std::cout << "tree size: " << tree.size << std::endl;
    std::cout << "clearing" << std::endl;
    tree.clear();
    std::cout << "DFS:" << std::endl;
    tree.DFS();
    std::cout << "tree size: " << tree.size << std::endl;
}

int main(int argc, char** argv) {
    int num = 15;
    if (argc > 1) {
        num = atoi(argv[1]);
    }
    srand(time(NULL));

//     for (int i = 0; i < 10; i++) {
//         std::cout << "running test " << i << std::endl;
//         test(num);
//     }
    test(num);

    return 0;
}
