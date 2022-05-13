#include "vbo.h"

#include "Polygon.h"
#include "Bases.h"
#include "Missiles.h"
#include "DrawPolygon.h"
#include "warfog.h"

#include "open_gl.h"

#include <malloc.h>
#include <cassert>

#include "include_Windows.h"

VBO_drawer vbo;

void transfering_to_vector_addElementVBO_2(
	::std::vector< float > const &element,
	::std::vector< ::std::vector< float > > *vectorArray,
	::std::vector< int > *indexArray )
{
	assert( vectorArray != nullptr );
	assert( indexArray != nullptr );

	if ( vectorArray == nullptr || indexArray == nullptr ) return;

	const size_t sizeOfNewElement = element.size();
	const size_t vectorArraySize = vectorArray->size();
	size_t vectorArrayCounter = 0;

	for (
		std::vector< std::vector< float > >::iterator vectorArrayIterator = vectorArray->begin();
		vectorArrayIterator != vectorArray->end();
		++vectorArrayIterator )
	{
		std::vector< float > &floats = *vectorArrayIterator;
		std::vector< float >::iterator floatIterator = floats.begin();
		std::vector< float >::const_iterator elementIterator = element.begin();

		for ( ;
			floatIterator != floats.end();
			++floatIterator )
		{
			if ( ::abs( *floatIterator - *elementIterator ) > SMALLEST_FLOAT ) {
				break;
			}
		}

		if ( elementIterator == element.end() ) {
			indexArray->push_back( static_cast< int >( vectorArrayCounter ) );
		}

		vectorArrayCounter += 1;
	}

	vectorArray->push_back( element );
}

void transfering_to_vector_addElementVBO_1( float *el, const size_t sizeOfElement, float **arr, int **ind ) {
	const int size = sizeof( float ) * sizeOfElement;

	size_t n = 0;

	if ( *arr ) {
		n = _msize( *arr ) / size;
	}

	size_t index = 0;

	for ( index = 0; index < n; index += 1 ) {
		size_t j = 0;

		for ( j = 0; j < sizeOfElement; j += 1 ) {
			if ( ::abs( el[ j ] - ( *arr )[ index * sizeOfElement + j ] ) > 0.0001f ) {
				break;
			}
		}

		if ( j == sizeOfElement ) {
			AddElem( static_cast< int >( index ), ind );
			return;
		}
	}

	AddElem( static_cast< int >( index ), ind );

	for ( size_t j = 0; j < sizeOfElement; j += 1 ) {
		AddElem( el[ j ], arr );
	}
}

void AddElemVBO(float* el,int el_size,float**arr,int**ind)
{
	int sz=(sizeof(float)*el_size);
	int i,j,n=0;
	if(*arr)n=(int)(_msize(*arr))/sz;
	for(i=0;i<n;i++)
	{
		for(j=0;j<el_size;j++)
			if(abs(el[j]-(*arr)[i*el_size+j])>0.0001f)break;
		if(j==el_size)
		{
			AddElem(i,ind);
			return;
		}
	}
	AddElem(i,ind);
	for(j=0;j<el_size;j++)
		AddElem(el[j],arr);
}

void VBO_drawer::InitUnitsVBO() {
//	int ij;
	tka quad[]={tka(-1,-1),tka(1,-1),tka(1,1),tka(-1,1)};
	tka un_txt[UNIT_TYPES][4][4];
	int quad_i[]={0,1,3,2};

	for ( size_t i = 0; i < UNIT_TYPES; i+= 1 ) {
		::glGenBuffersARB( 4, un_txtId[ i ] );
	}

	::glBindBufferARB( GL_ARRAY_BUFFER_ARB, vertexId[ 0 ] );
	::glBufferDataARB( GL_ARRAY_BUFFER_ARB, 4 * sizeof( tka ), quad, GL_STATIC_DRAW_ARB );

	::glBindBufferARB ( GL_ELEMENT_ARRAY_BUFFER_ARB, indexId[ 0 ] );
	::glBufferDataARB ( GL_ELEMENT_ARRAY_BUFFER_ARB, 4 * sizeof( int ), quad_i, GL_STATIC_DRAW_ARB );

	for ( size_t i = 0; i < UNIT_TYPES; i += 1 ) {
		for ( size_t j = 0; j < 4; j += 1 ) {
			( un_txt[ i ][ j ] )->setBoth( static_cast< float >( i ) / UNIT_TYPES, static_cast< float >( 3 - j ) / 4 );
			( un_txt[ i ][ j ] + 1 )->setBoth( static_cast< float >( i + 1 ) / UNIT_TYPES, static_cast< float >( 3 - j ) / 4 );
			( un_txt[ i ][ j ] + 2 )->setBoth( static_cast< float >( i + 1 ) / UNIT_TYPES, static_cast< float >( 4 - j ) / 4 );
			( un_txt[ i ][ j ] + 3 )->setBoth( static_cast< float >( i ) / UNIT_TYPES, static_cast< float >( 4 - j ) / 4 );

			::glBindBufferARB( GL_ARRAY_BUFFER_ARB, un_txtId[ i ][ j ] );
			::glBufferDataARB( GL_ARRAY_BUFFER_ARB, 4 * sizeof( tka ), un_txt[ i ][ j ], GL_STATIC_DRAW_ARB );
		}
	}
}

