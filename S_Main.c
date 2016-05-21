#include "Building_Header.h"

int main(int argc, char* argv[])
{
	Building* bld;
	bld = createBuilding();
	bld = InitBuilding(bld);
	
	int select_menu;
	int floor_num, room_num, space_num;
	int k;

	//BUILDING 0 / FLOOR 1 / ROOM 2 / SPACE 3 / QUIT -1
	int flag = 0;

	do
	{
		switch(flag)
		{
			case 0:
				select_menu = bld_menu_selector();
				switch(select_menu)
				{
					// FLOOR MENU
					case 1:
						flag = 1;
						break;

					// ROOM MENU
					case 2: 
						flag = 2;
						break;

					// SPACE MENU
					case 3:
						flag = 3;
						break;

					//PRINT BUILDING
					case 4:
						print_Building(bld);
						break;

					// TERMINATE FLAG
					case -1:
						break;
	
					// WRONG INPUT
					default:
						printf("Input Right Value!\n");
						break;
				}
				break;

			// FLOOR MENU
			case 1:
				select_menu = fl_menu_selector();
				switch(select_menu)
				{
					// ADD FLOOR
					case 1:
						printf("┌─────────────────────────────────────┐\n");
						printf("│[F1] ADD FLOOR                       │\n");
						printf("│ Input Number to add Floors          │\n");
						printf("└─────────────────────────────────────┘\n");
						printf("=> ");
						int temp;					
						scanf("%d", &temp);
						bld->floor_cnt += temp;
						bld->floor = addFloor(bld);
						break;

					// DELETE FLOOR
					case 2: 
						printf("┌────────────────────────────────────────┐\n");
						printf("│[F2] DEL FLOOR                          │\n");
						printf("│ Input Number to delete Floors          │\n");
						printf("└────────────────────────────────────────┘\n");
						printf("=> ");
									
						scanf("%d", &temp);
						bld->floor = delFloor(bld, temp);
						break;

					// PRINT FLOOR
					case 3:
						break;

					// BACK TO BUILDING MENU
					case 0:
						flag = 0;
						break;
					case -1:
						break;
					default:
						printf("Input Right Value!\n");
						break;
				}
				break;

			// ROOM MENU			
			case 2:
				select_menu = rm_menu_selector();
				switch(select_menu)
				{
					// ADD ROOM
					case 1:
						printf("┌─────────────────────────────────────┐\n");
						printf("│[R1-1] ADD ROOM                      │\n");
						printf("│ Input Floor Number to add Rooms     │\n");
						printf("└─────────────────────────────────────┘\n");
						printf("=> ");
											
						scanf("%d", &floor_num);
						floor_num--;
						system("clear");
						printf("┌─────────────────────────────────────┐\n");
						printf("│ [R1-2] Input Number to add Rooms    │\n");
						printf("└─────────────────────────────────────┘\n");
						printf("=> ");
						scanf("%d", &room_num);
						bld->floor[floor_num]->room_cnt += room_num;
						bld->floor[floor_num]->room = addRoom(bld->floor[floor_num]);
						break;

					// DELETE ROOM
					case 2: 
						printf("┌────────────────────────────────────────┐\n");
						printf("│[R2-1] DEL ROOM                         │\n");
						printf("│ Input Floor Number to delete Rooms     │\n");
						printf("└────────────────────────────────────────┘\n");
						printf("=> ");

						scanf("%d", &floor_num);
						floor_num--;

						system("clear");
						printf("┌────────────────────────────────────────┐\n");
						printf("│ [R2-2] Input Number to delete Rooms    │\n");
						printf("└────────────────────────────────────────┘\n");
						printf("=> ");
						scanf("%d", &room_num);
						bld->floor[floor_num]->room = delRoom(bld->floor[floor_num], room_num);
						break;

					// PRINT ROOM
					case 3:
						printf("test\n");
						printf("┌────────────────────────────────────────┐\n");
						printf("│[R2-1] DEL ROOM                         │\n");
						printf("│ Input Floor Number to delete Rooms     │\n");
						printf("└────────────────────────────────────────┘\n");
						printf("=> ");

						scanf("%d", &floor_num);
						floor_num--;

						system("clear");
						printf("┌────────────────────────────────────────┐\n");
						printf("│ [R2-2] Input Number to delete Rooms    │\n");
						printf("└────────────────────────────────────────┘\n");
						printf("=> ");
						scanf("%d", &room_num);
						room_num--;
						print_space(bld->floor[floor_num]->room[room_num]);
						break;

					// BACK TO BUILDING MENU
					case 0:
						flag = 0;
						break;

					// Program Terminated!
					case -1:
						break;
					default:
						printf("Input Right Value!\n");
						break;
				}
				break;
			
			// SPACE MENU
			case 3:
				select_menu = sp_menu_selector();
				switch(select_menu)
				{
					// ADD SPACE
					case 1:
						printf("┌───────────────────────────────────┐\n");
						printf("│[S1-1] ADD SPACE                   │\n");
						printf("│ Input Floor Number                │\n");
						printf("└───────────────────────────────────┘\n");
						printf("=> ");
											
						scanf("%d", &floor_num);
						floor_num--;
						system("clear");
						printf("┌─────────────────────────────┐\n");
						printf("│[S1-2] Input Room Number     │\n");
						printf("└─────────────────────────────┘\n");
						printf("=> ");
						scanf("%d", &room_num);

						system("clear");
						printf("┌──────────────────────────────────┐\n");
						printf("│[S1-3] Input Number to add Space  │\n");
						printf("└──────────────────────────────────┘\n");
						printf("=> ");
						scanf("%d", &space_num);

						bld->floor[floor_num]->room[room_num]->space_cnt += space_num;
						bld->floor[floor_num]->room[room_num]->space = addSpace(bld->floor[floor_num]->room[room_num]);
						break;

					// DEL SPACE
					case 2: 
						printf("┌────────────────────────────────────────┐\n");
						printf("│[S2-1] DEL SPACE                        │\n");
						printf("│ Input Room Number                      │\n");
						printf("└────────────────────────────────────────┘\n");
						printf("=> ");

						scanf("%d", &floor_num);
						floor_num--;

						system("clear");
						printf("┌────────────────────────────────────────┐\n");
						printf("│ [S2-2] Input Room Number               │\n");
						printf("└────────────────────────────────────────┘\n");
						printf("=> ");
						scanf("%d", &room_num);
						room_num--;						
				
						system("clear");
						printf("┌────────────────────────────────────────┐\n");
						printf("│ [S2-3] Input Space to delete Number    │\n");
						printf("└────────────────────────────────────────┘\n");
						printf("=> ");
						scanf("%d", &space_num);
						space_num--;

						bld->floor[floor_num]->room[room_num]->space = delSpace(bld->floor[floor_num]->room[room_num], space_num);
						
						break;
					case 3:
						
						break;
					case 0:
						flag = 0;
						break;
					case -1:
						break;
					default:
						printf("Input Right Value!\n");
						break;
				}
				break;		
		}
	}while(select_menu != -1);
	return 0;
}

