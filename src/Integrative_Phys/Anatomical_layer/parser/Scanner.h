//Scanner. This class scans a Protege file for tokens.
//Author; Robin Hu
#ifndef SCANNER_H
#define SCANNER_H

#include <cstring>
#include <iostream>
#include <fstream>
#include "resource.h"
using namespace std;



//enum defining all the special tokens in the Protege Grammar
enum ProtegeToken
{
	T_ERROR,	//error token
	T_ID,		//identifier
	T_CLASS,
	T_STRING,	//"string"

	T_LP,	//parentheses
	T_RP,

	T_OF	// of

};


//scans .pins file char by char.
class ProtegeScanner
{
public:
	ProtegeScanner();
	void openFile(const char *fileName);
	void closeFile();
	ProtegeToken getNextToken(char * buffer);	//scans the input file. Does two things:
										//returns the token type. Saves the token string in buffer.
	bool fileAtEnd();
private:
	ifstream fin;
	bool isFileOpen();
	char peekNextChar();		//looks at next char in file, but does not move file ptr.
	char nextCharNoWS();		//returns the next non whitespace character in the input file.
	char getNextChar();			//returns the next character from the input filestream, regardless if it is a whitespace.
	void skipTwoChars(char &c); //skips two characters; saves the third character in c.
	void append(char * str, char c);	//appends c to the end of str.
	
};



#endif //SCANNER_H