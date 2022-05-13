a:JMS template concrete class with factory method implementation:jctccfmi:
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
$FILE_BASE$< A_type >::~$FILE_BASE$() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< class A_type >
::jmsf::Pointer< $FILE_BASE$< A_type > > $FILE_BASE$< A_type >::create() noexept {
	$FILE_BASE$< A_type > *new$FILE_BASE$ = new $FILE_BASE$< A_type >;
	::jmsf::debugging::static_ObjectCreationLogger::registerCreation( ::jmsf::debugging::createMulInformationForUnobjectedCreation( new$FILE_BASE$, MACROS_FILE_AND_LINE ) );
	return ::jmsf::Pointer< $FILE_BASE$< A_type > >::createUnique( new$FILE_BASE$ );
}

template< class A_type >
$FILE_BASE$< A_type >::$FILE_BASE$() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
::jmsf::Pointer< $FILE_BASE$< A_type > > $FILE_BASE$< A_type >::createClone() const noexept {
	$FILE_BASE$< A_type > *new$FILE_BASE$ = new $FILE_BASE$< A_type >( *this );
	::jmsf::debugging::static_ObjectCreationLogger::registerCreation( ::jmsf::debugging::createMulInformationForUnobjectedCreation( new$FILE_BASE$, MACROS_FILE_AND_LINE ) );
	return ::jmsf::Pointer< $FILE_BASE$< A_type > >::createUnique( new$FILE_BASE$ );
}

template< class A_type >
$FILE_BASE$< A_type >::$FILE_BASE$( const $FILE_BASE$< A_type > & ) noexept // another
{}

template< class A_type >
const $FILE_BASE$< A_type > &$FILE_BASE$< A_type >::operator =( const $FILE_BASE$< A_type > &another ) noexept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

