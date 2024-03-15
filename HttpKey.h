#include <iostream>
#include <string>
#include <vector>

#ifndef HTTP_KEY
#define HTTP_KEY

class HttpKey {
public:
	HttpKey();
	std::string path, code;
	HttpKey(std::string path, std::string code);
	bool operator <(const HttpKey& rhs) const;
	bool operator ==(const HttpKey& rhs) const;
};

#endif
