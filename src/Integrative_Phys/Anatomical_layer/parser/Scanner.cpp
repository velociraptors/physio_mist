#include "Scanner.h"

ProtegeScanner::ProtegeScanner() 
{
	
	//constructor.

}


//returns the next token.
//The token string is saved in *buffer. The function returns the token type.
//An indentifier or a string will be saved in *buffer.
ProtegeToken ProtegeScanner::getNextToken(char *buffer) 
{
	char nextChar = nextCharNoWS();	//gets next non-white space character.

	//sometimes, a token starts with a "%" symbol. We need to ignore this.
	//We ignore the next two hex characters, because they represent special characters that are not
	//compatible with C++.
	if (nextChar == '%')
	{
		skipTwoChars(nextChar);
	}


	char tokenBuffer[MAX_TOKEN_LEN] = "";
	ProtegeToken pToken = T_ERROR;

		//tokenBuffer will hold the token string.

				//if the next char is a punctuation, check if it is a '"'
	if ( ispunct(nextChar) )
	{
										//searches the symbol table
		
		if ( nextChar == '"')
		{
			append(tokenBuffer,nextChar);
													//if a string is encountered
			while ( true )
			{
				nextChar = getNextChar();
				if ( nextChar == '\\' )
				{
													//handles special characters,like \" and \n
					nextChar = getNextChar();
					if (nextChar == '"')
						append(tokenBuffer,nextChar);
					else if (nextChar == 'n')
						append(tokenBuffer,'\n');	//appends a newline character
				}
				else if ( nextChar == '"')
				{
													//if an end quote is encountered, break loop.
					append(tokenBuffer,nextChar);	//appends final quote to string.
					break;							//exits loop, because the string is finished.
				}
				else
				{
													//appends everything else to buffer.
					append(tokenBuffer,nextChar);
				}
			}
			pToken = T_STRING;						//return a string type
		} //end if ' " '
		else if ( nextChar == '[' )					//if a "[" is found, parse as a class.
		{
			while ( true )
			{
				nextChar = getNextChar();
				
				if ( nextChar == ']')
				{
													//if an end ] is encountered, break loop.
						
					break;							//exits loop, because the string is finished.
				}
				else if ( isalnum(nextChar) )
				{
					//appends everything else to buffer.
					append(tokenBuffer,nextChar);
				}
				else
				{
					append(tokenBuffer,'_');
				}
			}
			pToken = T_CLASS;
		}
		else
		{
			append(tokenBuffer,nextChar);

			switch (nextChar)
			{
			case '(':
				pToken = T_LP;
				break;
			case ')':
				pToken = T_RP;
				break;
			default:
				pToken = T_ERROR;
			}
		}


		//if a string is NOT encountered, a regular punctuation token will be returned, if it is not undefined.
	}
		//if the next char is alphabetical, or numerical...
	else if ( isalnum(nextChar) )
	{
		append(tokenBuffer,nextChar);
		
		if ( isdigit(nextChar) )	//if the first character is a digit, put a character in front of it.
		{
			char tempBuffer[MAX_TOKEN_LEN] = "N"; //puts an "N" in front of a digit.

			strcpy(tokenBuffer,strcat(tempBuffer,tokenBuffer));
			
		}

		while ( true )
		{
			nextChar = peekNextChar();

			if ( isalnum(nextChar) || nextChar == '_' )
			{
				//if the next char is alphanum, append it to tokenBuffer
				append(tokenBuffer,nextChar);
				getNextChar();

			}
			else if ( nextChar == '+' )
			{
				//if a + sign is encountered
				append(tokenBuffer,'_'); //append an underscore
				getNextChar();
			}
			else if ( nextChar == '-')
			{
				//if a - sign is encountered, append it to buffer
				append(tokenBuffer,'_');	//instead, we will append an underscore, because C++ vars can't have '-'
				getNextChar();
			}
			else if (nextChar == '%')
			{
				//if a '%' is found, ignore the next two hex chars.
				skipTwoChars(nextChar);
			}
			else
			{
				//if nextChar is something else, break out of loop.
				break;
			}		//end if statements
		}			//end while
		//pToken = TokenTable.GetSymbolType (tokenBuffer);	//check the table for any character string token, like "of".
		
			//it must be an identifier.
		
		pToken = T_ID;
		if ( strcmp(tokenBuffer,"of") == 0)			//if tokenBuffer equals "of", return T_OF
		{
			pToken = T_OF;
		}
		
	}				// end if
	else if ( isdigit(nextChar) )
	{
									
		//in the .pins file, digits do not appear as integers, only as part of other tokens.
		
	}

	strcpy(buffer,tokenBuffer);	//copies tokenBuffer into buffer, which is passed in as an argument.
	return pToken;				//also returns the token type.

}

//returns the next NON-whitespace character in a file.
char ProtegeScanner::nextCharNoWS()
{
	if ( isFileOpen() )
	{
		char c;
		if ( ! fileAtEnd() )  c = fin.get();	//gets next character in the file.
		else return EOF;						//if reached file end, return EOF

		if ( isspace(c) ) nextCharNoWS();		//if the next character is a space, do a recursive call.
		else return c;							//otherwise, everything is okay, return c.
	}
	else return 0x00;							//if the file is not even open, return 0x00

}

//skips over two characters and stores the third character in c.
void ProtegeScanner::skipTwoChars(char &c) 
{
	getNextChar();	//skip two chars
	getNextChar();
	c = getNextChar();
}

//returns the next character in the file, regardless of what it is.
char ProtegeScanner::getNextChar() 
{
	 if ( isFileOpen() )
	 {
		 if ( ! fileAtEnd() ) return fin.get();
	 }
	 return 0x00;
}

//Peeks at the next character in the file, but does not move the file cursor.
char ProtegeScanner::peekNextChar() 
{
	if ( isFileOpen() )
	{
		if ( ! fileAtEnd() ) return fin.peek();
	}
	return 0x00;
}

//appends a character to the end of str.
//The character c is added to the end of str.
void ProtegeScanner::append(char *str, char c) 
{
	int len = strlen(str);
	if ( len < MAX_TOKEN_LEN - 1 )
	{
		str[len] = c;
		str[len+1] = '\0';	//adds null term
	}

}

//opens file for scanning.
void ProtegeScanner::openFile(const char *fileName) 
{
	
		fin.open(fileName);	//open file for reading

		if (!fin)
		{
			cerr << "File Could Not Be Found" << endl;
			exit(1);
		}
		else cout << "File " << fileName << " opened successfully." << endl;
}

//close file
void ProtegeScanner::closeFile() 
{
	if ( isFileOpen() )
	{
		fin.close();
	}
	
}

//checks if file is open.
bool ProtegeScanner::isFileOpen()
{
	return fin.is_open();
}

//checks if file cursor reached the EOF
bool ProtegeScanner::fileAtEnd()
{
	return fin.eof();
}