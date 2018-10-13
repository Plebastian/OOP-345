#include "Text.h"


sict::Text::Text(char * text)
{
	if (text != nullptr)
	{
		count++;
		m_text[count] = text;
	}
}

sict::Text::Text(const Text & other)
{
	if (this != &other) 
	{
		*this = other;
	}
}

sict::Text & sict::Text::operator=(const Text &other)
{
		delete[] m_text;//delete
		count = other.count;
		m_text = new string[count];//realocate current obj

		for (size_t i = 0; i < count; i++)
		{
			m_text[i] = other.m_text[i];
		}
	return *this;
}

sict::Text::Text(Text &&other)
{
	if (this != &other)
	{
		*this = other;
	}
}

sict::Text & sict::Text::operator=(Text &&other)
{
	return	*this = move(other);
}
