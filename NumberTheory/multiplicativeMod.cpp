
#include<iostream>
using namespace std;
class Triplet
{
public:
    int x;
    int y;
    int gcd;
};
Triplet extendedEuclid(int a ,int b)
{
    //base case
    if(b==0)
    {
        Triplet ans;
        ans.gcd=a;
        ans.x=1;
        ans.y=0;
        return ans;
    }
    //extended Euclid Algorithm
    Triplet smallAns=extendedEuclid(b,a%b);
    Triplet ans;
    ans.gcd=smallAns.gcd;
    ans.x=smallAns.y;
    ans.y=smallAns.x-(a/b)*smallAns.y;
    return ans;
}
int mmInverse(int a ,int m)
{
    Triplet ans=extendedEuclid(a,m);
    return ans.x;
}
int main()
{
    int a=5;
    int m=17;
    int ans=mmInverse(a,m);
    cout<<"multipicative Modulo inverse "<< ans<<endl;

}
