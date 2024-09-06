#pragma once
#include <iostream>
#include <cmath>
#include <vector>

template <typename T>
class Heap {
public:
	Heap(const std::vector<T>& nums) : heap(nums) {}
	T get();
	T getAndMove();
	void insert(const T& value);
	void printHeap();

protected:
	void init();
	virtual void downHeap(int index) = 0;
	virtual void upHeap(int index) = 0;

protected:
	std::vector<T> heap;
};

template <typename T>
T Heap<T>::get()
{
	if (heap.empty()) {
		throw std::runtime_error("Heap is empty");
	}
	return heap.front();
}

template <typename T>
T Heap<T>::getAndMove()
{
	if (heap.empty()) {
		throw std::runtime_error("Heap is empty");
	}
	T res = heap.front();
	heap.front() = heap.back();
	heap.pop_back();

	if (heap.size()) downHeap(0);

	return res;
}

template <typename T>
void Heap<T>::insert(const T& t)
{
	heap.push_back(t);
	upHeap(heap.size() - 1);
}

// ��һ��������ʽ��ӡ����
template <typename T>
void Heap<T>::printHeap()
{
	int n = heap.size();
	if (n == 0) {
		std::cout << "Heap is empty" << std::endl;
		return;
	}

	int levels = std::log2(n) + 1;  // �������Ĳ���
	int maxWidth = std::pow(2, levels) - 1;  // ��������ȣ�����ײ㣩

	int index = 0;
	for (int level = 0; level < levels; ++level) {
		int nodesOnLevel = std::pow(2, level);  // ��ǰ��Ľڵ�����
		int spaceBetween = maxWidth / nodesOnLevel;  // ÿ���ڵ�֮��ļ��

		// ��ӡ��ǰ���Ԫ�أ����ʵ�����ո�
		for (int i = 0; i < nodesOnLevel && index < n; ++i) {
			// ��ӡǰ�ÿո�
			if (i == 0) {
				for (int j = 0; j < spaceBetween / 2; ++j) {
					std::cout << " ";
				}
			}
			else {
				for (int j = 0; j < spaceBetween; ++j) {
					std::cout << " ";
				}
			}

			// ��ӡ�ڵ�
			std::cout << heap[index++];
		}

		std::cout << std::endl;  // ���У�������һ��
	}
}

template <typename T>
void Heap<T>::init()
{
	for (int i = heap.size() / 2 - 1; i >= 0; --i) {
		downHeap(i);
	}
}



template <typename T>
class MinHeap: public Heap<T> {
public:
	MinHeap(const std::vector<T>& nums) : Heap<T>(nums) { this->init(); }

private:
	void downHeap(int index) override;
	void upHeap(int index) override;
};

// �ӵ�ǰ�ڵ����µ����ѵĽṹ
template <typename T>
void MinHeap<T>::downHeap(int index)
{
	int left = index * 2 + 1, right = index * 2 + 2;
	int smallest = index;
	int size = this->heap.size();

	if (left < size && this->heap[left] < this->heap[smallest]) smallest = left;
	if (right < size && this->heap[right] < this->heap[smallest]) smallest = right;

	if (smallest != index) {
		std::swap(this->heap[index], this->heap[smallest]);
		downHeap(smallest);
	}
}

// �ӵ�ǰ�ڵ����ϵ����ѽṹ
template <typename T>
void MinHeap<T>::upHeap(int index)
{
	int parent = (index - 1) / 2;
	if (this->heap[parent] > this->heap[index]) {
		std::swap(this->heap[index], this->heap[parent]);
		upHeap(parent);
	}
}


template <typename T>
class MaxHeap: public Heap<T> {
public:
	MaxHeap(const std::vector<T>& nums) : Heap<T>(nums) { this->init(); }

private:
	void downHeap(int index) override;
	void upHeap(int index) override;

};

template <typename T>
void MaxHeap<T>::downHeap(int index)
{
	int left = index * 2 + 1, right = index * 2 + 2;
	int size = this->heap.size();
	int maxValue = index;

	if (left < size && this->heap[left] > this->heap[maxValue]) maxValue = left;
	if (right < size && this->heap[right] > this->heap[maxValue]) maxValue = right;

	if (index != maxValue) {
		std::swap(this->heap[index], this->heap[maxValue]);
		downHeap(maxValue);
	}
}

template <typename T>
void MaxHeap<T>::upHeap(int index)
{
	int parent = (index - 1) / 2;
	if (this->heap[index] > this->heap[parent]) {
		std::swap(this->heap[index], this->heap[parent]);
		upHeap(parent);
	}
}