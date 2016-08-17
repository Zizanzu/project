#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "template.h"

class Environment{
public:
    int x, y, grayScale;
    byte *pixels;
    bool createEnvironment(const char* fn, int dx, int dy, int grayScale);

    inline int getIdx(int dx, int dy){
        return x * y + dy * x + dx;
    }


    inline byte getValue(int dx, int dy){
        return pixels[x * y + dy * x + dx];
    }
    inline void setValue(int dx, int dy, byte pix){
        pixels[x * y + dy * x + dx] = pix;
    }

    int getSize(){
       return x*y;
    }

    bool writeImage(const char* fn);
    bool writeImage(const char* fn, byte *image);
    void getNeighbors(int idx, int *neigh, int &size);

};


#endif // ENVIRONMENT_H
