#include "tireTree.h"

int main()
{
	TireTree<char> t1;
	t1.insert("hello");
	t1.insert("hi");
	t1.insert("xiaoming");

	std::cout << (t1.find("zhutou") ? "true" : "false") << std::endl;
	return 0;
}