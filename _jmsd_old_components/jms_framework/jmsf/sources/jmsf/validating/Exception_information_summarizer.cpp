#include "Exception_information_summarizer.h"


#include "jmsf/texting/Ansii_stream.hin"


namespace jmsf {
namespace validating {

// static
pointing::cShared< texting::Ansii_text > Exception_information_summarizer::create_file_and_line_summary(
	const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa,
	const pointing::cShared< texting::Ansii_text > &a_filename,
	typeing::Memory_natural a_line_number ) noexcept
{
	pointing::Shared< texting::Ansii_stream > ansii_stream = an_aaa->create_ansii_stream();

	ansii_stream->put( a_filename );
	ansii_stream->put( texting::Aaa_sl( an_aaa, JMSF_SL( "( " ) ) );
	ansii_stream->put( a_line_number );
	ansii_stream->put( texting::Aaa_sl( an_aaa, JMSF_SL( " )" ) ) );

	return texting::Aaa_cs( an_aaa, ansii_stream );
}

// static
pointing::cShared< texting::Ansii_text > Exception_information_summarizer::create_reason_description_summary(
	const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa,
	const pointing::cShared< texting::Ansii_text > &a_reason_description ) noexcept
{
	pointing::Shared< texting::Ansii_stream > ansii_stream = an_aaa->create_ansii_stream();

	ansii_stream->put( texting::Aaa_sl( an_aaa, JMSF_SL( "Reason: " ) ) );
	ansii_stream->put( a_reason_description );

	return texting::Aaa_cs( an_aaa, ansii_stream );
}

// static
pointing::cShared< texting::Ansii_text > Exception_information_summarizer::create_detailed_description_summary(
	const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa,
	const pointing::cShared< texting::Ansii_text > &a_detailed_description ) noexcept
{
	pointing::Shared< texting::Ansii_stream > ansii_stream = an_aaa->create_ansii_stream();

	ansii_stream->put( texting::Aaa_sl( an_aaa, JMSF_SL( "Details: " ) ) );
	ansii_stream->put( a_detailed_description.is_empty() ? texting::Aaa_sl( an_aaa, JMSF_SL( "no details" ) ) : a_detailed_description );

	return texting::Aaa_cs( an_aaa, ansii_stream );
}

// static
pointing::cShared< texting::Ansii_text > Exception_information_summarizer::create_type_information_summary(
	const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa,
	const pointing::cShared< texting::Ansii_text > &a_type_information ) noexcept
{
	pointing::Shared< texting::Ansii_stream > ansii_stream = an_aaa->create_ansii_stream();

	ansii_stream->put( texting::Aaa_sl( an_aaa, JMSF_SL( "Type: " ) ) );
	ansii_stream->put( a_type_information.is_empty() ? texting::Aaa_sl( an_aaa, JMSF_SL( "no type information" ) ) : a_type_information );

	return texting::Aaa_cs( an_aaa, ansii_stream );
}

// static
pointing::cShared< texting::Ansii_text > Exception_information_summarizer::create_exception_hierarchy_summary(
	const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa,
	const pointing::cShared< texting::Ansii_text > &a_subsystem,
	const pointing::cShared< texting::Ansii_text > &a_category,
	const pointing::cShared< texting::Ansii_text > &a_name ) noexcept
{
	const pointing::cShared< texting::Ansii_text > space_slash_space = texting::Aaa_sl( an_aaa, JMSF_SL( " / " ) );
	pointing::Shared< texting::Ansii_stream > ansii_stream = an_aaa->create_ansii_stream();

	ansii_stream->put( texting::Aaa_sl( an_aaa, JMSF_SL( "Exception hierarchy: " ) ) );
	ansii_stream->put( a_subsystem );
	ansii_stream->put( space_slash_space );
	ansii_stream->put( a_category );
	ansii_stream->put( space_slash_space );
	ansii_stream->put( a_name );

	return texting::Aaa_cs( an_aaa, ansii_stream );
}

// static
pointing::cShared< texting::Ansii_text > Exception_information_summarizer::create_all_summary(
	const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa,
	const pointing::cShared< texting::Ansii_text > &a_filename,
	typeing::Memory_natural a_line_number,
	const pointing::cShared< texting::Ansii_text > &a_reason_description,
	const pointing::cShared< texting::Ansii_text > &a_detailed_description,
	const pointing::cShared< texting::Ansii_text > &a_type_information,
	const pointing::cShared< texting::Ansii_text > &a_subsystem,
	const pointing::cShared< texting::Ansii_text > &a_category,
	const pointing::cShared< texting::Ansii_text > &a_name ) noexcept
{
	const pointing::cShared< texting::Ansii_text > semicolon_and_space = texting::Aaa_sl( an_aaa, JMSF_SL( "; " ) );
	pointing::Shared< texting::Ansii_stream > ansii_stream = an_aaa->create_ansii_stream();

	ansii_stream->put( create_file_and_line_summary( an_aaa, a_filename, a_line_number ) );
	ansii_stream->put( semicolon_and_space );
	ansii_stream->put( create_reason_description_summary( an_aaa, a_reason_description ) );
	ansii_stream->put( semicolon_and_space );
	ansii_stream->put( create_detailed_description_summary( an_aaa, a_detailed_description ) );
	ansii_stream->put( semicolon_and_space );
	ansii_stream->put( create_type_information_summary( an_aaa, a_type_information ) );
	ansii_stream->put( semicolon_and_space );
	ansii_stream->put( create_exception_hierarchy_summary( an_aaa, a_subsystem, a_category, a_name ) );

	return texting::Aaa_cs( an_aaa, ansii_stream );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
pointing::cShared< texting::Ansii_text > Exception_information_summarizer::get_file_and_line_summary(
	const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const noexcept
{
	return
		create_file_and_line_summary(
			an_aaa,
			_the_exception_information->get_filename().get_as_cshared(),
			_the_exception_information->get_line_number() );
}

pointing::cShared< texting::Ansii_text > Exception_information_summarizer::get_reason_description_summary(
	const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const noexcept
{
	return
		create_reason_description_summary(
			an_aaa,
			_the_exception_information->get_reason_description().get_as_cshared() );
}

pointing::cShared< texting::Ansii_text > Exception_information_summarizer::get_detailed_description_summary(
	const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const noexcept
{
	return
		create_detailed_description_summary(
			an_aaa,
			_the_exception_information->get_detailed_description().get_as_cshared() );
}

pointing::cShared< texting::Ansii_text > Exception_information_summarizer::get_type_information_summary(
	const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const noexcept
{
	return
		create_type_information_summary(
			an_aaa,
			_the_exception_information->get_type_information().get_as_cshared() );
}

pointing::cShared< texting::Ansii_text > Exception_information_summarizer::get_exception_hierarchy_summary(
	const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const noexcept
{
	return
		create_exception_hierarchy_summary(
			an_aaa,
			_the_exception_information->get_exception_subsystem().get_as_cshared(),
			_the_exception_information->get_exception_category().get_as_cshared(),
			_the_exception_information->get_exception_name().get_as_cshared() );
}

pointing::cShared< texting::Ansii_text > Exception_information_summarizer::get_all_summary(
	const memorying::Womp< texting::Ansii_allocating_assistor > &an_aaa ) const noexcept
{
	return
		create_all_summary(
			an_aaa,
			_the_exception_information->get_filename().get_as_cshared(),
			_the_exception_information->get_line_number(),
			_the_exception_information->get_reason_description().get_as_cshared(),
			_the_exception_information->get_detailed_description().get_as_cshared(),
			_the_exception_information->get_type_information().get_as_cshared(),
			_the_exception_information->get_exception_subsystem().get_as_cshared(),
			_the_exception_information->get_exception_category().get_as_cshared(),
			_the_exception_information->get_exception_name().get_as_cshared() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Exception_information_summarizer::~Exception_information_summarizer() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Exception_information_summarizer::Exception_information_summarizer(
	const memorying::Womp< memorying::Allocator > &a_reference_counters_allocator,
	const memorying::Womp< memorying::Allocator > &an_exception_information_allocator,
	const Exception &an_exception ) noexcept
	:
		_the_exception_information(
			Exception_information::create_from_exception(
				a_reference_counters_allocator,
				an_exception_information_allocator,
				an_exception ) )
{}

Exception_information_summarizer::Exception_information_summarizer(
	const pointing::cShared< Exception_information > &an_exception_information ) noexcept
	:
		_the_exception_information( an_exception_information )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Exception_information_summarizer::Exception_information_summarizer( const Exception_information_summarizer &/*another*/ ) noexcept {
//}

//const Exception_information_summarizer &Exception_information_summarizer::operator =( const Exception_information_summarizer &another ) noexcept {
//	if ( &another == this ) return *this;

//	// copy
//	return *this;
//}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Exception_information_summarizer::Exception_information_summarizer( Exception_information_summarizer &&/*another*/ ) noexcept {
//}

//Exception_information_summarizer &Exception_information_summarizer::operator =( Exception_information_summarizer &&another ) noexcept {
//	if ( &another == this ) return *this;

//	// move
//	return *this;
//}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace validating
} // namespace jmsf
