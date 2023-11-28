#include <iostream>
using namespace std;

// Bai1
void setArray(int a[], int &n) { //1
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void printArray(int a[], int n) { //2
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int sumArray(int a[], int n) { //3
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += a[i];
	}
	return s;
}

int findMin(int a[], int n) { //4
	int Min = a[1];
	for (int i = 1; i < n; i++) {
		if (a[i] < Min) {
			Min = a[i];
		}
	}
	return Min;
}

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int countNumberOfPrime(int a[], int n) { //5
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (isPrime(a[i])) {
			c++;
		}
	}
	return c;
}

bool isAscendingOrder(int a[], int n) {
	for (int i = 0; i < n -1; i++) {
		if (a[i] > a[i + 1]) {
			return false;
		}
	}
	return true;
}

int countOccurrences(int a[], int n, int x) {
	int f = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			f++;
		}
	}
	return f;
}

void deleteItems(int a[], int &n, int x) {
	int cX = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			cX++;
			for (int j = i; j < n - 1; j++) {
				a[j] = a[j + 1];
			}
		}
	}
	n -= cX;
}

void deleteItemsFromIndex(int a[], int &n, int index, int no_items) {
//	for (int i = index; i < index + no_items; i++) {
//		for (int j = i; j < i + no_items; j++) {
//			a[j] = a[j + 1];
//		}
//	}
//	n -= no_items;
	for (int i = 0; i < n; i++) {
		if (i >= index && i < index + no_items) {
			for (int j = i; j < n; j++) {
				a[j] = a[j + 1];
			}
		}
	}
	n -= no_items;
}

void deleteAt(int a[], int &n, int pos) {
	for (int i = pos; i < n - 1; i++) {
		a[i] = a[i + 1];
	}
	n -= 1;
}

void deletePrimes(int a[], int &n) {
	int cP = 0;
	for (int i = 0; i < n; i++) {
		if (isPrime(a[i])) {
			cP++;
			deleteAt(a, n, i);
		}
	}
//	n -= cP;
}

void deleteAllPrimes(int a[], int &n) {
	for (int i = 0; i < n; i++) {
		if (isPrime(a[i])) {
			deleteAt(a, n, i);
		}
	}
}

int findPrime(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (isPrime(a[i])) return i;
	}
	return -1;
}

int searchAt(int a[], int n, int k) {
	for (int i = 0; i < n; i++) {
		if (a[i] == k) return i;
	}
	return -1;
}

void deleteAllPrimesOri(int a[], int &n) {
	int pos = -1;
	do {
		pos = findPrime(a, n);
		if (pos != -1) {
//			for (int i=0; i<n; ++i) cout << a[i] << " ";
//			cout << '\n' << pos << '\n';
			deleteAt(a, n, pos);
		}
	} while (pos != -1);
}

int main1() {
	int a[] = {1, 1,2,3, 1, 1, 5, 6, 7, 8,9 ,1, 11, 1, 7, 9, 11};
	int n = sizeof(a) / sizeof(int);
	cout << n << endl;
	deleteAllPrimes(a, n);
	printArray(a, n);
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Bai3 - Mảng hai chiều

#define MAX 100

void set2dArray(int a[][MAX], int &m, int &n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
}

void print2dArray(int a[][MAX], int &m, int &n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

#include <cmath>

int numlen(long long n) {
	if (n == 0) return 1;
	return trunc(log10(abs(n))) + 1 + (n < 0);
}

void prettyPrint2dArray(int a[][MAX], int &m, int &n) {
	int maxLen = 1, tlen = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			tlen = numlen(a[i][j]);
			if (tlen > maxLen) maxLen = tlen;
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int w = maxLen - numlen(a[i][j]); w > 0; w--) {
				cout << " ";
			}
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int sumArray(int a[][MAX], int m, int n) {
	int s = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			s += a[i][j];
	return s;
}

int countNumberOfPrime(int a[][MAX], int m, int n) {
	int c = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (isPrime(a[i][j])) c++;
	return c;
}

int countNumberOfUniquePrime(int a[][MAX], int m, int n) {
	unsigned long long p = 1;
	int c = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (isPrime(a[i][j])) {
				if (p % a[i][j] != 0) {
					p *= a[i][j];
					c++;
				}
			}
		}
	}
	return c;
}

int countNumberOfUniquePrime2(int a[][MAX], int m, int n) {
	int cP[MAX] = {};
	int c = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (isPrime(a[i][j]) && searchAt(cP, c, a[i][j]) == -1) {
				cP[c++] = a[i][j];
			}
		}
	}
	return c;
}

void deleteMatrixCol(int a[][MAX], int &m, int &n, int col) {
	for (int i = 0; i < m; ++i)
		for (int j = col; j < n - 1; ++j)
			a[i][j] = a[i][j + 1];
	n--;
}

