#pragma once
//------------------


//#include <stdio.h>
//#include <string.h>

//#include "winspe.h"
//#include "my_assert.h"

#include "../Naturals.hpp"
#include "../Bitwise.hpp"

#include "../Boolean.hxx"


namespace jmsf {
namespace typeing {
namespace examples {


//static const char * XMLVERSION = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";

//--------------------------------------------------------------------------
class Char_string {

public:
	Char_string();

private:
	Char_string( Memory_natural buffer_size, Memory_natural buffer_size_increment );	
	Char_string( const char *s );
//	Char_string( const char *fn, const char *mode); // load content of a text file fn
	
public:

public:
	~Char_string();

	Char_string( const Char_string &another );

public:
	void grow( Memory_natural new_size ); // increases the size of the allocated area
	
	void dump();
	
	void operator =( const Char_string & );
	void operator =( const char * );
	void operator =( char );
	
	// built a temporary copy in str_buf the character string as parameter function to be compatible with const char * ex: strcpy (target, my-string);
	operator const char*();
	
	// comparators
	Boolean operator ==( const Char_string &s );
	Boolean operator ==( const char *s );
	Boolean operator !=( const Char_string &s );
	Boolean operator !=( const char *s );
	Boolean operator >( const Char_string &s );
	Boolean operator >( const char *s );
	Boolean operator <( const Char_string & s );
	Boolean operator <( const char *s );
	Boolean operator >=( const Char_string & s );
	Boolean operator >=( const char *s );
	Boolean operator <=( const Char_string &s );
	Boolean operator <=( const char *s );
	
	// append
	void operator +=( char );
	void operator +=( const Char_string & );
	void operator +=( const char * );
	
	// append the type of stream
	Char_string &operator <<(const Char_string&);
	Char_string &operator <<(const char*);
	Char_string &operator <<(char);
	Char_string &operator <<(unsigned char x);
	Char_string &operator <<(int);
	Char_string &operator <<(unsigned int);
	Char_string &operator <<(short x);
	Char_string &operator <<(unsigned short x);
	Char_string &operator <<( long x );
	Char_string &operator <<(unsigned long x);
	Char_string &operator <<(float);
	
	// append the characters to reach a get_length desiree
	Char_string &fill( char c, Memory_natural quantity_of_characters );
	
	// dump stream types	
	Char_string &operator >>( char*);
	Char_string &operator >>( char&);
	Char_string &operator >>(int&);
	Char_string &operator >>(long&);
	Char_string &operator >>(float&);
	Char_string &operator >>(short& x);	
	Char_string &operator >>(unsigned int&);
	Char_string &operator >>(unsigned char& x);	
	Char_string &operator >>(unsigned short& x);	
	Char_string &operator >>(unsigned long& x);
	
	// before emptying the terminator if it exists, otherwise all
	Char_string &get_line( char *bufr, Memory_natural size_buf, char terminator = '\n');
	
	// next read string between c1 and c2 excluded if ok, this contains the following c2, thus avoiding to trample
//	Char_string &get_sentence(char* bufr, int size_buf, char c1='<', char c2= '>');
	
	// read a character
	char item( Memory_natural character_index );
	
	// read / write a character
	char &operator []( Memory_natural character_index );
	
	// get_length of the string without the terminator
	Memory_natural get_length();
	
	// chain get_length with the terminator (depending ostrstream)
	Memory_natural get_full_length();
	
	// test if string empty
	Boolean empty();
	
	// uppercase <-> lowercase
	void upcase();
	void downcase();
	
	// oter and white tab
	void remove_blanks();
	
	// of occurrence research
	Memory_natural index( char c, Memory_natural posdeb = Memory_natural_nil );
	Memory_natural index( const char * , Memory_natural posdeb = Memory_natural_nil );
	Memory_natural index( const Char_string &substring, Memory_natural posdeb = Memory_natural_nil );	
	Boolean contains( const char *c_substring );	
	Boolean contains( const Char_string &substring );
	
	// extracting a substring
	Char_string from( Memory_natural pos ); // extraction from pos included
	Char_string before( Memory_natural pos ); // extraction before pos excluded
	Char_string fromAndBefore( Memory_natural posdeb, Memory_natural posfin ); // extraction from pos included and excluded before pos / YB * 240903 * /	
	Char_string from( char c );	
	Char_string before( char c );	
	Char_string until( char c );

	// modification of the chain: delete, global substitution
	void del( Memory_natural posdeb, Memory_natural len ); // deletion of text
	void gsub( const char *s1, const char *s2 );
	
	// reading pointer character string
	const char *chars();
	
	// reading and tsunami of flags associated to the operator ">>"
	Bitwise< Memory_natural > flags();	
	void reset_flags();
	
	// split on selected separator (default = '').
	// Destroy the pointer after use (if! = NULL) :: by charstring delete_pt (pt)
	// makes the no words in nb_items
//	Char_string *split( short &nb_items, char sep = ' ' );	
	
//	static void delete_pt( const Char_string *pt ); // delete [] pt
	
	//	Manipulation Functions stream or XML documents

// 	// get an XML element, return = offset for the following research, or 0 if not found
// 	int getXMLElement( const char *xmlElementName, Char_string &xmlElement, int fromIndex = 0 );
// 
// 	// get the contents of an XML element if the presence of the tag start and end
// 	bool getXMLElementValue( const char *xmlElementName, Char_string &xmlElementValue, int fromIndex = 0 );
// 
// 	// get the value of an attribute of an XML element
// 	bool getXMLAttributeValue( const char *xmlAttributeName, Char_string &xmlAttributeValue, int fromIndex = 0 );
// 
// 	// Counting occurrences nb XML Elements with or without content, with or without attribute
// 	int	getNbXMLElement( const char *xmlElementName );
// 
// 	// Encoding of an XML element
// 	void setXMLElement( const char *xmlElementName, const char *xmlElementValue );
// 	void setXMLElement( const char *xmlElementName, long xmlElementValue );
// 
// 	// Encoding tag beginning of an XML element
// 	void setBeginXMLElement( const char *xmlElementName );
// 
// 	// Encoding end tag of an XML element
// 	void setEndXMLElement( const char *xmlElementName );
	
	// test flags
	Boolean ok();
    Boolean operator !();

private:
	void init( Memory_natural size, Memory_natural size_grow );
	void copy( const char *s2 );

private:
	Memory_natural _quantity_of_characters; // string get_length
	Memory_natural _character_buffer_size; // allocated space
	Memory_natural _buffer_size_granularity; // expansion grain
	Bitwise< Memory_natural > _operation_result_flags; // E_ErrRead flags after ">>" or get_line (tidal to each assignment "=")
	char *_character_buffer;
	
private:
	static const Memory_natural _read_character_bit_constant;
	static const Memory_natural _read_integer_bit_constant;
	static const Memory_natural _read_floating_point_bit_constant;
	static const Memory_natural _read_multiple_characters_bit_constant;
	static const Memory_natural _open_file_bit_constant;
	static const Memory_natural _read_file_bit_constant;

	enum E_ErrRead {
		read_char = 1,
		read_int = 2,
		read_float = 4,
		read_chars = 8,
		open_file = 0x10, // 16
		read_file = 0x20 }; // 32
		
// friend Char_string operator + (const Char_string&, const Char_string&);
// friend Char_string operator + (const Char_string&, const char*);
// friend Char_string operator + (const char*, const Char_string&);

};

//--------------------------------------------------------------------------

} // namespace examples
} // namespace typeing
} // namespace jmsf
