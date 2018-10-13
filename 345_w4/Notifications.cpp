#include "Notifications.h"
#include <iostream>

extern char recordDelimiter;

sict::Notifications::Notifications()//message is cleared to a safe empty state
{
	m_message.clear();
}

sict::Notifications::Notifications(std::ifstream & in)
{
	Notifications notification;
	do 
	{
		sict::Message message(in, recordDelimiter);
		if (!message.empty())
		{
			notification += std::move(message);
		}
	} while (in);
}

sict::Notifications::Notifications(const Notifications & other)//copy constuctor
{
	m_message = other.m_message;
}

sict::Notifications & sict::Notifications::operator=(const Notifications & other)
{
	if (this != &other) {
		m_message = other.m_message;
	}
	return *this;
}

sict::Notifications::Notifications(Notifications && other)
{
	m_message = other.m_message;
	other.m_message.clear();
}

sict::Notifications && sict::Notifications::operator=(Notifications && other)//move operator
{
	if (this != &other) {
		//moves other message to current message (this=>m_message)
		m_message = std::move(other.m_message);
	}
	return std::move(*this);
}

sict::Notifications::~Notifications()
{
	m_message.clear();
}

void sict::Notifications::operator+=(const Message & msg)//adds message to set
{
	//adds msg to end of vector
	m_message.push_back(msg);
}

void sict::Notifications::display(std::ostream & os) const
{
	for (auto m = m_message.begin(); m !=m_message.end(); m++)
	{
		m->display(os);
	}

}
