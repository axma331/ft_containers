#ifndef FT_REVERSE_ITERATOR_HPP
# define FT_REVERSE_ITERATOR_HPP

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

#endif
