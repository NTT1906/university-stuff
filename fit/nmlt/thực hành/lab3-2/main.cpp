#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

unsigned long long bai1(unsigned long long n) {
    unsigned long long s, i;
    s = 0;
    for (i = 4; i < n; i += 4) {
        if (i % 5 != 0) {
            s += i;
        }
    }
    return s;
}

unsigned long long bai2(long long n) {
    double x, s;
    if (n < 1) {
        cout << 0;
        return 0;
    }
    s = 1;
    for (unsigned long long i = 2; i <= n; i++) {
        s += i / (i - 1.0);
    }
    return s;
}

unsigned long long bai3() {
    unsigned long long n, i, p, s;
    cin >> n;
    if (n <= 1) {
        return 1;
    }
    s = 1;
    p = 1;
    for (i = 2; i <= n; i++) {
        p *= i;
        s += p;
    }
    return s;
}

void bai4() {
    unsigned long long n, s = 1, i;
    int soUoc = 1;
    cin >> n;
    cout << 1 << " ";
    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            soUoc++;
            cout << i << " ";
            s += i;
        }
    }
    if (n > 1) {
        soUoc++;
        s += n;
        cout << n;
    }
    cout << "\n";
    cout << "Có " << soUoc << " ước" << endl;
    cout << "Tổng các ước là: " << s << endl;
}

bool isPrime(unsigned long long n) { //bai5a
    if(n < 2) return false;
    for (long long i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}

//void bai5a() {
//    unsigned long long n, i;
//    int u = 2;
//    cin >> n;
//    if (n >= 2) {
//        for (i = 2; i < sqrt(n); i++) {
//            if (n % i == 0) {
//                u++;
//            }
//        }
//    } else {
//        cout << "Ko SNT";
//        return;
//    }
//    if (u > 2) cout << "Ko SNT";
//    else cout << "SNT";
//}

void bai5b() {
    unsigned long long n, i, k;
    cin >> n;
    for (k = n; k > 2; k--) {
        int u = 2;
        for (i = 2; i < sqrt(k); i++) {
            if (k % i == 0) {
                u++;
                break;
            }
        }
        if (u == 2) {
            break;
        }
    }
    cout << k;
}

void bai6a();
void bai6b();
void bai6c();

void bai7() {
    int n, i, b;
    cin >> n;
    i = n < 0;
    if (i == 1) {
        cout << 1;
    }
    n = abs(n);
    while (n > 0) {
        cout << n % 2;
        n /= 2;
    } // bi nguoc :l
}

void bai8() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 9; j++) cout << j << "x" << i << "=" << j*i << "  ";
        cout << endl;
    }
}

