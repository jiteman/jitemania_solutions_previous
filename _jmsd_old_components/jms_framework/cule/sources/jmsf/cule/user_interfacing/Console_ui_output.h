#pragma once


#include "Ui_output.h"


namespace jmsf {
namespace cule {
namespace user_interfaces {


class Console_ui_output :
	public Ui_output
{

public:
	// virtual
	~Console_ui_output() noexcept;
	Console_ui_output();

protected:
	// virtuals
	void print( const pointing::cShared< texting::Ansii_text > &a_string ) const override final;
	void print( const texting::String_literal &native_string ) const override final;
	//~virtuals

private:
	Console_ui_output( const Console_ui_output & ) {}
	const Console_ui_output &operator=( const Console_ui_output & ) { return *this; }

};


} // namespace
}
}
