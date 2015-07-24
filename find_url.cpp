#include<vector>
#include<string>
#include<algorithm>
#include<cctype>
#include"find_url.h"

using std::vector;
using std::string;

vector<string> find_url(const string& s)
{
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();

	while(b != e)
	{
		/*finds the instance "://" and makes b point to the
		first character of the protocol name preceding the
		instance "://" */
		b = url_beg(b, e);

		//the condition will be true if we find an instance above
		if(b != e)
		{
			//find the rest of the url after "://"
			iter after = url_end(b, e);

			//stores the currently found url in the vector
			ret.push_back(string(b, after));

			//for finding more url if present in the file
			b = after;
		}
	}
	return ret;
}

string::const_iterator url_end(string::const_iterator b, string::const_iterator e)
{
	return find_if(b,e,not_url_char);
}

bool not_url_char(char c)
{
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";
	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(),c) != url_ch.end());
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e)
{
	static const string sep = "://";

	typedef string::const_iterator iter;
	//i marks for where the separator was found
	iter i = b;

	//search tries to find the sep in the range [b, e) if found i denotes :
	//if the sep is not found search will return its second argument e
	while((i = search(i,e,sep.begin(),sep.end())) != e)
	{
		//make sure that the separator is not at the beginning or end of line
		if(i != b && i + sep.size() != e)
		{
			//beg marks the end of protocol name
			iter beg = i;
			//beg[-1] is same as *(beg-1) the idea is that if container supports indexing so does it's iterator
			while(i != b && isalpha(beg[-1]))
				--beg;

			//is there at least one appropriate character before and after the separator?
			if(beg != i && !not_url_char(i[sep.size()])) //i[sep.size()] is same as *(i+sep.size())
				return beg;
		}
		//the separator we found was not part of a URL advance i past this separator
		i += sep.size();
	}
	return e;

}/*
 * extract_url.cpp
 *
 *  Created on: Jul 24, 2015
 *      Author: KESHAW
 */




