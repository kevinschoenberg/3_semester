#ifndef _BINARY_SEARCH_H_
#define _BINARY_SEARCH_H_

using namespace std;

/** Performs the standard binary search using two comparisons per level. */

template <typename iterator, typename Object>
iterator recBinarySearch(iterator first, iterator last, const Object& value) {
	iterator begin = first;
	iterator end = last;
	if (begin != end) {
		int distance = std::distance(begin, end);
		iterator middle = std::next(begin, distance/2);
		if(*middle == value) {
			return middle;
		} else if(*middle < value) {
			return recBinarySearch(next(middle), last, value);
		} else {
			return recBinarySearch(first, middle, value);
		}
	}
	return last;
}

template <typename iterator, typename Object>
iterator binarySearch(iterator first, iterator last, const Object& value) {
	iterator begin = first;
	iterator end = last;
	while (begin != end) {
		int distance = std::distance(begin, end);
		iterator middle = std::next(begin, distance/2);
		if(*middle == value) {
			return middle;
		} else if(*middle < value) {
			begin = std::next(middle);
		} else {
			end = middle;
		}
	}
	return last;
}

#endif
