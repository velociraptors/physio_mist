/**************************************************************************************************
functions.cpp
Contributor(s):	Robin Hu
Description: Utility functions used for parsing purposes

***************************************************************************************************/
#include "functions.h"

char*	convertToUpper(char *str)
{
	int	length = strlen(str);
	for(int i = 0; i < length ; i++)
	{
		if ( str[i] >= 'a' )
			str[i] -= 32;
	}

	return str;
}

/*Inserts spaces after each character in a string. for example, "STRING" becomes "S T R I N G" */
char*	insertSpaces(const char *str)
{
	const int length = strlen(str);
	if (length == 0)	return "";

	const int newlength = length*2;
	char *newstr = new char[newlength];

	int newstrindex = 0;
	for(int i = 0; i < length; i++)
	{
		newstr[newstrindex] = str[i];

		if (i == (length - 1))
			newstr[newstrindex+1] = '\0';
		else
			newstr[newstrindex+1] = ' ';

		newstrindex += 2;
	}

	return newstr;
}

/*Convert a character to an integer.*/
float	convertCharToInt(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (c - '0');
	}
	else
		return (-1);
}

/*Given a string, like "1.234", this function returns a floating point value, 1.234*/
double	convertStrToFloat(const char* str)
{
	const int	length = strlen(str);
	int	magnitude = -1;

	/*Find number of digits in front of decimal point, if there is a decimal point.*/
	for(int i = 0; i < length; i++)
	{
		if ( str[i] != '.' )	magnitude++;
		else	break;
	}

	double base = 1;
	for (int i = 0; i < magnitude; i++)
	{
		base *= 10;
	}

	double finalnumber = 0;
	for (int i = 0; i < length; i++)
	{
		if ( str[i] == '.' ) continue;

		double	digit = convertCharToInt(str[i]);
		if (digit == (-1))
		{
			//That means there is an illegal character
			return 0;
		}
		
		finalnumber += digit*base;
		base = base/10;
	}

	if ( str[0] == '-')	finalnumber = -finalnumber;

	return finalnumber;
}
