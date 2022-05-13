#pragma once


#include "realization_Memory_model.hxx"

#include "../Memory_model.h"


namespace jmsf {
namespace encodebuba {
namespace informing {
namespace realizing {


class realization_Memory_model :
	public Memory_model
{

public:
	// virtuals Memory_model
	bool is_detected() const noexcept;
	const ::std::string &get_name() const noexcept;
	const ::std::string &get_test_result() const noexcept;
	//~virtuals Memory_model

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual Memory_model
	~realization_Memory_model() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	realization_Memory_model() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	realization_Memory_model( const realization_Memory_model &another ) noexcept;
	const realization_Memory_model &operator =( const realization_Memory_model &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	bool _is_detected;
	::std::string _name;
	::std::string _test_result;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace informing
} // namespace encodebuba
} // namespace jmsf
