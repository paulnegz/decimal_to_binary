#include <bits/stdc++.h>
#include <math.h> 
#include <cmath>
#include<algorithm> 

using namespace std;


double binary_to_decimal(double binary,double level);
double decimal_to_binary(double decimal, double level);
double max_num_of_consecutive_ones(double binary,double consecutive);
int main()
{
    double n =0;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    double binary = decimal_to_binary(n,0);
    cout<<"binary number: "<<binary<<". Max consecutive is: ";
    cout<<max_num_of_consecutive_ones(binary,0);

    return 0;
}
double binary_to_decimal(double binary,double level)
{
    if (binary/10>0)
    {
        return( fmod(binary,10.0)*pow (2, level)+binary_to_decimal(floor(binary/10),level+1)  );
    }
    else
    {
        return (binary)*pow (2, level);
    }
    
}
double decimal_to_binary(double decimal, double level)
{
    if (decimal >= 1)
    {
        return decimal_to_binary(floor(decimal/2), level+1)+fmod(decimal,2.0)*pow (10, level);
    }
    else
    {
        return 0;
    }    
}
double max_num_of_consecutive_ones(double binary,double consecutive)
{
    if (binary>0)
    {
        if ( fmod(binary,10.0)==1 )
        {   
            return max_num_of_consecutive_ones(floor(binary/10),consecutive+1);
        }
        else
        {
            return max(consecutive,max_num_of_consecutive_ones(floor(binary/10),0) );
            
        }
    }
    else
    {
        return consecutive;
    }
    


}
