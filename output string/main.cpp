// The output program for numbers
#include<bits/stdc++.h>
#include <string>
#include <bitset>
#include <iostream>

using namespace std;

int main()
{
    ifstream in("../input string/result.txt");
    vector <string> lines;
    vector <string> results;
    string input;

    while (getline(in, input)){
       lines.push_back(input);
    }

    in.close();

    for(string myString : lines){
        int z=myString.length();
        bool o = false;
        if(myString[z-1]=='@'){
            myString.erase(z-1,1);
            o = true;
        }
        string fin="";
        string result ="";
        for(int i=0; i<myString.length(); i+=4){
            string x = myString.substr(i,4);
            int c = stoi(x,nullptr,2);
            while(c>-1){
                if(i==(myString.length()-4)){
                    if(c>0){
                        result.insert(result.length(),"0");
                    }
                    else if (c==0){
                        if(o==false){
                            result.insert(result.length(),"1");
                        }
                    }
                }
                else{
                    if(c>0){
                        result.insert(result.length(),"0");
                    }
                    else if (c==0){
                        result.insert(result.length(),"1");
                    }
                }
                c--;
            }

            stringstream sstream(result);
            string output;
            while(sstream.good()){
                bitset<8> bits;
                sstream >> bits;
                char c = char(bits.to_ulong());
                output += c;
            }
            fin=output;

        }
        results.push_back(fin);
    }
    for(string digit : results){
        cout <<digit<<endl;
    }
    ofstream out("result.txt");
    for(string digit : results){
        out<<digit<<endl;
    }

    out.close();

    return 0;
}
