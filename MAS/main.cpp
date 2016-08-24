#include <core/template.h>
#include <core/environment.h>



int main(int argc, char *argv[])
{

    //QCoreApplication a(argc, argv);

    cout << argv[1] << endl;

    Mat im_rgb  = imread(argv[1]);
    Mat im_gray;
    cvtColor(im_rgb,im_gray,CV_RGB2GRAY);

    imwrite(argv[2],im_gray);

    namedWindow( "Result window", CV_WINDOW_AUTOSIZE );
    imshow( "Result window", im_gray );

    Environment *env = new Environment();
    env->createEnvironment(argv[2], im_gray.cols, im_gray.rows,125);
    int idx = 0;
    for(int i=0; i < im_gray.cols; i++){
        cout << i << ": ";
        for(int j=0; j <  im_gray.rows; j++){

            env->tostring(idx);
            idx++;
        }
        cout << endl;
     }

    env->writeImage(argv[3]);

    //remove(argv[2]);

    waitKey(0);
    return 0;
}
