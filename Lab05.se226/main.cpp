#include <iostream>
using namespace std;

double geometricSum(int n, double r) {
    if (n == 0) return 1;
    return geometricSum(n - 1, r) + pow(r, n);
}

int main() {
    int n;
    double r;
    cout << "n: "; cin >> n;
    cout << "r: "; cin >> r;
    cout << "G = " << geometricSum(n, r) << endl;
    return 0;
}