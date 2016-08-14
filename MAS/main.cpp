#include <QtWidgets/QApplication>

#include <core/template.h>
#include <core/environment.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main(int argc, char *argv[])
{

    //QCoreApplication a(argc, argv);
    cout << "Hello World!" << endl;
    Mat im_gray = imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);

    Environment *env = new Environment();
    env->createEnvironment(argv[1],1000,471,125);
    cout << env->pixels << endl;
    return 0;
}
