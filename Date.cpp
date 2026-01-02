#include <iostream>

bool leap_year(int year);

void Date(int &count) {
	int year, month, day;

	year = count / (365 * 24 * 3600);
	day = count / (3600 * 24) % 365;
	month = 1;

	int leap_days = year / 4; // quotient needed 55/4 = 13.75 == 13
	year = year + 1970; //updating year
	
	//calculating month and date ---> exhausting days per month and getting date
	int date = day - leap_days;
	while (date > 0) {
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			if ((date - 30) > 0) {
				month++;
				date -= 30;
			}
		}
		if (month == 2) {
			if ((date - 28) > 0) {
				month++;   			
				date -= 28;
			}
			else if ((date - 29) > 0 && leap_year(year)) {
				month++;
				date -= 29;
			}
		}
		else if ((date - 31) > 0) {
			month++;
			date -= 31;
		}
		else {
			break;
		}
	}

	std::cout << "Date: " << date << "/" << month << "/" << year << std::endl;
}
