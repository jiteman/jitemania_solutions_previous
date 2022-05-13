#pragma once


#include "jmsf/typeing/Naturals.hpp"


namespace jmsf {
namespace cule {
namespace to_libs {
namespace system {


class System_time {

	static const typeing::Natural MILLISECONDS_IN_SECOND; // = 1000;

public:
	virtual ~System_time() noexcept;
	System_time() noexcept;

	typeing::Natural getCurrentTimeInMilliseconds() const noexcept;

private:
	System_time( const System_time & ) noexcept;
	const System_time &operator=( const System_time & ) noexcept;

};


} // namespace
}
}
}
