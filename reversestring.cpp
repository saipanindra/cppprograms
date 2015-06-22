/* 
 * File:   main.cpp
 * Author: transformer
 *
 * Created on June 21, 2015, 2:41 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include<iostream>
#include <algorithm>
using namespace std;

/*
 * 
 */ 
char* reverse2(char *str) 
{ 
    if(!str)return str;
    if(strlen(str) == 1) return str;
    char *buffer = (char *)malloc(sizeof(str));
    char *res = buffer;
    strcpy(buffer, str);
    char *end =  buffer;
    while(*end)
    {
       ++end;
    }
    end--;
    while(buffer < end)
    {
	char temp = *buffer;
	*buffer = *end;
	buffer++;
	*end = temp;
	end--;
    }
    return res;
}

int main(int argc, char** argv) {
    char *input = "hello world";
    cout << reverse2(input);
}



