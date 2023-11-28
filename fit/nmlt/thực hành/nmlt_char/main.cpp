#include <iostream>
#include <cstring>
using namespace std;

void toupper(char a[1000000], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] > 96 && a[i] < 123) {
            a[i] = a[i] - 32;
        }
    }
}

void tolower(char a[1000000], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] > 64 && a[i] < 91) {
            a[i] = a[i] + 32;
        }
    }
}

bool isLower(char a[1000000], int n) {
    while (n > 0) {
        if (a[n] == '\0') {
            n--;
            continue;
        }
        if (a[n] < 97 || a[n] > 122) {
            return false;
        }
        n--;
    }
    return true;
}

bool isUpper(char a[1000000], int n) {
    while (n > 0) {
        if (a[n] == '\0') {
            n--;
            continue;
        }
        if (a[n] < 65 || a[n] > 90) {
            return false;
        }
        n--;
    }
    return true;
}

bool isAlphabet(char a[1000000], int n) {
    while (n > 0) {
        if (a[n] == '\0' || (a[n] > 96 && a[n] < 123) || (a[n] > 64 && a[n] < 91)) {
            n--;
            continue;
        }
        return false;
    }
    return true;
}


bool isDigit(char a[1000000], int n) {
    while (n > 0) {
        if (a[n] == '\0' || (a[n] >= '0' && a[n] <= '9')) {
            n--;
            continue;
        }
        return false;
    }
    return true;
}

bool isSpace(char a[1000000], int n) {
    while (n > 0) {
        if (a[n] != '\0' && a[n] != ' ' && a[n] != '\t' && a[n] != '\n' && a[n] != '\r' && a[n] != '\v' && a[n] != '\f') {
            return false;
        }
        n--;
        continue;
    }
    return true;
}

bool isPunct(char a[1000000], int n) {
    return !isAlphabet(a, n) && !isDigit(a, n) && !isSpace(a, n);
}

int strcomp(char a, char b) {
    int c = a - b;
    return c;
}

void delSpace(char s[]) {
    int pos = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == ' ') {
            s[pos] = s[i];
            pos = i;
        }
    }
    s[pos] = '0';
}

bool isSpace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f';
}

void tachDongChr(string s) {
	int sLen = s.length();
	bool hasSpace = false;
	for (int i = 0; i < sLen; i++) {
		if (isSpace(s[i])) {
			if (!hasSpace) {
				cout << endl;
			}
			hasSpace = true;
		} else {
			hasSpace = false;
			cout << s[i];
		}
	}
}

void printLongestWordNotFinal(string s) {
	int a = 0, b = 0;
	int Max = 0;
	bool hasSpace = false;
	int m = 0, n = -1;
	for (int i = 0; s[i]; i++) {
		if (isSpace(s[i])) {
			hasSpace = true;
		} else {
			if (hasSpace) {
				m = i;
				n = i;
			} else {
				n++;
			}
			hasSpace = false;
		}
		if ((hasSpace || !s[i]) && n - m + 1 > Max) {
			Max = n - m + 1;
			a = m;
			b = n;
		}
	}
	for (int i = a; i <= b; i++) {
		cout << s[i];
	}
	cout << endl;
}

void printLongestWord(string s) {
	int a = 0, b = 0;
	int Max = 0;
	bool hasSpace = false;
	int m = 0, n = -1;
	for (int i = 0; s[i]; i++) {
		if (isSpace(s[i])) {
			hasSpace = true;
		} else {
			if (hasSpace) {
				hasSpace = false;
				m = i;
				n = i;
			} else {
				n++;
			}
		}
		if (n - m + 1 > Max) {
			Max = n - m + 1;
			a = m;
			b = n;
		}
	}
	for (int i = a; i <= b; i++) {
		cout << s[i];
	}
	cout << endl;
}

void printLongestWordPre(string s) {
	int a = 0, b = 0;
	int Max = 0;
	bool hasSpace = false;
	int l = s.length();
//	cout << "String len: " << l << endl;
	int m = 0, n = -1;
	for (int i = 0; s[i]; i++) {
//		cout << i << " - ";
		if (isSpace(s[i])) {
//			cout << "\"" << s[i] << "\"" << "  SPACE - " << m << ":" << n << "   MAX: " << Max << "   COORD: " << a << ":" << b << endl;
			hasSpace = true;
		} else {
			if (hasSpace) {
				m = i;
				n = i;
			} else {
				n++;
			}
			bool hasSetNewMax = false;
			if (n - m + 1 > Max) {
				Max = n - m + 1;
				hasSetNewMax = true;
				a = m;
				b = n;
			}
			hasSpace = false;
//			cout << "\"" << s[i] << "\"" << "   WORD - " << m << ":" << n << "   MAX: " << Max << "   COORD: " << a << ":" << b << endl;
//			cout << "NEW MAX HAS SET: " << a << ":" << b << " => " << Max << endl;
			hasSetNewMax = false;
		}
	}
//	cout << endl << "COORD: " << a << ":" << b << endl;
//	cout << "LWORD: \"";
	for (int i = a; i <= b; i++) {
		cout << s[i];
	}
//	cout << "\"" << endl;
}

