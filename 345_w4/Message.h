#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <iostream>

namespace sict

{
	class Message 
	{
	private: 
		std::string m_user;
		std::string m_tweet;
		std::string m_reply;
	public:
		Message(std::ifstream& in, char c);
		bool empty() const;
		void display(std::ostream&) const;
	};
}