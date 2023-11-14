#include <iostream>

using namespace std;

void test() {
    ///int a[10] = {}; // khai bao gia tri mac dinh la 0
    ///int a[10] = {1}; // khai bao gia tri mac dinh la 0, gia tri dau la 1
    int a[10]; // gia tri rac
    for (int i = 0; i < 10; i++) {
        cout << i <<":" << a[i] << endl;
    }
}

int numFreq(long long n, int k) {
    int f = 0;
    while (n > 0) {
        if (n % 10 == k) {
            f++;
        }
        n/=10;
    }
    return f;
}

bool isPrime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isSpecial(long long n, int maxFreq) {
    if (!isPrime(n)) return false;
    for (int i = 0; i < 10; i++) {
        if (numFreq(n, i) > maxFreq) return false;
    }
    return true;
}

void yA() {
    long long n;
    int maxFreq;
    cin >> n >> maxFreq;
    cout << isSpecial(n, maxFreq);
}

void yB() {
    long long a, b;
    cin >> a >> b;
    long long s = 0;
    int c = 0;
    for (long long i = a; i <= b; i++) {
        if (isSpecial(i, 1)) {
            s += i;
            c++;
        }
    }
    cout << 1.0*s / c;
}

int main() {
    yB();
    return 0;
}
