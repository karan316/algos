#include<iostream>
#include<cmath>

int main()
{
    double n = pow(2,pow(2,4));
    while(n>1)
    {
        n = sqrt(n);
        std::cout<<n<<std::endl;
    }
}