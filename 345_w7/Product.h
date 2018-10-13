#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include "iProduct.h"
namespace w7 {
	class Product : public iProduct
	{
		int m_number;
		double m_price;

	public:
		Product() : m_number(0), m_price(0.0) {};
		Product(int n, double p) : m_number(n), m_price(p) {};
		double getCharge() const { return m_price; };
		virtual void display(std::ostream&) const;

	};


	class TaxableProduct : public Product
	{
		char m_Tax;

	public:
		TaxableProduct() : Product(), m_Tax('\0') {};
		TaxableProduct(int n, double p, char t) : Product(n, p), m_Tax(t) { std::cerr << p; };
		double getCharge() const
		{
			return Product::getCharge()*(m_Tax == 'H' ? 1.13 : 1.08);
		};
		void display(std::ostream&) const;
	};
}

#endif // !
