#include <string>

#include "HttpObject.h"
#include "HttpResponse.h"

HttpResponse::HttpResponse(std::string &line) {
	std::vector<std::string> words = HttpObject::split(line);
	if(words.size() < 1) {
		throw std::invalid_argument("no http code available");
	}

	HttpResponse::code = words.at(1);
}
