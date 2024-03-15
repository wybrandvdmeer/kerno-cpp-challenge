#include <string>

#include "HttpObject.h"

class HttpResponse : public HttpObject {
public:
	HttpResponse(std::string &line);
};
