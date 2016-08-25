#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <cmath>
#include <time.h>
#include <istream>
#include <iostream>
#include <map>
#include <fstream> //ifstream
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

typedef unsigned int uint;
typedef unsigned char byte;
typedef unsigned short ushort;

float gaussian(int value, float mean, float varDis);

typedef struct _map{
    int key;
    float value;
} mapx;


#endif // TEMPLATE_H
