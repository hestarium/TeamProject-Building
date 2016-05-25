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

	int electric_bill;
	int water_bill;
	int room_price;
	int room_type;
	int price;

	int flag;
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

#define STANDARD_ROOM 1
#define BUSINESS_ROOM 2
#define SWEET_ROOM    3

// BASE FUNCTION
int bld_menu_selector();
int fl_menu_selector();
int rm_menu_selector();
int sp_menu_selector();
void print_Building(Building* bld);

Building* createBuilding();
Building* InitBuilding(Building* bld);
Building* setBuilding(Building* bld, int floor_num, int room_num);

Floor** createFloor(int cnt);
Floor** addFloor(Building* bld, int cnt);
Floor** delFloor(Building* bld, int cnt);

Room** createRoom(int cnt);
Room** addRoom(Floor* fl, int cnt);
Room** delRoom(Floor* fl, int cnt);

Space** createSpace(int cnt);
Space** addSpace(Room* rm);
Space** delSpace(Room* rm, int cnt);
void print_space(Room* rm, int floor_num, int room_num);
void change_name(Room* rm, int from, int to);


// ADDED FUNCTION
#include <math.h>
#include <time.h>

int getday();

int getElePrice();
int getWaterPrice();

void loan();

int fstMenu();
int sndMenu(Building* bld);
int trdMenu(int* price);

int getfstPrice(int price, int menu);
int getsndPrice(int price, int menu);
int gettrdPrice(int price, int menu);

int* assign_a_room(Building* bld, int* room_info, int room_type);
int check_room(Building* bld, int room_type);
void save_data(Building* bld, int* room_info, int price);
int calculate(Building* bld);
//void checkTime(time_t startTime, time_t endTime);
//void getMinus(int* price);


