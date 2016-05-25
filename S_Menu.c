#include "Building_Header.h"

time_t timer;
struct tm *t;

int getDay(){
	int price =0;
	timer = time(NULL);

	t=localtime(&timer);
		
	return t->tm_wday;
}

int getElePrice(){
	srand(time(NULL));

	int h_t[256];
	int m_t[256];
	int h=0, m=0;
	int i,j,temp1,temp2;
	double price_h, price_m,price;
	int index_e= (rand()%10)*2;
	//int index_w= rand()%10;
	
	timer = time(NULL);
	t= localtime(&timer);
	h = 35-(t->tm_hour);
	m = 59-(t->tm_min);

	for(i=0; i<index_e;i++){
		h_t[i] = rand()%h;
		m_t[i] = rand()%m;
	}
	for(i=0;i<index_e-1;i++){
		for(j=0;j<index_e-1;j++){
			if(h_t[j]>h_t[j+1]){
				temp1 = h_t[j];
				h_t[j]=h_t[j+1];
				h_t[j+1]=temp1;
			}
			if(m_t[j]>m_t[j+1]){
				temp2 = m_t[j];
				m_t[j] = m_t[j+1];
				m_t[j+1] = temp2;
			}
		}
	}
	for(i=1;i<index_e;i+=2){
		price_h=(h_t[i]-h_t[i-1])*15;
		price_m=(m_t[i]-m_t[i-1])*15/60;

		price +=price_h+price_m;
	}
	//printf("전기세 금액 %f\n", price);
	return price;
}

int getWaterPrice(){
	srand(time(NULL));

	int h_t[256];
	int m_t[256];
	int h=0, m=0;
	int i,j,temp1,temp2;
	double price_h, price_m,price;
	int index_e= (rand()%5)*2;
	//int index_w= rand()%10;
	
	timer = time(NULL);
	t= localtime(&timer);
	h = 35-(t->tm_hour);
	m = 59-(t->tm_min);

	for(i=0; i<index_e;i++){
		h_t[i] = rand()%h;
		m_t[i] = rand()%m;
	}
	for(i=0;i<index_e-1;i++){
		for(j=0;j<index_e-1;j++){
			if(h_t[j]>h_t[j+1]){
				temp1 = h_t[j];
				h_t[j]=h_t[j+1];
				h_t[j+1]=temp1;
			}
			if(m_t[j]>m_t[j+1]){
				temp2 = m_t[j];
				m_t[j] = m_t[j+1];
				m_t[j+1] = temp2;
			}
		}
	}
	for(i=1;i<index_e;i+=2){
		price_h=(h_t[i]-h_t[i-1])*10;
		price_m=(m_t[i]-m_t[i-1])*10/60;

		price +=price_h+price_m;
	}
	
	return price;
}

void loan(){
	unsigned int loanMoney = 2500000000;
	int loanYear = 10;
	double loanRate = 0.08;

	double temp;
	double dayMoney, yearMoney;
	temp= pow((1+loanRate), 10.0);

	yearMoney = (loanMoney*temp*loanRate)/(temp-1);
	dayMoney = yearMoney/365;

	printf("%f\n",dayMoney);
}


int fstMenu()
{
	int m_num, flag = -1;
	do
	{
		timer = time(NULL);
		t= localtime(&timer);

		printf("┌──────────────┐\n");
		printf("│	       │\n");
		printf("│  1. 대실     │\n");
		printf("│              │\n");
		printf("│  2. 숙박     │\n");
		printf("│	       │\n");
		printf("│  3. 정산     │\n");
		printf("│	       │\n");		
		printf("│  -1. QUIT    │\n");	
		printf("│	       │\n");	
		printf("└──────────────┘\n");
	
		printf("input Sleep's menu\n");		
		scanf("%d", &m_num);
		
		if(m_num < -1 && m_num > 3)
		{
			printf("Wrong Input Number!\n");
			flag = -1;
			continue;
		}

		else if((t->tm_hour >=16 || t->tm_hour <= 13) && m_num == 1)
		{
			printf("대실은 할 수 없는 시간입니다.\n");
			printf("숙박을 선택하려면 2번을 누르세요\n");
			flag = -1;
		}

		else
			flag = 0;
	
	}while(flag != 0);
		
	return m_num;
}

