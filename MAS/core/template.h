#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <cmath>
#include <time.h>
#include <istream>
#include <iostream>
#include <fstream> //ifstream
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

typedef unsigned int uint;
typedef unsigned char byte;
typedef unsigned short ushort;

float gauss(int value, float mean, float varDis);

#endif // TEMPLATE_H
