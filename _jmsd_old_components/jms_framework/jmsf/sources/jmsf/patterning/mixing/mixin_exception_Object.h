#pragma once


#include "jmsf/patterning/Object.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace patterning {
namespace mixing {


class JMSF_SHARED_INTERFACE mixin_exception_Object :
	public virtual Object
{

public:
	// virtuals Object
	typeing::Boolean is_null() const noexcept;
	typeing::Boolean is_exception() const noexcept;

	void throw_if_exception() const;
	//~virtuals	Object

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	~mixin_exception_Object() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_exception_Object() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace mixing
} // namespace patterning
} // namespace jmsf
