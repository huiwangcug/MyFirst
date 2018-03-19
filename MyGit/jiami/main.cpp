#include <iostream>
#include <string>

using namespace std;

void change(string &s)  //大写字母都变小写
{
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            s[i]+=32;
        }
    }
}
int main()
{
    string str;
    getline(cin,str);
    change(str);
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]!=' ')
        {
            str[i]-=96;
            str[i]=(str[i]+3)%26;
            str[i]+=96;
            cout<<str[i];
        }
        else
            cout<<" ";
    }
    cout<<endl;
    return 0;
}
