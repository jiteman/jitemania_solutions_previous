#pragma once


#include "jmsf/encodebuba/logging_macroses.h"

#include "jmsf_logging_flags.h"


#if defined( JMSF_LOG_IS_ON )
	#define JMSF_LOG_NAME "jmsf"

	#define JMSF_LOG_OUTPUT( message ) \
		JMSF_ENCODEBUBA_LOG_OUTPUT( JMSF_LOG_NAME, ( message ) )

	#define JMSF_LOG_OUTPUT_TYPED( message, type ) \
		JMSF_ENCODEBUBA_LOG_OUTPUT_TYPED( JMSF_LOG_NAME, ( message ), ( type ) )

	#define JMSF_LOG_CONDITIONAL_OUTPUT( condition, message ) \
		JMSF_ENCODEBUBA_LOG_CONDITIONAL_OUTPUT( JMSF_LOG_NAME, ( condition ), ( message ) )

	#define JMSF_LOG_CONDITIONAL_OUTPUT_TYPED( condition, message, type ) \
		JMSF_ENCODEBUBA_LOG_CONDITIONAL_OUTPUT_TYPED( JMSF_LOG_NAME, ( condition ), ( message ), ( type ) )

#endif

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#if defined( JMSF_IS_PRE_ERROR_LOG_IS_ON )
	#define JMSF_PRE_ERROR_LOG_OUTPUT( message ) \
		JMSF_LOG_OUTPUT( ( message ) )

	#define JMSF_PRE_ERROR_LOG_OUTPUT_TYPED( message, type ) \
		JMSF_LOG_OUTPUT_TYPED( ( message ), ( type ) )

	#define JMSF_PRE_ERROR_LOG_CONDITIONAL_OUTPUT( condition, message ) \
		JMSF_LOG_CONDITIONAL_OUTPUT( ( condition ), ( message ) )

	#define JMSF_PRE_ERROR_LOG_CONDITIONAL_OUTPUT_TYPED( condition, message, type ) \
		JMSF_LOG_CONDITIONAL_OUTPUT_TYPED( ( condition ), ( message ), ( type ) )

#else
	#define JMSF_PRE_ERROR_LOG_OUTPUT( message )
	#define JMSF_PRE_ERROR_LOG_OUTPUT_TYPED( message, type )
	#define JMSF_PRE_ERROR_LOG_CONDITIONAL_OUTPUT( condition, message )
	#define JMSF_PRE_ERROR_LOG_CONDITIONAL_OUTPUT_TYPED( condition, message, type )

#endif


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#if defined( JMSF_SHOULD_IS_PRE_ERROR_LOG_IS_ON )
	#define JMSF_SHOULD_PRE_ERROR_LOG_OUTPUT( message ) \
		JMSF_LOG_OUTPUT( ( message ) )

	#define JMSF_SHOULD_PRE_ERROR_LOG_OUTPUT_TYPED( message, type ) \
		JMSF_LOG_OUTPUT_TYPED( ( message ), ( type ) )

	#define JMSF_SHOULD_PRE_ERROR_LOG_CONDITIONAL_OUTPUT( condition, message ) \
		JMSF_LOG_CONDITIONAL_OUTPUT( ( condition ), ( message ) )

	#define JMSF_SHOULD_PRE_ERROR_LOG_CONDITIONAL_OUTPUT_TYPED( condition, message, type ) \
		JMSF_LOG_CONDITIONAL_OUTPUT_TYPED( ( condition ), ( message ), ( type ) )

#else
	#define JMSF_SHOULD_PRE_ERROR_LOG_OUTPUT( message )
	#define JMSF_SHOULD_PRE_ERROR_LOG_OUTPUT_TYPED( message, type )
	#define JMSF_SHOULD_PRE_ERROR_LOG_CONDITIONAL_OUTPUT( condition, message )
	#define JMSF_SHOULD_PRE_ERROR_LOG_CONDITIONAL_OUTPUT_TYPED( condition, message, type )

#endif


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#if defined( JMSF_INIT_DEINIT_ERROR_LOG_IS_ON )
	#define JMSF_INIT_DEINIT_ERROR_LOG_OUTPUT( message ) \
		JMSF_LOG_OUTPUT( ( message ) )

	#define JMSF_INIT_DEINIT_ERROR_LOG_OUTPUT_TYPED( message, type ) \
		JMSF_LOG_OUTPUT_TYPED( ( message ), ( type ) )

	#define JMSF_INIT_DEINIT_ERROR_LOG_CONDITIONAL_OUTPUT( condition, message ) \
		JMSF_LOG_CONDITIONAL_OUTPUT( ( condition ), ( message ) )

	#define JMSF_INIT_DEINIT_ERROR_LOG_CONDITIONAL_OUTPUT_TYPED( condition, message, type ) \
		JMSF_LOG_CONDITIONAL_OUTPUT_TYPED( ( condition ), ( message ), ( type ) )

#else
	#define JMSF_INIT_DEINIT_ERROR_LOG_OUTPUT( message )
	#define JMSF_INIT_DEINIT_ERROR_LOG_OUTPUT_TYPED( message, type )
	#define JMSF_INIT_DEINIT_ERROR_LOG_CONDITIONAL_OUTPUT( condition, message )
	#define JMSF_INIT_DEINIT_ERROR_LOG_CONDITIONAL_OUTPUT_TYPED( condition, message, type )

#endif
