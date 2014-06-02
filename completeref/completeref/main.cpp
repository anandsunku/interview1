//
//  main.cpp
//  completeref
//
//  Created by anand on 02/06/14.
//  Copyright (c) 2014 AnandSunku. All rights reserved.
//

#include <iostream>

using namespace std;


void testingassignment();

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

    friend loc operator++(loc& op1);
    friend loc operator++(loc& op1,int);
    
    //equal to operator
    // 1. without reference in the parameter, again a copy constructor is called
    // 2. without a const in the parameter, mistaken changes can be made in the code
    // 3. should return a reference otherwise will end up in calling a copy constructor, again creating a object.
    loc& operator=(const loc& objRhs); 

};


void loc::show(){
    cout<< longitude<< " ";
    cout<< latitude<<endl;
}

//friend operator to loc class
loc operator+(const loc& op1, const loc& op2){
    
    loc temp;
    
    temp.longitude = op1.longitude + op2.longitude;
    temp.latitude = op1.latitude + op2.latitude;
    
    // the reference of the temp object is actually received in the = operator.
    // if not a reference is mentioned in the = operator, there would have been a call to copy constructor.
    return temp;
}

//im gonna make the ++ operator as a friend to the loc class
loc operator++(loc& op1){
    
    op1.latitude++;
    op1.longitude++;
    
    return op1;
}

loc operator++(loc& op1,int){
    
    op1.latitude++;
    op1.longitude++;
    
    return op1;
}



//will this create new object, when the object is returned ?
loc& loc::operator=(const loc& objRhs){
    
    latitude = objRhs.latitude;
    longitude = objRhs.longitude;

    cout<<"\n\n\n"<<"about to return a *this in operator = "<<endl;
    
    return *this;
}


class sappa {
    int m_internal;
    
    
    
public:

    sappa(){
        m_internal = 10;
    }
    
    sappa(int lhs){
        m_internal = lhs;
    }
    
    sappa& operator = (sappa& objrhs){
        
        m_internal =  objrhs.m_internal;
        
        return *this;
    }
    
    void show(){
        cout<<"m_internal = "<<m_internal<<endl;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    
    sappa ob1(20),ob2,ob3;
    
    ob3 = ob2 = ob1;
    
    cout<<"now ob2"<<endl;
    
    ob2.show();
    
    cout<<"now ob3"<<endl;
    
    ob3.show();
    
    return 0;
}

void testingunaryoperator()
{
    loc ob1(10,10);
    
    ++ob1;
    ob1.show();
    
    ob1++;
    ob1.show();
    
}

void testingassignment()
{
    loc ob1(10,20), ob2(5,30), ob3(9,9);
    
    cout<<"\n\n\n"<<"about to call--> ob1 = ob1 + ob2;  "<<endl;
    /*
     1. ob1. operator + ( ob2 );
     2. return the temp in operator +
     3. ob1.operator = ( temp )
     */
    ob3 = ob1 = ob1 + ob2; //todo : need to revert back
    
    ob1.show();
    ob3.show();
    
    ob1.setlatlon(990, 990);
    
    cout<<"\n\n"<<"this should not be 990,990"<<endl;
    ob3.show();
    

}


