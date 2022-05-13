#pragma once


#include "jmsd/platform_support/common_preprocessor_constants.h"


// detect ILP32
#if JMSD_ARCHITECTURE_TYPE == JMSD_ARCHITECTURE_TYPE_INTEL_X86 && defined( JMSD_GNU_CCPP_COMPILER_IS_DETECTED ) || \
	JMSD_ARCHITECTURE_TYPE == JMSD_ARCHITECTURE_TYPE_INTEL_X86 && defined( JMSD_MICROSOFT_VISUAL_CPP_COMPILER_IS_DETECTED )

	#define JMSD_MEMORY_MODEL_IS_ILP32				JMSD_CPP_TRUE
	#define JMSD_MEMORY_MODEL_ILP32_IS_DEFINED		JMSD_CPP_TRUE


	namespace jmsd {
	namespace platform_support {
	namespace memory_models {

		// platform byte
		typedef unsigned char byte_type;

		// Ansii_char, Unicode_char
		typedef char character_type;

		// Shortest_integer, Integer_8_bits, Integer_1_byte
		typedef signed char integer_1_byte_type;

		// Shortest_natural, Natural_8_bits, Natural_1_byte
		typedef unsigned char natural_1_byte_type;

		// Short_integer, Integer_16_bits, Integer_2_bytes
		typedef signed short int integer_2_bytes_type;

		// Short_natural, Natural_16_bits, Natural_2_bytes
		typedef unsigned short int natural_2_bytes_type;

		// Integer, Integer_32_bits, Integer_4_bytes
		typedef signed int integer_4_bytes_type;

		// Natural, Natural_32_bits, Natural_4_bytes
		typedef unsigned int natural_4_bytes_type;

		// Long_integer, Integer_64_bits, Integer_8_bytes
		typedef signed long long integer_8_bytes_type;

		// Long_natural, Natural_64_bits, Natural_8_bytes
		typedef unsigned long long natural_8_bytes_type;

		// Memory_difference
		typedef signed long integer_pointer_type;

		// Memory_size
		typedef unsigned long natural_pointer_type;

		// Real_short
		typedef float real_4_bytes_type;

		// Real
		typedef double real_8_bytes_type;


	} // namespace memory_models
	} // namespace platform_support
	} // namespace jmsd

#else
	#define JMSD_MEMORY_MODEL_ILP32_IS_DEFINED		JMSD_CPP_FALSE

#endif
