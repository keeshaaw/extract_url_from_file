#include<iostream>
#include<vector>
#include<string>
#include"find_url.h"

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::endl;


int main()
{
	string s;
	vector<string> url;

	while(getline(cin,s))
	{
		url = find_url(s);
		for(vector<string>::const_iterator i = url.begin(); i != url.end(); ++i)
			cout << (*i) << endl;
	}

	return 0;
}
/*
 * main_url.cpp
 *
 *  Created on: Jul 24, 2015
 *      Author: KESHAW
 */




