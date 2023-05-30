#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <ctype.h>

#include "../hederfiles/Lexer.hpp"

Lexer::Lexer(std::string &src)
{
	m_program.open(src);
}

std::vector<std::string> Lexer::doLexer()
{
	std::vector<std::string> vec_words;

	if (!m_program.is_open()) {
		throw std::runtime_error("file not opened");
	}
	std::string line;
	std::string str;
	int i = 0;
	while (getline(m_program, line)) {
		while (line[i] != '\0') {
			isdigit(std::stoi(line));
			if (isdigit(line[i])) {
				str += line[i];
				i++;
				continue;
			} else if (line[i] == ' ') {
				i++;
				continue;
			} else {
				str += ' ';
				str += line[i];
				str += ' ';
				i++;
			}
		}
		vec_words.push_back(str);
		str = {};
		i = 0;
	}
	m_program.close();

	return vec_words;
}