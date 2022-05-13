a:JMS template singleton realization implementation:jctsri:
namespace realizations {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
$FILE_BASE$< A_type >::~$FILE_BASE$() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
$FILE_BASE$< A_type >::$FILE_BASE$() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
$FILE_BASE$< A_type >::$FILE_BASE$( const $FILE_BASE$< A_type > & ) noexept // other
{}

template< class A_type >
const $FILE_BASE$< A_type > &$FILE_BASE$< A_type >::operator =( const $FILE_BASE$< A_type > &other ) noexept {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizations


