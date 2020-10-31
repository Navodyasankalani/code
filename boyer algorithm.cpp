#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<bits/stdc++.h>
#include<malloc.h>
#include<vector>
#include<algorithm>
# define d 256 

using std::ofstream;
using namespace std;

struct line{
	string num;
	int index;
};

ofstream r("results.txt");

void heuristic(string str,int size,int bchar[d])  
{  
    int i;  
  
    for(i=0;i<d;i++) // Initialize all occurrences as -1   
        bchar[i]=-1;  
   
    for(i=0;i<size;i++)  
        bchar[(int)str[i]]=i;  
}   

void boyersearch(char* pat,vector<char>myvector)
{
	
	int m=strlen(pat);
	int n=myvector.size();

    int bchar[d];  
  
    heuristic(pat, m, bchar);  
  
    int s=0; // s=shift of the pattern 
    
    while(s<=(n-m))  
    {  
        int j=m-1;  
  
        while(j>=0 && pat[j]==myvector[s+j])  
            j--;  
  
        if (j<0)  
        {  
            cout<<"pattern Index : "<<s<<endl;
			r<<j<<endl;  
  
            s +=(s+m<n)?m-bchar[myvector[s+m]] : 1;  
  		}  
  
        else
          
            s += max(1,j-bchar[myvector[s+j]]);  
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
		
		boyersearch(pat,myvector);
}