void bai9() {
    int h, i, j;
    cin >> h;
    for (i = 1; i <= h; i++) {
        for (j = 0; j < h - i; j++) {
            cout << " ";
        }
        for (j = 1; j < i*2; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}

void bai10() {
    cout << "10p: " << 10 * 3.6 << endl;
    cout << "15p: " << 15 * 3.6 << endl;
    cout << "20p: " << 20 * 3.6 << endl;
    cout << "25p: " << 25 * 3.6 << endl;
    cout << "30p: " << 30 * 3.6 << endl;
}

void bai11();
void bai12(); //x

int fib(int n) {
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

void bai14() {
    long long n, s, i, p1, p2;
    cin >> n;
    s = 1;
    p1 = 0;
    p2 = 1;
    for (i = 1; i < n; i++) {
        s = p1 + p2;
        p1 = p2;
        p2 = s;
    }
    cout << s;
}

void bai15() {
    double lun, cao, n;
    n = -1;
    lun = 100;
    cao = -100;
    while (n != 0) {
        cout << "Nhap vao chieu cao: ";
        cin >> n;
        if (n != 0) {
            if (n > cao) {
                cao = n;
            }
            if (n < lun) {
                lun = n;
            }
        }
    }
    cout << "Chieu cao cua hoc sinh dung dau danh sach: " << lun << endl;
    cout << "Chieu cao cua hoc sinh dung cuoi danh sach: " << cao << endl;
}

void bai16() {
    while (1) {
        cout << "MAY TINH DON GIAN\n";
        cout << "1. Cong\n";
        cout << "2. Tru\n";
        cout << "3. Nhan\n";
        cout << "4. Chia\n";
        cout << "0. Dung chuong trinh\n";
        cout << "Lua chon cua ban la:\n";
        long long a, b, chosen;
        cin >> chosen;
        if (chosen < 1 || chosen > 4) {
            cout << "Ban da thoat chuong trinh!";
            break;
        }
        cout << "Moi nhap vao so thu nhat: "; cin >> a;
        cout << "Moi nhap vao so thu hai: "; cin >> b;
        cout << "Ket qua: ";
        switch (chosen) {
            case 1: cout << a << " + " << b << " = " << a + b; break;
            case 2: cout << a << " - " << b << " = " << a - b; break;
            case 3: cout << a << " * " << b << " = " << a * b; break;
            case 4: cout << a << " / " << b << " = " << 1.0*a / b; break;
        };
        cout << endl;
        cout << "----------------------------------------\n";
    }
}
//#include <unistd.h>
void bai17() {
    long long m, s;
    cout << "Nhap vao so phut: "; cin >> m;
    cout << "Nhap vao so giay: "; cin >> s;
    m += s / 60;
    s %= 60;
    while (m >= 0 && s >= 0) {
        cout << m << ":" << s;
        if (m == 0) {
            if (s <= 5 && s != 0) cout << " Tich tac";
            if (s == 0) cout << " Reng reng reng";
        }
        s--;
        if (m > 0 && s < 0) {
            m--;
            s = 59;
        }
        cout << endl;
    }
}

void bai18() {
    long long s, k = 0;
    cin >> s;
    while (s != 1) {
        if (s % 2 == 0) {
            s /= 2;
        } else {
            s = 3*s + 1;
        }
        cout << s << ", ";
        k++;
    }
    cout << endl << k << endl;
}

void bai19() {
    int i;
    char c, C;
    for (i = 'a'; i <'z'; i++) {
        c = i;
        C = i - 32;
        cout << c << " - " << C << endl;
    }
}

void bai20a() {
    long long n, rN;
    cin >> n;
    rN = 0;
    while (n > 0) {
        rN = rN * 10 +  n % 10;
        n /= 10;
    }
    cout << rN;
}

void bai20b() {
    long long n, c, l;
    cin >> n;
    c = 0;
    l = 0;
    while (n > 0) {
        if ((n % 10) % 2 == 0) c++;
        else l++;
        n /= 10;
    }
    cout << c << endl << l;
}

void bai17hour() {
    long long h, m, s;
    cout << "Nhap lan luot gio, phut, giay: ";
    cin >> h >> m >> s;
    m += s / 60;
    s %= 60;
    h += m / 60;
    m %= 60;
    while (h >= 0 && m >= 0 && s >= 0) {
//        cout << "STA: " << h << ":" << m << ":" << s;
        if (h < 10) cout << "0";
        cout << h << ":";
        if (m < 10) cout << "0";
        cout << m << ":";
        if (s < 10) cout << "0";
        cout << s;
        if (m == 0) {
            if (s <= 5 && s != 0) cout << " Tich tac";
            if (s == 0) cout << " Reng reng reng";
        }
        s--;
        if (h > 0 && m <= 0) {
            h--;
            m = 59;
        }
        if (m > 0 && s < 0) {
            m--;
            s = 59;
        }
//        cout << endl << "END: " <<  h << ":" << m << ":" << s;
        cout << endl;
    }
}

void drawSandClock() { // nang tu bai9
    int h, i, j;
    cin >> h;
    for (i = h/2; i > 0; i--) {
        for (j = 0; j < h/2 - i; j++) {
            cout << " ";
        }
        for (j = 1; j < i*2; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    for (i = 2; i <= h/2; i++) {
        for (j = 0; j < h/2 - i; j++) {
            cout << " ";
        }
        for (j = 1; j < i*2; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}

void drawSideWayTriangle() {
    int h, i, j;
    cin >> h;
    for (i = 2; i <= h; i++) {
        for (j = 0; j < h - i; j++) {
            cout << " ";
        }
        for (j = 1; j < i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}

void drawNotPascalTriangle() {
    int h, i, j;
    cin >> h;
    for (i = 1; i <= h; i++) {
        for (j = 0; j < h - i; j++) {
            cout << " ";
        }
        for (j = 1; j <= i; j++) {
            cout << j;
        }
        for (j = i - 1; j >= 1; j--) {
            cout << j;
        }
        cout << "\n";
    }
}

void printPascal(int row){
    for (int n = 1; n <= row; n++) {
        for (int r = 1; r < row - n + 1; r++) cout << "  ";

        int v = 1;
        for (int r = 1; r <= n; r++) {
            cout << v << "   ";
            v = v * (n - r) / r;
        }
        cout<<endl;
    }
}

int ucln(int a, int b) {
    if (b == 0) return a;
    return ucln(b, a % b);
}

int gcd(int a, int b) {
    int tmp;
    while(b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

void btvn_rutGonPhanSo() {
    long long a, b, i, u;
    cin >> a >> b;
    if (a % b == 0) {
        cout << a / b;
        return;
    }
    i = (a * b) >= 0 ? 1 : -1;
    a = abs(a);
    b = abs(b);
    u = ucln(a, b);
    cout << i * (a / u) << "/" << b / u;
}

vector<int> freq(
    int n,
    int Max,
    vector<int> &a
) {
    vector<int> r(Max, 0);

    for (int i = 0; i < n; i++) {
        r[a[i]]++;
    }
    return r;
}

int timFred() {
    int n;
    cin >> n;
    int Max = -1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > Max) {
            Max = a[i];
        }
    }
    vector<int> r = freq(n, Max, a);
    for (int i = 0; i < Max; i++) {
        cout << r[i] << " ";
    }
    return 0;
}

int main() {
    bai9();
    return 0;
}