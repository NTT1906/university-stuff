#include <iostream>
#include <cmath>
using namespace std;

void printPrimeFactors2(long long n) {
    long long i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            cout << i << " ";
            while (n % i == 0) {
                n /= i;
            }
        }
        i++;
    }
    cout << n;
}

void printPrimeFactors(long long n) {
    int o;
    for (long long i = 2; i <= sqrt(n); i++){
        if (n % i == 0) {
            cout << i << " ";
            while (n%i == 0){
                n /= i;
            }
        }
    }
    if (n > 0) cout << n << endl;
}

int main() {
	long long n;
	cin >> n;
	printPrimeFactors2(n);
	return 0;
}
