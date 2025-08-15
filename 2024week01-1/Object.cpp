#include <iostream>
#include"Object.h"

using namespace std;

void TestObjects(){
    Object *t[4];
    for(int i=0;i<3;i++){
        t[i]=new Object(i+1);
    }
    delete t[2];
    delete t[1];
    t[3]=new Object(4);
    delete t[3];
    delete t[0];
}