#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>

std::string getWord(std::vector<std::string> &wordVector) {
	return wordVector[rand() % wordVector.size()];
}

void loadWords(std::string fileName, std::vector<std::string> &target) {
	std::ifstream fileStream(fileName);
	std::string l;
	while (std::getline(fileStream, l)) {
		target.push_back(l);
	}
}