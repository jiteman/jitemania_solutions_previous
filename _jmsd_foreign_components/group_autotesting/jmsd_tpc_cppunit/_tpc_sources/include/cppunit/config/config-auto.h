#pragma once

// linux

#define HAVE_CMATH 1

/* include/cppunit/config-msvc6.h. Manually adapted from
   include/cppunit/config-auto.h */

/* define to 1 if the compiler implements namespaces */
#ifndef CPPUNIT_HAVE_NAMESPACES
#define CPPUNIT_HAVE_NAMESPACES  1
#endif

#ifndef CPPUNIT_HAVE_GCC_ABI_DEMANGLE
#define CPPUNIT_HAVE_GCC_ABI_DEMANGLE 1
#endif

/* define if library uses std::string::compare(string,pos,n) */
#ifdef CPPUNIT_FUNC_STRING_COMPARE_STRING_FIRST
#undef CPPUNIT_FUNC_STRING_COMPARE_STRING_FIRST
#endif

/* Define if you have the <dlfcn.h> header file. */
#ifndef CPPUNIT_HAVE_DLFCN_H
#define CPPUNIT_HAVE_DLFCN_H 1
#endif

#define CPPUNIT_HAVE_SSTREAM 1

/* Name of package */
#ifndef CPPUNIT_PACKAGE
#define CPPUNIT_PACKAGE  "cppunit"
#endif


// Compiler error location format for CompilerOutputter
// See class CompilerOutputter for format.
#define CPPUNIT_COMPILER_LOCATION_FORMAT "%p:%l:"

// Define to 1 if the compiler support C++ style cast.
#define CPPUNIT_HAVE_CPP_CAST 1

/* define to 1 if the compiler has _finite() */
#ifndef CPPUNIT_HAVE__FINITE
#define CPPUNIT_HAVE__FINITE 1
#endif


#ifndef CPPUNIT_NO_TESTPLUGIN
#define CPPUNIT_NO_TESTPLUGIN 1
#endif
