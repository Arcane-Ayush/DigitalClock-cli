#include <iostream>
#include <ctime>   // even though made the program using this will maybe update to chrono -- just like in stopWatch.
#include <conio.h>
#include <chrono>
//#include <Windows.h>
#include <thread>
#include <cstdlib>

void clock_time24(int& count);
void clock_time12(int& count);
void Date(int& count);
void stopWatch();


char inputFormat;

void instructionsStart() {
	std::cout << "INSTRUCTIONS:\n---> FIRST:  Choose your clock mode <---\n---> SECOND: To Quit/Exit Press 'q' <---\n";
	std::cout << "1. 24Hr Format      2. 12Hr Format      3. Stop Watch\n";
	std::cin >> inputFormat;
	std::system("cls");
}

int main() {
	instructionsStart();

	bool run = true;
	while (run) {
		int count = (int)time(nullptr);      // the time() is the unix_time_of_epoch in seconds ---> from ctime
		count = count + ((5 * 3600) + 1800);


		if (inputFormat == '1') {
			clock_time24(count);
			Date(count);

		}
		else if (inputFormat == '2') {
			clock_time12(count);
			Date(count);
		}
		else if (inputFormat == '3') {
			stopWatch();
			instructionsStart();
		}
		else if (inputFormat == 'q') {
			std::cout << "****************Thanks for using our Clock****************";
			run = false;
			std::cin.get();
		}
		else {
			std::cout << "Choose Valid Option.\n";
			instructionsStart();
			//continue;   ( needed to skip kbhit() .. or can add the delay here and put it then but skipping ) 
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		system("cls");   // woah no need to use std damn-

		// To break once the clock starts
		if (_kbhit()) {
			char ch = _getch();
			if (ch == 'q') instructionsStart();
		}

	}
}
//there will be an error in the printout maybe in miliseconds because there are many processes happening after fetching the time and the priniting out.. so the print out would be inaccurate even from the system time.
