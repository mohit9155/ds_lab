#include <stdio.h> 
#include <string.h>

void computeLPSArray(char* pat, int M, int* lps);
int rep[100]={0}; 
int k=0;

// Prints occurrences of txt[] in pat[] 
void KMPSearch(char* pat, char* txt) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 

	// create lps[] that will hold the longest prefix suffix 
	// values for pattern 
	int lps[M]; 

	// Preprocess the pattern (calculate lps[] array) 
	computeLPSArray(pat, M, lps); 

	int i = 0; // index for txt[] 
	int j = 0; 
	// index for pat[] 
		int c=0;
	while (i < N) { 
		if (pat[j] == txt[i]) { 
			j++; 
			i++; 
		} 

		if (j == M) { 
			printf("\nFound pattern at index %d ", i - j); 
			rep[k++]=i-j;
			j = lps[j - 1]; 
		} 

		// mismatch after j matches 
		else if (i < N && pat[j] != txt[i]) { 
			// Do not match lps[0..lps[j-1]] characters, 
			// they will match anyway 
			if (j != 0) 
				j = lps[j - 1]; 
			else
				i = i + 1; 
		} 
	} 
} 

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(char* pat, int M, int* lps) 
{ 
	// length of the previous longest prefix suffix 
	int len = 0; 

	lps[0] = 0; // lps[0] is always 0 

	// the loop calculates lps[i] for i = 1 to M-1 
	int i = 1; 

	while (i < M) { 
		if (pat[i] == pat[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else // (pat[i] != pat[len]) 
		{ 
			// This is tricky. Consider the example. 
			// AAACAAAA and i = 7. The idea is similar 
			// to search step. 
			if (len != 0) { 
				len = lps[len - 1]; 

				// Also, note that we do not increment 
				// i here 
			} 
			else // if (len == 0) 
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 
void replace(char s[],char txt[],char pat[])
{
	int lens,lentxt,lenp,i,j,shift,K;
	int a[100];
	lens=strlen(s);
	lentxt=strlen(txt);
	lenp=strlen(pat);
	if(lens==lenp)
	{
		//printf("k=%d",k);
		k--;
		
		while(k>=0)
		{
			//printf("ho");
			i=lens;
			j=0;
			while(i!=0)
			{
				txt[rep[k]++]=s[j++];
				i--;
			}
			k--;
		}
		puts(txt);
	}
	else if(lens<lenp)
	{
		k--;
		while(k>=0)
		{
			//printf("ho");
			i=lens;
			j=0;
			while(i!=0)
			{
				txt[rep[k]++]=s[j++];
				i--;
			}
			k--;
		}
		puts(txt);	
	}
		
}

// Driver program to test above function 
int main() 
{ 
	char txt[100],pat[100],s[100]; 
	printf("Enter a string:");
	gets(txt);
	printf("Enter a Pattern:");
	gets(pat);
	
	KMPSearch(pat, txt); 
	printf("\nEnter a word to replace:");
	gets(s);
	replace(s,txt,pat);
	
	
	return 0; 
} 
