#pragma once

#include "Environment.hxx"


#include "encodebuba.h"


namespace jmsf {
namespace encodebuba {


class JMSF_ENCODEBUBA_SHARED_INTERFACE Environment {

public:
	virtual bool is_ok() const noexcept = 0;
	virtual bool is_not_ok() const noexcept = 0;
	virtual int get_status_code() const noexcept = 0;
	virtual const char *get_status_text_message() const noexcept = 0;

	virtual void increase_instance_counter() noexcept = 0;
	virtual void decrease_instance_counter() noexcept = 0;
	virtual bool no_valid_instances() const noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	virtual ~Environment() noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace encodebuba
} // namespace jmsf
