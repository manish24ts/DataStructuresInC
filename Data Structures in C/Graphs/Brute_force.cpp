/* Cprogram to implement  Brute Force Algorithm */
#include<stdio.h>
#include<string.h>
int BruteForcesearch( char *pat, char *text)
{
       int i,j;
      int m=strlen(pat);    // length of pattern
       int n=strlen(text);    // length of text
       for(i=0;i<=n-m;i++)
      {
          for(j=0;j<m;j++)
           {
              if(text[i+j]!=pat[j])
                  break;
           }
              if(j==m)
                     return i;
          
          
     }
     return -1;
}

int main()
{
    char text[50],pat[30];
    int res;
    printf("Enter Text :");
    gets(text);
    printf("Enter Pattern:");
    gets(pat);
    res=BruteForcesearch(pat,text);
    if(res==-1)
         printf("Pattern Not found in the given text\n");
    else
       printf("Pattern found at %d index ",res);
}
