#pragma once


// Message prior error in code
//#define JMSF_IS_PRE_ERROR_LOG_IS_ON

// Message prior exception in Should
//#define JMSF_SHOULD_IS_PRE_ERROR_LOG_IS_ON

// Message for initialization/deinitialization
#define JMSF_INIT_DEINIT_ERROR_LOG_IS_ON


#if \
	defined( JMSF_IS_PRE_ERROR_LOG_IS_ON ) || \
	defined( JMSF_SHOULD_IS_PRE_ERROR_LOG_IS_ON ) || \
	defined( JMSF_INIT_DEINIT_ERROR_LOG_IS_ON )

	#define JMSF_LOG_IS_ON

#endif