int main() {
	printLongestWord("How do I print HelloWorld in C++?");
	return 0;
}

void printLongestWordOld3(string s) {
	int a = 0, b = 0;
	int Max = 0;
	bool hasSpace = false;
	int l = s.length();
	cout << "Chuoi dai: " << l << endl;
	int m = 0, n = 0;
	for (int i = 0; i < l; i++) {
		cout << i << " - ";
		if (isSpace(s[i])) {
			if (!hasSpace) {
				cout << endl;
			}
			cout << "\"" << s[i] << "\"" << "  SPACE - " << m << ":" << n << "   MAX: " << Max << "   COORD: " << a << ":" << b << endl;
			hasSpace = true;
		} else {
			if (hasSpace) {
				m = i;
				n = i;
			} else {
				n++;
			}
			hasSpace = false;
			cout << "\"" << s[i] << "\"" << "   WORD - " << m << ":" << n << "   MAX: " << Max << "   COORD: " << a << ":" << b << endl;
		}
		if (n - m > Max) {
			Max = n - m;
			a = m;
			b = n;
			cout << endl << "NEW MAX " << a << ":" << b << " => " << Max << endl;
		}
	}
	cout << endl << "COORD: " << a << ":" << b << endl;
	cout << "LWORD: \"";
	for (int i = a; i <= b; i++) {
		cout << s[i];
	}
	cout << "\"" << endl;
}

void printLongestWordOld2(string s) {
	int a = 0, b = 0;
	int Max = 0;
	bool hasSpace = false;
	int l = s.length();
	cout << "Chuoi dai: " << l << endl;
	int m = 0, n = 0;
	for (int i = 0; i < l; i++) {
		cout << i << " - ";
		if (isSpace(s[i])) {
			if (!hasSpace) {
				cout << endl;
			}
			cout << "\"" << s[i] << "\"" << "  SPACE - " << m << ":" << n << "   MAX: " << Max << "   COORD: " << a << ":" << b << endl;
			hasSpace = true;
		} else {
			n++;
			if (hasSpace) {
				m = n + 1;
				n = i;
			}
			cout << "\"" << s[i] << "\"" << "   WORD - " << m << ":" << n << "   MAX: " << Max << "   COORD: " << a << ":" << b << endl;
			hasSpace = false;
		}
		if (n - m > Max) {
			Max = n - m;
			a = m;
			b = n;
		}
	}
	cout << endl << "COORD: " << a << ":" << b << endl;
	cout << "LWORD: \"";
	for (int i = a; i <= b; i++) {
		cout << s[i];
	}
	cout << "\"" << endl;
}

void printLongestWordOld(string s) {
	int a, b;
	int Max = 0;
	bool hasSpace = false;
	int l = s.length();
	cout << "Chuoi dai: " << l << endl;
	int m = 0, n = 0;
	for (int i = 0; i < l; i++) {
		if (isSpace(s[i])) {
			if (!hasSpace) {
				m = n + 1;
				cout << endl;
			}
			cout << s[i] << "  SPACE - " << m << ":" << n << "   MAX: " << Max << endl;
			hasSpace = true;
		} else {
			cout << s[i] << "   WORD - " << m << ":" << n << "   MAX: " << Max << endl;
			hasSpace = false;
		}
		n++;
		if (n - m > Max) {
			Max = n - m;
			a = m;
			b = n;
		}
	}
	cout << endl << "COORD: " << a << ":" << b << endl;
	cout << "LWORD: \"";
	for (int i = a; i <= b; i++) {
		cout << s[i];
	}
	cout << "\"" << endl;
}

void tachDong(string s) {
    int sLen = s.length();
    int pos = -1;
    int i = 0;
    for (;i < sLen; i++) {
        if (isSpace(s[i])) {
            if (pos + 1 != i) {
                cout << s.substr(pos + 1, i - pos) << endl;
            }
            pos = i;
        }
    }
    cout << s.substr(pos + 1);
}

int main22() {
    char s[] = "hi hello      nihao  ahoy";
    delSpace(s);
    cout << s;
}

int main3() {
    char a[1000000] = "././.";
    string s;
    cout << s;
    if (isPunct(a, 100)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}

int main2() {
    cout << strcomp('a', 'A');
    char a[10];
    cin.ignore(4);
    cin.getline(a, 10);
//    a[9] = 'a';
    cout << a;
    return 0;
}
