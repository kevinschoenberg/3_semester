#ifndef _SEPARATE_CHAINING_H_
#define _SEPARATE_CHAINING_H_

#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int nextPrime(int n);
bool isPrime(int n);

template<typename HashedObj>
class HashTable {
  public:
  	HashTable(int size = 101):currentSize {0} {
		theLists.resize(nextPrime(size));
	}

	void makeEmpty();
	bool contains(const HashedObj& x) const;
	bool insert(const HashedObj& x);
	bool remove(const HashedObj& x);
	HashedObj findMax();

  private:
	vector<list<HashedObj>> theLists;	// The array of Lists
	int currentSize;

	size_t myhash(const HashedObj& x) const;
	void rehash();

};

#include "hash_table_chaining.tpp"

#endif
