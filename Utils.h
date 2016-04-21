#ifndef UTILS_H
#define UTILS_H


#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

int StoN(std::string _s) {
	std::string strNum;
	std::stringstream ss;
	ss << _s;
	int result;
	return ss >> result ? result : -1;
}

#endif
