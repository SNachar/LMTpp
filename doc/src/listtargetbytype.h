#ifndef LIST_TARGET_BY_TYPE_H
#define LIST_TARGET_BY_TYPE_H

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std;

#include "target.h"
#include "token.h"

struct ListTargetByType {

    vector<Target*> list_example;
    vector<Target*> list_tutorial;
    //vector<Target*> list_generic_comment;
    vector<Target*> list_class_struct;
    vector<Target*> list_function;
    vector<Target*> list_webpage;
};


#endif

