#ifndef FT_ITERATOR_HPP
# define FT_ITERATOR_HPP

#include <cstddef>
#include "utils.hpp"
// #include "random_access_iterator.hpp"
// class random_access_iterator;

namespace ft
{
	/*Iterator tags*/

	struct output_iterator_tag {};
	struct input_iterator_tag {};
	struct forward_iterator_tag			:	input_iterator_tag {};
	struct bidirectional_iterator_tag	:	forward_iterator_tag {};
	struct random_access_iterator_tag	:	bidirectional_iterator_tag {};

	/*Iterator base class*/

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};
	
	/*Iterator traits*/

	template <class Iter>
	struct iterator_traits {
		typedef typename Iter::iterator_category	iterator_category;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
	};

	template <class Iter>
	struct iterator_traits <Iter*> {
		typedef random_access_iterator_tag		iterator_category;
		typedef Iter							value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef Iter*							pointer;
		typedef Iter&							reference;
	};

	template <class Iter>
	struct iterator_traits <const Iter*> {
		typedef random_access_iterator_tag		iterator_category;
		typedef Iter							value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef const Iter*						pointer;
		typedef const Iter&						reference;
	};


	/*Advance*/

	template <class InIter>
	void	_advance(InIter& it, typename iterator_traits<InIter>::difference_type n, input_iterator_tag) {
		for (; n > 0; --n)
			++it;
	}

	template <class BiIter>
	void	_advance(BiIter& it, typename iterator_traits<BiIter>::difference_type n, bidirectional_iterator_tag) {
		for (size_t i(0); i < n; ++i)
			n > 0 ? ++it : --it;
	}

	template <class RanIter>
	void	_advance(RanIter& it, typename iterator_traits<RanIter>::difference_type n, random_access_iterator_tag) {
		it += n;
	}

	template <class Iter, typename Distance>
	void advance(Iter& it, Distance n) {
		_advance(it, n, iterator_traits<Iter>::iterator_category());
	}

	/*Distance*/

	template <class InIter>
	typename iterator_traits<InIter>::difference_type	_dictance(InIter first, InIter last, input_iterator_tag) {
			typename iterator_traits<InIter>::defference_type cnt(0);
			for (; first != last; ++first)
				++cnt;
			return cnt;			
		};

	template <class RanIter>
	typename iterator_traits<RanIter>::difference_type	_dictance(RanIter first, RanIter last, random_access_iterator_tag) {
				return last - first;
		};

	template <class Iter>
	typename iterator_traits<Iter>::difference_type		distance(Iter first, Iter last) {
		return _dictance(first, last, typename iterator_traits<Iter>::iterator_category());
	}

};
#endif
