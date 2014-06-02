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
    
    void setlatlon(int lat, int lon){
        latitude = lat;
        longitude = lon;
    }
    
    
    loc(const loc& objSource){
        
        cout<<"copy constructor of loc is called "<<endl;
        
        longitude = objSource.longitude;
        latitude = objSource.latitude;
    }
    
    void show();
    friend loc operator+(const loc& op1,const loc&  op2);
    
    //equal to operator
    // 1. without reference in the parameter, again a copy constructor is called
    // 2. without a const in the parameter, mistaken changes can be made in the code
    // 3. should return a reference otherwise will end up in calling a copy constructor, again creating a object.
    //void operator=(const loc& objRhs);
    loc& operator=(const loc& objRhs);
};


void loc::show(){
    cout<< longitude<< " ";
    cout<< latitude<<endl;
}

loc operator+(const loc& op1, const loc& op2){
    
    loc temp;
    
    temp.longitude = op1.longitude + op2.longitude;
    temp.latitude = op1.latitude + op2.latitude;
    
    return temp;
}

//will this create new object, when the object is returned ?
//void loc::operator=(const loc& objRhs){
loc& loc::operator=(const loc& objRhs){
    
    latitude = objRhs.latitude;
    longitude = objRhs.longitude;

    cout<<"\n\n\n"<<"about to return a *this in operator = "<<endl;
    
    return *this;
}

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    
    loc ob1(10,20), ob2(5,30), ob3(9,9);

    cout<<"\n\n\n"<<"about to call--> ob1 = ob1 + ob2;  "<<endl;
    /*
     1. ob1. operator + ( ob2 );
     2. return the temp in operator +
     3. ob1.operator = ( temp )
     */
    ob3 = ob1 = ob1 + ob2;
    
    ob1.show();
    ob3.show();
    
    ob1.setlatlon(990, 990);
    
    cout<<"\n\n"<<"this should not be 990,990"<<endl;
    ob3.show();
    

    return 0;
}

/*
Output of the above code
 
 Hello, World!
 
 
 about to call--> ob1 = ob1 + ob2;
 
 about to return a *this in operator =
 
 about to return a *this in operator =
 15 50
 15 50
 
 this should not be 990,990
 15 50
 Program ended with exit code: 0




*/