#include <iostream>
using namespace std;

void bai1() {
    int h, m, s;
    cin >> h >> m >> s;
    if (h < 0 || h > 23) {
        cout << "h không hợp lệ!, " << h << "\n";
        return;
    }
    if (m < 0 || m > 59) {
        cout << "m không hợp lệ!, " << m << "\n";
        return;
    }
    if (s < 0 || s > 59) {
        cout << "s không hợp lệ!, " << s << "\n";
        return;
    }
    cout << "Hợp lệ!\n";
}

void bai2() {
    int t, l, h;
    cin >> t >> l >> h;
    if (t + l + h >= 15) {
        if (t >= 4 && l >= 4 && h >= 4) {
            cout << "Đậu";
            return;
        }
        if (t >= 5 && l >= 5 && h >= 5) {
            cout << "Học đều các môn";
            return;
        } else {
            cout << "Học chưa đều các môn";
        }
    } else {
        cout << "Thi hỏng";
    }
}

void bai3() {
    int n, i;
    cin >> n;
    if (n < 2 && n >= 0) {
        cout << n << " la so chinh phuong";
        return;
    }
    for (i = 2; i < n / 2; ++i) {
        if (i * i == n) {
            cout << n << " la so chinh phuong";
            return;
        }
    }
    cout << n << " khong phai la so chinh phuong";
}

void bai4() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << n << " la so chan";
    } else {
        cout << n << " la so le";
    }
}

void bai5a() {
    int n;
    cin >> n;
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        cout << n << " là năm nhuận!";
    } else {
        cout << n << " là năm không nhuận!";
    }
}

void bai5b() {
    int n, t;
    cin >> t >> n;

    switch (t) {
        case 2:
            cout << "Tháng 2 có " << ((n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) ? 29 : 28) << " ngày.";
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << "Tháng " << t << " có 31 ngày.";
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            cout << "Tháng " << t << " có 30 ngày.";
            break;
        default:
            cout << "Tháng khônh hợp lệ!\n";
    }
}

void bai6() {
    int n;
    cin >> n;
    switch (n) {
        case 0: cout << "Không"; break;
        case 1: cout << "Một"; break;
        case 2: cout << "Hai"; break;
        case 3: cout << "Ba"; break;
        case 4: cout << "Bốn"; break;
        case 5: cout << "Năm"; break;
        case 6: cout << "Sáu"; break;
        case 7: cout << "Bảy"; break;
        case 8: cout << "Tám"; break;
        case 9: cout << "Chín"; break;
        default: cout << "Số không hợp lệ!";
    }
}

void bai7() {
    int a, b, c, Max, Min;
    cin >> a >> b >> c;
    Max = a;
    Min = b;

    // chua xong
}

void bai8() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b < c || a + c < b || b + c < a) {
        cout << "Khong phai tam giac\n";
        return;
    }
    if (a == b && a == c && b == c) {
        cout << "Tam giac deu";
    } else {
        if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
            if (a == b || a == c || b == c) {
                cout << "Tam giac vuong can\n";
            } else {
                cout << "Tam giac vuong";
            }
        } else {
            if (a == b || a == c || b == c) {
                cout << "Tam giac can\n";
            } else {
                cout << "Tam giac thuong";
            }
        }
    }
}

void bai9() {
    int k;
    double g, t = 0;
    cin >> k;
    t = (k > 0) * 15;
    if (k >= 2) {
        if (k >= 6) {
            t += 4 * 13.5 + (k - 5) * 11;
        } else {
            t += (k - 1) * 13.5;
        }
    }
    if (k > 120) {
        t *= 0.9;
    }
    cout << t;
}

void bai10() {

}

void bai12() {
    int x;
    cin >> x;
    if (x <= 9) {
        cout << x;
    } else {
        cout << "T: " << static_cast<char> (x + 67) << "\n";
    }
}

#include <cmath>

void bai14() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "Vo so nghiem!";
            } else {
                cout << "Vo nghiem!";
            }
        } else {
            cout << "Mot ngiem la: " << (-1.0 * c)/b;
        }
    } else {
        int delta;
        delta = b * b - 4 * a * c;
        if (delta >= 0) {
            if (delta > 0) {
                cout << "Hai nghiem x1, x2 la: " << (-b + sqrt(delta)) / (2.0 * a) << " " << (-b - sqrt(delta)) / (2.0 * a);
            }
        } else {
            cout << "Vo nghiem!";
        }
    }
}

int main() {
    while(1)
    bai12();
    return 0;
}
