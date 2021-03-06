//
//  main.cpp
//  allocation
//
//  Created by anand on 02/06/14.
//  Copyright (c) 2014 AnandSunku. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <new>

using namespace std;

class loc {
    int longitude, latitude;
    
public:
    loc(){}
    loc(int lg, int lt){
        longitude = lg;
        latitude = lt;
    }
    
    void show(){
        cout<<longitude<<endl;
        cout<<latitude<<endl;
    }
    
    void *operator new(size_t size);
    void operator delete(void* p);
};

//new overloaded relative to loc.
void *loc::operator new(size_t size){
    
    void *p;
    
    cout<<" in overloaded new. \n";
    
    p = malloc(size);
    
    if(!p){
        bad_alloc ba;
        throw ba;
    }
    
    return p;
}

void loc::operator delete(void *p){
    cout<< " In overloaded delete. \n";
    
    free(p);
}


int main(int argc, const char * argv[])
{

    // insert code here...
    cout << "jai vinayaka!\n";
    
    loc *p1, *p2;
    
    try {
        p1 = new loc (10,20);
    } catch (bad_alloc xa) {
        cout<< "Allocation error for p1 . \n";
        return 1;
    }
    
    try {
        p2 = new loc(-10,-20);
    } catch (bad_alloc xa) {
        cout<< " Allocation error for p2 .\n";
        return 1;
    }
    
    p1->show();
    p2->show();
    
    delete p1;
    delete p2;
    
    return 0;
}

