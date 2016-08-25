
#include "core/template.h"
#include "magent/spidersegmentation.h"
#include "magent/spider.h"
#include "core/spiderinfo.h"

void SpiderSegmentation::statistic(Environment *result, Environment *gt, const char *fn){

}

SpiderSegmentation::SpiderSegmentation(Config *_conf, Environment *_env):
    AgentSegmentation(_env, _conf){
        data->info = new SpiderInfo();
    }

void SpiderSegmentation::detectHistogram(){

}

void SpiderSegmentation::initAgents(){

    cout << "init agent cpu" << endl;
    data->info->numberAgentPerColony = atoi(conf->infos["spider_agent_per_colony"].c_str());
    data->aglist = new Spider[data->info->numberAgentPerColony*data->info->numberColony];

    int idx = 0;
    for(int i = 0; i < data->info->numberColony; i++){
        for(int j = 0; j < data->info->numberAgentPerColony; j++){
            data->aglist[idx].colony = i;
            Posision pos(rand() % env->x, rand() % env->y);
            data->aglist[idx].posision = pos;
            data->aglist[idx].lastposision = data->aglist[idx].posision;
            idx++;
        }
    }
}

void SpiderSegmentation::initDragline(){

    cout << "initDragline" << endl;

    SpiderInfo *si = (SpiderInfo*) data->info;
    cout << "number colony: "<< data->info->numberColony << endl;
    //clocl;
    int size = env->x * env->y;

    si->dls = (int*) malloc(size * si->nbDl * sizeof(int));
    if(si->dls == NULL){
        cout << "si->dls FAIL" << endl;
        exit(1);
    }

    fill_n(si->dls,size * si->nbDl, -1);

    si->nbSilkColony = (byte*) malloc(
                    size * si->nbDl * data->info->numberColony * sizeof(byte));
    if(si->nbSilkColony == NULL){
        cout << "si->nbSilkColony FAIL" << endl;
        exit(1);
    }

    fill_n(si->nbSilkColony, size * si->nbDl * data->info->numberColony,0);

    cout << "Time comsuming for initializing dragline is " << "set time"<< endl;

}

void SpiderSegmentation::initialize(){

    SpiderInfo *si = (SpiderInfo*) data->info;

    data->info->numberColony = atoi(
            conf->infos["spider_number_colony"].c_str());
    si->backprobability = atof(conf->infos["backprobability"].c_str());
    si->pAttractSelf = atof(conf->infos["pAttractSelf"].c_str());
    si->pAttractOther = atof(conf->infos["pAttractOther"].c_str());
    si->pSaturation = atof(conf->infos["pSaturation"].c_str());
    si->constantWeight = atof(conf->infos["constantWeight"].c_str());



    //detectHistogram();
    initAgents();
    initDragline();
}

void SpiderSegmentation::runNStep(){

    cout << "simulate cpu" << endl;

    int numberIterator = atoi(conf->infos["spider_iterator"].c_str());
    int size = data->info->numberColony * data->info->numberAgentPerColony;
    int next = 0;
    SpiderInfo *si = (SpiderInfo*) data->info;
    si->neigh = new int[8];
    si->scut = new int[si->nbDl];
    for(int i = 0; i < numberIterator; i++){
        if(i % 100 == 0)
            cout << "time spider: " << i << endl;
        for(int j = 0; j < size; j++){
            data->aglist[j].perception(env, data->info);
            data->aglist[j].decision(env, data->info, next);
            data->aglist[j].decision(env, data->info,next);
        }
    }

}

void SpiderSegmentation::exportImage(Environment *_result){

}
