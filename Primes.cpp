#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n) {
    double sn = sqrt(n);
    bool ret = true;
    for (int i = 2; i <= sn; i++) {
        if (n % i == 0) ret = false;
        if (!ret) break;
    }
    return ret;
}
int main() {
    int n; cin >> n;
    int primeCount = 1, twinPrimeCount = 0, prvPrime;
    cout << 2 << endl;
    for (int i = 3; i <= n; i++) {
        if (isPrime(i)) {
            cout << i << endl;
            primeCount++;
            prvPrime = i;
        }
    }
    cout << primeCount << " Prime Numbers";
}
