#include "heap.h"

// 大根堆的测试
void test_MaxHeap()
{
    std::vector<int> nums = { 1, 2, 3, 4, 9, 8, 7, 6 };
    MaxHeap<int> heap(nums);

    // 打印堆
    std::cout << "MaxHeap:" << std::endl;
    heap.printHeap();

    // 测试插入
    heap.insert(10);
    std::cout << "After inserting 10:" << std::endl;
    heap.printHeap();

    // 测试取出最大值并移动
    int maxVal = heap.getAndMove();
    std::cout << "Max value: " << maxVal << std::endl;
    std::cout << "After removing max:" << std::endl;
    heap.printHeap();
}

// 小根堆的测试
void test_MinHeap()
{
    std::vector<int> nums = { 10, 30, 20, 50, 60, 70, 40, 90 };
    MinHeap<int> heap(nums);

    // 打印堆
    std::cout << "MinHeap:" << std::endl;
    heap.printHeap();

    // 测试插入
    heap.insert(5);
    std::cout << "After inserting 5:" << std::endl;
    heap.printHeap();

    // 测试取出最小值并移动
    int minVal = heap.getAndMove();
    std::cout << "Min value: " << minVal << std::endl;
    std::cout << "After removing min:" << std::endl;
    heap.printHeap();
}

int main()
{
    test_MaxHeap();
    std::cout << "===============================" << std::endl;
    test_MinHeap(); 
    return 0;
}
