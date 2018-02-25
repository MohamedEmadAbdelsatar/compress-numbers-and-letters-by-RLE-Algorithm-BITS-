// The input program for numbers
#include<bits/stdc++.h>
#include <string>
#include <bitset>
#include <iostream>

using namespace std;

int main()
{

    ifstream in("in.txt");
    vector <string> lines;
    vector <string> results;
    string input;
    while (getline(in, input)){
       lines.push_back(input);
    }

    in.close();

    for(string myString : lines){
        int t=0;
        long long x = stoll (myString);
        queue <int> s;
        while(x >10){
            int c = x %10;
            s.push(c);
            x=x/10;
        }
        s.push(x);
        string val ="";
        while(!s.empty()){
            int i=0;
            bitset <8> bin(s.front());
            s.pop();
            stringstream ss;
            ss<<bin;
            string str=ss.str();
            val.insert(i,str);
            i+=8;
        }

        string result="";
        int len=0;
        int c=0;
        int z=val.length();
        float org=val.length();

        for (int i=0; i<val.length(); i++){
                if(val[0]=='1'){
                    result ="0000";
                    continue;
                }
                if(i==(val.length()-1)){
                    bitset <4> bin(c+1);
                    int x = result.length();
                    stringstream ss;
                    ss<<bin;
                    string str=ss.str();
                    result.insert(x,str);
                }
                if(val[i]=='0'){
                    if(c==15){
                        bitset <4> bin(c);
                        int x = result.length();
                        stringstream ss;
                        ss<<bin;
                        string str=ss.str();
                        result.insert(x,str);
                        c=0;
                    }
                    else{
                        c++;
                    }
                }
                else{
                    bitset <4> bin(c);
                    int x = result.length();
                    stringstream ss;
                    ss<<bin;
                    string str=ss.str();
                    result.insert(x,str);
                    c=0;
                }
        }
        if(val[z-1]=='0'){
            int x = result.length();
            result.insert(x,"@");
        }
        float f =result.length();
        float r =(f/org)*100;
        cout<<"the compression ratio is "<<r<<"%"<<endl;
        results.push_back(result);

    }


    ofstream out("result.txt");
    for(string digit : results){
        out<<digit<<endl;
    }
    out.close();
    return 0;
}
