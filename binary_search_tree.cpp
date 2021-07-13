#include "binary_search_tree.h"
using namespace std;

tree_node *binary_search_tree::left_most(tree_node *current)
{
    while(current->left_child != nullptr)
    {
        current = current->left_child;
    }

    return current;
}

tree_node *binary_search_tree::right_most(tree_node *current)
{
    while(current->right_child != nullptr)
    {
        current = current->right_child;
    }

    return current;
}

tree_node *binary_search_tree::in_order_predecessor(tree_node *current)
{
    if(current->left_child != nullptr)
    {
        return right_most(current->left_child);
    }

    tree_node *predecessor = current->parent;
    while(predecessor != nullptr && current == predecessor->left_child)
    {
        current = predecessor;
        predecessor = current->parent;
    }
    return predecessor;
}

tree_node *binary_search_tree::in_order_successor(tree_node *current)
{
    if(current->right_child != nullptr)
    {
        return left_most(current->right_child);
    }

    tree_node *successor = current->parent;
    while(successor != nullptr && current == successor->right_child)
    {
        current = successor;
        successor = current->parent;
    }
    return successor;
}

tree_node *binary_search_tree::search(int key)
{
    tree_node *current = root;
    while(current != nullptr && current->_key != key)
    {
        if(current->_key < key)
        {
            current = current->right_child;
        }
        else
        {
            current = current->left_child;
        }
    }
    return current;

}

void binary_search_tree::insert_binary_search_tree(int key, string value)
{
    tree_node *insert_node_parent = nullptr;
    tree_node *current = root;
    tree_node *insert_node = new tree_node(key, value);

    while(current != nullptr)
    {
        insert_node_parent = current;

        if(insert_node->_key < current->_key)
        {
            current = current->left_child;
        }
        else
        {
            current = current->right_child;
        }
    }

    insert_node->parent = insert_node_parent;

    if(insert_node_parent == nullptr)
    {
        root = insert_node;
        return;
    }
    else if(insert_node->_key < insert_node_parent->_key)
    {
        insert_node_parent->left_child = insert_node;
    }
    else
    {
        insert_node_parent->right_child = insert_node;
    }

}

void binary_search_tree::delete_binary_search_tree(int key)
{
    tree_node *delete_node = search(key);
    if(delete_node == nullptr)
    {
        cout << "not found" <<endl;
        return;
    }
    
    tree_node *real_delete_node = nullptr;
    tree_node *delete_node_child = nullptr;

    if(delete_node->left_child == nullptr || delete_node->right_child == nullptr)
    {
        real_delete_node = delete_node;
    }
    else
    {
        real_delete_node = in_order_successor(delete_node);
    }

    if(real_delete_node->left_child != nullptr)
    {
        delete_node_child = real_delete_node->left_child;
    }
    else
    {
        delete_node_child = real_delete_node->right_child;
    }

    if(delete_node_child != nullptr)
    {
        delete_node_child->parent = real_delete_node->parent;
    }

    if(real_delete_node->parent == nullptr)
    {
        root = delete_node_child;
    }
    else if(real_delete_node == real_delete_node->parent->left_child)
    {
        real_delete_node->parent->left_child = delete_node_child;
    }
    else
    {
        real_delete_node->parent->right_child = delete_node_child;
    }

    if(real_delete_node != delete_node)
    {
        delete_node->_key = real_delete_node->_key;
        delete_node->_value = real_delete_node->_value;
    }
    real_delete_node = nullptr;
    delete real_delete_node;
}

void binary_search_tree::in_order_print()
{
    tree_node *current = left_most(root);

    while(current != nullptr)
    {
        cout << "(" << current->_key << ")" << current->_value << " ";
        current = in_order_successor(current);
    }
}

void binary_search_tree::level_order()
{
    queue<tree_node*> q_node;
    q_node.push(root);

    while(!q_node.empty())
    {
        tree_node *current = q_node.front();
        q_node.pop();
        cout << "(" << current->_key << ")" << current->_value << " ";
        if(current->left_child != nullptr)
        {
            q_node.push(current->left_child);
        }

        if(current->right_child != nullptr)
        {
            q_node.push(current->right_child);
        }
    }
}