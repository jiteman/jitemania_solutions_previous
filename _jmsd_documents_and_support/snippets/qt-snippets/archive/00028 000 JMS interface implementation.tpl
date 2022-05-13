a:JMS interface implementation:jcii:
class null_$FILE_BASE$ :
	public $FILE_BASE$,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_$FILE_BASE$ >
{

public:
	// virtuals $FILE_BASE$
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_$FILE_BASE$() noexept {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_$FILE_BASE$ >;
	static null_$FILE_BASE$ *createInstance() noexept {
		return new null_$FILE_BASE$;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_$FILE_BASE$() noexept {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< $FILE_BASE$ > createClone() const noexept {
		return ::jmsf::Proxy< $FILE_BASE$ >::createNonlinkedFor( this );
	}

private:
	null_$FILE_BASE$( const null_$FILE_BASE$ & ) noexept {} // another
	
	const null_$FILE_BASE$ &operator =( const null_$FILE_BASE$ &another ) {
		if ( this == &another ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_$FILE_BASE$::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_$FILE_BASE$ :
	public $FILE_BASE$,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_$FILE_BASE$ > {

public:
	// virtuals ExternalSoftware
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_$FILE_BASE$() noexept {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_$FILE_BASE$ >;
	static exception_$FILE_BASE$ *createInstance() noexept {
		return new exception_$FILE_BASE$;
	}

private:
	exception_$FILE_BASE$() noexept {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< $FILE_BASE$ > createClone() const noexept {
		return ::jmsf::Proxy< $FILE_BASE$ >::createNonlinkedFor( this );
	}

private:
	exception_$FILE_BASE$( const exception_$FILE_BASE$ & ) noexept {} // another

	const exception_$FILE_BASE$ &operator =( const exception_$FILE_BASE$ &another ) {
		if ( &another == this ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_$FILE_BASE$::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
$FILE_BASE$ *$FILE_BASE$::getNull() noexept {
	return null_$FILE_BASE$::instance();
}

// static
$FILE_BASE$ *$FILE_BASE$::getException() noexept {
	return exception_$FILE_BASE$::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


