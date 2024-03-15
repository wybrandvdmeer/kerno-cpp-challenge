#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include "HttpObject.h"

using namespace std;

static std::vector<std::string> requestKeywords = {"POST", "PATCH", "GET", "PUT"};
static std::vector<std::string> responseKeywords = {"HTTP/1.1"};
static std::string traceIDKeyword = "X-Trace-ID:";

HttpObject::HttpObject(Type type) {
	HttpObject::type = type;
}

bool HttpObject::isHttpRequest(const std::string &line) {
	std::vector<std::string> words = split(line);
	return !words.empty() && contains(requestKeywords, words.front());
}

bool HttpObject::isHttpResponse(const std::string &line) {
	std::vector<std::string> words = split(line);
	return !words.empty() && contains(responseKeywords, words.front());
}

void HttpObject::getTraceId(std::string &line) {
	std::vector<std::string> words = split(line);
	if(words.front() == traceIDKeyword) {
		HttpObject::traceId = words.at(1);
	}
}

std::vector<std::string> HttpObject::split(const std::string &s) {
	std::stringstream ss(s);
	std::string item;
	std::vector<std::string> elems;
	while (std::getline(ss, item, ' ')) {
		elems.push_back(item);
	}
	return elems;
}

bool HttpObject::contains(std::vector<std::string> v, std::string x) {
	return std::find(v.begin(), v.end(), x) != v.end();
}
