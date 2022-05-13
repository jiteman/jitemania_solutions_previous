#pragma once


#include "jmsf/texting/String_literal.h"
#include "jmsf/typeing/Naturals.hpp"

#include "jmsf/validating/File_and_line.h"

#include "jmsf/cule/registering/Test_registry.hxx"
#include "Test_fixture.hxx"
#include "Test_disabled.hxx"

#include "jmsf/cule/cule.h"


namespace jmsf {
namespace cule {
namespace testing {


class JMSF_CULE_SHARED_INTERFACE Test {

public:
	static const registering::Test_registry &get_test_registry() noexcept;

public:
	virtual void set_up_fixture() const;
	virtual void tear_down_fixture() const;

public:
	virtual void run() const = 0;

public:
	virtual const texting::String_literal &get_name() const noexcept;
	virtual const texting::String_literal &get_filename() const noexcept;
	virtual typeing::Memory_natural get_line_number() const noexcept;

protected:
	const validating::File_and_line &get_file_and_line() const noexcept;

public:
	virtual ~Test() noexcept;
	Test( const texting::String_literal &test_name, const validating::File_and_line &file_and_line ) noexcept;

private:
	Test( const Test &another ) noexcept;
	const Test &operator =( const Test &another ) noexcept;

private:
	const texting::String_literal _test_name;
	const validating::File_and_line _file_and_line;

private:
	static registering::Test_registry _test_registry;

private: friend Test_disabled;
	Test() noexcept;
	static registering::Test_registry &take_test_registry() noexcept;

};


} // namespace testing
} // namespace cule
} // namespace jmsf
