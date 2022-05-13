#pragma once


namespace jmsf {
namespace validating {

// Exceptions hierarchy
// This (Exception) is base exception for JMSF.

// There are two lines of childs:
// 1. Subsystem line: JMSF, CULE, etc.
// 2. Type line: Error, Failure, Inability, etc.

// There are partial implementations:
// 1. ::jmsf::validating::mixing::mixin_Exception - implements storing of the information provided by the exception thrower
// 2. Subsystem (::jmsf::validating::jmsf_Exception, ::jmsf::cule::validating::cule_Exception, etc.) - implement storing of subsystem information
// 3. Type (::jmsf::validating::basing::exception_Error, (...)::exception_Failure, (...)::exception_Inability, etc. ) - implement storing of exception type information

// There are basic classes for creating concrete exception (examples for two subsystems):
// 1. jmsf_Error_exception inherits from jmsf_Exception and basing::exception_Error
// 2. cule_Failure_exception inherits from cule_Exception and basing::exception_Failure
// etc.

// To create concrete exception, do as following:
// 1.
// <subsystem_1>_concrete_(inability)_exception :
//		public ::subsystem_1::validating::subsystem_1_Inability_exception,
//		public ::jmsf::validating::mixing::mixin_Exception
// 2. create method const ::jsmf::pointing::cWeak< ::jmsf::texting::Ansii_text > get_exception_name() const noexcept; returning value of the variable
// 3. in constructor inialize the variable with class name
// done.


class Exception;


} // namespace validating
} // namespace jmsf
