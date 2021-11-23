class iterator
{
private:
    BinaryNode *current;
    
public:
    friend class BinarySearchTree<Object>;

    // Public constructor for iterator.
    iterator()
    {
        current = nullptr;
    }

    iterator(BinaryNode *p)
    {
        current = p;
    }

    const Object &operator*()
    {
        return current->element;
    }

    bool operator==(const iterator &rhs)
    {
        return current == rhs.current;
    }

    bool operator!=(const iterator &rhs)
    {
        return !(*this == rhs);
    }

    /* Pre-in/decrement. */
    iterator &operator++()
    {
        current = current->left;
        return *this;
    }

    iterator &operator--()
    {
        current = current->right;
        return *this;
    }
    

    /* Post-in/decrement. */
    iterator operator++(int)
    {
        iterator old = *this;
        ++(*this);
        return old;
    }

    iterator operator--(int)
    {
        iterator old = *this;
        --(*this);
        return old;
    }

    
};