void print_Building(Building* bld)
{
	int i, j;
	for(i = bld->floor_cnt - 1; i >= 0; i--)
	{
		for(j = 0; j < bld->floor[i]->room_cnt; j++)
			printf("┌───────┐ ");

		printf("\n");
		for(j = 0; j < bld->floor[i]->room_cnt; j++)
			printf("│ %2d%d%d  │ ", i + 1, 0, j + 1);

		printf("\n");
		for(j = 0; j < bld->floor[i]->room_cnt; j++)		
			printf("└───────┘ ");

		printf("%2dF\n", i + 1);		
	}	
}



int bld_menu_selector()
{
	printf("\n");
	printf("┌──────────────────────┐\n");
	printf("│    MENU - BUILDING   │\n");
	printf("│  [1] FLOOR           │\n");
	printf("│  [2] ROOM            │\n");
	printf("│  [3] SPACE           │\n");
	printf("│  [4] PRINT BUILDING  │\n");
	printf("│  [-1] Quit           │\n");
	printf("└──────────────────────┘\n");
	printf("=> ");

	int input;
	scanf("%d", &input);
	return input;
}

int fl_menu_selector()
{
	printf("\n");
	printf("┌─────────────────────┐\n");
	printf("│    MENU - FLOOR     │\n");
	printf("│  [1] ADD FLOOR      │\n");
	printf("│  [2] DELETE FLOOR   │\n");
	printf("│  [3] PRINT FLOOR    │\n");
	printf("│  [0] BACK           │\n");
	printf("│  [-1] Quit          │\n");
	printf("└─────────────────────┘\n");
	printf("=> ");

	int input;
	scanf("%d", &input);
	return input;
}

