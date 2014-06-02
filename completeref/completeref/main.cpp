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
    
    loc(const loc& objSource){
        
        cout<<"copy constructor of loc is called "<<endl;
        
        longitude = objSource.longitude;
        latitude = objSource.latitude;
    }
    
    void show();
    friend loc operator+(loc op1, loc op2);
    
    //equal to operator
    loc operator=(loc objRhs);
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

//will this create new object, when the object is returned ?
loc loc::operator=(loc objRhs){
    
    latitude = objRhs.latitude;
    longitude = objRhs.longitude;

    cout<<"\n\n\n"<<"about to return a *this in operator = "<<endl;
    
    return *this;
}

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    
    loc ob1(10,20), ob2(5,30);

    cout<<"\n\n\n"<<"about to call--> ob1 = ob1 + ob2;  "<<endl;
    /*
     1. ob1. operator + ( ob2 );
     2. return the temp in operator +
     3. ob1.operator = ( temp )
     */
    ob1 = ob1 + ob2;
    
    ob1.show();
    

    return 0;
}

