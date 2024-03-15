#include <algorithm>
#include <string>
#include <iostream>
#include <thread>

#include "ParseInput.h"
#include "ReportThread.h"

using namespace std;

char* getOption(char ** begin, char ** end, const std::string & option)
{
    char ** itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return *itr;
    }
    return NULL;
}

int main(int argc, char ** argv) {
	std::string reportPath;
	int interval=1;

	char *file = getOption(argv, argv + argc, "-o");
	if(file != NULL) {
		reportPath.append(std::string(file));
	}

	char *intervalString = getOption(argv, argv + argc, "-i");
	if(intervalString != NULL) {
		try {
			interval = std::stoi(intervalString);
		} catch(std::exception const &e) {
			cerr << "Wrong interval argument.\n";
			return 1;
		}
	}

	ParseInput parseInput;
	ReportThread reportThread(&parseInput.httpKeysMap);
	std::thread t = reportThread.report(reportPath, interval);
	parseInput.parse();

	t.join();

	return 0;
}
