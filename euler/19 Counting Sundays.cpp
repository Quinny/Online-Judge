#include <iostream>

bool isLeapYear(int); 

int main(void){
	const int daysPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int year = 1901;
	int day = 1;
	int month = 1;
	int weekDay = 1; // monday : 0, tuesday : 1 ... sunday : 6
	int ans = 0;
	while(year <= 2000){
		while(month <= 12){
			if(day == 1 && weekDay == 6) ans++;
			int check = (month == 2 && isLeapYear(year)) ? 1 : 0;
			while(day <= daysPerMonth[month] + check){
				day++;
				weekDay = (weekDay + 1) % 7;
			}
			month++;
			day = 1;
		}
		year++;
		month = 1;
	}
	std::cout << ans << std::endl;
	return 0;
}

bool isLeapYear(int y){
	return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}