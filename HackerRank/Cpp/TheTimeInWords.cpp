//https://www.hackerrank.com/challenges/the-time-in-words

#include<iostream>
#include<map>

using namespace std;

int main()
{
    map<int,string> timeMap;
    timeMap[1] = "one";
    timeMap[2] = "two";
    timeMap[3] = "three";
    timeMap[4] = "four";
    timeMap[5] = "five";
    timeMap[6] = "six";
    timeMap[7] = "seven";
    timeMap[8] = "eight";
    timeMap[9] = "nine";
    timeMap[10] = "ten";
    timeMap[11] = "eleven";
    timeMap[12] = "twelve";
    timeMap[13] = "thirteen";
    timeMap[14] = "fourteen";
    timeMap[15] = "fifteen";
    timeMap[16] = "sixteen";
    timeMap[17] = "seventeen";
    timeMap[18] = "eighteen";
    timeMap[19] = "nineteen";
    timeMap[20] = "twenty";
    timeMap[21] = "twenty one";
    timeMap[22] = "twenty two";
    timeMap[23] = "twenty three";
    timeMap[24] = "twenty four";
    timeMap[25] = "twenty five";
    timeMap[26] = "twenty six";
    timeMap[27] = "twenty seven";
    timeMap[28] = "twenty eight";
    timeMap[29] = "twenty nine";

    int h,m;
    cin>>h>>m;
    if(m==0)
    {
        cout<<timeMap[h]<<" o' clock";
    }
    else if(m==30)
    {
        cout<<"half past "<<timeMap[h];
    }
    else if(m==15)
    {
        cout<<"quarter past "<<timeMap[h];
    }
    else if(m==45)
    {
        cout<<"quarter to "<<timeMap[h+1];
    }
    else if(m<30)
    {
        if(m==1)
        {
            cout<<timeMap[m]<<" minute past "<<timeMap[h];
        }
        else
        {
            cout<<timeMap[m]<<" minutes past "<<timeMap[h];
        }

    }
    else
    {
        if(m==59)
        {
            cout<<timeMap[60-m]<<" minute to "<<timeMap[h+1];
        }
        else
        {
            cout<<timeMap[60-m]<<" minutes to "<<timeMap[h+1];
        }

    }
    cout<<endl;
}
