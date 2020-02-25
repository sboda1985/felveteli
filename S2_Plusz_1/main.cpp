#include <iostream>

using namespace std;

//i-1, j+1
int iprev(int i, int n)
{
    if ((i-1) >= 0)
    {
        return i-1;
    }
    return n-1;
}

int jnext(int j, int n)
{
    if (j + 1 <= n - 1)
    {
        return j + 1;
    }
    return 0;
}

int main()
{
    int lepes[100][100];
    int n = 11;
    int szamlalo = 1;
    int i= n/2;
    int j = n-1;
    lepes[i][j] = szamlalo;
    szamlalo++;
    do
    {
        while(lepes[iprev(i, n)][jnext(j, n)] == 0)
        {
            lepes[iprev(i, n)][jnext(j, n)] = szamlalo;
            i = iprev(i, n);
            j = jnext(j, n);
            szamlalo++;

        }
        j--;
        if(lepes[i][j] == 0)
        {
            lepes[i][j] = szamlalo;
            szamlalo++;
        }
    }
    while(szamlalo<n*n);

    int S = 0;
    for(int i=0; i<n; i++){
        S+=lepes[i][i];
    }
    cout << S;
    return 0;
}
