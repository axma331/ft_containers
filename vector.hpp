#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

#include <memory>

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector {
		public:
			typedef T	volue_type;
			typedef Allocator	allocator_type;
			typedef typename allocator_type::reference	reference;
			typedef typename allocator_type::const_reference const_reference;

			

	};


};

#endif