void VBO_drawer::InitBasesVBO()
{
	int i;
	tka quad[]={tka(-BASE_SIZE,-BASE_SIZE),tka(BASE_SIZE,-BASE_SIZE),tka(BASE_SIZE,BASE_SIZE),tka(-BASE_SIZE,BASE_SIZE)};
	tka b_txt[BASE_LEVEL_NUM][4];
	int quad_i[]={0,1,3,2};
	glGenBuffersARB (BASE_LEVEL_NUM, b_txtId);

	glBindBufferARB ( GL_ARRAY_BUFFER_ARB, vertexId[1] );
	glBufferDataARB ( GL_ARRAY_BUFFER_ARB, 4 * sizeof ( tka ), quad, GL_STATIC_DRAW_ARB );
	glBindBufferARB ( GL_ELEMENT_ARRAY_BUFFER_ARB, indexId[1] );
	glBufferDataARB ( GL_ELEMENT_ARRAY_BUFFER_ARB, 4 * sizeof ( int ), quad_i, GL_STATIC_DRAW_ARB );
	for(i=0;i<BASE_LEVEL_NUM;i++)
	{
		(b_txt[i])->setBoth(float(i)/BASE_LEVEL_NUM,0);
		(b_txt[i]+1)->setBoth(float(i+1)/BASE_LEVEL_NUM,0);
		(b_txt[i]+2)->setBoth(float(i+1)/BASE_LEVEL_NUM,1);
		(b_txt[i]+3)->setBoth(float(i)/BASE_LEVEL_NUM,1);
		glBindBufferARB ( GL_ARRAY_BUFFER_ARB, b_txtId[i]);
		glBufferDataARB ( GL_ARRAY_BUFFER_ARB, 4 * sizeof ( tka ), b_txt[i], GL_STATIC_DRAW_ARB );
	}


}
void VBO_drawer::InitMissilesVBO()
{
//	int i;
	tka quad[]={tka(-MISSSIZE_TODRAW,-MISSSIZE_TODRAW),tka(0,0),
				tka(MISSSIZE_TODRAW,-MISSSIZE_TODRAW),tka(1,0),
				tka(MISSSIZE_TODRAW,MISSSIZE_TODRAW),tka(1,1),
				tka(-MISSSIZE_TODRAW,MISSSIZE_TODRAW),tka(0,1)};
	int quad_i[]={0,1,3,2};

	glBindBufferARB ( GL_ARRAY_BUFFER_ARB, vertexId[2] );
	glBufferDataARB ( GL_ARRAY_BUFFER_ARB, 8 * sizeof ( tka ), quad, GL_STATIC_DRAW_ARB );
	glBindBufferARB ( GL_ELEMENT_ARRAY_BUFFER_ARB, indexId[2] );
	glBufferDataARB ( GL_ELEMENT_ARRAY_BUFFER_ARB, 4 * sizeof ( int ), quad_i, GL_STATIC_DRAW_ARB );
}


