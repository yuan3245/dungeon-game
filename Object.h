#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class Object{
public:
    Object();
    Object(string, string);

    void setName(string);
    void setTag(string);
    string getName();
    string getTag();

//private:
    string name;
    string tag;

};



#endif // OBJECT_H_INCLUDED
