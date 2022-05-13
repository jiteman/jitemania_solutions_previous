a:JMS concrete class with factory method implementation:jcccfmi:
class $FILE_BASE$ {
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
$FILE_BASE$::~$FILE_BASE$() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
::jmsf::Pointer< $FILE_BASE$ > $FILE_BASE$::create() noexept {
	$FILE_BASE$ *new$FILE_BASE$ = new $FILE_BASE$;
	::jmsf::debugging::static_ObjectCreationLogger::registerCreation( ::jmsf::debugging::createMulInformationForUnobjectedCreation( new$FILE_BASE$, MACROS_FILE_AND_LINE ) );
	return ::jmsf::Pointer< $FILE_BASE$ >::createUnique( new$FILE_BASE$ );
}

$FILE_BASE$::$FILE_BASE$() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Pointer< $FILE_BASE$ > $FILE_BASE$::createClone() const noexept {
	$FILE_BASE$ *new$FILE_BASE$ = new $FILE_BASE$( *this );
	::jmsf::debugging::static_ObjectCreationLogger::registerCreation( ::jmsf::debugging::createMulInformationForUnobjectedCreation( new$FILE_BASE$, MACROS_FILE_AND_LINE ) );
	return ::jmsf::Pointer< $FILE_BASE$ >::createUnique( new$FILE_BASE$ );
}

$FILE_BASE$::$FILE_BASE$( const $FILE_BASE$ & ) noexept // another
{}

const $FILE_BASE$ &$FILE_BASE$::operator =( const $FILE_BASE$ &another ) noexept {
	if ( this == &another ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

