#include <iostream>
#include "TList.h"
using namespace std;

int main() {
	TList<int> list;
	list.InsFirst(10);
	list.InsLast(20);
	list.InsLast(30);
	list.InsLast(40);

    std::cout << "Lists elements: ";
    for (auto it = list.Begin(); it != list.End(); ++it) {
        std::cout << *it << " "; 
    }
    std::cout << std::endl;

    std::cout << "Lists elements * 2: ";
    for (auto it = list.Begin(); it != list.End(); ++it) {
        *it *= 2; 
        std::cout << *it << " "; 
    }
    std::cout << std::endl;

	return 0;
}