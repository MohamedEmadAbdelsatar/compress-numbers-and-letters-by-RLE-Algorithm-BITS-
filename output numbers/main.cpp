// The output program for numbers
#include<bits/stdc++.h>
#include <string>
#include <bitset>
#include <iostream>

using namespace std;

int main()
{
    ifstream in("../input numbers/result.txt");
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
                else {
                    if(c>0){
                        result.insert(result.length(),"0");
                }
                    else if (c==0){
                        result.insert(result.length(),"1");
                    }
                }
                c--;
            }
        }

        for(int i=0; i<result.length(); i+=8){
            string z = result.substr(i,8);
            unsigned long n =bitset<8>(z).to_ulong();
            cout<<n;
        }
        cout<<endl;
    }
    return 0;
}
