//===================================================================
// Name        : Program 1
// Author      : Michelle Pinnock
// Version
// Description : Program 1 Part 2 Assignment
//===================================================================
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

map<string, int> myWords;
map<int,int> bLines;
map<int,vector<string>> bycount;
int counter =0;
string line;

void longestWords()
{
    string::size_type longest = 0;
    for(auto element: myWords)
    {
        if(element.first.size() > longest)
            longest = element.first.size();
    }
    string output = "";
    string comma =", ";
    for(auto it: myWords)
    {
        if(it.first.size() == longest)
        {
            string current = it.first;
            output += current + comma;
        }
    }
    if(output.length()==0)
        cout << output;
    else
    {
        output = output.substr(0, output.length()-2);
        cout << output << endl;
        
    }
}
void cFlag()
{
    string::size_type longest = 0;
    for(auto element: myWords)
    {
        if(element.first.size() > longest)
            longest = element.first.size();
    }
    string output = "";
    string comma =", ";
    for(auto it: myWords)
    {
        if(it.first.size() == longest)
        {
            string current = it.first + "(" + to_string(it.second) + ")";
            output += current + comma;
        }
    }
    if(output.length()==0)
        cout << output;
    else
    {
        output = output.substr(0, output.length()-2);
        cout << output << endl;
    }
}
void mFlag()
{
    map<int,vector<string>> bycount;
    string::size_type longest = 0;
    int counter = 0;
    
    for(auto it: myWords)
    {
        if(it.first.size() > longest)
            longest = it.first.size();
    }
    string output = "";
    string comma =", ";
    for(auto it: myWords)
    {
        if(it.first.size() == longest)
        {
            if(it.second > counter)
                counter = it.second;
        }
    }
    for(auto it: myWords)
    {
        if(it.first.size() == longest)
        {
            if(it.second == counter)
            {
                string current = it.first;
                output += current + comma;
            }
        }
    }
    if(output.length()==0)
        cout << output;
    else
    {
        output = output.substr(0, output.length()-2);
        cout << output << endl;
    }
}
void cmFlag()
{
    map<int,vector<string>> bycount;
    string::size_type longest = 0;
    int counter = 0;
    
    for(auto it: myWords)
    {
        if(it.first.size() > longest)
            longest = it.first.size();
    }
    string output = "";
    string comma =", ";
    for(auto it: myWords)
    {
        if(it.first.size() == longest)
        {
            if(it.second > counter)
                counter = it.second;
        }
    }
    for(auto it: myWords)
    {
        if(it.first.size() == longest)
        {
            if(it.second == counter)
            {
                string current = it.first + "(" + to_string(it.second) + ")";
                output += current + comma;
            }
        }
    }
    if(output.length()==0)
        cout << output;
    else
    {
        output = output.substr(0, output.length()-2);
        cout << output << endl;
    }
}

int main(int argc, char * argv[])
{
    map<int,int> myLines;
    map<int,int> bLines;
    string fileName, line, word;
    int curr, max, b;
    bool cflag = false;
    bool mflag = false;
    bool bflag = false;
    
    ifstream myFile;
    
    if (argc <2)
    {
        cerr << "NO FILES" << endl;
    }
    for(int i=1; i <argc; i++)
    {
        max=0;
        if(strcmp(argv[i], "-c") ==0)
        {
            cflag =true;
            continue;
        }
        if(strcmp(argv[i], "-m") ==0)
        {
            mflag =true;
            continue;
        }
        if(strcmp(argv[i], "-b") ==0)
        {
            bflag =true;
            continue;
        }
        if (strncmp(argv[i], "-",1) == 0 && strncmp(argv[i], "-c",2)!=0 && strncmp(argv[i], "-m",3)!=0 && strncmp(argv[i], "-b",4)!=0)
        {
            cerr << argv[i]<<" "<<"UNRECOGNIZED FLAG" << endl;
            exit(0);
        }
        
        myFile.open(argv[i]);
        if(myFile.is_open())
        {
            while(getline(myFile, line))
            {
                b=0;
                stringstream iss(line);
                while(iss >> word)
                {
                    //cout << word.length()<< endl;
                    b= b + word.length();
                    b= b+1;
                    ++myWords[word];
                }
                ++bLines[b-1];
                
                curr = line.length();
                ++myLines[curr];
                if(max < curr)
                {
                    max = curr;
                }
                
                //cout <<"Length:"<< b<<endl;
                
            }
            
            cout << argv[i] << ":"<< endl;
            myFile.close();
            
            
            if((bflag==true)&&(mflag==false)&&(mflag==false))                   //b flag
            {
                longestWords();
                map<int, int>::iterator rit;
                rit = bLines.find(-1);
                bLines.erase(rit);
                if(bLines.empty())
                {
                    cout << 0 << endl;
                }
                else
                    cout <<(--bLines.end())->first<< endl;
            }
            if((cflag==true)&&(mflag==false)&&(bflag==false))                  //c flag
            {
                cFlag();
                map<int, int>::iterator rit;
                rit =myLines.find(max);
                cout << rit->first <<"(" << rit->second << ")" <<endl;
            }
            if((mflag==true)&&(cflag==false)&&(bflag==false))                  //m flag
            {
                mFlag();
                map<int, int>::iterator rit;
                rit =myLines.find(max);
                cout << rit->first << endl;
            }
            if((cflag==true)&&(mflag==true)&&(bflag==false))                  //c flag & m flag
            {
                cmFlag();
                map<int, int>::iterator rit;
                rit =myLines.find(max);
                cout << rit->first <<"(" << rit->second << ")" <<endl;
            }
            if((bflag==true)&&(mflag==true)&&(mflag==true))                  //all flag arguments
            {
                cmFlag();
                map<int, int>::iterator rit;
                rit = bLines.find(-1);
                bLines.erase(rit);
                if(bLines.empty())
                {
                    ++bLines[0];
                    cout << rit->first <<"(" << rit->second << ")" <<endl;
                }
                else
                    cout <<(--bLines.end())->first<< "(" << (--bLines.end())->second << ")"<< endl;
            }
            if ((bflag==false)&&(cflag==false)&&(mflag==false))
            {
                longestWords();
                map<int, int>::iterator rit;
                rit =myLines.find(max);
                cout << rit->first <<endl;
            }
            
            myWords.clear();
            myLines.clear();
            bLines.clear();
        }
        else
            cerr << argv[i]<< " FILE NOT FOUND" << endl;
        
    }
}


