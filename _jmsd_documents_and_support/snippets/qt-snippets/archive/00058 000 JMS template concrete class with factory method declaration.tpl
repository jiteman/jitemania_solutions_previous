a:JMS template concrete class with factory method declaration:jctccfmd:
template< class A_type >
class $FILE_BASE$ {

public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend ::jmsf::DeleterForPointer< $FILE_BASE$< A_type > >;
	~$FILE_BASE$() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static ::jmsf::Pointer< $FILE_BASE$ > create() noexept;

private:
	$FILE_BASE$() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	::jmsf::Pointer< $FILE_BASE$ > createClone() const noexept;

private:
	$FILE_BASE$( const $FILE_BASE$ &another ) noexept;
	const $FILE_BASE$ &operator =( const $FILE_BASE$ &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