int rm_menu_selector()
{
	printf("\n");
	printf("┌─────────────────────┐\n");
	printf("│    MENU - ROOM      │\n");
	printf("│  [1] ADD ROOM       │\n");
	printf("│  [2] DELETE ROOM    │\n");
	printf("│  [3] PRINT ROOM     │\n");
	printf("│  [0] BACK           │\n");
	printf("│  [-1] Quit          │\n");
	printf("└─────────────────────┘\n");
	printf("=> ");

	int input;
	scanf("%d", &input);
	return input;
}

int sp_menu_selector()
{
	printf("\n");
	printf("┌─────────────────────┐\n");
	printf("│    MENU - SPACE     │\n");
	printf("│  [1] ADD SPACE      │\n");
	printf("│  [2] DELETE SPACE   │\n");
	printf("│  [3] PRINT SPACE    │\n");
	printf("│  [0] BACK           │\n");
	printf("│  [-1] Quit          │\n");
	printf("└─────────────────────┘\n");
	printf("=> ");

	int input;
	scanf("%d", &input);
	return input;
}

void print_space(Room* rm)
{
	printf("rm->space_cnt = %d\n", rm->space_cnt);
	switch(rm->space_cnt)
	{
		case 0:
			printf("┌───────────────────────┐\n");
			printf("│                       │\n");
			printf("│         EMPTY         │\n");
			printf("│                       │\n");
			printf("└───────────────────────┘\n");
			break;

		case 1:
			printf("┌───────────────────────┐\n");
			printf("│                       │\n");
			printf("│          [1]          │\n");
			printf("│                       │\n");
			printf("└───────────────────────┘\n");
			break;

		case 2:
			printf("┌───────────┬───────────┐\n");
			printf("│           │           │\n");
			printf("│    [1]    │    [2]    │\n");
			printf("│           │           │\n");
			printf("└───────────┴───────────┘\n");
			break;

		case 3:
			printf("┌───────┬───────┬───────┐\n");
			printf("│       │       │       │\n");
			printf("│  [1]  │  [2]  │  [3]  │\n");
			printf("│       │       │       │\n");
			printf("└───────┴───────┴───────┘\n");
			break;

		case 4:
			printf("┌───────────┬───────────┐\n");
			printf("│    [1]    │    [2]    │\n");
			printf("├───────────┼───────────┤\n");
			printf("│    [3]    │    [4]    │\n");
			printf("└───────────┴───────────┘\n");
			break;
	}
}
/*
int* seperate_fl_rm(int room_num, int* arr_room_num)
{
	char* s_room_num = itoa(room_num);
	int count, i;
	
	for(i = 0; i < strlen(s_room_num); i++)
		if(s_room_num[i] == '0')
			break;
		else
			count++;

	if(count > 0)
	{
		
	}

	else
	{
	}

	
}
*/
