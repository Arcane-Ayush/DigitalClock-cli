#include <iostream>

//could make a single function but that will lose the flexiblity

void clock_time24(int &count) {
	//int count = (int)time(nullptr);
	//count = count + ((5 * 3600) + 1800);
	int hr, min, s;
	
	hr = (count/3600)%24 ; 
	min = (count / 60)%60;
	s = count % 60;

	//std::cout << "Time: " << hr << ":" << min << ":" << s << std::endl;

	//brute forced -- because doesn't know to use setw( set words/char ) and stringstream 
	if (hr < 10) {
		std::cout << "Time: " << "0" << hr << ":";
	}
	else std::cout << "Time: " << hr << ":";
	if (min < 10) {
		std::cout << "0" << min << ":";
	}
	else std::cout << min << ":";
	if (s < 10) {
		std::cout << "0" << s  << std::endl;
	}
	else std::cout << s << std::endl;
}




void clock_time12(int& count) {
	int hr, min, s;
	
	hr = (count/3600)%24 ; 
	min = (count / 60)%60;
	s = count % 60;

	if (hr > 12) {
		hr = hr % 12;
		std::cout << "Time: " << hr << ":" << min << ":" << s << " P.M."<< std::endl;
	}
	else std::cout << "Time: " << hr << ":" << min << ":" << s << " A.M."<< std::endl;

}
