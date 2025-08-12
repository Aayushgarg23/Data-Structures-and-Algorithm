#include<iostream>
using namespace std;

/*The bitwise right shift operation (low + high) >> 1 is faster than division by 2 (low + high) / 2.
This is because the right shift operation is a simpler bitwise operation at the hardware level, 
while division is computationally more expensive. In a test with 1,000,000 iterations,the right shift 
averaged about 0.079s, while the division took about 0.120s

n % 2 and n / 2 involve division — slower than bitwise operations.

n & 1 and n >> 1 are simple bitwise instructions — faster in practice.

time(for both): (O(log n)),
space: O(1)

but bitwise version is faster in real execution due to smaller constant factors.
*/

int countSetDigit(int n)
{
    int cnt = 0;
    while(n!=0)
    {
        if(n%2==1)cnt++;
        n/=2;
    }
    return cnt;
}

int countSetDigitBitwise(int n)
{
    int cnt = 0;
    while(n!=0)
    {
        cnt+= n&1;
        n= n>>1;
    }
    return cnt;
}

/* there is one more way to do it

time: O(no. of set bits)*/

int countSetBit(int n)
{
    int cnt=0;
    while(n!=0)
    {
        cnt++;
        n = n&(n-1);
    }
    return cnt;
}

int main()
{
    cout << countSetBit(1) << endl;
    cout << countSetBit(15) << endl;
    cout << countSetBit(4) << endl;
    cout << countSetBit(5) << endl;
    cout << countSetBit(7) << endl;
}