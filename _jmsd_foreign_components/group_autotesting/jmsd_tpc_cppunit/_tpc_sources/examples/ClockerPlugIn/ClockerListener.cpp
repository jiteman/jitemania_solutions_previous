// //////////////////////////////////////////////////////////////////////////
// Implementation file ClockerListener.cpp for class ClockerListener
// (c)Copyright 2000, Baptiste Lepilleur.
// Created: 2002/04/19
// //////////////////////////////////////////////////////////////////////////
#include <cppunit/Test.h>
#include <cppunit/portability/Stream.h>
#include "ClockerListener.h"
#include "ClockerModel.h"
#include <stdio.h>


ClockerListener::ClockerListener( ClockerModel *model,
                                  bool text,
	bool const too_long_only )
    : m_model( model )
    , m_text( text ),
		_too_long_only( too_long_only )
{
}


ClockerListener::~ClockerListener()
{
}


void
ClockerListener::startTestRun( CPPUNIT_NS::Test *test,
                               CPPUNIT_NS::TestResult *eventManager )
{
  m_model->setExpectedTestCount( test->countTestCases() *2 );
}


void
ClockerListener::endTestRun( CPPUNIT_NS::Test *test,
                             CPPUNIT_NS::TestResult *eventManager )
{
  if ( m_text )
    printStatistics();
}


void
ClockerListener::startTest( CPPUNIT_NS::Test *test )
{
  m_model->enterTest( test, false );
}


void
ClockerListener::endTest( CPPUNIT_NS::Test *test )
{
  m_model->exitTest( test, false );
}


void
ClockerListener::startSuite( CPPUNIT_NS::Test *suite )
{
  m_model->enterTest( suite, true );
}


void
ClockerListener::endSuite( CPPUNIT_NS::Test *suite )
{
  m_model->exitTest( suite, true );
}


void ClockerListener::printStatistics() const {
	CPPUNIT_NS::stdCOut() << ::std::endl;
	printTest( 0, "" );
	CPPUNIT_NS::stdCOut() << "\n";
	CPPUNIT_NS::stdCOut() << "Total elapsed time: ";
	printTime( m_model->totalElapsedTime() );
	CPPUNIT_NS::stdCOut() << ", average test case time: ";
	printTime( m_model->averageTestCaseTime() );
}


void
ClockerListener::printTest( int const testIndex, ::std::string const &indentString ) const {
	::std::string indent = indentString;
	int const indentLength = 3;

	bool const do_print_this_test =
		!_too_long_only ||
		( m_model->is_leaf( testIndex ) && m_model->testTimeFor( testIndex ) > TOO_LONG_TRESHOLD );

	if ( do_print_this_test ) {
		printTestIndent( indentString, indentLength );
		printTime( m_model->testTimeFor( testIndex ) );

		CPPUNIT_NS::stdCOut() << m_model->testPathFor( testIndex ).getChildTest()->getName();
		CPPUNIT_NS::stdCOut() << "\n";
	}

	if ( m_model->childCountFor( testIndex ) == 0 ) {
		indent += ::std::string( indentLength, ' ' );
	} else {
		indent += "|" + ::std::string( indentLength - 1, ' ' );
	}

	for ( int index = 0; index < m_model->childCountFor( testIndex ); ++index ) {
		printTest( m_model->childAtFor( testIndex, index ), indent );
	}
}


void
ClockerListener::printTestIndent( const std::string &indent,
                                  const int indentLength ) const
{
  if ( indent.empty() )
    return;

  CPPUNIT_NS::stdCOut() << "   ";
  CPPUNIT_NS::stdCOut() << indent.substr( 0, indent.length() - indentLength ) ;
  CPPUNIT_NS::stdCOut() << "+"  <<  std::string( indentLength -1, '-' );
}


void ClockerListener::printTime( double const time ) const {
	CPPUNIT_NS::stdCOut() << '(';

	char const *too_long_test_message = nullptr;
	{
		if ( time > ACCEPTANCE_TRESHOLD ) {
			too_long_test_message =  "[ACCEPTANCE] ";
		} else if ( time > FUNCTIONAL_TRESHOLD ) {
			too_long_test_message =  "[FUNCTIONAL] ";
		} else if ( time > TOO_LONG_TRESHOLD ) {
			too_long_test_message =  "[TOO LONG] ";
		}
	}

	if ( too_long_test_message != nullptr ) {
		CPPUNIT_NS::stdCOut() << too_long_test_message;
	}

	CPPUNIT_NS::stdCOut() << ClockerModel::timeStringFor( time ) << "s) ";
}
