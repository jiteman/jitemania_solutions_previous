#pragma once


#include "jmsf/typeing/Boolean.hxx"
#include "jmsf/memorying/Destructor.hxx"


#include "jmsf/jmsf.h"


namespace jmsf {
namespace patterning {


class JMSF_SHARED_INTERFACE Object {

public:
	virtual typeing::Boolean is_null() const noexcept = 0;
	virtual typeing::Boolean is_exception() const noexcept = 0;

	virtual void throw_if_exception() const = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// public:
// 	typeing::Boolean isReal() const noexcept;
// 	void _deleteThisIfReal() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected: friend memorying::Destructor< Object >;
	virtual ~Object() noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};


} // namespace patterning
} // namespace jmsf
