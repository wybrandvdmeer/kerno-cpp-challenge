#include <iostream>
#include <string>
#include <vector>

#include "Type.h"

#ifndef HTTP_OBJECT
#define HTTP_OBJECT

class HttpObject {
public:
	HttpObject(Type type);
	static bool isHttpRequest(const std::string &line);
	static bool isHttpResponse(const std::string &line);
	std::string traceId, code, path;
	void getTraceId(std::string &line);
	Type type;

protected:
	static std::vector<std::string> split(const std::string &s);
private:
	static bool contains(std::vector<std::string> v, std::string x);
};

#endif
