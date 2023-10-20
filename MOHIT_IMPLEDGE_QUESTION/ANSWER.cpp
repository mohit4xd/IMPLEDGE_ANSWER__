#include <iostream>
#include <fstream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

//COMPOUND STRING CHECKING FUNCTION


bool COMP(string word, unordered_set<string> &st)
{
    int l = word.length();
    for (int i = 0; i < l; i++)
    {
        string pre = word.substr(0, i + 1);
        string suf = word.substr(i + 1);
        if ((st.find(pre) != st.end() && st.find(suf) != st.end()) ||
            (st.find(pre) != st.end() && COMP(suf, st)))
        {
          
            return true;
        }
    }
    return false;
}

//FUNCTION FOR ARRANGING STRING IN ALPHABEDICALLY ORDER;

bool mycomp(string a, string b)
{

    return a < b;
}


int main()
{
    auto start = high_resolution_clock::now();        //START OF EXEXUTION TIMER


    fstream new_file;                       
  
    if (new_file.is_open())
    {
        new_file << "My Function \n";
        new_file.close();
    }
   string file_path =R"(C:\Users\HP\Desktop\MOHIT_IMPLEDGE_QUESTION\input_02.txt)";
    new_file.open(file_path, ios::in);
    vector<string> words;
    if (new_file.is_open())
    {
        string sa;

        while (getline(new_file, sa))
        {
            words.push_back(sa);
        }

        new_file.close();

       
    }

    int n = words.size();
    vector<string> result;
    unordered_set<string> st(begin(words), end(words));
    for (int i = 0; i < n; i++)
    {
        string word = words[i];
        if (COMP(word, st))
        {
            result.push_back(word);
        }
    }

    sort(result.begin(), result.end(), mycomp);
 
   //FINDING OUT LAGREST ,SECOND LARGEST  STRING

    string s1 = "";
    string s2 = "";
    int z = 0,zz=0;
    for (int i = result.size() - 1; i >=0; i--)
    {
        z = result[i].length();
        if (z >= s1.length())
        {
            s1 = result[i];
        }
    }
    for (int i = result.size() - 1; i >= 0; i--)
    { 

         zz = result[i].length();
        if (zz >= s2.length() && result[i] != s1)
        {
            s2 = result[i];
        }
    }
    cout << "Longest Compound Word : "
         << " " << s1 << endl;
           cout<<endl;
    cout << "Second Longest Compound Word : "
         << " " << s2 << endl;
           cout<<endl;
    auto stop = high_resolution_clock::now();                         //END OF EXECUTION TIME
    auto duration = duration_cast<milliseconds>(stop - start);
    cout <<"Time taken to process file  :  " << duration.count() << " milli seconds"<<endl;
    cout<<endl;
    cout<<"------------------------------------------------------------------------------------------"<<endl;

}
