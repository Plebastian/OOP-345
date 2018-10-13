// Workshop 10 - Multi-Threading
// SecureData.cpp

#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#include <ios>
#include <thread>
#include <functional>
#include "SecureData.h"

namespace w10 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key) {
		// open text file
		std::fstream input(file, std::ios::in);
		if (!input)
			throw std::string("\n***Failed to open file ") +
			std::string(file) + std::string(" ***\n");

		// copy from file into memory
		nbytes = 0;
		input >> std::noskipws;
		while (input.good()) {
			char c;
			input >> c;
			nbytes++;
		}
		nbytes--;
		input.clear();
		input.seekg(0, std::ios::beg);
		text = new char[nbytes + 1];

		int i = 0;
		while (input.good())
			input >> text[i++];
		text[--i] = '\0';
		std::cout << "\n" << nbytes << " bytes copied from text "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		std::cout << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key) {
		const unsigned int num = 2;
		std::thread threads[num];
		size_t encodethread = nbytes / num;
		Cryptor crypt[num];
		for (size_t i = 0; i < num; i++)
		{
			threads[i] = std::thread(std::bind(
				converter, 
				text + i * num, 
				key, 
				i+1 < num ? encodethread : 
				(nbytes - i * encodethread), 
				crypt[i]));
		}
		for (size_t it = 0; it < num; it++)
		{
			threads[it].join();
		}
		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else {
			// open binary file
			std::ofstream is;
			is.open(file, std::ios::out);
			// write binary file here
			if (is.fail())
			{
				throw std::string("\n***No file could be opened " + std::string(file) + " ***\n");
			}
			else
			{
				//std::cerr << nbytes << std::endl;
				for (int i = 0; i < nbytes; i++)
				{
					is << text[i];
				}
			}
			
		}
	}

	void SecureData::restore(const char* file, char key) {
		// open binary file
		std::ifstream os;
		os.open(file, std::ios::in);
		if (os.fail())
		{
			throw std::string("\n***No file could be opened " + std::string(file) + " ***\n");
		}
		else
		{
			nbytes = -1;
			char tempchar = 0;
			while (os.good())
			{
				os.read(&tempchar, 1);
				//os >> tempchar;
				nbytes++; //!< count number of chars

			}

			std::cerr << nbytes << std::endl;
			delete[] text;
			text = new char[nbytes +1]; //!< allocate memory here
			text[nbytes] = '\0';
			os.clear();
			os.seekg(0, std::ios::beg);
			os.read(text, nbytes);
		}
		
		

		std::cout << "\n" << nbytes + 1 << " bytes copied from binary file "
			<< file << " into memory (null byte included)\n";
		encoded = true;

		// decode using key
		code(key);
		std::cout << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}

}