void VBO_drawer::InitKrugVBO()
{
	tka *cc=new tka[2*FOG_CIRC_NUM+1];
	int *id=new int[FOG_CIRC_NUM+1];
	int *id1=new int[2*FOG_CIRC_NUM];
	float *col= new float[FOG_CIRC_NUM*8];
	float sa=(float)sin(2*PI/(FOG_CIRC_NUM-1));
	float ca=(float)cos(2*PI/(FOG_CIRC_NUM-1));
	tka tmpt(1,0);
	int i;
	cc->setBoth(0,0);
	for(i=0;i<FOG_CIRC_NUM*8;i++)
		col[i]=0;
	for(i=0;i<FOG_CIRC_NUM;i++)
	{
		//col[FOG_CIRC_NUM*4+i*4+3]=0;
		col[i*4+3]=1;
	}
	for(i=0;i<FOG_CIRC_NUM;i++)
	{
		id[i]=i;
		cc[i+1]=tmpt;
		cc[i+1+FOG_CIRC_NUM]=tmpt*FOG_SMOOTH_KOEF;
		id1[i*2]=i;
		id1[i*2+1]=i+FOG_CIRC_NUM;
		tmpt.rotate(sa,ca);
	}
	id[i]=i;


	glBindBufferARB ( GL_ARRAY_BUFFER_ARB, vertexId[3] );
	glBufferDataARB ( GL_ARRAY_BUFFER_ARB, (FOG_CIRC_NUM+1) * sizeof ( tka ), cc, GL_STATIC_DRAW_ARB );
	glBindBufferARB ( GL_ELEMENT_ARRAY_BUFFER_ARB, indexId[3] );
	glBufferDataARB ( GL_ELEMENT_ARRAY_BUFFER_ARB, (FOG_CIRC_NUM+1) * sizeof ( int ), id, GL_STATIC_DRAW_ARB );

	glBindBufferARB ( GL_ARRAY_BUFFER_ARB, vertexId[4] );
	glBufferDataARB ( GL_ARRAY_BUFFER_ARB, 2*FOG_CIRC_NUM * sizeof ( tka ), cc+1, GL_STATIC_DRAW_ARB );
	glBindBufferARB ( GL_ELEMENT_ARRAY_BUFFER_ARB, indexId[4] );
	glBufferDataARB ( GL_ELEMENT_ARRAY_BUFFER_ARB, (2*FOG_CIRC_NUM) * sizeof ( int ), id1, GL_STATIC_DRAW_ARB );

	glGenBuffersARB (1, &fog_colId);
	glBindBufferARB ( GL_ARRAY_BUFFER_ARB, fog_colId );
	glBufferDataARB ( GL_ARRAY_BUFFER_ARB, 8*FOG_CIRC_NUM * sizeof ( float ), col, GL_STATIC_DRAW_ARB );

	delete[] cc;
	delete[] id;
	delete[] id1;
	delete[]col;
}

