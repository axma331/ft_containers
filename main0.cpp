#include <iostream>
#include "stack.hpp"
#include "random_access_iterator.hpp"
#include "vector.hpp"

template <template<class> class Vector>
class A {
	public:
	Set(Vector<> v) {a = v[2]; };

	private:
	Vector::const_reference a;
}

int main(){
	// ft::stack<int> s1;
	// ft::stack<int> s2;

	// if (s1.empty() && s2.empty()) {
	// 	for (size_t i(0); i < 5; ++i) {
	// 		s1.push(i*2);
	// 		s2.push(i*3);
	// 		std::cout << "s1: " << s1.top() << "\t";
	// 		std::cout << "s2: " << s2.top() << "\n";			
	// 	}
	// }
	// if (s1.empty() && s2.empty())
	// 		std::cout << "No empty!\n";
	// else {
	// 	s1.top() = 444;
	// 	s2.top() = 333;
	// 		s1.push(2);
	// 		s2.push(2);
	// }

	// if (!s1.empty() && !s2.empty()) {
	// 	for (size_t i(0); i < 5; ++i) {
	// 		std::cout << "s1: " << s1.top() << "size:"<< s1.size() <<"\t";
	// 		std::cout << "s2: " << s2.top() << "size:"<< s1.size() <<"\n";			
	// 		s1.pop();
	// 		s2.pop();
	// 	}
	// }
	// if (s1.empty() && s2.empty())
	// 		std::cout << "Is empty!\n";

	std::vector<int>	v1;
	ft::vector<int>		v2;

	std::vector<int, boost::allocator>::iterator	i1 = v1.begin();


	
	std::vector<int>::const_reference a = v1[2];
	const int& b = v1[2];



	ft::vector<int>::iterator	i2 = v2.begin();
	// std::

	return 0;
}
