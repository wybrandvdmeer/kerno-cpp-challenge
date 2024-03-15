#include <map>
#include <thread>
#include <string>
#include <fstream>

#include "HttpKeysMap.h"

using namespace std;

class ReportThread {
public:
	ReportThread(HttpKeysMap * httpKeysMap);
	std::thread report(std::string path);
private:
	void reportInThread();
	HttpKeysMap *httpKeysMap;
	ofstream reportStream;
	void write(const char*);
};
