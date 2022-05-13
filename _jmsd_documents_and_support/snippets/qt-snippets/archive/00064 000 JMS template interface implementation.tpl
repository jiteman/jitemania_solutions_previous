a:JMS template interface implementation:jctii:
template< class A_type >
class null_$FILE_BASE$ :
	public $FILE_BASE$< A_type >,
	public ::jmsf::patterns::mixins::mixin_null_Object,
	public ::jmsf::patterns::Singleton< null_$FILE_BASE$< A_type > >
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
private: friend ::jmsf::patterns::Singleton< null_$FILE_BASE$< A_type > >;
	static null_$FILE_BASE$ *createInstance() noexept {
		return new null_$FILE_BASE$;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_$FILE_BASE$() noexept {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::pointing::Proxy< $FILE_BASE$ > createClone() const noexept {
		return ::jmsf::pointing::Proxy< $FILE_BASE$ >::createNonlinkedFor( this );
	}

private:
	null_$FILE_BASE$( const null_$FILE_BASE$ & ) noexept {} // another
	
	const null_$FILE_BASE$ &operator =( const null_$FILE_BASE$ &another ) {
		if ( &another == this ) return *this;

		// copy
		::jmsf::validating::Should::neverViolateCopyingProhibition( "null_$FILE_BASE$< A_type >::operator =()", FILE_AND_LINE );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

template< class A_type >
class exception_$FILE_BASE$ :
	public $FILE_BASE$< A_type >,
	public ::jmsf::patterns::mixins::mixin_exception_Object,
	public ::jmsf::patterns::Singleton< exception_$FILE_BASE$< A_type > >
{

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
private: friend ::jmsf::patterns::Singleton< exception_$FILE_BASE$< A_type > >;
	static exception_$FILE_BASE$ *createInstance() noexept {
		return new exception_$FILE_BASE$;
	}

private:
	exception_$FILE_BASE$() noexept {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::pointing::Proxy< $FILE_BASE$ > createClone() const noexept {
		return ::jmsf::pointing::Proxy< $FILE_BASE$ >::createNonlinkedFor( this );
	}

private:
	exception_$FILE_BASE$( const exception_$FILE_BASE$ & ) noexept {} // other

	const exception_$FILE_BASE$ &operator =( const exception_$FILE_BASE$ &other ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::validating::Should::neverViolateCopyingProhibition( "exception_$FILE_BASE$< A_type >::operator =()", FILE_AND_LINE );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< A_type >
$FILE_BASE$< A_type > *$FILE_BASE$< A_type >::getNull() noexept {
	return null_$FILE_BASE$< A_type >::instance();
}

// static
template< A_type >
$FILE_BASE$< A_type > *$FILE_BASE$< A_type >::getException() noexept {
	return exception_$FILE_BASE$< A_type >::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


