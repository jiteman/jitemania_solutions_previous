#pragma once


#include "Units.h"
#include "Bases.h"

#include <vector>


#define VBO_NUM 10

class VBO_drawer
{
public:
	unsigned un_txtId[ UNIT_TYPES ][ 4 ]; // для каждого типа юнита(и для каждого из 4-х типов повреждений) свои текстурные коорд.
	unsigned b_txtId[BASE_LEVEL_NUM];//для баз
	unsigned fog_colId;//для границы тумана

private:
	unsigned vertexId[ VBO_NUM ];
	unsigned indexId[ VBO_NUM ];
	//0-квадрат юнита  1-квадрат базы 2-квадрат снаряда(с текстурными коорд.)
	//3-круг для тумана войны 4-его граница "красивая"

public:
	unsigned *_obstacleVertexIdentifiers;//для препятствий-полигонов
	unsigned *_obstacleIndexIdentifiers;

	unsigned *_obstacleFrameVertexIdentifiers;//для рамки препятствий-полигонов
	unsigned *_obstacleFrameIndexIdentifiers;
	unsigned *_obstacleFrameIndexNumbers;//число индексов(зарание неизвесно)

	unsigned *_obstacleShadowVertexIdentifiers;//для теней препятствий-полигонов
	unsigned *_obstacleShadowIndexIdentifiers;
	unsigned *_obstacleShadowIndexNumbers;

public:
	bool InitVBO();
	void UnInitVBO();

	unsigned get_vertex_id( size_t vertex_identifier_index );
	unsigned get_index_id( size_t index_identifier_index );

	void StartUnit();
	void StartBase();
	void StartMissile();
	void StartKrug();



	void SwitchToUnit(char type,char life);
	void SwitchToBase(char type);

	void InitUnitsVBO();
	void InitBasesVBO();
	void InitMissilesVBO();
	void InitKrugVBO();
	void InitPolyVBO();

	void UnInitPolyVBO();

	VBO_drawer(){_obstacleVertexIdentifiers=0;}

};

extern VBO_drawer vbo;

void transfering_to_vector_addElementVBO_2(
	::std::vector< float > const &element,
	::std::vector< ::std::vector< float > > *vectorArray,
	::std::vector< int > *indexArray );

void AddElemVBO(float* el,int el_size,float**arr,int**ind);
