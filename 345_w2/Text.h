
#pragma once 
#include <fstream>
#include <iostream>
#include <string>
#define _TEXT_H_
#ifdef _TEXT_H_

using namespace std;

namespace sict{
	class Text {
	private:
		size_t count; //!< size_t adapts to machine compiled on
		string* m_text;
	public:
		size_t size() const { return count; };
		Text() : count(0) { m_text = nullptr;  };
		Text(char * text = nullptr);
		Text(const Text& );
		Text& operator = (const Text& );
		Text(Text&& );
		Text& operator = (Text&& );
		~Text() { delete[] m_text; }
		};
}
#endif // _TEXT_H_