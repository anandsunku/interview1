//
//  main.cpp
//  completeref
//
//  Created by anand on 02/06/14.
//  Copyright (c) 2014 AnandSunku. All rights reserved.
//

#include <iostream>

using namespace std;

class loc {
    int longitude,latitude;
    
public:
    
    loc() {}
    
    loc(int lg, int lt){
        longitude = lg;
        latitude = lt;
    }
    void show();
    friend loc operator+(loc op1, loc op2);
};


void loc::show(){
    cout<< longitude<< " ";
    cout<< latitude<<endl;
}

loc operator+(loc op1, loc op2){
    
    loc temp;
    
    temp.longitude = op1.longitude + op2.longitude;
    temp.latitude = op1.latitude + op2.latitude;
    
    return temp;
}

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    
    loc ob1(10,20), ob2(5,30);
    
    ob1 = ob1 + ob2;
    ob1.show();

    return 0;
}

