//https://www.hackerrank.com/challenges/encryption
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <math.h>
using namespace std;
int main()
{
    int l,lb,ub,i=0,k=0,rows,columns;
    char ch[85];
    gets(ch);
    l=strlen(ch);
    rows=(int)floor(sqrt(l));
    columns=(int)ceil(sqrt(l));
    if(rows*columns<l)
    {
        rows=columns;
    }
    char mat[rows][columns];
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            if(i*columns+j<l)
            {
                mat[i][j]=ch[i*columns+j];
            }
            else
            {
                mat[i][j]='\0';
            }
        }
    }
    for(int i=0;i<columns;i++)
    {
        for(int j=0;j<rows;j++)
        {
            if(mat[j][i]!='\0')
            {
                cout<<mat[j][i];
            }
        }
        cout<<" ";
    }
}
