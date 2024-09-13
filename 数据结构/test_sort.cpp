#include "sort.h"

std::vector<int> nums;

int main()
{
	nums = {5, 4, 2, 3, 1};

	//quickSort(0, nums.size() - 1);
	quickSortRecursion();

	for (auto x : nums) std::cout << x << std::endl;

	return 0;
}