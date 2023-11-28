#include <iostream>

using namespace std;

[[maybe_unused]] void bai1() {
    std::cout << "Hello, World!" << std::endl;
}

[[maybe_unused]] void bai11() {
    long long n;
    cin >> n;

    cout << n / 3600 << ":";
    cout << (n % 3600) / 60 << ":";
    cout << (n % 3600) % 60;
}

#include <cmath>

//int dem(long long d = 0) {
//    if (d == 0) return 1;
//    return floor(log10(abs(d))) + 1 + d < 0);
//}

int dem(long long d = 0) {
    return to_string(d).length();
}

[[maybe_unused]] void bai16() {
    long long a, b;
//    cout << "Nhập a, b: ";
    cin >> a >> b;
    long long product = a*b;
    int demA = dem(a);
    int demB = dem(b);
    int demP;
    long long p;
    string line = "" + string(demA + demB, '-');
    string le1, le2;
    le1 = string(demA, ' '); // 9999999999
    le2 = string(demB, ' ');
    cout << le2 << a << "\nx\n" << le1 << b << "\n";
    cout << line << "\n";
    for (int i = 0; i < demB - (b < 0); i++) {
        p = a*(b/(int) pow(10, i) % 10);
        demP = dem(p*pow(10, i));
        cout << string(demA + demB - demP, ' ') << p << "\n";
    }
    cout << line << "\n";
    demP = demA + demB - dem(product);
    if (demP < 0) {
        demP = 0;
    }
    cout << string(demP, ' ') << product << "\n";
}

int intrand(int a, int b) {
    int range = b - a + 1;
    return rand() % range + a;
}

void bai2new() {
    char cha;
    cin >> cha; // 97, 122
    if (cha >= 'a' && cha <= 'z') {
        cha = cha - 32;
    } else if (cha >= 'A' && cha <= 'Z') {
        cha = cha + 32;
    }

    cout << cha << "\n";
}

int main() {
    long long d;
    while (1)
    bai16();
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    bai16();
    return 0;
}
