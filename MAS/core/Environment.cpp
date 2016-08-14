#include "template.h"
#include "environment.h"

bool Environment::createEnvironment(const char *fn, int dx, int dy, int grayScale){

    x = dx;
    y = dy;
    grayScale = grayScale;

    ifstream file;
    file.open(fn, ios::binary);
    if(!file){
        cerr << "Cannot open the file image" << fn << endl;
        return false;
    }
    int length = x * y, idx = 0, size = sizeof(byte);
    pixels = new byte[length];
    byte c;

    while(idx < length){
        file.read((char*) &c, size);
        pixels[idx++] = c;
    }

    file.close();
    return true;
}

bool Environment::writeImage(const char* fn) {
    ofstream file;
    file.open(fn, ios::binary);
    if (!file) {
        cerr << "Cannot save the files image MRI 3D" << fn << endl;
        return false;
    }
    int tmp;
    int begin = 0;
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                tmp = pixels[begin];
                file.write((char*) &tmp, sizeof(char));
                begin++;
            }
        }
    file.close();
    return true;
}

void Environment::getNeighbors(int idx, int *neigh, int &size){

    size = 0;
    x = y = 3;
    cout << "Id 1, 1: " << getIdx(1, 1) << endl;
    int py = idx % (x * y) / x;
    int px = idx % (x * y) % x;
    cout << "Px: " << px << endl;
    cout << "Py: " << py << endl;
    for(int n = -1; n <= 1; n++){
        if(n + py < 0 || n + py >= y)
            continue;
        for(int m = -1; m <= 1; m++){
            if(m + px < 0 || m + px >=x)
                continue;
            neigh[size++] = getIdx(m + px, n + py);
        }

    }

}
