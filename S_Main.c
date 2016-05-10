#include "Building_Header.h"

int main(int argc, char* argv[])
{
	Building* bld;
	bld = createBuilding();
	bld = InitBuilding(bld);
	
	int select_menu;
	int floor_num, room_num;
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
					case 1:
						flag = 1;
						break;
					case 2: 
						flag = 2;
						break;
					case 3:
						flag = 3;
						break;
					case 4:
						print_Building(bld);
						break;
					case -1:
						break;
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
						printf("│[1] ADD FLOOR                        │\n");
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
						printf("│[2] DEL FLOOR                           │\n");
						printf("│ Input Number to delete Floors          │\n");
						printf("└────────────────────────────────────────┘\n");
						printf("=> ");
									
						scanf("%d", &temp);
						bld->floor = delFloor(bld, temp);
						break;

					// PRINT FLOOR
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

			// ROOM MENU			
			case 2:
				select_menu = rm_menu_selector();
				switch(select_menu)
				{
					// ADD ROOM
					case 1:
						printf("┌─────────────────────────────────────┐\n");
						printf("│[1] ADD ROOM                         │\n");
						printf("│ Input Floor Number to add Rooms     │\n");
						printf("└─────────────────────────────────────┘\n");
						printf("=> ");
											
						scanf("%d", &floor_num);
						floor_num--;
						system("clear");
						printf("┌─────────────────────────────────────┐\n");
						printf("│ Input Number to add Rooms           │\n");
						printf("└─────────────────────────────────────┘\n");
						printf("=> ");
						scanf("%d", &room_num);
						bld->floor[floor_num]->room_cnt += room_num;
						bld->floor[floor_num]->room = addRoom(bld->floor[floor_num]);
						break;
					case 2: 
						printf("┌────────────────────────────────────────┐\n");
						printf("│[2] DEL ROOM                            │\n");
						printf("│ Input Floor Number to delete Rooms     │\n");
						printf("└────────────────────────────────────────┘\n");
						printf("=> ");

						scanf("%d", &floor_num);
						floor_num--;

						system("clear");
						printf("┌────────────────────────────────────────┐\n");
						printf("│ Input Number to delete Rooms           │\n");
						printf("└────────────────────────────────────────┘\n");
						printf("=> ");
						scanf("%d", &room_num);
						bld->floor[floor_num]->room = delRoom(bld->floor[floor_num], room_num);
						break;

					// PRINT ROOM
					case 3:
						break;

					// BACK!
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
					case 1:
						break;
					case 2: 
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
