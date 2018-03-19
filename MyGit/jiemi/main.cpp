#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void change(string &s)  //��д��ĸ����Сд
{
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            s[i]+=32;
        }
    }
}

bool IsSentence(string s)  //�ж��Ƿ���һ������
{
    string ss[20];
    int j=0;
    for(int i=0; i<s.length(); i++) //�������е�ÿ��������ȡ����
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
        ifstream ifile("F://dictionary.txt",ios::binary);  //ֻ�����ļ�
        while(getline(ifile,temp))   //���ļ���һ�д���temp
        {
            string word;
            for(int i=0; i<temp.length(); i++)   //��temp�еĵ�����ȡ�����ŵ�word��
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
        if(k==j)  //����������˻�û���������
            return false;
    }
    return true;
}

int main()
{
    string str;
    getline(cin,str);
    change(str);
    for(int i=1; i<26; i++)  //����25�ν���
    {
        string s=str;
        for(int j=0; j<s.length(); j++)
        {
            if(s[j]!=' ')
            {
                s[j]-=96;
                s[j]+=26;  //��ֹ�����s[j]-iΪ��
                s[j]=(s[j]-i)%26;
                s[j]+=96;
            }
        }
        if(IsSentence(s))
            cout<<s<<endl;
    }
    return 0;
}
