//
//  main.cpp
//  howmuch
//
//  Created by anand on 02/06/14.
//  Copyright (c) 2014 AnandSunku. All rights reserved.
// references : http://www.gotw.ca/gotw/009.htm

#include <iostream>

using namespace std;

class nobody {
};

class character {
    char value;
};
class integers{
    int intval;
};

class doubles{
    double dvalue;
};

class fewmembers {
    char value;
    int secondone;
    char value1;
    double thirdone;
};

class diffmembers {
    char value;
    int secondone;
    char value1;
    double thirdone;
};

class withstatic :public integers{
public:
    static int  value;
    
    static void showoff();
    
    char value1;
};

void withstatic::showoff(){
    cout<<"this is too much "<<endl;
}

int main(int argc, const char * argv[])
{
    cout<< "jai vinayaka"<<endl;
    
    nobody ob1;
    character ob2;
    integers ob4;
    doubles ob5;
    withstatic ob6;
    
    fewmembers ob10;
    diffmembers ob11;

    
    printf("size of nobody = %ld object size = %ld\n", sizeof(nobody),sizeof(ob1));
    
    printf("size of character = %ld  object size = %ld\n", sizeof(character), sizeof(ob2));

    printf("size of integers = %ld  object size = %ld\n", sizeof(integers), sizeof(ob4));

    printf("size of doubles = %ld  object size = %ld\n", sizeof(doubles), sizeof(ob5));
    
    printf("size of withstatic = %ld  object size = %ld\n", sizeof(withstatic), sizeof(ob6));
    
    printf("more space \n\n\n");
    
    printf("size of fewmembers should be = %ld \n", sizeof(char)+sizeof(int)+sizeof(char)+sizeof(double));
    
    printf("size of fewmembers = %ld  object size = %ld\n", sizeof(fewmembers), sizeof(ob10));
    
    printf("size of diffmembers = %ld  object size = %ld\n", sizeof(diffmembers), sizeof(ob11));
    
    return 0;
}

