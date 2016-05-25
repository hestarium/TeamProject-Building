#include "Building_Header.h"

int main(int argc, char* argv[])
{
	Building* bld;
	bld = createBuilding();
	bld = InitBuilding(bld);
	
	int select_menu, room_select_menu;
	int floor_num, room_num, space_num;
	int i, j, k, temp, price, t_flag;
	int first_type, second_type, third_type;
	int from, to, calc_result = 0;
	int* room_info;
	room_info = (int *)malloc(sizeof(int) * 2);

	printf("Input your building's floor number and room number\n");
	printf("floor number: ");
	scanf("%d", &floor_num);
	printf("room number: ");
	scanf("%d", &room_num);

	bld = setBuilding(bld, floor_num, room_num);

	// USER -2 / BUILDING = ADMIN 0 / FLOOR 1 / ROOM 2 / SPACE 3 / QUIT -1

	int flag = -2;
	system("clear");
	do
	{
		switch(flag)
		{
			case -2:
				price = 0;
				first_type = fstMenu();
				if(first_type == 1 || first_type == 2)
				{
					price += getfstPrice(price, first_type);
					second_type = sndMenu(bld);
					if(1 <= second_type && second_type <= 3)
					{
						room_info = assign_a_room(bld, room_info, second_type);
						price = getsndPrice(price, second_type);
						third_type = trdMenu(&price);
						
						if(third_type == 0)
						{
							save_data(bld, room_info, price);
							flag = -2;
							break;
						}

						else if(third_type == -1)
							select_menu = -1;

						else
							printf("[Error][trdMenu] - Wrong Value!\n"); 
					}

					else
						printf("[Error][sndMenu] - Wrong Value! => %d\n", second_type);
					
				}
		
				else if(first_type == 3)
				{
					calc_result = calculate(bld);
					printf("Calculate Result = %d\n", calc_result);
				}

				else if(first_type == 0)
					flag = 0;

				else if(first_type == -1)
					flag = -1;
			
				else
					printf("[Error][fstMenu] - Wrong Value!\n");
				
				break;
				
			case 0:
				select_menu = bld_menu_selector();
				switch(select_menu)
				{
					case -2:
						flag = -2;
						break;
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

			// FLOOR MENU - COMPLETE
			case 1:
				select_menu = fl_menu_selector();
				switch(select_menu)
				{
					// ADD FLOOR - COMPLETE
					case 1:
						system("clear");
						printf("┌─────────────────────────────────────┐\n");
						printf("│[F1] ADD FLOOR                       │\n");
						printf("│ Input Number to add Floors          │\n");
						printf("└─────────────────────────────────────┘\n");
						printf("=> ");									
						scanf("%d", &temp);

						if(temp <= 0)
						{
							system("clear");
							printf("Unavailable value to add floors! => FLOOR COUNT: %dF\n", bld->floor_cnt);
							break;
						}

						//bld->floor_cnt += temp;
						bld->floor = addFloor(bld, temp);
						system("clear");
						printf("Complete to add floors! => FLOOR COUNT: %dF\n", bld->floor_cnt);
						break;

					// DELETE FLOOR - COMPLETE
					case 2: 
						system("clear");
						printf("┌────────────────────────────────────────┐\n");
						printf("│[F2] DEL FLOOR                          │\n");
						printf("│ Input Number to delete Floors          │\n");
						printf("└────────────────────────────────────────┘\n");
						printf("=> ");		
						scanf("%d", &temp);
						if(temp <= 0 || bld->floor_cnt - temp <= 0)
						{
							system("clear");
							printf("Unavailable value to delete floors! => FLOOR COUNT: %dF\n", bld->floor_cnt);
							break;
						}
						
					
						bld->floor = delFloor(bld, temp);
						system("clear");
						printf("Complete to delete floors! => FLOOR COUNT: %dF\n", bld->floor_cnt);
						break;

					// BACK TO BUILDING MENU - COMPLETE
					case 0:
						system("clear");
						flag = 0;
						break;

					// PROGRAM TERMINATED - COMPLETE
					case -1:
						break;

					default:
						system("clear");
						printf("Input Right Value!\n");
						break;
				}
				break;

			// ROOM MENU - PROCESSING	
			case 2:
				select_menu = rm_menu_selector();
				switch(select_menu)
				{
					// ADD ROOM - COMPLETE
					case 1:
						system("clear");
						printf("┌─────────────────────────────────────┐\n");
						printf("│[R1-1] ADD ROOM                      │\n");
						printf("│ Input Floor Number to add Rooms     │\n");
						printf("└─────────────────────────────────────┘\n");
						printf("=> ");							
						scanf("%d", &floor_num);
						floor_num--;
						if(floor_num < 0 || bld->floor_cnt <= floor_num)
						{
							system("clear");
							printf("Unavailable Floor Number! => Top Floor: %dF\n", bld->floor_cnt);
							break;
						} 

						system("clear");
						printf("┌─────────────────────────────────────┐\n");
						printf("│[R1-2] ADD ROOM    F:%3dF            │\n", floor_num + 1);
						printf("│ Input Number to add Rooms           │\n");
						printf("└─────────────────────────────────────┘\n");
						printf("=> ");
						scanf("%d", &room_num);

						if(room_num <= 0)
						{
							system("clear");
							printf("Cannot add room! => input: %d\n", room_num);
							break;
						}

						bld->floor[floor_num]->room = addRoom(bld->floor[floor_num], room_num);
						system("clear");
						printf("Complete to add rooms at %dF! => Room Count = %d\n", floor_num + 1, bld->floor[floor_num]->room_cnt);
						break;

					// DELETE ROOM - COMPLETE
					case 2: 
						system("clear");
						printf("┌────────────────────────────────────────┐\n");
						printf("│[R2-1] DEL ROOM                         │\n");
						printf("│ Input Floor Number to delete Rooms     │\n");
						printf("└────────────────────────────────────────┘\n");
						printf("=> ");

						scanf("%d", &floor_num);
						floor_num--;
						if(floor_num < 0 || bld->floor_cnt <= floor_num)
						{
							system("clear");
							printf("Unavailable Floor Number! => Top Floor: %dF\n", bld->floor_cnt);
							break;
						} 

						system("clear");
						printf("┌─────────────────────────────────────┐\n");
						printf("│[R2-2] DEL ROOM    F:%3dF            │\n", floor_num + 1);
						printf("│ Input Number to delete Rooms        │\n");
						printf("└─────────────────────────────────────┘\n");
						printf("=> ");
						scanf("%d", &room_num);

						if(room_num < 0 || bld->floor[floor_num]->room_cnt <= room_num)
						{
							system("clear");
							printf("You tried to delete too many rooms! => Room Count: %d\n", bld->floor[floor_num]->room_cnt);
							break;
						}

						bld->floor[floor_num]->room = delRoom(bld->floor[floor_num], room_num);
						system("clear");
						printf("Complete to delete rooms at %dF! => Room Count = %d\n", floor_num + 1, bld->floor[floor_num]->room_cnt);

						break;

					// PRINT ROOM - COMPLETE
					case 3:
						system("clear");
						printf("┌────────────────────────────────────────┐\n");
						printf("│[R3-1] PRINT ROOM                       │\n");
						printf("│ Input Floor Number to select Rooms     │\n");
						printf("└────────────────────────────────────────┘\n");
						printf("=> ");

						scanf("%d", &floor_num);
						floor_num--;
						if(floor_num < 0 || bld->floor_cnt <= floor_num)
						{
							system("clear");
							printf("Unavailable Floor Number! => Top Floor: %dF\n", bld->floor_cnt);
							break;
						} 

						system("clear");
						printf("┌────────────────────────────────────────┐\n");
						printf("│[R3-2] PRINT ROOM   F: %3dF             │\n", floor_num + 1);
  						printf("│ Input Number to print Room             │\n");
						printf("└────────────────────────────────────────┘\n");
						printf("=> ");
						scanf("%d", &room_num);
						room_num--;

						if(room_num < 0 || bld->floor[floor_num]->room_cnt <= room_num)
						{
							system("clear");
							printf("Unavailable Room Number! => Room Count: %d\n", bld->floor[floor_num]->room_cnt);
							break;
						}
						system("clear");
						print_space(bld->floor[floor_num]->room[room_num], floor_num, room_num);
						
						break;

					// BACK TO BUILDING MENU
					case 0:
						system("clear");
						flag = 0;
						break;

					// Program Terminated!
					case -1:
						break;

					default:
						system("clear");
						printf("Input Right Value!\n");
						break;
				}
				break;
			
			// SPACE MENU
			case 3:
				select_menu = sp_menu_selector();
				switch(select_menu)
				{
					// ADD SPACE - COMPLETE
					case 1:
						system("clear");
						printf("┌───────────────────────────────────┐\n");
						printf("│[S1-1] ADD SPACE                   │\n");
						printf("│ Input Floor Number                │\n");
						printf("└───────────────────────────────────┘\n");
						printf("=> ");				
						scanf("%d", &floor_num);
						floor_num--;

						if(floor_num < 0 || bld->floor_cnt <= floor_num)
						{
							system("clear");
							printf("Unavailable Floor Number! => Top Floor: %dF\n", bld->floor_cnt);
							break;
						} 

						system("clear");
						printf("┌────────────────────────────────┐\n");
						printf("│[S1-2] ADD SPACE   F: %3dF      │\n", floor_num + 1);
						printf("│ Input Room Number to add SPACE │\n");
						printf("└────────────────────────────────┘\n");
						printf("=> ");
						scanf("%d", &room_num);
						room_num--;

						if(room_num < 0 || bld->floor[floor_num]->room_cnt <= room_num)
						{
							system("clear");
							printf("Unavailable Room Number! => Room Count: %d\n", bld->floor[floor_num]->room_cnt);
							break;
						}

						system("clear");
						printf("┌──────────────────────────────────┐\n");
						printf("│[S1-3] ADD SPACE   F: %3dF R: %3dF│\n", floor_num + 1, room_num + 1); 
						printf("│ Input Number to add Space        │\n");
						printf("└──────────────────────────────────┘\n");
						printf("=> ");
						scanf("%d", &space_num);

						if(space_num <= 0 || bld->floor[floor_num]->room[room_num]->space_cnt + space_num > 4)
						{
							system("clear");
							printf("Unavailable Value to add Space! => Space Count: %d\n", bld->floor[floor_num]->room[room_num]->space_cnt);
							break;
						}

						bld->floor[floor_num]->room[room_num]->space_cnt += space_num;
						bld->floor[floor_num]->room[room_num]->space = addSpace(bld->floor[floor_num]->room[room_num]);

						system("clear");
						printf("Complete to add Spaces at %d-%d Room => Space Count = %d\n", floor_num + 1, room_num + 1, bld->floor[floor_num]->room[room_num]->space_cnt);
						break;

					// DEL SPACE - COMPLETE
					case 2: 
						system("clear");
						printf("┌───────────────────────────────────┐\n");
						printf("│[S2-1] DEL SPACE                   │\n");
						printf("│ Input Floor Number                │\n");
						printf("└───────────────────────────────────┘\n");
						printf("=> ");
											
						scanf("%d", &floor_num);
						floor_num--;
						if(floor_num < 0 || bld->floor_cnt <= floor_num)
						{
							system("clear");
							printf("Unavailable Floor Number! => Top Floor: %dF\n", bld->floor_cnt);
							break;
						} 

						system("clear");
						printf("┌───────────────────────────────────┐\n");
						printf("│[S2-2] DEL SPACE   F: %3dF         │\n", floor_num + 1);
						printf("│ Input Room Number to delete SPACE │\n");
						printf("└───────────────────────────────────┘\n");
						printf("=> ");
						scanf("%d", &room_num);
						room_num--;

						if(room_num < 0 || bld->floor[floor_num]->room_cnt <= room_num)
						{
							system("clear");
							printf("Unavailable Room Number! => Room Count: %d\n", bld->floor[floor_num]->room_cnt);
							break;
						}

						system("clear");
						printf("┌──────────────────────────────────┐\n");
						printf("│[S2-3] DEL SPACE   F: %3dF R: %3dF│\n", floor_num + 1, room_num + 1); 
						printf("│ Input Number to delete Space     │\n");
						printf("└──────────────────────────────────┘\n");
						printf("=> ");
						scanf("%d", &space_num);

						if(space_num <= 0 || bld->floor[floor_num]->room[room_num]->space_cnt - space_num < 0)
						{
							system("clear");
							printf("Unavailable Value to delete Space! => Space Count: %d\n", bld->floor[floor_num]->room[room_num]->space_cnt);
							break;
						}

						bld->floor[floor_num]->room[room_num]->space = delSpace(bld->floor[floor_num]->room[room_num], space_num);
						system("clear");
						printf("Complete to delete Space! => Space Count: %d\n", bld->floor[floor_num]->room[room_num]->space_cnt);
						break;
					
					// CHANGE PERSON
					case 3:
						system("clear");
						printf("┌───────────────────────────────────┐\n");
						printf("│[S3-1] CHANGE PERSON               │\n");
						printf("│ Input Floor Number                │\n");
						printf("└───────────────────────────────────┘\n");
						printf("=> ");
											
						scanf("%d", &floor_num);
						floor_num--;
						if(floor_num < 0 || bld->floor_cnt <= floor_num)
						{
							system("clear");
							printf("Unavailable Floor Number! => Top Floor: %dF\n", bld->floor_cnt);
							break;
						} 

						system("clear");
						printf("┌───────────────────────────────────┐\n");
						printf("│[S3-2] CHANGE PERSON   F: %3dF     │\n", floor_num + 1);
						printf("│ Input Room Number                 │\n");
						printf("└───────────────────────────────────┘\n");
						printf("=> ");
						scanf("%d", &room_num);
						room_num--;

						if(room_num < 0 || bld->floor[floor_num]->room_cnt <= room_num)
						{
							system("clear");
							printf("Unavailable Room Number! => Room Count: %d\n", bld->floor[floor_num]->room_cnt);
							break;
						}

						system("clear");
						printf("┌───────────────────────────────────────────┐\n");
						printf("│[S3-3] CHANGE PERSON  F: %3dF R: %3d       │\n", floor_num + 1, room_num + 1); 
						printf("│ Input first space number to change person │\n");
						printf("└───────────────────────────────────────────┘\n");
						printf("\n------------- Room Info %d-%d -------------\n", floor_num + 1, room_num + 1);
						for(i = 0; i < bld->floor[floor_num]->room[room_num]->space_cnt; i++)
							printf("[%d] name = %s\n", i + 1, bld->floor[floor_num]->room[room_num]->space[i]->host_name);
						printf("=> ");
						scanf("%d", &from);
						from--;

						system("clear");
						printf("┌───────────────────────────────────────────┐\n");
						printf("│[S3-4] CHANGE PERSON  F: %3dF R: %3d P: %d  │\n", floor_num + 1, room_num + 1, from + 1); 
						printf("│ Input second space number to change person│\n");
						printf("└───────────────────────────────────────────┘\n");
						printf("\n------------- Room Info %d-%d -------------\n", floor_num + 1, room_num + 1);
						for(i = 0; i < bld->floor[floor_num]->room[room_num]->space_cnt; i++)
							printf("[%d] name = %s\n", i + 1, bld->floor[floor_num]->room[room_num]->space[i]->host_name);
						printf("=> ");
						scanf("%d", &to);
						to--;

						change_name(bld->floor[floor_num]->room[room_num], from, to);
						print_space(bld->floor[floor_num]->room[room_num], floor_num, room_num);
					
						break;
					// BACK TO BUILDING MENU
					case 0:
						system("clear");
						flag = 0;
						break;

					// PROGRAM TERMINATED!
					case -1:
						break;

					// Wrong Value!
					default:
						system("clear");
						printf("Input Right Value!\n");
						break;
				}
				break;		
		}

	}while(select_menu != -1);

	for(i = 0; i < bld->floor_cnt; i++)
	{
		for(j = 0; j < bld->floor[i]->room_cnt; j++)
		{
			for(k = 0; k < bld->floor[i]->room[j]->space_cnt; k++)
			{
				free(bld->floor[i]->room[j]->space[k]);
			}
			free(bld->floor[i]->room[j]->space);
			free(bld->floor[i]->room[j]);
		}
		free(bld->floor[i]->room);
		free(bld->floor[i]);
	}
	free(bld);

	return 0;
}

void print_Building(Building* bld)
{
	system("clear");
	int i, j, k, count = 0;
	for(i = bld->floor_cnt - 1; i >= 0; i--)
	{
		for(j = 0; j < bld->floor[i]->room_cnt; j++)
			printf("┌────────┐ ");

		printf("\n");
		for(j = 0; j < bld->floor[i]->room_cnt; j++)
			printf("│ %2d-%2d  │ ", i + 1, j + 1);

		printf("\n");
		for(j = 0; j < bld->floor[i]->room_cnt; j++)		
			printf("└────────┘ ");

		printf("%2dF\n", i + 1);		
	}	

	printf("Room Number: %d\n", bld->floor_cnt * bld->floor[0]->room_cnt);

	for(i = 0; i < bld->floor_cnt; i++)
	{
		for(j = 0; j < bld->floor[i]->room_cnt; j++)
		{
			for(k = 0; k < bld->floor[i]->room[j]->space_cnt; k++)
			{
				if(bld->floor[i]->room[j]->space[k]->host_name != NULL)
					count++;
			}
		}
	}
	printf("Person Number: %d\n", count); 
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
	printf("│  [3] CHANGE Person  │\n");
	printf("│  [0] BACK           │\n");
	printf("│  [-1] Quit          │\n");
	printf("└─────────────────────┘\n");
	printf("=> ");

	int input;
	scanf("%d", &input);
	return input;
}

void print_space(Room* rm, int floor_num, int room_num)
{
	system("clear");
	int i;
	switch(rm->room_type)
	{
		case STANDARD_ROOM:
			printf("---------Room Type : STARDARD -----------\n");
			break;

		case BUSINESS_ROOM:
			printf("---------Room Type : BUSINESS -----------\n");
			break;

		case SWEET_ROOM:
			printf("---------Room Type : SWEET -----------\n");
			break;

		default:
			printf("[Error][print_space] - Wrong value at room_type => room_type : %d\n", rm->room_type);
			break;
	}
	
	printf("---------Room Info : %d-%d---------\n", floor_num + 1, room_num + 1);
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

	for(i = 0; i < rm->space_cnt; i++)
		printf("[%d] name: %s\n", i + 1, rm->space[i]->host_name);
	printf("[*] Electric Bill = %d\n", rm->electric_bill);
	printf("[*] Water Bill = %d\n", rm->water_bill);
	printf("[*] Price = %d\n", rm->price);
}
