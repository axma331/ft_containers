#ifndef FT_ITERATOR_HPP
# define FT_ITERATOR_HPP

#include <cstddef>
#include "utils.hpp"

namespace ft
{
	/*Iterator tags*/

	struct output_iterator_tag {};
	struct input_iterator_tag {};
	struct forward_iterator_tag			:	input_iterator_tag {};
	struct bidirectional_iterator_tag	:	forward_iterator_tag {};
	struct random_access_iterator_tag	:	bidirectional_iterator_tag {};

	/*Iterator traits*/

	template <class Iterator>
	struct iterator_traits {
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	template <class T>
	struct iterator_traits <T*> {
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef T*								pointer;
		typedef T&								reference;
	};

	template <class T>
	struct iterator_traits <const T*> {
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef const T*						pointer;
		typedef const T&						reference;
	};

	/*Iterator base class*/

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct Iterator {
		typedef Category	iterator_category;
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
	};


	/*Reverse iterator*/	//Реализовать после напсиания основного итератора!

	template <class Iterator>
	struct reverse_iterator {
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

		Iterator	Iter;
	};	

	/*Advance*/

	template <class InIter, typename Distance, typename IterCategory>
	void	advance_overload(InIter& it, Distance n, IterCategory) {
		for (size_t i(0); i < n; ++i)
			++it;
	}

	template <class BiIter, typename Distance>
	void	advance_overload(BiIter& it, Distance n, ft::bidirectional_iterator_tag) {
		for (size_t i(0); i < n; ++i)
			n > 0 ? ++it : --it;
	}

	template <class RanIter, typename Distance>
	void	advance_overload(RanIter& it, Distance n, ft::random_access_iterator_tag) {
		n > 0 ? it += n : it -= n;
	}

	template <class Iter, typename Distance>	//??? Почему мы не можем указать просто интовое значение? Нужно ли сравнить с difference_type
	void advance(Iter& it, Distance n) {
		advance_overload(it, n, ft::iterator_traits<Iter>::iterator_category);
	}
	// {	//Second ver.
	// template<class InputIter, typename Distance>
	// void	random_advance(InputIter& it, Distance n) { for (size_t i(0); i <= n; ++i) ++it;}
// 
	// template<class InputIter, typename Distance>
	// void	sequential_advance(InputIter& it, Distance n) {	it +=n; }
// 
	// template <class InputIter, typename Distance>
	// void advance(InputIter& it, Distance n) {
	// 	ft::is_same<typename ft::iterator_traits<InputIter>::iterator_category, ft::random_access_iterator_tag>::value ?
	// 		ft::random_advance(it, n) : ft::sequential_advance(it, n); 	 }
	// }

	/*Distance*/

	template <class Iter, typename IterCategory>
	typename ft::iterator_traits<Iter>::difference_type
		dictance_overload(Iter first, Iter last, IterCategory) {
			if (first < last) {
				size_t i(1);
				Iter cnt = first;
				while (++cnt != last)
					++i;
				return i;
			}
		};

	template <class RanIter>
	typename ft::iterator_traits<RanIter>::difference_type
		dictance_overload(RanIter first, RanIter last, ft::random_access_iterator_tag) {
			if (first < last)
				return last - first;
		};

	template <class Iter>
	typename ft::iterator_traits<Iter>::difference_type	distance(Iter first, Iter last) {	// Прописать исключения
		return dictance_overload(first, last, ft::iterator_traits<Iter>::iterator_category);
	}

	/*Need realisation*/

	// back_inserter
	// front_inserter
	// inserter

};
#endif
