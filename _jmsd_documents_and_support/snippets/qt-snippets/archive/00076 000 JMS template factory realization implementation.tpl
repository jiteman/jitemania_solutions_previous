a:JMS template factory realization implementation:jctfri:
namespace realizations {


template< class A_type >
::jmsf::pointing::Proxy< $Interface_name$< A_type > > $FILE_BASE$< A_type >::create$Interface_name$() const noexept {
	return ::jmsf::pointing::Proxy< $Interface_name$< A_type > >::createUnique( new realization_$Interface_name$< A_type > );
}

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


