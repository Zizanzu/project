#ifndef SPIDERSEGMENTATION
#define SPIDERSEGMENTATION

#include "magent/agentsegmentation.h"
#include "core/environment.h"

class SpiderSegmentation: public AgentSegmentation {
public:

    SpiderSegmentation(Config *_conf, Environment *_env);

    void exportImage(Environment *_result);
    void initialize();
    void runNStep();

    virtual void initAgents();
    void initDragline();
    void detectHistogram();
    void postProcess(int idxNotVisit, int *notVisit, Environment *_result);

    void statistic(Environment *result, Environment *gt, const char* fn);

};

#endif // SPIDERSEGMENTATION

