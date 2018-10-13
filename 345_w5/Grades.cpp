#include "Grades.h"

Grades::Grades(std::string filename)//!< opens and get information from file 
{
	std::ifstream file;//(filename);
	try
	{
		file.open(filename);
		if (file.fail())
		{
			throw "Error:: File could not open!";
		}
		//size_t count = 0;
		std::string ss;
		double grade;

		// get count of lines...
		while (file.good())
		{
			std::getline(file, ss, '\n');
			count++;
		}

		file.clear(); //!< clear file stream
		file.seekg(0, std::ios::beg); //!< reset to beginning of file

		//allocate member variables
		m_studentN = new std::string[count];
		m_grade = new double[count];

		//reading from file begins
		int i = 0;
		while (!file.fail())
		{
			std::getline(file, m_studentN[i], ' ');

			std::getline(file, ss, '\n');
			grade = atof(ss.c_str());
			m_grade[i] = grade;

			i++;
		}
	}
	catch (std::string err)
	{
		// show error message
		std::cout << err << std::endl;
	}
};