void deleteMatrixRow(int a[][MAX], int &m, int &n, int row) {
	for (int j = 0; j < n; ++j)
		for (int i = row; i < m - 1; ++i)
			a[i][j] = a[i + 1][j];
	m--;
}

void deleteMatrixRowCol(int a[][MAX], int &m, int &n, int row, int col) {
	// delete part 1,
	for (int i = row; i < m - 1; ++i) {
		for (int j = 0; j < col; ++j) {
			cout << "P1: " << i << ":" << j << " {" << a[i][j] << "} -> " << i + 1 << ":" << j << "{" << a[i + 1][j] << "}" << endl;
			a[i][j] = a[i + 1][j];
		}
	}
	// delete part 2
	for (int i = 0; i < row; ++i) {
		for (int j = col; j < n - 1; ++j) {
			cout << "P2: " << i << ":" << j << " {" << a[i][j] << "} -> " << i << ":" << j + 1 << "{" << a[i][j + 1] << "}" << endl;
			a[i][j] = a[i][j + 1];
		}
	}
	// delete lower conner part
	for (int i = row; i < m - 1; ++i) {
		for (int j = col; j < n - 1; ++j) {
			cout << "P3: " << i << ":" << j << " {" << a[i][j] << "} -> " << i + 1 << ":" << j + 1 << "{" << a[i + 1][j + 1] << "}" << endl;
			a[i][j] = a[i + 1][j + 1];
		}
	}
	m--;
	n--;
}

int findItemPosMatrix(int a[][MAX], int &m, int &n, int x, int &row, int &col) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j] == x) {
				row = i;
				col = j;
				return 1;
			}
		}
	}
	return -1;
}

void deleteMatrixItems(int a[][MAX], int &m, int &n, int x) {
	int pos = -1;
	int row = 0;
	int col = 0;
	do {
		pos = findItemPosMatrix(a, m, n, x, row, col);
		if (pos == 1) {
//			cout << row << " : " << col << endl;
			deleteMatrixRowCol(a, m, n, row, col);
//			deleteMatrixRow(a, m, n, row);
//			deleteMatrixCol(a, m, n, col);
		}
	} while (pos != -1);
}

void deleteMatrixItemsOrigin(int a[][MAX], int &m, int &n, int x) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j] == x) {
				deleteMatrixRowCol(a, m, n, i, j);
//				deleteMatrixRow(a, m, n, i);
//				deleteMatrixCol(a, m, n, j);
// this two work! but the general deleteMatrixRowCol don't. Edit: fixed deleteMatrixRowCol!
			}
		}
	}
}

int mainOfDeleteMatrix() {
	int a[MAX][MAX] = {{1, 2, 9, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

	int m = 4;
	int n = 4;
	prettyPrint2dArray(a, m, n);
	cout << endl;
//	deleteMatrixRowCol(a, m, n, 3, 2);
	deleteMatrixItems(a, m, n, 16);
	prettyPrint2dArray(a, m, n);
	cout << endl;
	return 0;
}

/// Bai 4
#include <cstring>
void bai41() {
	const int maxLengthPerName = 50;
	const int maxVotes = 100000;
	char voters[50][maxLengthPerName];
	int votes[50] = {};
	int n;
	cout << "Input n = ";
	cin >> n;
	if (n > 50) {
		cout << "The amount of voters must be smaller than " << 50 << "\n";
		return;
	}
	cin.ignore(1, '\n');
	for (int i = 0; i < n; i++) {
		cout << "Input the name of person " << i + 1 << ": ";
		cin.getline(voters[i], maxLengthPerName);
		voters[i][maxLengthPerName - 1] = '\0';
	}
	int total = 0;
	int winner = 0;
	int maxVote = -1;
	for (int i = 0; i < n; i++) {
		cout << "Input the votes of " << voters[i] << ": ";
		cin >> votes[i];
		if (votes[i] > maxVote) {
			maxVote = votes[i];
			winner = i;
		}
		total += votes[i];
	}
	cout << "Candidate        Votes    Received % of Total Votes\n";
	for (int i = 0; i < n; i++) {
		cout << voters[i];
		for (int j = 17 - strlen(voters[i]); j > 0; j--) cout << " ";
		cout << votes[i];
		for (int j = 17 - numlen(votes[i]); j > 0; j--) cout << " ";
		cout.precision(2);
		cout << fixed << votes[i] * 100.0 / total;
		cout << "\n";
	}
	cout << "\nTotal            " << total << "\n"; // 17 -5 = 12 whitespace
	cout << "The Winner of the Election is " << voters[winner];
}

// Bai 4.2


int main() {
	bai41();
	return 0;
}
