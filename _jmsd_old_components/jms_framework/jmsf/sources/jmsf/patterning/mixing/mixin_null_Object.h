#pragma once


#include "jmsf/patterning/Object.h"

#include "jmsf/typeing/Boolean.hxx"


#include "jmsf/jmsf.h"


namespace jmsf {
namespace patterning {
namespace mixing {


class JMSF_SHARED_INTERFACE mixin_null_Object :
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
	~mixin_null_Object() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_null_Object() noexcept;


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};


} // namespace mixing
} // namespace patterning
} // namespace jmsf
