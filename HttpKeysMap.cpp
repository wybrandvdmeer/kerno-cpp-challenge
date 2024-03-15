#include "HttpKeysMap.h"
#include "HttpKey.h"

using namespace std;

std::map<HttpKey,int> * HttpKeysMap::get() {
	mtx.lock();
	return &httpKeys;
}

void HttpKeysMap::release() {
	mtx.unlock();
}
