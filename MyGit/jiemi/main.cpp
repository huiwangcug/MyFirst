#include <iostream>
#include <string>
#include <fstream>

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

bool IsSentence(string s)  //判断是否是一个句子
{
    string ss[20];
    int j=0;
    for(int i=0; i<s.length(); i++) //将句子中的每个单词提取出来
    {
        if(s[i]!=' ')
        {
            ss[j]+=s[i];
        }
        else
            j++;
    }
    while(j!=-1)
    {
        int k=j;
        string temp;
        ifstream ifile("F://dictionary.txt",ios::binary);  //只读打开文件
        while(getline(ifile,temp))   //读文件的一行存入temp
        {
            string word;
            for(int i=0; i<temp.length(); i++)   //将temp中的单词提取出来放到word中
            {
                if(temp[i]!=' ')
                    word+=temp[i];
                else
                    break;
            }
            if(ss[j]==word)
            {
                j--;
                break;
            }
        }
        ifile.close();
        if(k==j)  //如果查找完了还没有这个单词
            return false;
    }
    return true;
}

int main()
{
    string str;
    getline(cin,str);
    change(str);
    for(int i=1; i<26; i++)  //尝试25次解密
    {
        string s=str;
        for(int j=0; j<s.length(); j++)
        {
            if(s[j]!=' ')
            {
                s[j]-=96;
                s[j]+=26;  //防止下面的s[j]-i为负
                s[j]=(s[j]-i)%26;
                s[j]+=96;
            }
        }
        if(IsSentence(s))
            cout<<s<<endl;
    }
    return 0;
}
