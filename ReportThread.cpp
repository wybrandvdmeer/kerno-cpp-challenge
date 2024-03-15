#include <string>
#include <map>
#include <thread>
#include <chrono>
#include <iostream>
#include <fstream>

#include "ReportThread.h"
#include "HttpKey.h"

using namespace std;

ReportThread::ReportThread(HttpKeysMap * httpKeysMap) {
	ReportThread::httpKeysMap = httpKeysMap;
}

void ReportThread::reportInThread() {
	while(true) {
		bool hdr=true;

		std::map<HttpKey,int> * httpKeys = httpKeysMap->get();
		for (const auto &p : *httpKeys) {
			HttpKey pp = p.first;
			char buf[1000];
			sprintf(buf, "%s,%s -> %d\n", pp.path.c_str(), pp.code.c_str(), p.second); 

			if(hdr) {
				write("Report\n");
				hdr = false;
			}	

			write(buf);
		}

		httpKeys->clear();

		httpKeysMap->release();

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
}

void ReportThread::write(const char * line) {
	if(ReportThread::reportStream.is_open()) {
		ReportThread::reportStream << line << std::flush;
	} else {
		cout << line << std::flush;
	}
}

std::thread ReportThread::report(std::string path) {
	if(!path.empty()) {
		ReportThread::reportStream.open(path.c_str());
	} 

	std::thread thread_obj(&ReportThread::reportInThread, this);
	return thread_obj;
}

