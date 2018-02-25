// The input program for names
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
        float org =myString.length();
        string strbinary = "";

        for (int i = 0; i < myString.size(); ++i){
          string str = "";
          bitset<8> bin(myString[i]);
          stringstream ss;
          ss<<bin;
          str=ss.str();
          strbinary.insert(strbinary.length(),str);
        }

        //cout<<"The binary code of the string is "<<strbinary<<endl<<endl;
        string result="";

        int len=0;
        int c=0;
        int z=strbinary.length();
        for (int i=0; i<strbinary.length(); i++){
            if(strbinary[0]=='1'){
                result ="0000";
                continue;
            }
            if(i==(strbinary.length()-1)){
                bitset <4> bin(c+1);
                int x = result.length();
                stringstream ss;
                ss<<bin;
                string str=ss.str();
                result.insert(x,str);
            }
            if(strbinary[i]=='0'){
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
        if(strbinary[z-1]=='0'){
            int x = result.length();
            result.insert(x,"@");
        }
        float f = result.length();
        float r = (f/org)*100;
        cout<<"the compression ratio is "<<r<<"%"<<endl;
        results.push_back(result);
    }

    ofstream out("result.txt");
    for(string digit : results){
        out<<digit<<endl;
    }
    out.close();

    //double Ratio;

    return 0;
}
