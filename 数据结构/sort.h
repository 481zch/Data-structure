#pragma once
#include <iostream>
#include <vector>
#include <queue>

extern std::vector<int> nums;
using PII = std::pair<int, int>;

void bubble_sort()
{
	int n = nums.size();
	for (int i = 0; i < n - 1; ++i) {
		bool swapped = false;

		for (int j = 0; j < n - i - 1; ++j) {
			if (nums[j] > nums[j + 1]) {
				std::swap(nums[j], nums[j + 1]);
				swapped = true;
			}
		}

		if (!swapped) {
			break;
		}
	}
}

void heapify(int index)
{
	int n = nums.size();
	int left = index * 2 + 1, right = index * 2 + 2;
	int cur = index;
	if (left < n && nums[left] > nums[index]) cur = left;
	if (right < n && nums[right] > nums[index]) cur = right;

	if (cur != index) {
		std::swap(index, cur);
		heapify(index);
	}
}

void heapSort()
{
	int n = nums.size();
	for (int i = n / 2 - 1; i >= 0; --i) {
		heapify(i);
	}
	for (int i = n - 1; i >= 0; --i) {
		std::swap(nums[0], nums[i]);
		heapify(0);
		nums.pop_back();
	}
}

// 递归处理下的快速排序
void quickSort(int l, int r)
{
	if (l >= r) return;
	int mid = nums[l + (r - l) / 2];
	int i = l, j = r;

	while (i <= j) {
		while (nums[i] < mid) ++i;
		while (nums[j] > mid) --j;
		if (i <= j) {
			std::swap(nums[i], nums[j]);
			++i;
			--j;
		}
	}

	quickSort(l, j + 1);
	quickSort(i, r);
}

// 非递归处理下的快速排序
void quickSortRecursion()
{
	std::queue<PII> q;
	q.push({ 0, nums.size() - 1 });

	while (!q.empty()) {
		auto [l, r] = q.front();
		q.pop();

		if (l >= r) continue;

		int mid = nums[l + (r - l) / 2];
		int i = l, j = r;

		while (i <= j) {
			while (nums[i] < mid) ++i;
			while (nums[j] > mid) --j;
			if (i <= j) {
				std::swap(nums[i], nums[j]);
				++i;
				--j;
			}
		}

		q.push({ l, j + 1 });
		q.push({i, r});
	}
}