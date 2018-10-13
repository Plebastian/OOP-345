#pragma once
#include "Message.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <fstream>

#ifndef _NOTIFICATIONS_H_
#define _NOTIFICATIONS_H_

namespace sict

{
	class Notifications 
	{
		std::vector <Message> m_message;
	public:
		Notifications();
		Notifications(std::ifstream& in);
		Notifications(const Notifications &);
		Notifications& operator = (const Notifications&);
		Notifications(Notifications&&);
		Notifications&& operator=(Notifications&&);
		~Notifications();
		void operator+=(const Message& msg);
		void display(std::ostream& os) const;
	};
}

#endif _NOTIFICATIONS_H_