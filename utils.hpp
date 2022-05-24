#ifndef FT_UTILS_HPP
# define FT_UTILS_HPP

#include <type_traits>

namespace ft
{
	/*Enable if*/

	template <bool conditional, typename>	//не указано название типа, т.к. не используется, аналогично ли это "typename T = void"?
	struct enable_if;

	template <typename T>
	struct enable_if <true, T> {		//Вероятно красивее было бы написать "is_same<T, T> : ft::true_type"
		typedef T type;
	};

	/*Is same*/

	template <typename T1, typename T2>
	struct is_same {
		static const bool value = false;
	};

	template <typename T>
	struct is_same <T, T> {
		static const bool value = true;
	};

	/*Is integral*/

	template <class T, T v>
	struct integral_constant {
		static const T	value = v;
		typedef const T	value_type;	// При использовании класса std вероятно тут не const
		typedef integral_constant<T, v>	type;

		operator	value_type() const {return value;};	// При использовании класса std подставляется operator bool, а не operator const bool!
		value_type	operator()() const {return value;};	// В std нет выводиться данная перегрузка, может её стоит сделать private
	};

	typedef integral_constant <bool, false>	false_type;
	typedef integral_constant <bool, true>	true_type;

	template <class>
				struct is_integral_type								: false_type {};
	template <>	struct is_integral_type <bool>						: true_type {};
	template <>	struct is_integral_type <char>						: true_type {};		//Вероятно так же стоит напистаь и для
	template <>	struct is_integral_type <char16_t>					: true_type {};		//версий с const, иначе не сзоже с std
	template <>	struct is_integral_type <char32_t>					: true_type {};
	template <>	struct is_integral_type <wchar_t>					: true_type {};
	template <>	struct is_integral_type <signed char>				: true_type {};
	template <>	struct is_integral_type <short int>					: true_type {};
	template <>	struct is_integral_type <int>						: true_type {};
	template <>	struct is_integral_type <long int>					: true_type {};
	template <> struct is_integral_type <long long int>				: true_type {};
	template <> struct is_integral_type <unsigned char>				: true_type {};
	template <>	struct is_integral_type <unsigned short int>		: true_type {};
	template <>	struct is_integral_type <unsigned int>				: true_type {};
	template <>	struct is_integral_type <unsigned long int>			: true_type {};
	template <>	struct is_integral_type <unsigned long long int>	: true_type {};

	template <class T>
	struct is_integral : is_integral_type<T> {};
};

#endif
