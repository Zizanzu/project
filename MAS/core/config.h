#ifndef CONFIG
#define CONFIG

#include "template.h"

class Config {
public:
    map<string, string> infos;
    bool readFile(const char* fn);
};

#endif // CONFIG

