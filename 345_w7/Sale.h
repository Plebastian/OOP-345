#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include "iProduct.h"
namespace w7
{
	class Sale
	{
		std::vector<iProduct* > m_products;
	public:
		Sale::Sale(char *);
		void display(std::ostream& os) const;
	};
}