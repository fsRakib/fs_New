#include <stdio.h>
int main()
{
    char ch1[100],ch2[100];
    int i, j, count=0;
    fgets(ch1, 100, stdin);
    puts(ch1);
    for (i=0; (ch1[i]!=0); i++)
    {
        count++;
    }
    j=count-1;
    for(i=0,j=count-1; i<count; i++,j--)
    {
        ch2[j]=ch1[i];
    }
    puts(ch2);
    return 0;
}
