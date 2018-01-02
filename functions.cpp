#include <ctype.h>
#include <string>
void upperString(std::string &String) {
	/*
	Change tous les charactères d'un string en majsucules
	*/
	for (int i(0); i < String.size(); i++) 
		String[i] = toupper(String[i]);
}

void swapChars(std::string &str, int p1, int p2) {
	/*
	la fonction modifie str en échangeant les valeurs de str[p1] et str[p2]
	*/
	char tmp(str[p1]);
	str[p1] = str[p2];
	str[p2] = tmp;
}