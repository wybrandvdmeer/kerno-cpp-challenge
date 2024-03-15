#include <shared_mutex>
#include <map>

#include "HttpObject.h"
#include "HttpKey.h"

#ifndef HTTP_KEY_MAP
#define HTTP_KEY_MAP

class HttpKeysMap {
public:
	std::map<HttpKey,int> * get();
	void release();

private:
	std::map<HttpKey, int> httpKeys;
	std::shared_mutex mtx;
};

#endif
