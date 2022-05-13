#pragma once

#include "myfuns.h"
#include "st.h"


#define MIN_NUM_IN_GROUP 50
#define MAX_NUM_IN_GROUP 160

#define MAX_GROUPS_NUM 200
#define GROUP_ALESRT_DIST 100

struct Group
{
	tka pos, nav;
	st< int > un;
	void CorrectRoute();
	void UnGroup();
	void GoOnCurPos(bool add);
};

extern Group global_groups[ MAX_GROUPS_NUM ];

void UpdateGroups();

int CreateGroup(el<int>* beg);
void DeleteGroup(int id);
void UpdateGroup(int id);

//void JoinFromGroups(st<int>*ss);
//void UnGroup(int *i);
void GroupUnits(st<int>*sl);
int GetGroupsNum();
void DeleteAllGroups();

void GroupCheck(Group* g);
void GroupLook(Group* g);
void GroupCorrectRoute(Group* g);

int JoinUnitAuto(int id);
void AutoCreateGroup(char pl);
