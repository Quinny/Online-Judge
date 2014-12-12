#include <iostream>

bool leap_year(int); 

int main(){
	const int days_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int day = 1;
	int weekDay = 1; // monday : 0, tuesday : 1 ... sunday : 6
	int ans = 0;
	for(int year = 1901; year <= 2000; year++){
		for(int month = 1; month <= 12; month++){
			if(day == 1 && weekDay == 6) ans++;
			int check = (month == 2 && leap_year(year)) ? 1 : 0;
			while(day <= days_month[month] + check){
				day++;
				weekDay = (weekDay + 1) % 7;
			}
			day = 1;
		}
	}
	std::cout << ans << std::endl;
	return 0;
}

bool leap_year(int y){
	return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}