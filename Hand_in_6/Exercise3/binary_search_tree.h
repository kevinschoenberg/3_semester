#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include <stdexcept>
#include <algorithm>
using namespace std;

template<typename Object>
class BinarySearchTree {
  public:
	BinarySearchTree() : root {nullptr} {}

	BinarySearchTree(const BinarySearchTree& rhs) : root {nullptr} {
		root = clone(rhs.root);
	}

	~BinarySearchTree() { makeEmpty(); }

	BinarySearchTree& operator=(const BinarySearchTree& rhs) {
		BinarySearchTree copy(rhs);
		std::swap(*this, copy);
		return *this;
	}

    const Object& findMin() const; // find min element
    const Object& findMax() const; // find max element
    bool isEmpty() const; // test for emptiness
    void printTree(ostream& out = cout) const;
    void makeEmpty(); // empty tree
    void insert(const Object& x); // insert item
	bool contains(const Object& x) const; // look for item
    void remove(const Object& x); // remove item

	#include "set_itr.h"

    iterator Sinsert(const Object &x)
    {
        insert(x);
        return Sfind(x);
    }
    iterator Sfind(const Object &x) const
    {
		iterator out;
        BinaryNode *node = root;
        while (node != nullptr)
        {
            if (node->element == x)
            {
                return out{node};
            }
            else if (x < node->element)
            {
                node = node->left;
            }
            else if (x > node->element)
            {
                node = node->right;
            }
        }
        return iterator(nullptr);
    }

    iterator Serase(iterator &itr)
    {
        iterator out {itr->parent};
        remove(itr->element);
        return out;
    }

private:
  struct BinaryNode {
	  Object element;
	  BinaryNode *left;
	  BinaryNode *right;
	  BinaryNode *parent;

	  BinaryNode(const Object& theElement, BinaryNode* lt, BinaryNode* rt, BinaryNode* pt) :
	  	  element {theElement}, left {lt}, right {rt}, parent {pt} { }
  	};

  	BinaryNode *root;

	/**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
	void insert(const Object& x, BinaryNode* &t) {
		if (t == nullptr)
			t = new BinaryNode{x, nullptr, nullptr, nullptr};
		else {
			if (x < t->element)
				if(t->left != nullptr)
				{
					insert(x, t->left);
				} else
				{
					std::cout << "test" << std::endl;
					t->left = new BinaryNode{x, nullptr, nullptr, t};
				}
			else if (t->element < x)
				if(t->right != nullptr)
				{
					insert(x, t->right);
				} else
				{
					t->right = new BinaryNode{x, nullptr, nullptr, t};
				}
			else; // Duplicate; do nothing
		}
	}

	/**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
	void remove(const Object& x, BinaryNode* &t) {
		if (t == nullptr)
			return;				// Item not found; do nothing
		if (x < t->element)
			remove(x, t->left);
		else if (t->element < x)
			remove(x, t->right);
		else if (t->left != nullptr && t->right != nullptr)	// Two children
		{
			t->element = findMin(t->right)->element;
			remove(t->element, t->right);
		} else {
			BinaryNode*oldNode = t;
			t = (t->left != nullptr) ? t->left : t->right;
			delete oldNode;
		}
	}

	/**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
	BinaryNode *findMin(BinaryNode* t) const {
		if (t == nullptr)
			return nullptr;
		if (t->left == nullptr)
			return t;
		return findMin(t->left);
	}

	/**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
	BinaryNode *findMax(BinaryNode* t) const {
		if (t != nullptr)
			while (t->right != nullptr)
				t = t->right;
		return t;
	}

	/**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
	bool contains(const Object& x, BinaryNode* t) const {
		if (t == nullptr)
			return false;
		else if (x < t->element)
			return contains(x, t->left);
		else if (t->element < x)
			return contains(x, t->right);
		else
			return true;	// Match
	}

	/**
     * Internal method to make subtree empty.
     */
	void makeEmpty(BinaryNode* &t) {
		if (t != nullptr) {
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		t = nullptr;
	}

	/**
     * Internal method to print a subtree rooted at t in sorted order.
     */
	void printTree(BinaryNode* t, ostream & out) const {
		if (t != nullptr) {
			printTree(t->left, out);
			out << t->element << endl;
			printTree(t->right, out);
		}
	}

	/**
     * Internal method to clone subtree.
     */
	BinaryNode *clone(BinaryNode* t) const {
		if (t == nullptr)
			return nullptr;
		else
			return new BinaryNode{t->element, clone(t->left), clone(t->right), clone(t->parent)};
	}
};

#include "binary_search_tree.tpp"

#endif
