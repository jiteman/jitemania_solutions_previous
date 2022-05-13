#pragma once


#include "Ui_output.h"


namespace jmsf {
namespace cule {
namespace user_interfaces {


class Debug_ui_output :
	public Ui_output
{

public:
	// virtual
	~Debug_ui_output() noexcept;
	Debug_ui_output();

protected:
	// virtuals
	void print( const pointing::cShared< texting::Ansii_text > &a_string ) const override final;
	void print( const texting::String_literal &a_string ) const override final;
	//~virtuals

private:
	Debug_ui_output( const Debug_ui_output & ) {}
	const Debug_ui_output &operator =( const Debug_ui_output & ) { return *this; }

};


} // namespace
}
}
