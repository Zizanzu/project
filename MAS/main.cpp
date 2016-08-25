#include <core/template.h>
#include <core/environment.h>
#include <magent/spidersegmentation.h>
#include <core/config.h>


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

    Config *config = new Config();
    config->readFile(argv[4]);




    Environment *rsEnv = new Environment();

    SpiderSegmentation *spiderSg = new SpiderSegmentation(config, env);

    //spiderSg->SpiderSegmentation(config, env);

    spiderSg->excute(rsEnv);
    cout << "Result "<< endl;
    int idx1 = 0;
    for(int i=0; i < im_gray.cols; i++){
            cout << i << ": ";
            for(int j=0; j <  im_gray.rows; j++){

                rsEnv->tostring(idx1);
                idx1++;
            }
            cout << endl;
         }


    waitKey(0);
    return 0;
}
