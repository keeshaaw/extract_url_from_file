/*
 * find_url.h
 *
 *  Created on: Jul 20, 2015
 *      Author: KESHAW
 */

#ifndef FIND_URL_H_
#define FIND_URL_H_

#include<vector>
#include<string>

std::vector<std::string> find_url(const std::string&);

std::string::const_iterator url_beg(std::string::const_iterator, std::string::const_iterator);

std::string::const_iterator url_end(std::string::const_iterator, std::string::const_iterator);

bool not_url_char(char);

#endif /* FIND_URL_H_ */
