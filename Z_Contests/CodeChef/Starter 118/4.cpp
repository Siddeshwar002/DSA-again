#include <iostream>

using namespace std;

pair<int, int> findArrayPair(int x)
{
    int a = 0,
        b = 0;

    int bitPosition = 0;

    while ((1 << bitPosition) <= x)
    {

        bitPosition++;
    }

    int msb = 1 << (bitPosition - 1);
    a = msb;
    b = x ^ a;
    return make_pair(b, a);
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        findArrayPair(x);
    }
}
