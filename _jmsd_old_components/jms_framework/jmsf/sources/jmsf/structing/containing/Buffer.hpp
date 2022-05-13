#pragma once

#include "Buffer.hxx"


#include "jmsf/memorying/Awamp.hpp"

//#include "jmsf/memorying/Constructor.hxx"
//#include "jmsf/memorying/Destructor.hxx"
#include "jmsf/memorying/Amp.hxx"
#include "jmsf/memorying/Omp.hxx"


namespace jmsf {
namespace structing {
namespace containing {


template< class A_type >
class Buffer {

public:
	const memorying::Wamp< A_type > &get_array() const noexcept;
	memorying::Wamp< A_type > &take_array() noexcept;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

	// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Buffer() noexcept;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Buffer() noexcept;

private:
	Buffer( const memorying::Amp< A_type > &an_array_memory_pointer ) noexcept;

public:
	static Buffer create( const memorying::Amp< A_type > &an_array_memory_pointer );

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Buffer( const Buffer &another ) noexcept;
	const Buffer &operator =( const Buffer &another ) noexcept;

public:
	Buffer( Buffer &&another ) noexcept;
	Buffer &operator =( Buffer &&another ) noexcept;

	// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Awamp< A_type > _awamp_memory_buffer;

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

	// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace containing
} // namespace structing
} // namespace jmsf
