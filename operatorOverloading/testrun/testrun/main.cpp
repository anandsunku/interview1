//
//  main.cpp
//  testrun
//
//  Created by anand on 29/05/14.
//  Copyright (c) 2014 AnandSunku. All rights reserved.
//

#include <iostream>

using namespace std;

void basicTesting();

void objectTesting();

/*
 
 1. just cout and check for invocation of the ++ operator overload --> done
 2. what is that we can do between postfix and prefix   --> done
 3. return the pointer, reference, return by value --> in_progress
 4. make the friend implementation of the unary operator
 5.
*/

class Timetest {
public:
    int m_hour;
    int m_minutes;

public:
    Timetest(); // general constructor
    Timetest(int hour, int minutes); // parameter constructor
    Timetest(const Timetest& objSource);
    
    ~Timetest();
    
public:
//  postfix operator overloading
    Timetest operator++(int);
//  prefix operator overloading
    Timetest& operator++();
    
public:
    //general purpose dump
    void printyourself();

};

Timetest::~Timetest(){
    cout<<"Destructor was called "<<endl;
}

Timetest::Timetest(){
    
    cout<<"default constructor was called"<<endl;
    m_hour = 1;
    m_minutes = 1;

}

Timetest::Timetest(int hour, int minutes){

    cout<<"parameter constructor was called "<<endl;
    
    m_hour = hour;
    m_minutes = minutes;
    
}

Timetest::Timetest(const Timetest& objSource){

    cout<<"copy constructor was called "<<endl;
    
    m_hour = objSource.m_hour;
    m_minutes = objSource.m_minutes;
}

//general purpose dump
void Timetest::printyourself(){
    
    cout<<"dumping me: "<<endl;
    cout<<"m_hour = "<< m_hour<<endl;
    cout<<"m_minutes = "<< m_minutes<<endl;
}

// overloading the postfix operator
Timetest Timetest::operator++(int){
    
    //store the old value, increment internal value, return the object with old value
    int oldhour, oldminutes;
    
    cout<<"post fix operator was called"<<endl;
    
    oldhour = m_hour;
    oldminutes = m_minutes;
    
    m_hour++;
    m_minutes++;
    
    return Timetest(oldhour,oldminutes);
}

//overloading the prefix operator
Timetest& Timetest::operator++(){
    
    (*this).m_hour++;
    (*this).m_minutes++;
    
    return *this;
}

void TimeTester(const Timetest& objSource ){
    
    cout<<"this is the time tester function"<<endl;
    
    cout<<"value of the tester hour = "<< objSource.m_hour<<endl;
    
    cout<<"value of the tester minutes = "<<objSource.m_minutes<<endl;
}

void objectTesting()
{
    Timetest objTest;
    
    TimeTester(objTest++);
    
    cout<<"value of the main function hour = "<< objTest.m_hour<<endl;
    
    cout<<"value of the main function minutes = "<<objTest.m_minutes<<endl;
    
}


int main(int argc, const char * argv[])
{

    cout<<"this is my start jai vinayaka"<<endl;
    
//    basicTesting();
//    objectTesting();
    
    Timetest objPrefix(10,100);
    
    
    
    
    return 0;
}





// i would like to overload the ++ operator

class tester {
public:
    int m_value;
    
    // basic constructor
    tester()
    {
        m_value = 0;
    }
    
    // single value constructor
    tester(int value){
        m_value = value;
    }
    
    // copy constructor
    tester(const tester& copySource){
        m_value = copySource.m_value;
    }
    
public:
    //overloading the postfix operator
    int operator ++(int){
        
        cout<<"1. increment the internal value 2. then return the old value"<<endl;
        
        int oldValue = m_value;
        
        m_value++;
        
        return oldValue;
    }
    
    //overloading the prefix operator
    int operator ++(){
        cout<<"1. simple first increment the value and return the latest value"<<endl;
        
        m_value++;
        
        return m_value;
    }
    
};





void basicTesting()
{
    tester objTester;
    
    cout<<"i am gonna call the post fix operator"<<endl;
    
    int returnValue = objTester++;
    
    cout<<"return value ="<<returnValue<<endl<<"after calling the post fix the value of the m_value = "<<objTester.m_value<<endl;
    
    cout<<"now i am gonna call the prefix operator"<<endl;
    
    returnValue = ++objTester;
    
    cout<<"return value = "<<returnValue<<endl<<"after calling the prefix operator the value of the m_value"<<objTester.m_value<<endl;
    
}