#ifndef AGENTSEGMENTATION
#define AGENTSEGMENTATION

#include "core/segmentation.h"
#include "core/environment.h"
#include "mas.h"
//#include "Agent.h"
//#include "Info.h"

class AgentSegmentation: public Segmentation {
public:

//	Agent* aglist;
//	Info* info;
    MASS *data;

    AgentSegmentation(Environment *_env, Config* _conf):Segmentation(_env,_conf){
//		aglist=0;
//		info=0;
        data=new MASS();
    }
    ~AgentSegmentation(){}
    inline void run(){
        runNStep();
    }
    virtual void exportImage(Environment *_result)=0;
    virtual void initialize()=0;
    virtual void runNStep()=0;
    virtual void initAgents()=0;

    virtual void statistic(Environment *result, Environment *gt, const char* fn)=0;
};


#endif // AGENTSEGMENTATION

