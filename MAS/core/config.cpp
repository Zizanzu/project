#include "template.h"
#include "config.h"

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
        //elems.push_back("\n");
    }
    return elems;
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}


istream& operator >>(istream& ins, map<string, string>& d) {
    string s, key, value;
    vector<string> x;
    // For each (key, value) pair in the file
    while (getline(ins, s)) {
        //string::size_type begin = s.find_first_not_of(" \f\t\v\r");
        string::size_type begin = s.find_first_not_of(" \f\t\v\r\n");

        // Skip blank lines
        if (begin == string::npos)
            continue;

        // Skip commentary
        if (string("#;").find(s[begin]) != string::npos)
            continue;

        x = split(s, '=');

        // Insert the properly extracted (key, value) pair into the map
        d[x[0]] = x[1];
    }

    return ins;
}

bool Config::readFile(const char* fn) {
    ifstream f(fn);
    if (!f) {
        cerr << "Cannot open the file config" << fn << endl;
        return false;
    }
    f >> infos;
    f.close();
    return true;
}

