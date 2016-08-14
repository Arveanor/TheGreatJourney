#ifndef _LOADER_H_
#define _LOADER_H_

#include <iostream>
#include "Atts.h"
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include <boost/filesystem.hpp>
#include <string>
#include <fstream>
#include <streambuf>
#include <vector>

class Loader {
	const std::string enemiesDir = "Enemies";
public:

	Loader();
	char *get_file_contents(const char *filename);
	void loadEnemies(std::vector<Atts> &A);
};

#endif
