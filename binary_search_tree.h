#ifndef __BINARY_SEARCH_TREE_H_
#define __BINARY_SEARCH_TREE_H_

#include <iostream>
#include <string>
#include <queue>

using namespace std;

class binary_search_tree;

class tree_node
{
    private:
        tree_node *left_child = nullptr;
        tree_node *right_child = nullptr;
        tree_node *parent = nullptr;
        int _key = 0;
        string _value = "";
    public:

        tree_node()
        {
            left_child = nullptr;
            right_child = nullptr;
            parent = nullptr;
            _key = 0;
            _value = "";
        };

        tree_node(int key, string value)
        {
            left_child = nullptr;
            right_child = nullptr;
            parent = nullptr;
            _key = key;
            _value = value;
        };

        int get_key(){ return _key; };
        string get_value(){ return _value; };

        friend class binary_search_tree;
};

class binary_search_tree
{
    private:
        tree_node *root = nullptr;
        tree_node *left_most(tree_node *current);
        tree_node *right_most(tree_node *current);
        tree_node *in_order_predecessor(tree_node *current);
        tree_node *in_order_successor(tree_node *current);

    public:
        binary_search_tree()
        {
            root = nullptr;
        };

        tree_node *search(int key);
        void insert_binary_search_tree(int key, string value);
        void delete_binary_search_tree(int key);
        void in_order_print();
        void level_order();    
};

#endif