int sndMenu(Building* bld){
	int m_num, i_check_room;	
	int flag = -1;
	
	i_check_room = check_room(bld, 4);
	if(i_check_room == -1)
	{
		printf("There's no empty room!\n");
		return -1;
	}

	else
	{
		do
		{
//			system("clear");
			printf("┌───────────────┐\n");
			printf("│	        │\n");
			printf("│  1. Standard  │\n");
			printf("│	        │\n");
			printf("│  2. Business  │\n");
			printf("│	        │\n");
			printf("│  3. Sweet     │\n");
			printf("│	        │\n");
			printf("└───────────────┘\n");

			printf("input Room's menu\n");
			scanf("%d", &m_num);

			flag = check_room(bld, m_num);

			if(flag == 0)
				break;
			else
			{
				switch(m_num)
				{
					case STANDARD_ROOM:
						printf("There's no standard room!\n");
						break;

					case BUSINESS_ROOM:
						printf("There's no business room!\n");
						break;

					case SWEET_ROOM:
						printf("There's no sweet_room!\n");

				}			
				continue;
			}

		}while(flag != 0);
	}
	
	return m_num;
}

int trdMenu(int* price){
	int m_num, flag = -2, temp = 0;
	
	temp = (*price);
	do
	{
//		system("clear");
		printf("┌─────────────────────┐\n");
		printf("│	       	      │\n");
		printf("│  1. 칫솔            │\n");
		printf("│  2. 때밀이 수건     │\n");
		printf("│  3. 일회용 샤워세트 │\n");
		printf("│  4. 일회용 면도기   │\n");
		printf("│  5. 일회용 오일     │\n");
		printf("│  0. CONTINUE	      │\n");
		printf("│ -1. QUIT	      │\n");
		printf("└─────────────────────┘\n");
		printf("Price = %d\n", temp);
		printf(" 물품의 번호를 입력하세요");
		scanf("%d" , &m_num);

		if(m_num == -1 || m_num == 0)
			flag = 0;

		else if(1 <= m_num && m_num <= 5)
			temp = gettrdPrice(temp, m_num);

		else
			printf("Input right value!\n");
//		printf("Price = %d\n", temp);

	}while(flag != 0);
	*price = temp;
	return m_num;
}


int getfstPrice(int price, int menu){
	
	int day=0;
	day = getDay();

	if(menu ==1){
		printf("대실을 선택하셨습니다.\n");
		if(day==0 || day==6){
			price += 40000;
		}else{
			price += 30000;
		}
	}else if(menu == 2){
		printf("숙박을 선택하셨습니다.\n");
		if(day==0 || day==6){
			price += 80000;
		}
		else{
			price+= 60000;
		}
	}

	return price;
}


int getsndPrice(int price, int menu){

	if(menu==1){
		printf(" Standard 룸을 선택하셨습니다.\n");
		price += 0;
	}else if(menu==2){
		printf(" Business 룸을 선택하셨습니다.\n");
		price+=20000;
	}else if(menu==3){
		printf(" Sweet 룸을 선택하셨습니다.\n");
		price+=40000;
	}

	return price;
}

int gettrdPrice(int price, int menu){
	if(menu==1){
		printf(" 칫솔을 선택하셨습니다.\n");
		price += 1000;
	}else if(menu ==2){
		printf(" 때밀이 수건을 선택하셨습니다.\n");
		price += 500;
	}else if(menu ==3){
		printf("일회용 샤워세트를 선택했습니다.\n");
		price += 3000;
	}else if(menu == 4){
		printf("면도기를 선택했습니다.\n");
		price +=500;
	}else if(menu ==5){
		printf("오일을 선택했습니다.\n");
		price += 4000;
	}
	return price;
}

/*
void checkTime(time_t startTime, time_t endTime){
	float gap;

	startTime = clock();
	endTime = clock();

	gap = (float)(endTime-startTime)/((CLOCKS_PER_SEC)*3600);

	printf("%f", gap);

}

void getMinus(int *price){
	int E_tax;
	int C_price;
	
	//퇴실시간-현재시간 * 15 = E_tax
	//퇴실시간-현재시간 * 10 = W_tax
	//방을 배정해준 순간부터 입실시간. 퇴실시간은 숙박은 다음날 12시까지 대실은 당일 4시까지 만약 현시간이 4시 이후면 대실은 할 수 없다. 대실은 16:00 - 현시간 숙박은 다음날 12+(12-현시간) 
}
*/
/*
int main(void){
	int price;
	getElePrice();
	getWaterPrice();
	loan();
	getfstPrice(&price);
	getsndPrice(&price);
	gettrdPrice(&price);
}
*/
