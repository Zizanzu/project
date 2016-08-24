#ifndef SEGMENTATION
#define SEGMENTATION

#include "environment.h"
#include "template.h"
#include "magent/mas.h"
#include "config.h"

class Segmentation {
public:
    Environment *env;
    Config* conf;
    Segmentation(Environment *_env, Config* _conf) {
        env = _env;
        conf = _conf;
    }
    virtual ~Segmentation() {
        free(env);
    }
    virtual void initialize()=0;
    virtual void run()=0;
    virtual void exportImage(Environment *result)=0;
    void excute(Environment *result) {
        initialize();
        run();
        exportImage(result);
    }
    virtual void statistic(Environment *result, Environment *gt,
            const char* fn)=0;
};

#endif // SEGMENTATION

