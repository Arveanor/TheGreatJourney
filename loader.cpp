#include <cstring>
#include "loader.h"
#include "Atts.h"
#include <boost/lexical_cast.hpp>

namespace bfs = boost::filesystem;
/*
char *get_file_contents(const char *filename)
{
	std::ifstream t;
	int length;
	t.open(filename);   			   // open input file
	t.seekg(0, std::ios::end);    // go to the end
	length = t.tellg();           // report location (this is the length)
	t.seekg(0, std::ios::beg);    // go back to the beginning
	char *buffer = new char[length];    // allocate memory for a buffer of appropriate dimension
	t.read(buffer, length);       // read the whole file into the buffer
	t.close();                    // close file handle

	return buffer;
}
*/
Loader::Loader() {

}

void Loader::loadEnemies() {
	//scan through a known subdirectory, and read all xml files...
	rapidxml::xml_document<> nmeDoc;
	rapidxml::xml_node<> *node;
	rapidxml::xml_attribute<> *attr;
	//rapidxml::file<> file("");
	Atts *tempEnemy;	
	bfs::directory_entry tempEntry;
	bfs::directory_iterator end_itr;
	bfs::directory_iterator dit = bfs::directory_iterator("Enemies");
	
	int dl, dh = 0;
	int numFiles = 0;
	char *fname = new char[512];
	for(dit; dit != end_itr; dit++) {
		std::cout << "path = " << dit->path().relative_path() << std::endl;
		fname = strcpy(fname, dit->path().relative_path().string().c_str());
		rapidxml::file<> file(dit->path().relative_path().string().c_str());
		nmeDoc.parse<0>(file.data());
		node = nmeDoc.first_node("Drake");	
		tempEnemy = new Atts();
		std::cout << node->name() << std::endl;
		node = node->first_node("name");
		tempEnemy->setName(node->value());
		std::cout << node->value() << std::endl;
		node = node->next_sibling();
		std::cout << node->value() << std::endl;
		tempEnemy->setPwr(boost::lexical_cast<int>(node->value()));
		node = node->next_sibling();
		tempEnemy->setDef(boost::lexical_cast<int>(node->value()));
		node = node->next_sibling();
		tempEnemy->setPrc(boost::lexical_cast<int>(node->value()));
		node = node->next_sibling();
		tempEnemy->setVit(boost::lexical_cast<int>(node->value()));
		node = node->next_sibling();
		tempEnemy->setExp(boost::lexical_cast<int>(node->value()));
		node = node->next_sibling();
		tempEnemy->setMaxHp(boost::lexical_cast<int>(node->value()));
		node = node->next_sibling();
		dl = boost::lexical_cast<int>(node->value());
		node = node->next_sibling();
		tempEnemy->setDmgRange(dl, boost::lexical_cast<int>(node->value()));
		node = node->next_sibling();
		tempEnemy->setArmor(boost::lexical_cast<int>(node->value()));
	} 
}
