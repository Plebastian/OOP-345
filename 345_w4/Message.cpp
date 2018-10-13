#include "Message.h"
#include <istream>

sict::Message::Message(std::ifstream & file, char c)
{
	std::streampos oldpos = file.tellg(); //!< stores current possition in the file
	std::string text;
	std::getline(file, text, c);//!< gets text from line from first file
	
	size_t words = 0;///counting number of words
	for (auto& iter : text) //!< https://codereview.stackexchange.com/questions/30547/number-of-words-in-a-string
	{
		if (iter == ' ')
		{
			words++;
		}
	}
	if (words > 0)
	{
		file.seekg(oldpos);//!< returns to saved possition; in this case beginning of the line
		
		file >> m_user;
		
		if (m_reply.empty())
		{
			file >> m_reply;

			if (m_reply.find('@') > 0)//!< checks if @ symbol appears in m_reply
			{
				getline(file, m_tweet, c);
				m_tweet = m_reply + m_tweet; //!< concatinates reply to tweet
				m_reply.clear();
			}
			else
			{
				m_reply = m_reply.substr(1);//!< remove char '@' from reply
			}
		}
		if (m_tweet.empty())
		{
			std::getline(file, m_tweet);
		}
	}
}

bool sict::Message::empty() const //returns true if the object is in a safe empty state
{
	if (m_user[0] == '\0' && m_tweet[0] == '\0' && m_reply[0] == '\0')
	{
		return true;
	}
	return false;
}

void sict::Message::display(std::ostream & os) const
{
	os << "Message" << std::endl;
	if (!m_user.empty()) 
	{
		os << "	User : " << m_user << std::endl;
	}
	if (!m_reply.empty())
	{
		os << "	Reply : " << m_reply << std::endl;
	}
	os << "	Tweet : " << m_tweet << std::endl;
}
