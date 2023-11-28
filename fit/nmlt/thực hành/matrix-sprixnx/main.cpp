#include <iostream>

using namespace std;

const int MAX = 100;

void printMatrix(int a[][MAX], int n) {
	int num;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
			num = a[i][j];
			if (num < 10) cout << " ";
			if (num < 100) cout << " ";
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
}

void makeClockwiseSpiral() {
	int n;
	cin >> n;
	int a[MAX][MAX];
	int c = 0;
	int p = 0;
	int q = 0;
	for (int i = 0; i < (n + 1) / 2; i++) {
		for (int j = i; j < n - i - 1; j++) {
			a[i][j] = c++;
		}
		for (int j = i; j < n - i - 1; j++) {
			a[j][n - i - 1] = c++;
		}
		for (int j = n - i - 1; j > i; j--) {
			a[n - i - 1][j] = c++;
		}
		for (int j = n - i - 1; j > i; j--) {
			a[j][i] = c++;
		}
	}
	if (n % 2 != 0) {
		a[(n - 1) / 2][(n - 1) / 2] = c++;
	}
	printMatrix(a, n);
}

void makeCounterClockwiseSpiral() {
	int n;
	cin >> n;
	int a[MAX][MAX];
	int c = n * n - 1;
	int p = 0;
	int q = 0;
	for (int i = 0; i < (n + 1) / 2; i++) {
		for (int j = i; j < n - i - 1; j++) {
			a[i][j] = c--;
		}
		for (int j = i; j < n - i - 1; j++) {
			a[j][n - i - 1] = c--;
		}
		for (int j = n - i - 1; j > i; j--) {
			a[n - i - 1][j] = c--;
		}
		for (int j = n - i - 1; j > i; j--) {
			a[j][i] = c--;
		}
	}
	if (n % 2 != 0) {
		a[(n - 1) / 2][(n - 1) / 2] = 0;
	}
	printMatrix(a, n);
}


int main() {
	makeCounterClockwiseSpiral();
    return 0;
}
