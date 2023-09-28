// LEET CODE problem number 69.
// #include <iostream>
// //#include <iomanip>

// using namespace std;

// long double mySqrt(long int& n)
// {
//     long double s = 0, e = n;
//     long double ans = 0;
//     const double precision = 0.0001; // A small value to check for precision

//     while ((e - s) > precision)
//     {
//        long double mid = (e - s) / 2 + s;

//         // predicate fn
//         if (mid * mid <= n)
//         {
//             ans = mid;
//             s = mid; // go right
//         }
//         else
//             e = mid; // go left
//     }
//     return ans;
// }

// int main()
// {
//     long int n = 129;
//    long double ans = mySqrt(n);
//     cout  << ans << endl;
//     //cout << fixed << setprecision(4) << ans << endl;
//     return 0;
// }




#include <iostream>
#include <vector>

using namespace std;

int mySqrt(int& n)
{
    int s = 0, e = n;
    double ans = 0;
    while (s <= e)
    {
        int mid = (e - s) / 2 + s;

        // predicate fn
        if (mid * mid <= n)
        {
            ans = mid;
            s = mid + 1; // go right
        }
        else
            e = mid - 1; // go left
    }
    return ans;
}

 double myPrecisionSqrt(int n)
{
    double sqrt = mySqrt(n);
    int precision = 10;
    double step = 0.1;
    for (int i = 0; i < precision; ++i)
    {
        double j = sqrt;
        while (j * j <= n)
        {
            sqrt = j;
            j += step;
        }
        step /= 10;
    }
    return sqrt;
}

int main()
{
    int n = 111;
    double ans =  myPrecisionSqrt(n);
    cout << ans <<endl;
   // cout << myPrecisionSqrt(n)<< endl;
    return 0;
}
