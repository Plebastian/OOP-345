#ifndef _I_PRODUCT_H_
#define _I_PRODUCT_H_

// Workshop 7 - STL Containers
// iProduct.h

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

namespace w7 {

	class iProduct 
	{
	public:
		virtual double getCharge() const = 0;
		virtual void display(std::ostream&) const = 0;
	};

	

	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	
	iProduct* readProduct(std::ifstream& file);
}


#endif