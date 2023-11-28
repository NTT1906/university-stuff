#include <iostream>
using namespace std;

int f0 = 0;
int f1 = 0;
int f2 = 0;
int f3 = 0;
int f4 = 0;
int f5 = 0;
int f6 = 0;
int f7 = 0;
int f8 = 0;
int f9 = 0;

void addFreq(int n) {
    switch (n) {
        case 0: f0++; break;
        case 1: f1++; break;
        case 2: f2++; break;
        case 3: f3++; break;
        case 4: f4++; break;
        case 5: f5++; break;
        case 6: f6++; break;
        case 7: f7++; break;
        case 8: f8++; break;
        case 9: f9++; break;
    }
}

int firstBiggestFreq() {
    int maxFreq = f0;
    if (f1 > maxFreq) maxFreq = f1;
    if (f2 > maxFreq) maxFreq = f2;
    if (f3 > maxFreq) maxFreq = f3;
    if (f4 > maxFreq) maxFreq = f4;
    if (f5 > maxFreq) maxFreq = f5;
    if (f6 > maxFreq) maxFreq = f6;
    if (f7 > maxFreq) maxFreq = f7;
    if (f8 > maxFreq) maxFreq = f8;
    if (f9 > maxFreq) maxFreq = f9;
    if (maxFreq == f0) {
        return 0;
    }
    if (maxFreq == f1) {
        return 1;
    }
    if (maxFreq == f2) {
        return 2;
    }
    if (maxFreq == f3) {
        return 3;
    }
    if (maxFreq == f4) {
        return 4;
    }
    if (maxFreq == f5) {
        return 5;
    }
    if (maxFreq == f6) {
        return 6;
    }
    if (maxFreq == f7) {
        return 7;
    }
    if (maxFreq == f8) {
        return 8;
    }
    return 9;
}

int findNumFreq(unsigned long long n) {
    while (n > 0) {
        addFreq(n % 10);
        n /= 10;
    }
    return firstBiggestFreq();
}

int main() {
    unsigned long long n;
    cout <<  "Input n: ";
    cin >> n;
    cout << "The most frequent number is " << findNumFreq(n);
    return 0;
}

int maybe_otherWay() {
    unsigned long long n, i, temp, Max = 0;
    cout <<  "Input n: ";
    cin >> n;
    for (i = 10; i > 0; i--) {
        temp = n;
    }
    cout << "The most frequent number is " << findNumFreq(n);
    return 0;
}