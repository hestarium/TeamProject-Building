#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct __SPACE
{
	char* host_name;
}Space;

typedef struct __ROOM
{
	Space** space;
	int space_cnt;
}Room;

typedef struct __FLOOR
{
	Room** room;
	int room_cnt;  
}Floor;

typedef struct __BUILDING
{
	Floor** floor;
	int floor_cnt;
}Building;

int bld_menu_selector();
int fl_menu_selector();
int rm_menu_selector();
int sp_menu_selector();
void print_Building(Building* bld);

Building* createBuilding();
Building* InitBuilding(Building* bld);

Floor** createFloor(int cnt);
Floor** addFloor(Building* bld);
Floor** delFloor(Building* bld, int cnt);
//Floor** printFloor();

Room** createRoom(int cnt);
Room** addRoom(Floor* fl);
Room** delRoom(Floor* fl, int cnt);

Space** createSpace(int cnt);
//Space** addSpace(int cnt);
//Space** delSpace(int cnt);
//Space** printSpace(int cnt);



