#include "Product.h"
namespace w7 {
	std::ostream& operator<<(std::ostream& os, const iProduct& p)
	{
		p.display(os);
		return os;
	};

	iProduct* readProduct(std::ifstream& file)
	{
		//! 
		//! This method reads a single line of the file and returns a iProduct pointer.
		//! If the file contains empty lines the function will set the iProduct pointer to an empty Product.
		//!
		iProduct* prod;
		size_t count{ 0 };
		if (!file.eof()) {
			std::string line;
			std::getline(file, line);
			if (line.size() < 1) {
				std::cout << std::string("File has an additional space at line ") ;
				return  prod = new Product();
			}

			else if (line.find('H') != std::string::npos) {
				return prod = new TaxableProduct(stoi(line.substr(0, line.find(' '))), stod(line.substr(line.find(' '), 7)), 'H');
			}
			else if (line.find('P') != std::string::npos) {
				return prod = new TaxableProduct(stoi(line.substr(0, line.find(' '))), stod(line.substr(line.find(' '), 7)), 'P');
			}
			else
			{
				return prod = new Product(stoi(line.substr(0, line.find(' '))), stod(line.substr(line.find(' '), 256)));

			}

			return prod;
		}
	}

	void Product::display(std::ostream & os) const 
	{
		//! Product display member function
		os << std::setfill(' ') << std::setw(10) << m_number << std::right << std::setw(10) <<  std::fixed << std::setprecision(2)  << Product::getCharge();
	}

	void TaxableProduct::display(std::ostream &os) const
	{
		//! Taxable Product display member function
		Product::display(os);
		os << " " << std::setw(4) << std::setfill(' ') << (m_Tax == 'H' ? "HST" : "PST");
	}

}

