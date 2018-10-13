
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

namespace sict {

	class Grades {
		std::string *m_number;
		double *grade;
		std::string* Letter;
		size_t count = 0;
	public:
		Grades() { m_number = nullptr; grade = nullptr; };
		Grades(std::string filename) ;
		template <typename F>
		void displayGrades(std::ostream& os, F Letter)
		{
			for (size_t i = 0; i < count; i++)
			{
				//std::cout <<std::setprecision(5) << grade[i];

				os << m_number[i] << " " 
					<< std::fixed << std::setprecision(2) << grade[i]
					<< " " << Letter(grade[i])  << std::endl;
			}
		}
	};

}