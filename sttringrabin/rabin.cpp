#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<bits/stdc++.h>
#include<malloc.h>
#include<vector>
#include<algorithm>
#define d 256

using std::ofstream;
using namespace std;

struct line{
	string num;
	int index;
};

ofstream r("results.txt");

int q=101;
void rabinsearch(char* pat,vector<char>myvector)
{
	
	int m=strlen(pat);
	int n=myvector.size();
	

    int i, j;  
    int p = 0; // hash value for pattern  
    int t = 0; // hash value for text  
    int h = 1;  
  
    for(i=0;i<m-1;i++)     // The value of h should be "pow(d, M-1)%q"  
        h=(h*d)%q;  
      
    for(i=0;i<m;i++)       // Calculate the hash value of pattern and first  
    {  
        p=(d*p+pat[i])%q;  
        t=(d*t+myvector[i])%q;  
    }  
  
    for(i=0;i<=n-m;i++)  
    {  
        if(p==t)  
        {  
            for(j=0;j<m;j++)  
            {  
                if(myvector[i+j]!=pat[j])  
                    break;  
            }  
  
            if(j==m)
			{
				cout<<"Pattern Index : "<< i<<endl; 
				r<<i<<endl; 
			}
        }   
        if(i<n-m)  
        {  
            t=(d*(t-myvector[i]*h)+myvector[i+m])%q;  
    
            if(t<0)  
            t=(t+q);  
        }  
    }  	
}
int main()
{
	vector<char>myvector;
	ifstream f;
	f.open("pi.txt");
	string x;
	long int temp=0;
	
	if(f)
		{
			while(!f.eof())
			{
				getline(f,x);
				temp++;
				if(temp>21)
				{
					for(long int i=0;i<x.size();i++)
					{
						int length=x.size();
						if(!isalnum(x[i]))
						{
							if(x[i]==':')
							{
								x.erase(i--,1);
								length=x.size();
								break;
							}
							x.erase(i--,1);
							length=x.size();
						}
					}
					stringstream st(x);
					line li;
					st>>li.num>>li.index;
					
					for(int j=0;j<54;j++)
					{
						if(li.num.size()!='\0')
						{
							myvector.push_back(li.num[j]);
						}
					}
				}
			}
		}
		char pat[]="961113";
		
		cout<<"My birthday string is : "<< pat <<endl<<endl<<endl;
		
		rabinsearch(pat,myvector);
}


