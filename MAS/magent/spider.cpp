
#include "spider.h"

void Spider::perception(Environment *env, SpiderInfo *info){
    SpiderInfo *si = (SpiderInfo*) info;

    si->size1 = 0;
    si->size2 = 0;
    //perception

    for (int n = -1; n <= 1; n++) {
        if (n + posision.y < 0 || n + posision.y >= env->y)
            continue;
        for (int m = -1; m <= 1; m++) {
            if (m + posision.x < 0 || m + posision.x >= env->x)
                continue;
            if(n==m && n==0)
                continue;
            si->neigh[si->size1] = env->getIdx(m + posision.x,n + posision.y);
            si->size1++;
        }
    }

    int idxPos = env->getIdx(posision.x, posision.y);
    for (int k = 0; k < si->nbDl; k++) {
        if (si->dls[idxPos * si->nbDl + k] != -1) {
            si->scut[si->size2] = si->dls[idxPos * si->nbDl + k];
            si->size2++;
        }
    }
}

void Spider::decision(Environment* env, SpiderInfo *info, int &next) {
    SpiderInfo *si = (SpiderInfo*) info;
    mapx probability[8 + si->nbDl];
    int proIdx = 0;
    int randomnext[8 + si->nbDl];
    int randIdx = 0;
    float totalWeight = 0;
    int idxPos = env->getIdx(posision.x, posision.y);
    int idxLP = env->getIdx(lastposision.x, lastposision.y);
    for (int k = 0; k < si->size1; k++) {
        if (idxLP == si->neigh[k])
            continue;
        probability[proIdx].key = si->neigh[k];
        probability[proIdx].value = si->constantWeight;
        totalWeight += si->constantWeight;
        proIdx++;
    }

    for (int m = 0; m < si->size2; m++) {
        if (idxLP == si->scut[m])
            continue;
        float ws = 0;
        int tmp = 0;
        for (int k = 0; k < si->nbDl; k++) {
            tmp = idxPos * si->nbDl + k;
            if (si->dls[tmp] == si->scut[m]) {
                float n1 = si->nbSilkColony[tmp * info->numberColony + colony];
                float sum = 0;
                for (int h = 0; h < info->numberColony; h++) {
                    sum += si->nbSilkColony[tmp * info->numberColony + h];
                }
                ws = si->pAttractSelf * min(n1, si->pSaturation);
                ws += si->pAttractOther * min(sum - n1, si->pSaturation);
                int index = isAccess(si->neigh, si->size1, si->scut[m]);
                if (index != -1) {
                    probability[index].value += ws;
                } else {
                    probability[proIdx].key = si->scut[m];
                    probability[proIdx].value = ws;
                    proIdx++;
                }
                totalWeight += ws;
                break;
            }
        }
    }

    float maxV = 0, tmp;
    randIdx = 0;
    for (int k = 0; k < proIdx; k++) {
        tmp = probability[k].value / totalWeight;
        if (tmp > maxV) {
            randIdx = 0;
            randomnext[randIdx] = probability[k].key;
            randIdx++;
            maxV = tmp;
        } else if (tmp == maxV) {
            randomnext[randIdx] = probability[k].key;
            randIdx++;
        }
    }
    next = randomnext[rand() % randIdx];
}

void Spider::action(Environment *env, SpiderInfo *info, int next){
    SpiderInfo *si = (SpiderInfo*) info;
    float gau = gaussian(env->pixels[next], si->mean[colony], si->selectivity[colony]/2);

    int idxPos = env->getIdx(posision.x, posision.y);

    int py = next % (env->x * env->y) / env->x;
    int px = next % (env->x * env->y) % env->x;
    Posision nextPosision(px, py);

    if (gau > 0.01) {
        bool found = false;
        int tmp = 0;
        for (int k = 0; k < si->nbDl; k++) {
            tmp = idxPos * si->nbDl + k;
            if (si->dls[tmp] == next) {
                si->nbSilkColony[tmp * info->numberColony + colony]++;
                found = true;
                break;
            }
        }
        if (!found) {
            for (int k = 0; k < si->nbDl; k++) {
                tmp = idxPos * si->nbDl + k;
                if (si->dls[tmp] == -1) {
                    si->dls[tmp] = next;
                    si->nbSilkColony[tmp * info->numberColony + colony]++;
                    break;
                }
            }
        }

        found = false;
        for (int k = 0; k < si->nbDl; k++) {
            tmp = next * si->nbDl + k;
            if (si->dls[tmp] == idxPos) {
                si->nbSilkColony[tmp * info->numberColony + colony]++;
                found = true;
                break;
            }
        }
        if (!found) {
            for (int k = 0; k < si->nbDl; k++) {
                tmp = next * si->nbDl + k;
                if (si->dls[tmp] == -1) {
                    si->dls[tmp] = idxPos;
                    si->nbSilkColony[tmp * info->numberColony + colony]++;
                    break;
                }
            }
        }

        lastposision = nextPosision;
    }

    float r = (float) rand() / 2147483647;
    if (r > si->backprobability) {
        posision = nextPosision;
    }
}


int Spider::isAccess(int *neigh, int size1, int p) {
    for (int i = 0; i < size1; i++) {
        if (neigh[i] == p)
            return i;
    }
    return -1;
}
