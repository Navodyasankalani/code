#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<bits/stdc++.h>
#include<malloc.h>
#include<vector>
#include<algorithm>

using std::ofstream;
using namespace std;

struct line{
	string num;
	int index;
};

ofstream r("results.txt");

void kmpsearch(char* pat,vector<char>myvector)
{
	
	int m=strlen(pat);
	int n=myvector.size();
	
	int next[m+1];

	for(int i=0;i<m+1;i++)
		next[i]=0;

	for(int i=1;i<m;i++)
	{
		int j=next[i+1];

		while(j>0 && pat[j]!=pat[i])
		j=next[j];

		if(j>0 || pat[j]==pat[i])
		next[i+1]=j+1;
	}

	for(int i=0,j=0;i<n;i++)
	{
		if(myvector[i]==pat[j])
		{
			if(++j==m)
			{
				cout<<"Pattern Index : "<<i-j+1<<endl;
				r<<i<<endl;
			}
		}
		else if(j>0) 
		{
			j=next[j];
			i--;
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
		
		kmpsearch(pat,myvector);
}


