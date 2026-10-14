#include <iomanip>
#include <cctype>
#include <algorithm>
#include <sstream>
#include "number_analysis.h"

bool isInteger(const string& vvid) {
    return vvid.find('.') == string::npos;
}

bool isEven(const string& vvid) {
    if (!isInteger(vvid)) {
        return false;
    }
    int number = stoi(vvid, nullptr, 0);
    return number % 2 == 0;
}

string getNumberFormat(const string& vvid) {
    if (vvid.length() > 2 && vvid[0] == '0' && (vvid[1] == 'x' || vvid[1] == 'X')) {
        return "ш≥стнадц€тковий";
    }
    if (vvid.length() > 1 && vvid[0] == '0') {
        return "в≥с≥мковий";
    }
    return "дес€тковий";
}

int getDecimalLength(const string& vvid) {
    stringstream ss;
    ss << setbase(10) << stol(vvid, nullptr, 0);
    return ss.str().length();
}