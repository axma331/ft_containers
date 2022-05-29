#ifndef FT_RANDOM_ACCESS_ITERATOR_HPP
# define FT_RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"
// class iterator;

namespace ft
{
	/*Random access iterator*/

	template <class T>
	class random_access_iterator : ft::iterator_traits<T*> {
		typedef typename ft::iterator_traits<T*>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<T*>::value_type		value_type;
		typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
		typedef typename ft::iterator_traits<T*>::pointer			pointer;
		typedef typename ft::iterator_traits<T*>::reference			reference;

	public:
		random_access_iterator() : _ptr(0) {}
		explicit random_access_iterator(pointer ptr) : _ptr(ptr) {}
		random_access_iterator(const random_access_iterator<T>& iter) : _ptr(iter._ptr) {}
		~random_access_iterator() {}

		random_access_iterator<T>&	operator=(const random_access_iterator<T>& iter) {
			if (this == &iter)
				return *this;
			return *(_ptr = iter._ptr);
		}

		reference	operator*() const {
			return	*_ptr;
		}

		// reference	operator->() const {
		// }

		//Так же понимать что делать с конст выражениями?!

		random_access_iterator<T>&	operator++() {
			return ++_ptr;
		}

		random_access_iterator<T>&	operator++(int) {
			random_access_iterator<T> tmp(*this);
			++_ptr;
			return tmp;
		}

		random_access_iterator<T>&	operator--() {
			return --_ptr;
		}

		random_access_iterator<T>&	operator--(int) {
			random_access_iterator<T> tmp(*this);
			--_ptr;
			return tmp;
		}

		random_access_iterator<T>	operator+(difference_type n) const {
			return random_access_iterator<T>(_ptr + n);
		}

		random_access_iterator<T>&	operator+=(difference_type n) {
			_ptr += n;
			return *this;
		}

		random_access_iterator<T>	operator-(difference_type n) const {
			return random_access_iterator<T>(_ptr - n);
		}

		random_access_iterator<T>&	operator-=(difference_type n) {
			_ptr -= n;
			return *this;
		}

		reference	operator[](difference_type n) const {
			return *(*this + n);
		}

		pointer	base() const {
			return _ptr;
		}

		friend bool	operator==(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs);
		friend bool	operator<(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs);

	protected:
		pointer	_ptr;
	};

	template <typename T>
	bool	operator==(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs) {
		return lhs._ptr == rhs._ptr;}

	template <typename T>
	bool	operator!=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs) {
		return !(lhs == rhs);}

	template <typename T>
	bool	operator<(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs) {
		return lhs._ptr < rhs._ptr;}

	template <typename T>
	bool	operator>(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs) {
		return rhs < lhs;}

	template <typename T>
	bool	operator<=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs) {
		return !(rhs < lhs);}

	template <typename T>
	bool	operator>=(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs) {
		return !(lhs < rhs);}

};
#endif
