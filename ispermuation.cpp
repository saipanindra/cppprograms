/* 
 * File:   main.cpp
 * Author: transformer
 *
 * Created on June 21, 2015, 7:44 PM
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

/*
 * 
 */
bool isPermuation(char *str1, char *str2)
{
    int *checker = new int[256]();
   if(strlen(str1)!= strlen(str2))
       return false;
   for(int i=0; i < strlen(str1); i++)
   {
       checker[str1[i]]++;
   }
   for(int i = 0 ; i < strlen(str2); i++)
   {
	if(--checker[str2[i]] < 0)
	    return false;
   }
    return true;
}
   
    


bool isPermuationUsingSort(std::string str1, std::string str2)
{
    if(str1.length() != str2.length())
	return false;
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    return str1.compare(str2) == 0;
    
}

int main(int argc, char** argv) {

    cout << isPermuationUsingSort("hello", "hillo");//0
    cout << isPermuation("hello", "hello"); //1
    cout << isPermuation("hello", "hillo"); // 0
    return 0;
}