void VBO_drawer::InitPolyVBO() {
// 	int i,n;
// 	float *arr;
// 	int* ind;
// 	tka** cur=Poly;

	_obstacleVertexIdentifiers = new unsigned[ global_quantityOfObstacles ];
	_obstacleIndexIdentifiers = new unsigned[ global_quantityOfObstacles ];
	::glGenBuffersARB( global_quantityOfObstacles, _obstacleVertexIdentifiers );
	::glGenBuffersARB( global_quantityOfObstacles, _obstacleIndexIdentifiers );

	_obstacleFrameVertexIdentifiers = new unsigned[ global_quantityOfObstacles ];
	_obstacleFrameIndexIdentifiers = new unsigned[ global_quantityOfObstacles ];
	_obstacleFrameIndexNumbers = new unsigned[ global_quantityOfObstacles ];
	::glGenBuffersARB( global_quantityOfObstacles, _obstacleFrameVertexIdentifiers );
	::glGenBuffersARB( global_quantityOfObstacles, _obstacleFrameIndexIdentifiers );

	_obstacleShadowVertexIdentifiers = new unsigned[ global_quantityOfObstacles ];
	_obstacleShadowIndexIdentifiers = new unsigned[ global_quantityOfObstacles ];
	_obstacleShadowIndexNumbers = new unsigned[ global_quantityOfObstacles ];
	::glGenBuffersARB( global_quantityOfObstacles, _obstacleShadowVertexIdentifiers );
	::glGenBuffersARB( global_quantityOfObstacles, _obstacleShadowIndexIdentifiers );

	for ( size_t i = 0; i < global_quantityOfObstacles; i += 1 ) {
		const size_t quantityOfVertices = global_obstacleVerticesQuantities[ i ];

		const size_t vertexArraySize = quantityOfVertices * 4;
		float *vertexArray = new float[ vertexArraySize ];
		const size_t indexArraySize = 3 * ( quantityOfVertices - 2 );
		int *indexArray = new int[ indexArraySize ];

		tka *currentObstacle = Poly[ i ];

		::GenVBOPoly( currentObstacle, vertexArray, indexArray );
		::glBindBufferARB( GL_ARRAY_BUFFER_ARB, _obstacleVertexIdentifiers[ i ] );
		::glBufferDataARB( GL_ARRAY_BUFFER_ARB, quantityOfVertices * 2 * sizeof ( tka ), vertexArray, GL_STATIC_DRAW_ARB );
		::glBindBufferARB( GL_ARRAY_BUFFER_ARB, 0 );

		::glBindBufferARB( GL_ELEMENT_ARRAY_BUFFER_ARB, _obstacleIndexIdentifiers[ i ] );
		::glBufferDataARB( GL_ELEMENT_ARRAY_BUFFER_ARB, 3 * ( quantityOfVertices - 2 ) * sizeof ( int ), indexArray, GL_STATIC_DRAW_ARB );
		::glBindBufferARB( GL_ELEMENT_ARRAY_BUFFER_ARB, 0 );
		delete[] vertexArray;
		delete[] indexArray;

		::GenVBOPolyFrame( currentObstacle, &vertexArray, &indexArray );
		_obstacleFrameIndexNumbers[ i ] = ( unsigned )_msize( indexArray ) / sizeof( unsigned );

		::glBindBufferARB( GL_ARRAY_BUFFER_ARB, _obstacleFrameVertexIdentifiers[ i ] );
		::glBufferDataARB( GL_ARRAY_BUFFER_ARB, ( int )_msize( vertexArray ), vertexArray, GL_STATIC_DRAW_ARB );
		::glBindBufferARB( GL_ARRAY_BUFFER_ARB, 0 );

		::glBindBufferARB( GL_ELEMENT_ARRAY_BUFFER_ARB, _obstacleFrameIndexIdentifiers[ i ] );
		::glBufferDataARB( GL_ELEMENT_ARRAY_BUFFER_ARB, _obstacleFrameIndexNumbers[ i ] * sizeof( unsigned ), indexArray, GL_STATIC_DRAW_ARB );
		::glBindBufferARB( GL_ELEMENT_ARRAY_BUFFER_ARB, 0 );
		delete[] vertexArray;
		delete[] indexArray;

		::GenVBOPolyShadow( currentObstacle, &vertexArray, &indexArray );
		_obstacleShadowIndexNumbers[ i ] = ( unsigned )_msize( indexArray ) / sizeof( unsigned );

		::glBindBufferARB( GL_ARRAY_BUFFER_ARB, _obstacleShadowVertexIdentifiers[ i ] );
		::glBufferDataARB( GL_ARRAY_BUFFER_ARB, ( int )_msize( vertexArray ), vertexArray, GL_STATIC_DRAW_ARB );
		::glBindBufferARB( GL_ARRAY_BUFFER_ARB, 0 );

		::glBindBufferARB( GL_ELEMENT_ARRAY_BUFFER_ARB, _obstacleShadowIndexIdentifiers[ i ] );
		::glBufferDataARB( GL_ELEMENT_ARRAY_BUFFER_ARB, _obstacleShadowIndexNumbers[ i ] * sizeof( unsigned ), indexArray, GL_STATIC_DRAW_ARB );
		::glBindBufferARB( GL_ELEMENT_ARRAY_BUFFER_ARB, 0 );
		delete[] vertexArray;
		delete[] indexArray;
	}
}

void VBO_drawer::UnInitPolyVBO()
{
	if(!_obstacleVertexIdentifiers)return;
	glDeleteBuffersARB (global_quantityOfObstacles, _obstacleVertexIdentifiers );
	glDeleteBuffersARB (global_quantityOfObstacles, _obstacleIndexIdentifiers  );
	delete[] _obstacleVertexIdentifiers;
	delete[] _obstacleIndexIdentifiers;

	glDeleteBuffersARB (global_quantityOfObstacles, _obstacleFrameVertexIdentifiers );
	glDeleteBuffersARB (global_quantityOfObstacles, _obstacleFrameIndexIdentifiers  );
	delete[] _obstacleFrameVertexIdentifiers;
	delete[] _obstacleFrameIndexIdentifiers;

	glDeleteBuffersARB (global_quantityOfObstacles, _obstacleShadowVertexIdentifiers );
	glDeleteBuffersARB (global_quantityOfObstacles, _obstacleShadowIndexIdentifiers  );
	delete[] _obstacleShadowVertexIdentifiers;
	delete[] _obstacleShadowIndexIdentifiers;

	delete[] _obstacleFrameIndexNumbers;
	delete[] _obstacleShadowIndexNumbers;
	_obstacleVertexIdentifiers=0;

}
bool VBO_drawer::InitVBO()
{
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		MessageBox( 0, "Cann't init glew!\n", "Error", MB_OK | MB_ICONERROR );
		return 0;
	}

	glEnableClientState ( GL_VERTEX_ARRAY );
	glEnableClientState ( GL_TEXTURE_COORD_ARRAY );
