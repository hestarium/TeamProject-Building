#include "Building_Header.h"

Building* createBuilding()
{
	Building* bld_Return = NULL;
	bld_Return = (Building *)malloc(sizeof(Building));
	if(bld_Return == NULL)
	{
		printf("[Error][createBuilding] - [MEMORY NOT ALLOCATED]\n");
		return NULL;
	}

	else
		memset(bld_Return, 0, sizeof(Building));
	
	return bld_Return;
}

Building* InitBuilding(Building* bld)
{
	bld->floor_cnt = 1;
	bld->floor = createFloor(bld->floor_cnt);

	bld->floor[0]->room_cnt = 3;
	bld->floor[0]->room = createRoom(bld->floor[0]->room_cnt);
	
	int i;
	for(i = 0; i < bld->floor[0]->room_cnt; i++)
	{
		bld->floor[0]->room[i]->space_cnt = 1;
		bld->floor[0]->room[i]->space = createSpace(bld->floor[0]->room[i]->space_cnt);
	}
	return bld;
}

/*************/
/****FLOOR****/
/*************/
Floor** createFloor(int cnt)
{
	Floor** fl_Return = NULL;
	fl_Return = (Floor **)malloc(sizeof(Floor *) * cnt);

	int i;
	for(i = 0; i < cnt; i++)
		fl_Return[i] = (Floor *)malloc(sizeof(Floor));
	
	if(fl_Return == NULL)
	{
		printf("[Error][createFloor] - [MEMORY NOT ALLOCATED\n");
		return NULL;
	}

	return fl_Return;
}

Floor** addFloor(Building* bld)
{
	bld->floor = (Floor **)realloc(bld->floor, sizeof(Floor *) * bld->floor_cnt);
	int i;
	for(i = 0; i < bld->floor_cnt; i++)
	{
		if(bld->floor[i] == NULL)
		{
			bld->floor[i] = (Floor *)malloc(sizeof(Floor));
			bld->floor[i]->room_cnt = 1;
			bld->floor[i]->room = createRoom(bld->floor[i]->room_cnt);		
		}
	}

	return bld->floor;
}

Floor** delFloor(Building* bld, int cnt)
{
	int i;
	for(i = bld->floor_cnt - 1; i >= bld->floor_cnt-1-cnt; i--)
		free(bld->floor[i]);

	bld->floor_cnt -= cnt;
	bld->floor = (Floor **)realloc(bld->floor, sizeof(Floor *) * bld->floor_cnt);

	return bld->floor;
}


/************/
/****ROOM****/
/************/
Room** createRoom(int cnt)
{
	Room** rm_Return;
	rm_Return = (Room **)malloc(sizeof(Room *) * cnt);
	
	int i;
	for(i = 0; i < cnt; i++)
		rm_Return[i] = (Room *)malloc(sizeof(Room));

	if(rm_Return == NULL)
	{
		printf("[Error][createRoom] - [MEMORY NOT ALLOCATED]\n");
		return NULL;
	}

	return rm_Return;
}

Room** addRoom(Floor* fl)
{
	fl->room = (Room **)realloc(fl->room, sizeof(Room *) * fl->room_cnt);
	int i;
	for(i = 0; i < fl->room_cnt; i++)
		if(fl->room[i] == NULL)
		{
			fl->room[i] = (Room *)malloc(sizeof(Room));
			fl->room[i]->space_cnt = 1;
			fl->room[i]->space = createSpace(fl->room[i]->space_cnt);
		}

	return fl->room;
}


Room** delRoom(Floor* fl, int cnt)
{
	int i;
	for(i = fl->room_cnt - 1; i >= fl->room_cnt - 1 - cnt; i--)
		free(fl->room[i]);

	fl->room_cnt -= cnt;
	fl->room = (Room **)realloc(fl->room, sizeof(Room *) * fl->room_cnt);

	return fl->room;
}

/*************/
/****SPACE****/
/*************/
Space** createSpace(int cnt)
{
	Space** sp_Return;
	sp_Return = (Space **)malloc(sizeof(Space *) * cnt);

	int i;
	for(i = 0; i < cnt; i++)
		sp_Return[i] = (Space *)malloc(sizeof(Space));
	if(sp_Return == NULL)
	{
		printf("[Error][createSpace] - [MEMORY NOT ALLOCATED]\n");
		return NULL;
	}

	return sp_Return;
}

Space** addSpace(Room* rm)
{
	rm->space = (Space **)realloc(rm->space,sizeof(Space *) * rm->space_cnt);
	int i;
	for(i = 0; i < rm->space_cnt; i++)
		if(rm->space[i] == NULL)
			rm->space[i] = (Space *)malloc(sizeof(Space));
	
	return rm->space;
}

Space** delSpace(Room* rm, int cnt)
{
	int i;
	for(i = rm->space_cnt - 1; i >= rm->space_cnt - 1 - cnt; i--)
		free(rm->space[i]);

	rm->space_cnt -= cnt;
	rm->space = (Space **)realloc(rm->space, sizeof(Space *) * rm->space_cnt);

	return rm->space;
}
