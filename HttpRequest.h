#include <string>

#include "HttpObject.h"

class HttpRequest : public HttpObject {
public:
	HttpRequest(std::string &line);
};
