#ifndef AGENT
#define AGENT

#include "core/template.h"
#include "core/environment.h"
#include "core/spiderinfo.h"

class Posision {
public:
    byte x, y;
    Posision(byte _x, byte _y) {
        x = _x;
        y = _y;
    }
    ~Posision() {
    }
};

class Agent {
public:
    Agent() :
            posision(0, 0), lastposision(0, 0), colony(0) {
    }
    virtual ~Agent() {
    }
    Posision posision, lastposision;
    byte colony;
    virtual void perception(Environment* env, SpiderInfo *info)=0;
    virtual void decision(Environment* env, SpiderInfo *info, int &next)=0;
    virtual void action(Environment* env, SpiderInfo *info, int next)=0;
};

#endif // AGENT

