/* 
 * File:   main.cpp
 * Author: transformer
 *
 * Created on June 21, 2015, 11:51 AM
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

/*
 * 
 */
int hasDuplicates(char* str)
{
    int checker = 0;
    int checkerCaps = 0;
    int len = strlen(str);
    for(int i = 0 ; i < len ; i++)
    {
	if(str[i] < 'a')
	{
	    int val = str[i] - 'A';
	    if((checkerCaps & (1 << val)) > 0)
	    {
		return 1;
	    }
	    checkerCaps |= (1<<val);
	}
	else
	{
	    int val = str[i] - 'a';
	    if((checker & (1 << val)) > 0)
		    return 1;
	    checker |= (1 << val);
	}
    }
    return 0;
}
int main(int argc, char** argv) {
   int r = hasDuplicates("ZaZ") ;
   cout << r;
}



