#include <iostream>
#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_utils.hpp"
#include <boost/filesystem.hpp>
#include <string>
#include <fstream>
#include <streambuf>
class Loader {

public:

	Loader();
	char *get_file_contents(const char *filename);
	void loadEnemies();


};
