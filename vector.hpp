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
			typedef Alloc											allocator_type;
			typedef typename Alloc::value_type						value_type;
			typedef typename Alloc::pointer							pointer;
			typedef typename Alloc::const_pointer					const_pointer;
			typedef typename Alloc::reference						reference;
			typedef typename Alloc::const_reference					const_reference;
			typedef typename Alloc::size_type						size_type;
			typedef typename Alloc::different_type					difference_type;
			typedef ft::random_access_iterator<value_type>			iterator;
			typedef ft::random_access_iterator<const value_type>	const_iterator;
			// typedef ft::reverse_iterator<iterator>				reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		private:
			T*			_arr;
			size_t		_size;
			size_t		_capacity;
			iterator	_first;
			iterator	_last;
			iterator	_end;
		public:
			vector() {};
			explicit	vector(const Alloc& alloc = Alloc()) {};

			explicit	vector(size_t n, const value_type& val = value_type(), const Alloc& alloc = Alloc()) { };

			template<class InIter>
			vector	(InIter first, InIter last, const Alloc& alloc = Alloc()) {}

			vector(const vector& other) {}	

			// ~vector() {};

			// operator=() {}

			reference		operator[](size_t i) {return _arr[i];}
			const_reference	operator[](size_t i) const {return _arr[i];}

			reference		at(size_t i) {
				if (i > _size)
					throw std::out_of_range("....");
				return _arr[i];
			}

			const_reference	at(size_t i) const {
				if (i > _size)
					throw std::out_of_range("....");
				return _arr[i];
			}

			// iterator			begin() {}
			// const_iterator	begin() const {}

			iterator		end() {return iterator(this + size());}
			const_iterator	end() const {return iterator(this + size());}

			// reserve_iterator			rbegin() {}
			// const_reserve_iterator	rbegin() const {}
			
			// reserve_iterator			rend() {}
			// const_reserve_iterator	rend() const {}

			size_type	capacity() const {return _capacity;}

			size_type	size() const {return _size;}

			// size_type	max_size() const {}

			// empty() {}

			// allocator_type	get_allocator {}

			// referense		front() {}
			// const_referense	front() const {}

			// reference		back() {}
			// const_reference	back() const {}

			void	push_back(const T& val) {
				if (_size == _capacity)
					reserve(2 * _capacity);
				new(_arr[_size]) T(val);
				++_size;
			}

			void	pop_back() {_arr[--_size].~T();}

			// template<class InIter>	
			//void	assign(InIter first, InIter last) {}

			// void	assign(size_type n, const value_type& x) {}

			// iterator	insert(iterator it, const value_type& x) {}
			// void		insert(iteratir it, size_type n, const value_type& x) {}
			// template<class InIter>
			// void		insert(iterator it, InIter first, InIter last) {}

			// iterator	erase(iterator it) {}
			// iterator	erase(iterator first, iterator last) {}

			void	reserve(size_type n) {
				// if (n > max_size())
				// 	throw std::length_error("Length error: oversize!");
				const Alloc& alloc = std::allocator<T>();
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

			//void	clear() {}

			//void	swap(vector x) {}
	};

	// template<class T>
	// T&	swap(const T&) {}

	template<class T>
	std::ostream&	operator<<(const std::ostream& out, const vector<T>& v) {
		return out << v._arr;
	}
};

#endif
