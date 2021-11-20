template<typename HashedObj>
bool HashTable<HashedObj>::contains(const HashedObj& x) const {
	auto& whichList = theLists[myhash(x)];
	return find(begin(whichList), end(whichList), x) != end(whichList);
}

template<typename HashedObj>
void HashTable<HashedObj>::makeEmpty() {
  for (auto& thisList : theLists)
		thisList.clear();
}

template<typename HashedObj>
bool HashTable<HashedObj>::insert(const HashedObj& x) {
	auto& whichList = theLists[myhash(x)];
	if (find(begin(whichList), end(whichList), x) != end(whichList))
		return false;
	whichList.push_back(x);

	// Rehash; see Section 5.5
	if (++currentSize > theLists.size())
		rehash();

	return true;
}

template<typename HashedObj>
bool HashTable<HashedObj>::remove(const HashedObj& x) {
	auto& whichList = theLists[myhash(x)];
	auto itr = find(begin(whichList), end(whichList), x);

	if (itr == end(whichList))
		return false;

	whichList.erase(itr);
	--currentSize;
	return true;
}

template<typename HashedObj>
size_t HashTable<HashedObj>::myhash(const HashedObj& x) const {
	static hash<HashedObj> hf;
	return hf(x) % theLists.size();
}

template<typename HashedObj>
void HashTable<HashedObj>::rehash() {
	vector <list<HashedObj>> oldLists = theLists;

	// Create new double-sized, empty table
	theLists.resize(nextPrime(2 * theLists.size()));
	for (auto & thisList:theLists) {
		thisList.clear();
	}

	// Copy table over
	currentSize = 0;
	for (auto& thisList:oldLists) {
		for (auto& x:thisList) {
			insert(std::move(x));
		}
	}
}

template<typename HashedObj>
HashedObj HashTable<HashedObj>::findMax() {
	//Since we don't know where the first element is, we use a boolean to tell if we have found the first element
	HashedObj current_max;
	bool first_element_found = false;
	//We look at each list in the vector
	for (int i = 0; i < theLists.size(); i++)
	// O(M), where M is the size of our hashtable
	{
		for (typename list<HashedObj>::iterator it = theLists[i].begin(); it != theLists[i].end(); ++it) 
		// O(N), where N is the number of elements we have inserted to the entire hash table. 
		// Therefore it is not O(NM) but O(N+M) since we have exactly N elements and will look at each only once.
		{
			//For each element in each list we compare the current max to the current value
			if(first_element_found) // O(1)
			{
				current_max = max(current_max, *it); // O(1), max() is O(1)
			} else{
				current_max = *it; // O(1)
				first_element_found = true; // O(1)
			}
		}
	}
	return current_max; // O(1)
}

int nextPrime(int n) {
	n += (n % 2 ? 0 : 1);
	while (!isPrime(n)) n += 2;
    return n;
}

bool isPrime(int n) {
    if (n == 2 || n == 3) return true;
    if (n == 1 || n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;

    return true;
}
