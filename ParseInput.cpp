#include <iostream>
#include <string>
#include <initializer_list>

#include "ParseInput.h"
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "HttpKey.h"

using namespace std;

ParseInput::ParseInput() {
}

void ParseInput::parse() {
	string line;
	HttpObject *httpObject=NULL;
	while(std::getline(std::cin, line)) {
		if(line.size() == 0 && httpObject != NULL) {
			regist(httpObject);
			httpObject = NULL;
		} else if(httpObject == NULL && HttpObject::isHttpRequest(line)) {
			httpObject = new HttpRequest(line); 
		} else if(httpObject == NULL && HttpObject::isHttpResponse(line)) {
			httpObject = new HttpResponse(line);
		} else {
			httpObject->getTraceId(line);
		}
	}

	if(httpObject != NULL) {
		regist(httpObject);
	}
}

void ParseInput::regist(HttpObject *httpObject) {
	for(auto h : httpObjects) {
		if(h->traceId == httpObject->traceId) {
			HttpKey httpKey;
			if(httpObject->code.empty()) {
				httpKey.code = h->code; 
				httpKey.path = httpObject->path;
			} else {
				httpKey.code = httpObject->code; 
				httpKey.path = h->path;
			}

			std::map<HttpKey,int> *httpKeys = ParseInput::httpKeysMap.get();

			auto it = httpKeys->find(httpKey);

			if(it == httpKeys->end()) {
				(*httpKeys)[httpKey] = 1;
			} else {
				it->second++;
			}

			httpKeysMap.release();

			delete h;
			delete httpObject;

			httpObjects.erase(h);
			return;

		} 
	}

	ParseInput::httpObjects.insert(httpObject);
}