//	glEnableClientState ( GL_INDEX_ARRAY  );

	glGenBuffersARB (VBO_NUM, vertexId );
	glGenBuffersARB (VBO_NUM, indexId );

	InitUnitsVBO();
	InitMissilesVBO();
	InitBasesVBO();
	InitKrugVBO();
	//if(PolyNum)InitPolyVBO();

	glBindBufferARB ( GL_ARRAY_BUFFER_ARB,         0 );
	glBindBufferARB ( GL_ELEMENT_ARRAY_BUFFER_ARB, 0 );

	return true;
}

void VBO_drawer::UnInitVBO()
{
	int i;
	for(i=0;i<UNIT_TYPES;i++)
		glDeleteBuffersARB(4,un_txtId[i]);
	for(i=0;i<BASE_LEVEL_NUM;i++)
		glDeleteBuffersARB(1,b_txtId);

	glDeleteBuffersARB (1, &fog_colId);
	glDeleteBuffersARB (VBO_NUM, vertexId );
	glDeleteBuffersARB (VBO_NUM, indexId  );
	//UnInitPolyVBO();
}

unsigned VBO_drawer::get_vertex_id( size_t const vertex_identifier_index ) {
	assert( vertex_identifier_index < VBO_NUM );
	return this->vertexId[ vertex_identifier_index ];
}

unsigned VBO_drawer::get_index_id( size_t index_identifier_index ) {
	assert( index_identifier_index < VBO_NUM );
	return this->indexId[ index_identifier_index ];
}

void VBO_drawer::StartUnit()
{
	glBindBufferARB   ( GL_ARRAY_BUFFER_ARB, vertexId[0] );
	glVertexPointer   ( 2, GL_FLOAT, sizeof(tka), 0);
	glBindBufferARB   ( GL_ARRAY_BUFFER_ARB, 0 );

	glBindBufferARB   ( GL_ELEMENT_ARRAY_BUFFER_ARB, indexId[0] );
	glIndexPointer    ( GL_UNSIGNED_INT, 0, 0 );

}
void VBO_drawer::SwitchToUnit(char type,char life)
{
	glBindBufferARB   ( GL_ARRAY_BUFFER_ARB, un_txtId[type][life] );
	glTexCoordPointer ( 2, GL_FLOAT, sizeof(tka), 0 );
	glBindBufferARB   ( GL_ARRAY_BUFFER_ARB, 0 );

	glBindBufferARB   ( GL_ELEMENT_ARRAY_BUFFER_ARB, indexId[0] );
	glIndexPointer    ( GL_UNSIGNED_INT, 0, 0 );

}

void VBO_drawer::StartMissile()
{
	glBindBufferARB( GL_ARRAY_BUFFER_ARB, vertexId[2] );
	glVertexPointer( 2, GL_FLOAT, 4*sizeof(GLfloat), 0 );
	glTexCoordPointer( 2, GL_FLOAT, 4*sizeof(GLfloat), (GLvoid*)(2*sizeof(GLfloat)) );
	glBindBufferARB ( GL_ELEMENT_ARRAY_BUFFER_ARB, indexId[2] );
	glIndexPointer( GL_UNSIGNED_INT, 0, 0 );

}

void VBO_drawer::StartKrug()
{
	glBindBufferARB( GL_ARRAY_BUFFER_ARB, vertexId[3] );
	glVertexPointer( 2, GL_FLOAT, sizeof(tka), 0 );
	glBindBufferARB   ( GL_ARRAY_BUFFER_ARB, 0 );
	glBindBufferARB ( GL_ELEMENT_ARRAY_BUFFER_ARB, indexId[3] );
	glIndexPointer( GL_UNSIGNED_INT, 0, 0 );
}
void VBO_drawer::StartBase()
{
	glBindBufferARB   ( GL_ARRAY_BUFFER_ARB, vertexId[1] );
	glVertexPointer   ( 2, GL_FLOAT, sizeof(tka), 0);
	glBindBufferARB   ( GL_ARRAY_BUFFER_ARB, 0 );

	glBindBufferARB   ( GL_ELEMENT_ARRAY_BUFFER_ARB, indexId[1] );
	glIndexPointer    ( GL_UNSIGNED_INT, 0, 0 );

}
void VBO_drawer::SwitchToBase(char type)
{
	glBindBufferARB   ( GL_ARRAY_BUFFER_ARB, b_txtId[type]);
	glTexCoordPointer ( 2, GL_FLOAT, sizeof(tka), 0 );
	glBindBufferARB   ( GL_ARRAY_BUFFER_ARB, 0 );

}
