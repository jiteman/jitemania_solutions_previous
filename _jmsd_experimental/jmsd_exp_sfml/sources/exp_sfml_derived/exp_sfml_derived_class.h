#pragma once


#include "exp_sfml_base_class.h"


#include "exp_sfml_derived.h"


namespace jmsd {
namespace exp_derived {


class JMSD_EXP_SFML_DERIVED_LIBRARY_TEMPLATE_SHARED_INTERFACE Exp_sfml_derived_class :
	public exp_base::Exp_sfml_base_class
{

public:
	// virtuals Exp_sfml_base_class
	//~virtuals Exp_sfml_base_class

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	char const *say_derived_hello() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual Exp_sfml_base_class
	~Exp_sfml_derived_class() noexcept override;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Exp_sfml_derived_class() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Exp_sfml_derived_class( Exp_sfml_derived_class const &another ) noexcept;
	Exp_sfml_derived_class &operator =( Exp_sfml_derived_class const &another ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	Exp_sfml_derived_class( Exp_sfml_derived_class &&another ) noexcept;
	Exp_sfml_derived_class &operator =( Exp_sfml_derived_class &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace exp_derived
} // namespace jmsd
