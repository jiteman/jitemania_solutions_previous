a:JMS factory method template base class implementation:jcfmtbci:
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
$FILE_BASE$< A_type >::~$FILE_BASE$() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
$FILE_BASE$< A_type >::$FILE_BASE$() noexept
{}

// static
template< class A_type >
$FILE_BASE$< A_type > $FILE_BASE$< A_type >::create() noexept {
	return $FILE_BASE$< A_type >();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
$FILE_BASE$< A_type >::$FILE_BASE$( const $FILE_BASE$< A_type > & ) noexept { // another
}

template< class A_type >
const $FILE_BASE$< A_type > &$FILE_BASE$< A_type >::operator =( const $FILE_BASE$< A_type > &another ) noexept {
	if ( &another == this ) return *this;

	// copy
	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

