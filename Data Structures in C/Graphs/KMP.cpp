
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void lps(char *p,int m,int *F);
int kmp(char *t,char *p);

int main()
{
    char txt[100],pat[100];
    int res;
    printf("Enter text:");
    //scanf("%[^\n]s",txt); 
    gets(txt);
    printf("Enter Pattern to be searced:");
   //scanf(" %[^\n]s",pat); 
   gets(pat);
    res=kmp(txt,pat);
    if(res==-1)
      printf("pattern not found");
      else
       printf("patern found at %d index",res);
       
}
void lps(char *p,int m,int *F)
{
    
    F[0]=0;
    int i=1;
    int j=0;
    
    while(i<m)
    {
        if(p[i]==p[j])
        {
            F[i]=j+1;
            i=i+1;
            j=j+1;
        }
        else if (j>0)
          j=F[j-1];
        else
        {
             F[i]=0;
             i=i+1;
        }
    }
}
int kmp(char *t,char *p)
{
     
    int i=0;
    int j=0;
    int m=strlen(p);
    int n=strlen(t);
    int  *F =(int *)malloc(sizeof(int )*m);
    lps(p,m,F);
    while(i<n)
    {
        if(t[i]==p[j])
        {
            if(j==m-1)
              return i-j;
            else
            {
              i=i+1;
              j=j+1;
            }
            
        }
        else
        {
            if(j>0)
              j=F[j-1];
             else
               i=i+1;
        }
        
    }
    return -1;
}
             

