#pragma once
#include <ostream>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

class Grades
{
private:
	std::string *m_studentN;
	double *m_grade;
	std::string* letter;
	size_t count = 0;
public:
	Grades() { m_studentN = nullptr; m_grade = nullptr; };
	Grades(std::string filename);
	template<typename T>
	void displayGrades(std::ostream& os, T letter) const
	{
		for (int i = 0; i < count; i++)
		{
			os << m_studentN[i].c_str() << " " << m_grade[i] << " " << letter(m_grade[i]) << std::endl;
		}
	};
};