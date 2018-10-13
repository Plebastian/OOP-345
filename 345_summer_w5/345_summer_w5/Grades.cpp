#include "Grades.h"

sict::Grades::Grades(std::string filename)
{
	try {
		std::ifstream file(filename);
		if (!file)
		{
			throw "Error:: File could not open!";
		}
		//count the number of lines in the file 
		//temp var to record lines
		std::string ss;
		double grades;
		while (!file.eof())
		{
			std::getline(file, ss, '\n');
			count++;
		}
		count--;
		//seek for the beginning of the file
		file.clear(); //clears the file stream
		file.seekg(0, std::ios::beg);

		//allocate member variables
		m_number = new std::string[count];
		grade = new double[count];
		for (size_t i = 0; i < count; i++)
		{
			std::getline(file, m_number[i], ' ');
			std::getline(file, ss, '\n');
			grades = atof(ss.c_str());
			grade[i] = grades;
		}
	}
	catch (std::string msg) {
		std::cout << msg << std::endl;
	}
	
}
