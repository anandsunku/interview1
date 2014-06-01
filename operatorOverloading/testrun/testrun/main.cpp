//
//  main.cpp
//  testrun
//
//  Created by anand on 29/05/14.
//  Copyright (c) 2014 AnandSunku. All rights reserved.
//  references
//  1.    http://www.tutorialspoint.com/cplusplus/increment_decrement_operators_overloading.htm
//  2.    effective c++ : Item 6:  Distinguish between prefix and postfix forms of increment and decrement operators.

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
    const Timetest operator++(int);
//  prefix operator overloading
    Timetest& operator++();
    
    //equal to operator
    void operator=(Timetest objRhs);
    
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
// looks like for the postfix, we need to return the const object.
const Timetest Timetest::operator++(int){
    
    //store the old value, increment internal value, return the object with old value
    Timetest oldvalue = *this;
    
    cout<<"post fix operator was called"<<endl;

    ++(*this).m_hour;
    ++(*this).m_minutes;
    
    return oldvalue;
}

//overloading the prefix operator
// looks like for the prefix , we need to return the reference.
Timetest& Timetest::operator++(){
    
    (*this).m_hour++;
    (*this).m_minutes++;
    
    return *this;
}

//overload the equalto operator
void Timetest::operator=(Timetest objRhs)
{
    cout<<"equal to operator called "<<endl;
    
    m_hour = objRhs.m_hour;
    m_minutes = objRhs.m_minutes;
}


// function to test the copy constructor
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
    
    Timetest objPostfix(10,10);
    
    // now increment the same, but not assign it anything.
    // what is happening inside
    //  1. it is creating an object for the previous value
    //  2. incrementing the self
    //  3. return the old object
    // so, now we have this object being incremented.
    // but we are not using the old object, we will see when that is going to get deleted.
    objPostfix++;
    
    //next my guess
    // now we need to receive an object that is
    Timetest objTemp; // ordinary constructor gets called
    
    // 1. old object copy cons gets called
    // 2. self increment the object
    // 3. return the const object from the postfix function
    // 4. now while receiving the same in objtemp
    //      4.1 will the equal to operator be called or copy constructor be called?
                //answer : mostly it is the equalto operator.
 
    //it is like
    //   objTemp.operator=(object returned by --> objPostfix.operator ++() );
    //   1. first the ++ operator function is called
    //   2. there is a object returned by the ++ operator function
    //   3. = operator function is called with object returned by the ++ operator
    //   4. once the equal (=) operator is finished, the destructor function of the object returned by the ++ operator is called
    //   5. now the objTemp is available to the code.
    
    // more deeper
    // ++ operator of objPostfix
    // const Timetest oldValue is returned
    // const Timetest oldValue is now the parameter for objTemp.operator = ( const Timetest OldValue )
    // so now
    //      const Timetest OldValue is transforming to """const Timetest& objRhs"""
    //
    // now we should not be able to modify the objRhs
    // the values are copied to the objTemp

    
    objTemp = objPostfix++;
    
    
    
    objPostfix.printyourself();
    
    cout<<"end of the main function"<<endl;
    
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