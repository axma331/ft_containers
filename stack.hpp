#ifndef FT_STACK_HPP
# define FT_STACK_HPP

# include <vector>

namespace ft
{
	template <class T, class Container = std::vector<T> >
		class stack {
		public:
			typedef Container	container_type;
			typedef typename container_type::value_type	value_type;
			typedef typename container_type::size_type	size_type;

			explicit	stack(const container_type& contr = container_type()) : _contr(contr) {}
			~stack() {}

			bool				empty() const {return _contr.empty();}
			size_type			size() const {return _contr.size();}
			value_type&			top() {return _contr.back();}
			const value_type&	top() const {return _contr.back();}
			void				push(const value_type& val) {_contr.push_back(val);}
			void				pop() {_contr.pop_back();}

			template <class T1, class Container1>
				friend bool	operator==(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);
			template <class T1, class Container1>
				friend bool	operator<(const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);
		protected:
			container_type _contr;
		};

	template <class T, class Container>
		bool	operator==(const stack<T, Container>& lhs, const  stack<T, Container>& rhs) {
			return lhs._contr == rhs._contr;
		}
	template <class T, class Container>
		bool	operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return lhs._contr < rhs._contr;
		}
	template <class T, class Container>
		bool	operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return !(lhs == rhs);
		}
	template <class T, class Container>
		bool	operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return rhs < lhs;
		}
	template <class T, class Container>
		bool	operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return !(rhs < lhs);
		}
	template <class T, class Container>
		bool	operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
			return !(lhs < rhs);
		}
}

#endif
