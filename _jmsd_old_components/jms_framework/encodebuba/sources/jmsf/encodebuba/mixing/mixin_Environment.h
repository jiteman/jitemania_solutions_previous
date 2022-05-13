#pragma once

#include "mixin_Environment.hxx"


#include "../Environment.h"


#include <cstddef>

#include "jmsf/encodebuba/encodebuba.h"


namespace jmsf {
namespace encodebuba {
namespace mixing {


class JMSF_ENCODEBUBA_SHARED_INTERFACE mixin_Environment :
	virtual public Environment
{

protected:
	static const size_t TOTAL_QUANTITY_OF_CODES = 8;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals Environment
	bool is_ok() const noexcept;
	bool is_not_ok() const noexcept;
	int get_status_code() const noexcept;
	const char *get_status_text_message() const noexcept;
	//~virtuals Environment

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtuals Environment
	void increase_instance_counter() noexcept;
	void decrease_instance_counter() noexcept;
	bool no_valid_instances() const noexcept;
	//~virtuals Environment

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	void initialize_mixin_environment();
	void terminate_mixin_environment() noexcept;
	void set_status_code( int status_code ) noexcept;
	void append_status_text_message( const char *status_text_message ) noexcept;
	size_t get_quantity_of_status_codes() const noexcept;

private:
	virtual void initialize_status_text_messages() = 0;
	virtual int initialize_environment() = 0;
	virtual void terminate_environment() noexcept = 0;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual Environment
	~mixin_Environment() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	mixin_Environment() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	mixin_Environment( const mixin_Environment &another ) noexcept;
	const mixin_Environment &operator =( const mixin_Environment &another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	unsigned int _instance_counter;
	int _status_code;
	size_t _quantity_of_codes;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	const char *_status_text_messages[ TOTAL_QUANTITY_OF_CODES ];

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	void mixin_initialize_status_text_messages();
	int mixin_initialize_environment();
	void mixin_terminate_environment() noexcept;

};


} // namespace mixing
} // namespace encodebuba
} // namespace jmsf
