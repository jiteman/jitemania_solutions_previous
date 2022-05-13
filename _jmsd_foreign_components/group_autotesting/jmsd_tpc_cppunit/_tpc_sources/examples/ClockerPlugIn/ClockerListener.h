// //////////////////////////////////////////////////////////////////////////
// Header file ClockerListener.h for class ClockerListener
// (c)Copyright 2000, Baptiste Lepilleur.
// Created: 2002/04/19
// //////////////////////////////////////////////////////////////////////////
#ifndef CLOCKERLISTENER_H
#define CLOCKERLISTENER_H

#include <cppunit/TestListener.h>


#include "cuc.h"


class ClockerModel;


/// TestListener that prints a flatten or hierarchical view of the test tree.
class JMSD_CUC_SHARED_INTERFACE ClockerListener : public CPPUNIT_NS::TestListener
{
	double const ACCEPTANCE_TRESHOLD = 2;
	double const FUNCTIONAL_TRESHOLD = 0.2;
	double const TOO_LONG_TRESHOLD = 0.02;

public:
  ClockerListener( ClockerModel *model,
                   bool text,
					bool too_long_only );

  virtual ~ClockerListener();

  void startTestRun( CPPUNIT_NS::Test *test,
                     CPPUNIT_NS::TestResult *eventManager );

  void endTestRun( CPPUNIT_NS::Test *test,
                   CPPUNIT_NS::TestResult *eventManager );

  void startTest( CPPUNIT_NS::Test *test );

  void endTest( CPPUNIT_NS::Test *test );

  void startSuite( CPPUNIT_NS::Test *suite );

  void endSuite( CPPUNIT_NS::Test *suite );

private:
  void printStatistics() const;

  void printTest( int testIndex,
                  const std::string &indentString ) const;

  void printTestIndent( const std::string &indent,
                        const int indentLength ) const;

  void printTime( double time ) const;

  /// Prevents the use of the copy constructor.
  ClockerListener( const ClockerListener &other );

  /// Prevents the use of the copy operator.
  void operator =( const ClockerListener &other );

private:
  ClockerModel *m_model;
  bool m_text;
	bool _too_long_only;
};



// Inlines methods for ClockerListener:
// -----------------------------------



#endif  // CLOCKERLISTENER_H
