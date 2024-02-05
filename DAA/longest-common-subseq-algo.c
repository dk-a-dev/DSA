#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(char x[], char y[], int xlen, int ylen)
{
    int l[6 + 1][6 + 1];
    for(int i=0;i<=xlen;i++){
        for(int j=0;j<=ylen;j++){
            if(i==0||y==0){
                l[i][j]=0;
            }
            else if(x[i-1]==y[j-1]){
                l[i][j]=l[i-1][j-1]+1;
            }
            else{
                l[i][j]=max(l[i-1][j],l[i][j-1]);
            }
        }
    }

    return l[xlen][ylen];
}
int main(int argc, char const *argv[])
{

    char x[] = "abaaba";
    char y[] = "babbab";
    int m = 6;
    int n = 6;
    printf("%d",lcs(x,y,m,n));
    return 0;
}
