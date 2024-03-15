#include <string>

#include "HttpKey.h"

using namespace std;

HttpKey::HttpKey() {
}

bool HttpKey::operator <(const HttpKey& rhs) const {
	return (this->path + this->code).compare(rhs.path + rhs.code) < 0;
}

bool HttpKey::operator ==(const HttpKey& rhs) const {
	return this->path == rhs.path && this->code == rhs.code;
}

