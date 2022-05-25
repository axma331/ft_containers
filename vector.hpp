#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <memory>
#include "iterators.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename ft::iterator_traits<T>::volue_type	iterator;
			// typedef 	const_iterator;
			// typedef 	reverse_iterator;
			// typedef 	const_reverse_iterator;
			// typedef 	difference_type;
			typedef size_t	size_type;



			//	Capacity:
			size_type	size() const {
				return _size;
			}

			size_type	capacity() const {
				return _capacity;
			}

			resize(size_type n, value_type val = value_type()) {
				if (n < _size) {
					while (--_size > n)
						_dynamic_arry[_size] = 0;
				}
				else if (n > _size) {
					if (n < _capacity) {

					}
					else {

					}
				}
			}

			reserve(size_type n) {
				if (n > max_size())
					throw std::length_error("Length error: oversize!");
				if (n > _capacity) {
					value_type* new_array = reinterpret_cast<value_type*>(new int8_t(n * sizof(value_type)));
					for (size_type i(0); i < _size; ++i)
						new(new_array + i) value_type(_dynamic_arry[i]);	//placement new (вызов конструктора по по конкретному участку памяти new_array + i)
					for (size_type i(0); i < _size; ++i)
						_dynamic_arry[i].~value_type();
					delete [] reinterpret_cast<int8_t*>(_dynamic_arry);
					_dynamic_arry = new_array;
					_capacity = n;
				}

			}

			// size_type	max_size() const {return std::numeric_limits<value_type> /sizeof(value_type);}

			vector() {}
			~vector() {}
		private:
			T*	_dynamic_arry;
			size_t	_size;
			size_t	_capacity;
	};
};

#endif
