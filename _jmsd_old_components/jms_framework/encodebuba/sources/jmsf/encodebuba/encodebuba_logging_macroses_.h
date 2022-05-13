#pragma once


#include "logging_macroses.h"

#include "encodebuba_logging_flags_.h"


#if defined( ENCODEBUBA_LOG_IS_ON )
	#define ENCODEBUBA_NAME "encodebuba"

	#define ENCODEBUBA_LOG_OUTPUT( message ) \
		JMSF_ENCODEBUBA_LOG_OUTPUT( ENCODEBUBA_NAME, ( message ) )

	#define ENCODEBUBA_LOG_OUTPUT_TYPED( message, type ) \
		JMSF_ENCODEBUBA_LOG_OUTPUT_TYPED( ENCODEBUBA_NAME, ( message ), ( type ) )

	#define ENCODEBUBA_LOG_CONDITIONAL_OUTPUT( condition, message ) \
		JMSF_ENCODEBUBA_LOG_CONDITIONAL_OUTPUT( ENCODEBUBA_NAME, ( condition ), ( message ) )

	#define ENCODEBUBA_LOG_CONDITIONAL_OUTPUT_TYPED( condition, message, type ) \
		JMSF_ENCODEBUBA_LOG_CONDITIONAL_OUTPUT_TYPED( ENCODEBUBA_NAME, ( condition ), ( message ), ( type ) )

	#include "jmsf/encodebuba/validating/macroses_Type_name.h"

	// a_type parameter left without parentheses intentionally
	#define ENCODEBUBA_TYPE( a_type ) \
		JMSF_ENCODEBUBA_TYPE_NAME( a_type )

	#define ENCODEBUBA_TYPE_OBJECT( an_object ) \
		JMSF_ENCODEBUBA_OBJECT_TYPE_NAME( ( an_object ) )

#else
	#define ENCODEBUBA_LOG_OUTPUT( message )
	#define ENCODEBUBA_LOG_OUTPUT_TYPED( message, type )
	#define ENCODEBUBA_LOG_CONDITIONAL_OUTPUT( condition, message )
	#define ENCODEBUBA_LOG_CONDITIONAL_OUTPUT_TYPED( condition, message, type )

#endif


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#if defined( ENCODEBUBA_IS_PRE_ERROR_LOG_IS_ON )
	#define ENCODEBUBA_PRE_ERROR_LOG_OUTPUT( message ) \
		ENCODEBUBA_LOG_OUTPUT( ( message ) )

	#define ENCODEBUBA_PRE_ERROR_LOG_OUTPUT_TYPED( message, type ) \
		ENCODEBUBA_LOG_OUTPUT_TYPED( ( message ), ( type ) )

	#define ENCODEBUBA_PRE_ERROR_LOG_CONDITIONAL_OUTPUT( condition, message ) \
		ENCODEBUBA_LOG_CONDITIONAL_OUTPUT( ( condition ), ( message ) )

	#define ENCODEBUBA_PRE_ERROR_LOG_CONDITIONAL_OUTPUT_TYPED( condition, message, type ) \
		ENCODEBUBA_LOG_CONDITIONAL_OUTPUT_TYPED( ( condition ), ( message ), ( type ) )

#else
	#define ENCODEBUBA_PRE_ERROR_LOG_OUTPUT( message )
	#define ENCODEBUBA_PRE_ERROR_LOG_OUTPUT_TYPED( message, type )
	#define ENCODEBUBA_PRE_ERROR_LOG_CONDITIONAL_OUTPUT( condition, message )
	#define ENCODEBUBA_PRE_ERROR_LOG_CONDITIONAL_OUTPUT_TYPED( condition, message, type )

#endif


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#if defined( ENCODEBUBA_SHOULD_IS_PRE_ERROR_LOG_IS_ON )
	#define ENCODEBUBA_SHOULD_PRE_ERROR_LOG_OUTPUT( message ) \
		ENCODEBUBA_LOG_OUTPUT( ( message ) )

	#define ENCODEBUBA_SHOULD_PRE_ERROR_LOG_OUTPUT_TYPED( message, type ) \
		ENCODEBUBA_LOG_OUTPUT_TYPED( ( message ), ( type ) )

	#define ENCODEBUBA_SHOULD_PRE_ERROR_LOG_CONDITIONAL_OUTPUT( condition, message ) \
		ENCODEBUBA_LOG_CONDITIONAL_OUTPUT( ( condition ), ( message ) )

	#define ENCODEBUBA_SHOULD_PRE_ERROR_LOG_CONDITIONAL_OUTPUT_TYPED( condition, message, type ) \
		ENCODEBUBA_LOG_CONDITIONAL_OUTPUT_TYPED( ( condition ), ( message ), ( type ) )

#else
	#define ENCODEBUBA_SHOULD_PRE_ERROR_LOG_OUTPUT( message )
	#define ENCODEBUBA_SHOULD_PRE_ERROR_LOG_OUTPUT_TYPED( message, type )
	#define ENCODEBUBA_SHOULD_PRE_ERROR_LOG_CONDITIONAL_OUTPUT( condition, message )
	#define ENCODEBUBA_SHOULD_PRE_ERROR_LOG_CONDITIONAL_OUTPUT_TYPED( condition, message, type )

#endif


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#if defined( ENCODEBUBA_INIT_DEINIT_ERROR_LOG_IS_ON )
	#define ENCODEBUBA_INIT_DEINIT_ERROR_LOG_OUTPUT( message ) \
		ENCODEBUBA_LOG_OUTPUT( ( message ) )

	#define ENCODEBUBA_INIT_DEINIT_ERROR_LOG_OUTPUT_TYPED( message, type ) \
		ENCODEBUBA_LOG_OUTPUT_TYPED( ( message ), ( type ) )

	#define ENCODEBUBA_INIT_DEINIT_ERROR_LOG_CONDITIONAL_OUTPUT( condition, message ) \
		ENCODEBUBA_LOG_CONDITIONAL_OUTPUT( ( condition ), ( message ) )

	#define ENCODEBUBA_INIT_DEINIT_ERROR_LOG_CONDITIONAL_OUTPUT_TYPED( condition, message, type ) \
		ENCODEBUBA_LOG_CONDITIONAL_OUTPUT_TYPED( ( condition ), ( message ), ( type ) )

#else
	#define ENCODEBUBA_INIT_DEINIT_ERROR_LOG_OUTPUT( message )
	#define ENCODEBUBA_INIT_DEINIT_ERROR_LOG_OUTPUT_TYPED( message, type )
	#define ENCODEBUBA_INIT_DEINIT_ERROR_LOG_CONDITIONAL_OUTPUT( condition, message )
	#define ENCODEBUBA_INIT_DEINIT_ERROR_LOG_CONDITIONAL_OUTPUT_TYPED( condition, message, type )

#endif
