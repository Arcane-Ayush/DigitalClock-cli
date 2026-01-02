#include <iostream>
#include <conio.h>
#include <iomanip>
#include <chrono>
#include <thread>
#include <cstdlib>  // for cls ---> Windows.h contain cstdlib ig; 
//#include <Windows.h>


// going to use chrono as want milliseconds in stopwatch
void stopWatch() {
	
	auto start = std::chrono::system_clock::now(); // the datatype is timepoint  ... so using auto
	
	bool run = true;
	while(run){
		auto now = std::chrono::system_clock::now();
		auto elapsed = now - start;
		
		//converting elapsed into milliseconds -- was trying to reassign but didn't work
		auto iterator = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();   // finally we got value in milisecond and fortunately subtracted.

		int hr, min, s, ms;

		hr = (iterator /(1000*3600)) % 24;
		min = (iterator /(1000* 60)) % 60;
		s = (iterator/1000) % 60;
		ms = iterator%1000;

		//trying in this one --> setfill('0') , fills empty space with 0 , setw(2) = total space , then the things which was going.

		std::cout << "Time: "
			<< std::setfill('0') << std::setw(2) << hr << ":"
			<< std::setfill('0') << std::setw(2) << min << ":"
			<< std::setfill('0') << std::setw(2) << s << "."
			<< std::setfill('0') << std::setw(3) << ms<< std::endl;

		if (_kbhit()) {
			char ch = _getch();
			if (ch == 'q')  run = false;
		}

		//Sleep(1000);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		system("cls");
	}
}
