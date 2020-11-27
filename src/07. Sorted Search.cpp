// 7. Sorted Search
/*
  Implement function countNumbers that accepts a sorted vector of unique integers and, efficiently with respect to time used, 
  counts the number of vector elements that are less than the parameter lessThan.
  For example, for vector v containing { 1, 3, 5, 7 }, countNumbers(v, 4) should return 2 because there are two vector elements less than 4.
*/
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

#if 1//INITIAL_CODE
int countNumbers(const std::vector<int>& sortedVector, int lessThan)
{
	int start = 0;
	int end = sortedVector.size() - 1;

	while (1)
	{
		int mid = (end - start) / 2 + start;

		if (start == end) // last bin
		{
			if (sortedVector[mid] >= lessThan)
				return mid;
			if (sortedVector[mid] < lessThan)
				return mid + 1;
		}

		if (sortedVector[mid] > lessThan) // travers to left
		{
			end = mid - 1;
			if (start > end)
				return mid;
		}
		else if (sortedVector[mid] < lessThan) // travers to right
		{
			start = mid + 1;
			if (start > end)
				return mid + 1;
		}
		else // exact same
			return mid;
	}
	return 0;
}
#endif 

#if USING_LOWER_BOUND
#include <algorithm>
#include <iterator>

int countNumbers(const std::vector<int>& sortedVector, int lessThan)
{
	// get an iterator to the first element >= lessThan
	auto itr = std::lower_bound(sortedVector.begin(), sortedVector.end(), lessThan); // O(log n)

	// return the distance between two iterators
	return std::distance(sortedVector.begin(), itr); // O(1)
}
#endif

#ifndef RunTests
int main()
{
	std::vector<int> v{ 1, 3, 5, 7 };
	std::cout << countNumbers(v, 4); // 2
	std::cout << countNumbers(v, 5); // 2
	std::cout << countNumbers(v, 6); // 3
	std::cout << countNumbers(v, 7); // 3
	std::cout << countNumbers(v, 0); // 0
	std::cout << countNumbers(v, 1); // 0

	std::vector<int> v2{ 1 };
	std::cout << countNumbers(v2, 4); // 1
	std::cout << countNumbers(v2, 5); // 1
	std::cout << countNumbers(v2, 6); // 1
	std::cout << countNumbers(v2, 7); // 1
	std::cout << countNumbers(v2, 0); // 0
	std::cout << countNumbers(v2, 1); // 0
}
#endif
