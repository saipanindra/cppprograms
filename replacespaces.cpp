/* 
 * File:   main.cpp
 * Author: transformer
 *
 * Created on June 21, 2015, 10:06 PM
 */

#include <cstdlib>
#include <string.h>
#include <iostream>


using namespace std;

/*
 * 
 */
char * replaceSpaces(char *input)
{
    int len = strlen(input);
    int numSpaces = 0;
    for(int i = len - 1 ; i >= 0; i--)
	if(input[i] == ' ' )
	    numSpaces++;
    int newlen = len + 2 * numSpaces;
    char *buffer = (char*)malloc(newlen);
    buffer[newlen] = '\0';
    for(int i = len - 1 ; i>= 0  ; i--)
    {
	if(input[i] == ' ')
	{
	    buffer[newlen - 1] = '0';
	    buffer[newlen - 2] = '2';
	    buffer[newlen - 3] = '%';
	    newlen = newlen - 3;
	}
	else
	{
	    buffer[newlen - 1] = input[i] ;
	    newlen = newlen - 1;
	}
    }
    return buffer;
}

int main(int argc, char** argv) {
    char * replacedString = replaceSpaces("Hello world");
    cout << replacedString;

}

