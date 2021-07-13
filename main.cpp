#include <iostream>
#include "binary_search_tree.h"

using namespace std;

// @ref: http://alrightchiu.github.io/SecondRound/binary-search-tree-introjian-jie.html

int main()
{
    binary_search_tree tree;
    
    tree.insert_binary_search_tree(8,"Mon");
    tree.insert_binary_search_tree(1024,"Tue");
    tree.insert_binary_search_tree(2,"Wed");
    tree.insert_binary_search_tree(512,"Thu");


    cout << "Inorder Traversal:\n";
    tree.in_order_print();
    cout << endl;
    cout << "Level-order Traversal:\n";
    tree.level_order();
    cout << endl;
    
    tree_node *node = tree.search(1024);
    if(node != nullptr){
    	cout << "There is "  << "(" << node->get_key() << ")" << node->get_value() << endl;
    }
    else {
    	cout << "no element with Key(1000)" << endl;
    }
    
    node = tree.search(3);
    if(node != nullptr){
    	cout << "There is "  << "(" << node->get_key() << ")" << node->get_value() << endl;
    }
    else {
    	cout << "no element with Key(73)" << endl;
    }

    tree.delete_binary_search_tree(1024);
    tree.in_order_print();
    cout << endl;

    return 0;
}