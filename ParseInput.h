#include <set>
#include <map>

#include "HttpObject.h"
#include "HttpKeysMap.h"

class ParseInput {
public:
	ParseInput();
	void parse();
	void regist(HttpObject * httpObject);
	HttpKeysMap httpKeysMap;

private:
	std::set<HttpObject*> httpObjects;
	void registHttpKey(HttpObject * left, HttpObject * right);
};
