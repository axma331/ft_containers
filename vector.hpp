#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <memory>
#include "iterator.hpp"
#include "random_access_iterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{

		public:
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::size_type				size_type;
			typedef typename allocator_type::different_type			difference_type;
			typedef ft::random_access_iterator<value_type>			iterator;
			typedef ft::random_access_iterator<const value_type>	const_iterator;
			// typedef 	reverse_iterator;
			// typedef 	const_reverse_iterator;
		private:
			T*			_arr;
			size_t		_size;
			size_t		_capacity;
			iterator	_first;
			iterator	_last;
			iterator	_end;
		public:
			explicit	vector(const allocator_type& alloc = allocator_type()) {};	//

			explicit	vector(size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) { };

			template<class InIter>
			vector	(InIter first, InIter last, const allocator_type& alloc = allocator_type()) {}

			vector(const vector& other) {}	

			// ~vector() {};

			// operator=() {}

			value_type&	operator[](size_t i) {return _arr[i];}

			// assign() {}

			value_type&	at(size_t i) {
				if (i > _size)
					throw std::out_of_range("....");
				return _arr[i];
			}

			// back() {}

			// iterator&	begin() const {return }

			size_t	capacity() const {return _capacity;}

			// clear() {}

			// empty() {}

			iterator	end() const {return iterator(this + size());}

			// erase() {}

			// frint() {}

			// get_allocator {}

			// insert() {}

			// size_type	max_size() const {return std::numeric_limits<value_type> /sizeof(value_type);}

			void	pop_back() {_arr[--_size].~T();}

			void	push_back(const T& val) {
				if (_size == _capacity)
					reserve(2 * _capacity);
				new(_arr[_size]) T(val);
				++_size;
			}

			// rbegin() {}

			// rend() {}

			void	reserve(size_type n) {
				// if (n > max_size())
				// 	throw std::length_error("Length error: oversize!");
				const allocator_type& alloc = std::allocator<T>();
				if (n > _capacity) {
					T* new_arr = alloc::allocate(n * sizeof(T)));
					//  char[n * sizeof(T)]);
					// int* new_arr = (int*)(new char[n * sizeof(int)]);
					//  T* new_arr = operator new(n * sizeof(T)); // - вроде как альтернатива  вышеописанному
					// Вecm нижеуказанный код содержит в себе uninitialized_copy
					// try {
					// 	uninitialized_copy(_arr, _arr + _size, new_arr);
					// } catch (...) {
					// 	delete[] reinterpret_cast<char*>(new_arr);
					// 	throw;
					// }
					
						size_t i(0);
						try {	
							for (; i < _size; ++i)
							alloc::construct(new_arr[i], _arr[i]);
								new (new_arr[i]) T(_arr[i]);	//placement new (вызов конструктора по по конкретному участку памяти new_arr + i)
						} catch (...) {
							for (;i >= 0; --i)
								new_arr[i].~T();
							delete[] reinterpret_cast<char*>(new_arr);
							// operator delete (new_arr); // - в случае использования operator new()
							throw;
						}
					//
					for (size_t i(0); i < _size; ++i)	//почему не использовать общий i?
						_arr[i].~T();
					delete[] reinterpret_cast<char*>(_arr);
					_arr = new_arr;
					_capacity = n;
				}
			}

			void	resize(size_t n, const T& val = T()) {
				if (n < _size) {
					while (_size > n)
						_arr[--_size].~T(); //Надо ли очищать память по данному адресу? ведь она входит в capacity
				}
				else if (n > _size) {
					if (n > _capacity) {
						reserve(n);
						_capacity = n;
					}
					while (_size < n)
						new(_arr[++_size - 1]) T(val);
				}
			}

			size_t	size() const {return _size;}

			// swap() {}



	};

	// template<class T>
	// T&	swap(const T&) {}

	template<class T>
	std::ostream&	operator<<(const std::ostream& out, const vector<T>& v) {
		return out << v._arr;
	}
};

#endif
