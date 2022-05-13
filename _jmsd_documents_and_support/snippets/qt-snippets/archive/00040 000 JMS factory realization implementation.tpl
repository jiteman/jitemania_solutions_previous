a:JMS factory realization implementation:jcfri:
namespace realizations {

::jmsf::Proxy< $Interface_name$ > $FILE_BASE$::create$Interface_name$() const noexept {
	return ::jmsf::Proxy< $Interface_name$ >::createUnique( new realization_$Interface_name$ );

}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
$FILE_BASE$::~$FILE_BASE$() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
$FILE_BASE$::$FILE_BASE$() noexept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
$FILE_BASE$::$FILE_BASE$( const $FILE_BASE$ & ) noexept // another
{}

const $FILE_BASE$ &$FILE_BASE$::operator =( const $FILE_BASE$ &another ) noexept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace realizations


