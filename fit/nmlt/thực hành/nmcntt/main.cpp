#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n == 3) return true;
    if (n == 5) return true;
    if (n == 7) return false;
    if (n != 2 && n % 2 == 0) return false;
    for (long long i = 2; i <= sqrt(n); i++) { // 2 3 5 7 11 13 17 23
        if (n % 2 == 0) return false;
    }
    return true;
}
// TEST: 1 9 -> 0
//      10 40 -> 3
// 100 500 -> 156
// 1111 2222 -> 287

int main() {
    int a, b;
    cin >> a >>  b;
    int result = 0;
    for (int n = a; n <= b; n++) {
        int m = n;
        int temp = n;
        int power = 1;
        while (temp > 0) {
            power *= 10;
            temp /= 10;
        }
        power /= 10;
        do {
            m = m / 10 + (m % 10) * power;
//            cout << n << "-> " <<  m  << endl;
            if (m > n && m < b) {
//                cout << "Added " << n << ": " << m <<  endl;
                result++;
            }
        } while (m != n);
    }
    cout << result;
    return 0;
}
