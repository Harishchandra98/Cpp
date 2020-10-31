#include<iostream>
#include<cstring>
#include<fstream>

#define NO_OF_CHARS 256

using namespace std;

void fullSuffixMatch(int shiftArr[], int boarderArr[], string pat)
{
	int M = pat.length();
	int i = M;
	int j = M+1;
	boarderArr[i] = j;
	
	while(i>0)
	{
		while(j<=M && pat[i-1] != pat[j-1])
		{
			if(shiftArr[j] == 0)
			{
				shiftArr[j] = j-1;
			}
			
			j = boarderArr[j];
		}
		
		i--;
		j--;
		boarderArr[i] = j;
	}
}

void partialSuffixMatch(int shiftArr[], int boarderArr[], string pat)
{
	int M = pat.length();
	int j;
	
	j = boarderArr[0];
	
	for(int i=0;i<M;i++)
	{
		if(shiftArr[i] == 0)
		{
			shiftArr[i] == j;
		}
		
		if(i=j)
		{
			j = boarderArr[j];
		}
	}
}

void search(string txt, string pat, int array[], int *index)
{
	int M = pat.length();
	int N = txt.length();
	
	int boarderArray[M+1];
	int shiftArray[M+1];
	
	for(int i=0;i<=M;i++)
	{
		shiftArray[i] = 0;
	}
	
	fullSuffixMatch(shiftArray, boarderArray, pat);
	partialSuffixMatch(shiftArray, boarderArray, pat);
	
	int shift = 0;
	
	while(shift<=(N-M))
	{
		int j = M-1;
		
		while(j>=0 && pat[j] == txt[shift+j])
		{
			j--;
		}
		
		if(j<0)
		{
			(*index)++;
			array[*index] = shift;
			shift = shift+shiftArray[0];
		}
		
		else
		{
			shift = shift+shiftArray[j+1];
		}
	}
}

int main()
{
	string a;
	string b = "970412";
	
	int rowcount = 0;
	int locArray[a.length()];
	int index = -1;
	
	fstream file;
	file.open("pi.txt");
	
	while(!file.eof())
	{
		getline(file, a);
		rowcount++;
		
		//char cstr[a.size()+1];
		//a.copy(cstr, a.size()+1);
		//cstr[a.size()] = '\0';
		
		search(a, b, locArray, &index);
		
		int i;
		
		for(i=0;i<=index;i++)
		{
			cout<<"Pattern found at position: "<<locArray[i]<<endl;
		}
	}
	
	return 0;
}
