#pragma once
#include <iostream>
#include <string>
#include <vector>

template <typename T>
struct node {
	T val;
	std::vector<node<T>*> childs;
	int num;
};

template <typename T>
class TireTree {
public:
	TireTree() { root = new node<T>(); }

	void insert(std::string s);

	bool find(std::string s);

	~TireTree();

private:
	void dfsClear(node<T>* cur);

private:
	node<T>* root;
};

template<typename T>
inline void TireTree<T>::insert(std::string s)
{
	node<T>* cur = root;
	for (auto x : s) {
		bool flag = false;
		for (node<T>* child : cur->childs) {
			if (child->val == x) {
				flag = true;
				cur = child;
				break;
			}
		}
		if (!flag) {
			node<T>* temp = new node<T>();
			temp->val = x;
			cur->childs.push_back(temp);
			cur = temp;
		}
	}

	++cur->num;
}

template<typename T>
inline bool TireTree<T>::find(std::string s)
{
	node<T>* cur = root;
	for (auto x : s) {
		bool flag = false;
		for (node<T>* child : cur->childs) {
			if (child->val == x) {
				cur = child;
				flag = true;
				break;
			}
		}

		if (!flag) return false;
	}
	return cur->num > 0;
}

template<typename T>
inline TireTree<T>::~TireTree()
{
	dfsClear(root);
}

template<typename T>
inline void TireTree<T>::dfsClear(node<T>* cur)
{
	if (cur) {
		for (auto child : cur->childs) {
			dfsClear(child);
		}
		delete cur;
	}
}

// 不去动态的申请节点连接，普通的数组写法
const int ALPHA = 26;
