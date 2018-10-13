// Workshop 5 - Lambda Expression
// w5.cpp
// Chris Szalwinski
// 2018-05-23

#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr <<
			"\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}


	sict::Grades grades(argv[1]);
	// lambda expression for converting to letter 
	auto letter = [](auto grade)//->std::auto
	{
	/*	std::string lettergrade;
		if (grade < 50)
			lettergrade = "F";
		else if (grade < 55)
			lettergrade = "D";
		else if (grade < 60)
			lettergrade = "D+";
		else if (grade < 65)
			lettergrade = "C";
		else if (grade < 70)
			lettergrade = "C+";
		else if (grade < 75)
			lettergrade = "B";
		else if (grade < 80)
			lettergrade = "B+";
		else if (grade < 80)
			lettergrade = "A";
		else if (grade <= 100)
			lettergrade = "A+";
		else 
			return "invalid grade";
		
		return lettergrade; 
		*/
			return 
				grade >= 90 ? static_cast<char>(Letter::A_PLUS) :  
				grade >= 80 ? static_cast<char>(Letter::A) :
				grade >= 75 ? static_cast<char>(Letter::B_PLUS) :
				grade >= 70 ? static_cast<char>(Letter::B) :
				grade >= 65 ? static_cast<char>(Letter::C_PLUS) :
				grade >= 60 ? static_cast<char>(Letter::C) :
				grade >= 55 ? static_cast<char>(Letter::D_PLUS) :
				grade >= 50 ? static_cast<char>(Letter::D) :
				static_cast<char>(Letter::F);
	};







	grades.displayGrades(std::cout, letter);


	// report the error message
	//std::cerr << argv[0] << ": Failed to open file "
	//	<< argv[1] << "\n";
	std::getchar();
	return 2;
}
