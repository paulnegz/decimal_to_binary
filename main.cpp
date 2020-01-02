#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int binary_to_decimal(int binary, int level);
int decimal_to_binary(int decimal, int level);
int main()
{
    int n = 0;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int binary = decimal_to_binary(n, 0);
    cout << "function ran!" << endl;
    //cout<<binary;

    return 0;
}
int binary_to_decimal(int binary, int level)
{
    if (binary / 10 > 0)
    {
        return ((binary % 10) * pow(2, level) + binary_to_decimal(binary / 10, level + 1));
    }
    else
    {
        return (binary)*pow(2, level);
    }
}
int decimal_to_binary(int decimal, int level)
{
    if (decimal >= 1)
    {
        return decimal_to_binary(decimal / 2, level + 1) + decimal % 2 * pow(10, level);
    }
    else
    {
        return 0;
    }
}