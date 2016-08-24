#ifndef INFO
#define INFO

class SpiderInfo {
public:
    int numberColony;
    int numberAgentPerColony;
    int *neigh;
    int size1;
    float backprobability;
    float pAttractSelf;
    float pAttractOther;
    float pSaturation;
    float constantWeight;

    float* selectivity;
    float* mean;

    int* dls;
//	ushort* nbSilk;
    byte *nbSilkColony;
    int nbDl;

    int *scut;
    int size2;
};

#endif // INFO

