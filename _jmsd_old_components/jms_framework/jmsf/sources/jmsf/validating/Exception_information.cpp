#include "Exception_information.h"


#include "jmsf/pointing/cWeak.hin"
#include "jmsf/pointing/cShared.hin"
#include "jmsf/memorying/Constructor.hin"
#include "jmsf/typeing/Naturals.hin"

#include "jmsf/validating/macroses_Should.h"

#include "jmsf/encodebuba/validating/native_Exception.h"


namespace jmsf {
namespace validating {


const pointing::cWeak< texting::Ansii_text > Exception_information::get_reason_description() const noexcept {
	if ( _reason_description.is_empty() ) return pointing::cWeak< texting::Ansii_text >();

	return _reason_description.get_as_cweak();
}

const pointing::cWeak< texting::Ansii_text > Exception_information::get_detailed_description() const noexcept {
	if ( _detailed_description.is_empty() ) return pointing::cWeak< texting::Ansii_text >();

	return _detailed_description.get_as_cweak();
}

const pointing::cWeak< texting::Ansii_text > Exception_information::get_type_information() const noexcept {
	if ( _type_information.is_empty() ) return pointing::cWeak< texting::Ansii_text >();

	return _type_information.get_as_cweak();
}

const pointing::cWeak< texting::Ansii_text > Exception_information::get_filename() const noexcept {
	if ( _filename.is_empty() ) return pointing::cWeak< texting::Ansii_text >();

	return _filename.get_as_cweak();
}

typeing::Memory_natural Exception_information::get_line_number() const noexcept {
	return _line_number;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
const pointing::cWeak< texting::Ansii_text > Exception_information::get_exception_name() const noexcept {
	if ( _exception_name.is_empty() ) return pointing::cWeak< texting::Ansii_text >();

	return _exception_name.get_as_cweak();
}

const pointing::cWeak< texting::Ansii_text > Exception_information::get_exception_category() const noexcept {
	if ( _exception_category.is_empty() ) return pointing::cWeak< texting::Ansii_text >();

	return _exception_category.get_as_cweak();
}

const pointing::cWeak< texting::Ansii_text > Exception_information::get_exception_subsystem() const noexcept {
	if ( _exception_subsystem.is_empty() ) return pointing::cWeak< texting::Ansii_text >();

	return _exception_subsystem.get_as_cweak();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Exception_information::~Exception_information() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Exception_information::Exception_information() noexcept
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Exception_information::Exception_information(
	const pointing::cShared< texting::Ansii_text > &reason_description,
	const pointing::cShared< texting::Ansii_text > &detailed_description,
	const pointing::cShared< texting::Ansii_text > &type_information,
	const pointing::cShared< texting::Ansii_text > &filename,
	const typeing::Memory_natural line_number,
	const pointing::cShared< texting::Ansii_text > &exception_name,
	const pointing::cShared< texting::Ansii_text > &exception_category,
	const pointing::cShared< texting::Ansii_text > &exception_subsystem ) noexcept
	:
		_reason_description( reason_description ),
		_detailed_description( detailed_description ),
		_type_information( type_information ),
		_filename( filename ),
		_line_number( line_number ),
		_exception_name( exception_name ),
		_exception_category( exception_category ),
		_exception_subsystem( exception_subsystem )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
const pointing::cShared< Exception_information > Exception_information::create_from_exception(
	const memorying::Womp< memorying::Allocator > &reference_counted_omp_allocator,
	const memorying::Womp< memorying::Allocator > &exception_information_allocator,
	const Exception &original_exception )
{
	jmsf_Should_never_be_empty( reference_counted_omp_allocator );
	jmsf_Should_never_be_empty( exception_information_allocator );

	return
		pointing::cShared< Exception_information >::create(
			reference_counted_omp_allocator,
			memorying::Constructor< Exception_information, Exception_information >::construct(
				exception_information_allocator,
				original_exception.get_reason_description().get_as_cshared(),
				original_exception.get_detailed_description().get_as_cshared(),
				original_exception.get_type_information().get_as_cshared(),
				original_exception.get_filename().get_as_cshared(),
				original_exception.get_line_number(),
				original_exception.get_exception_name().get_as_cshared(),
				original_exception.get_exception_category().get_as_cshared(),
				original_exception.get_exception_subsystem().get_as_cshared() ) );
}

// static
const pointing::cShared< Exception_information > Exception_information::create_from_native_exception(
	const memorying::Womp< memorying::Allocator > &reference_counted_omp_allocator,
	const memorying::Womp< memorying::Allocator > &exception_information_allocator,
	const memorying::Womp< texting::Ansii_allocating_assistor > &ansii_allocating_assistor,
	const encodebuba::validating::native_Exception &original_native_exception )
{
	jmsf_Should_never_be_empty( reference_counted_omp_allocator );
	jmsf_Should_never_be_empty( exception_information_allocator );
	jmsf_Should_never_be_empty( ansii_allocating_assistor );

	const memorying::Womp< texting::Ansii_allocating_assistor > &the_aaa = ansii_allocating_assistor;

	return
		pointing::cShared< Exception_information >::create(
			reference_counted_omp_allocator,
			memorying::Constructor< Exception_information, Exception_information >::construct(
				exception_information_allocator,
				texting::Aaa_sl( the_aaa, JMSF_SL( original_native_exception.get_reason_description() ) ),
				texting::Aaa_sl( the_aaa, JMSF_SL( original_native_exception.get_reason_description() ) ), // no detailed description
				texting::Aaa_sl( the_aaa, JMSF_SL( original_native_exception.get_type_information() ) ),
				texting::Aaa_sl( the_aaa, JMSF_SL( original_native_exception.get_filename() ) ),
				typeing::Memory_natural::create( original_native_exception.get_line_number() ),
				texting::Aaa_sl( the_aaa, JMSF_SL( original_native_exception.get_exception_name() ) ),
				texting::Aaa_sl( the_aaa, JMSF_SL( original_native_exception.get_exception_category() ) ),
				texting::Aaa_sl( the_aaa, JMSF_SL( original_native_exception.get_exception_subsystem() ) ) ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Exception_information::Exception_information( const Exception_information &/*another*/ ) noexcept {
//}

//const Exception_information &Exception_information::operator =( const Exception_information &another ) noexcept {
//	if ( &another == this ) return *this;

//	// copy
//	return *this;
//}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Exception_information::Exception_information( Exception_information &&/*another*/ ) noexcept {
//}

//Exception_information &Exception_information::operator =( Exception_information &&another ) noexcept {
//	if ( &another == this ) return *this;

//	// move
//	return *this;
//}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace validating
} // namespace jmsf

