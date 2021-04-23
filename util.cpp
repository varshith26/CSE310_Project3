// Varshith Poonati
//T-Th 6:00-7:15 pm
// CSE 310

#include "util.h"
#include<iostream>
#include<string>

string nextCommand(int *s, int *d, int *f){
    string s1,s2;
    cin>>s1;
    if(s1=="find")
    {
        cin>>*s>>*d>>*f;
        return s1;
    }
    if(s1=="write")
    {
        cin>>s2>>*s>>*d;
        return s1;
    }
    if(s1=="stop")
    {
        return s1;
    }
}
