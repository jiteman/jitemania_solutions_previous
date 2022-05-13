#pragma once


#include "realization_Compiler.hxx"

#include "../Compiler.h"


namespace jmsf {
namespace encodebuba {
namespace informing {
namespace realizing {


class realization_Compiler :
	public Compiler
{

public:
	// virtuals Compiler
//	bool is_detected() const noexcept;
	const ::std::string &get_name() const noexcept;
	const ::std::string &get_version() const noexcept;
	bool is_gcc() const noexcept;
	bool is_visual_cpp() const noexcept;
	//~virtuals Compiler

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual Compiler
	~realization_Compiler() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	realization_Compiler() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_Compiler( const realization_Compiler &another ) noexcept;
	const realization_Compiler &operator =( const realization_Compiler &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
//	bool _is_detected;
	::std::string _name;
	::std::string _version;
	bool _is_gcc;
	bool _is_visual_cpp;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace informing
} // namespace encodebuba
} // namespace jmsf
