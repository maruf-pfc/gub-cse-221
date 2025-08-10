#include <bits/stdc++.h>
using namespace std;

int check_parity(int n, int i, int code[])
{
    int p = 0, k;
    for (int j = i; j <= n; j = k + i)
    {
        for (k = j; k < j + i && k <= n; k++) 
        { 
            if (code[k] == 1) p++;
        }
    }
    if (p % 2 == 0) return 0; 
    else return 1;
}

void hamming_code(int data[], int num)
{
    int r = 0, m = 0, n, j = 1, c, code[50];

    while ((r + num + 1) > (pow(2, r))) r++;

    n = num + r;
    for (int i = 1; i <= n; i++)
    {
        if (i == pow(2, m) && m <= r)
        {
            code[i] = 0; 
            m++;
        }
        else
        {
            code[i] = data[j]; 
            j++;
        }
    }

    m = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == pow(2, m) && m <= r)
        {
            c = check_parity(n, i, code);
            code[i] = c;
            m++;
        }
    }

    cout << "The hamming code for given data is: ";
    for (int i = n; i > 0; i--) cout << code[i];
    cout << "\nEnter the received code: ";
    for (int i = n; i > 0; i--) cin >> code[i];

    m = j = c = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == pow(2, m) && m <= r)
        {
            c = c + (pow(2, j) * check_parity(n, i, code));
            j++;
            m++;
        }
    }
    if (c == 0) cout << "\nNo Error Found.\n";
    else cout << "\nError Detected.\n";
}

int main()
{
    int data[50], num;

    cout << "Enter the size of data: ";
    cin >> num;
    cout << "Enter the data: ";
    for (int i = num; i > 0; i--)
        cin >> data[i];

    hamming_code(data, num);
}
