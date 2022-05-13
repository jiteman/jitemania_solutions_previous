#pragma once


#include "jmsf/stdal/stdal_stl.h"


#define MAX_ZBLOCKS 100
#define MAX_COUNTERS 10

#define BB(i) ZZZ.StartBlock(i);
#define BB1(i) ZZZ.EndBlock(i);
#define INCR_CNT(i) ZZZ.counter[i]++;


struct zblock
{
	unsigned long start, num;
	float val;
};

class Zamer {

	zblock blocks[ MAX_ZBLOCKS ];

public:
	Zamer();
	unsigned long counter[ MAX_COUNTERS ];

	void StartBlock(int i);
	void EndBlock(int i);
	void WriteReport();
};

extern Zamer ZZZ;
