#pragma once


#include "Ui_output.h"

#include "jmsf/synchronizing/Event.hxx"

#include <sstream>
#include <memory>
#include <thread>


namespace jmsf {
namespace cule {
namespace user_interfaces {


class Console_ui_output_threaded :
	public Ui_output
{

public:
	void printing_thread();
	void print_maintenance_thread();

public:
	// virtual
	~Console_ui_output_threaded() noexcept;
	Console_ui_output_threaded();


protected:
	// virtuals
	void print( const pointing::cShared< texting::Ansii_text > &a_string ) const override final;
	void print( const texting::String_literal &native_string ) const override final;
	//~virtuals

private:
	void switch_buffers_if_ready() const;

private:
	Console_ui_output_threaded( const Console_ui_output_threaded & ) {}
	const Console_ui_output_threaded &operator=( const Console_ui_output_threaded & ) { return *this; }

private:
	::std::unique_ptr< synchronizing::Event > _resume_event;
	::std::unique_ptr< synchronizing::Event > _is_ready_event;
	mutable ::std::unique_ptr< ::std::stringstream > _local_string;
	mutable ::std::unique_ptr< ::std::stringstream > _remote_string;

	::std::unique_ptr< ::std::thread > _remote_thread;

};


} // namespace
}
}
