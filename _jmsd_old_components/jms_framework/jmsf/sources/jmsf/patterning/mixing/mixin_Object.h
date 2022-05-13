#pragma once


#include "../Object.h"
#include "jmsf/typeing/Boolean.hxx"
//#include "jmsf/texting/String_literal.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace patterning {
namespace mixing {


class JMSF_SHARED_INTERFACE mixin_Object :
	public virtual Object
{

public:
	// virtuals
	typeing::Boolean is_null() const noexcept;
	typeing::Boolean is_exception() const noexcept;

	void throw_if_exception() const;
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	~mixin_Object() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_Object() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
//	static const texting::String_literal MIXIN_OBJECT_COPY_PROHIBITION_IS_VIOLATED;
//	static const char_type *const MIXIN_OBJECT_COPY_PROHIBITION_IS_VIOLATED;

};


} // namespace mixing
} // namespace patterning
} // namespace jmsf
