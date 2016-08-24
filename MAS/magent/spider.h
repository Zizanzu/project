#ifndef SPIDER
#define SPIDER

#include "agent.h"

class Spider: public Agent {
public:
    void perception(Environment* env, SpiderInfo *info);
    void decision(Environment* env, SpiderInfo *info, int &next);
    void action(Environment* env, SpiderInfo *info, int next);

    int isAccess(int *neigh, int size1, int p);
};

#endif // SPIDER

