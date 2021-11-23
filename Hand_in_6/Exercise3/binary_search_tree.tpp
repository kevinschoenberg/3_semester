/**
 * Find the smallest item in the tree.
 * Throw UnderflowException if empty.
 */
template<typename Object>
const Object& BinarySearchTree<Object>::findMin() const {
	if (isEmpty()) throw underflow_error("tree is empty.");
	return findMin(root)->element;
}
/**
 * Find the largest item in the tree.
 * Throw UnderflowException if empty.
 */
template<typename Object>
const Object& BinarySearchTree<Object>::findMax() const {
	if (isEmpty()) throw underflow_error("tree is empty.");
	 return findMax(root)->element;
}

/**
 * Returns true if x is found in the tree.
 */
template <typename Object>
bool BinarySearchTree<Object>::contains(const Object& x) const {
	return contains(x, root);
}

/**
 * Test if the tree is logically empty.
 * Return true if empty, false otherwise.
 */
template<typename Object>
bool BinarySearchTree<Object>::isEmpty() const {
	return root == nullptr;
}

/**
 * Print the tree contents in sorted order.
 */
template<typename Object>
void BinarySearchTree<Object>::printTree(ostream& out) const {
	if (isEmpty()) {
		out << "Empty tree" << endl;
	} else
		printTree(root, out);
}

/**
 * Make the tree logically empty.
 */
template<typename Object>
void BinarySearchTree<Object>::makeEmpty() {
	makeEmpty(root);
}

/**
 * Insert x into the tree; duplicates are ignored.
 */
template<typename Object>
void BinarySearchTree<Object>::insert(const Object& x) {
	insert(x, root);
}

/**
 * Remove x from the tree. Nothing is done if x is not found.
 */
template<typename Object>
void BinarySearchTree<Object>::remove(const Object& x) {
	remove(x, root);
}
