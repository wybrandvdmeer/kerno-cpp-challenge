#include <string>

#include "HttpObject.h"
#include "HttpRequest.h"

HttpRequest::HttpRequest(std::string &line) {
	std::vector<std::string> words = HttpObject::split(line);
	if(words.size() < 1) {
		throw std::invalid_argument("no path available");
	}

	HttpRequest::path = words.at(1);
}
