#ifndef MAS
#define MAS

#include "agent.h"
#include "core/spiderinfo.h"

class MASS {
public:
    Agent* aglist;
    SpiderInfo* info;
    MASS(){
        aglist = 0;
        info = 0;
    }
    ~MASS() {
        free(aglist);
        free(info);
    }
};


#endif // MAS

