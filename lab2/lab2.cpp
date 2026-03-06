/*#include <iostream>
using namespace std;

int main() {
    int num, current, steps;

    while (true) {
        cout << "Please enter a positive integer greater than 9: ";
        cin >> num;
        if (num > 9) break;
        cout << "Number must be greater than 9!" << endl;
    }

    steps = 0;
    current = num;
    cout << current;

    while (current > 9) {
        int total = 0;
        int temp = current;
        while (temp > 0) {
            total += temp % 10;
            temp /= 10;
        }
        cout << " → " << total;
        current = total;
        steps++;
    }

    cout << "\nFinal value: " << current << endl;
    cout << "Total steps: " << steps << endl;

    return 0;
}


#include <iostream>
using namespace std;

int main() {
int num;
while (true) {
cout << "Please enter a number between 10 and 100: ";
cin >> num;
if (num >= 10 && num <= 100) break;
cout << "Please enter a number between 10 and 100!" << endl;
}

int fizz_count = 0, buzz_count = 0, fizzbuzz_count = 0;

for (int i = 1; i <= num; i++) {
if (i % 7 == 0) continue;
if (i % 3 == 0 && i % 5 == 0) {
cout << "FizzBuzz" << endl;
fizzbuzz_count++;
} else if (i % 3 == 0) {
cout << "Fizz" << endl;
fizz_count++;
} else if (i % 5 == 0) {
cout << "Buzz" << endl;
buzz_count++;
} else {
cout << i << endl;
}
}

cout << "Fizz: " << fizz_count << endl;
cout << "Buzz: " << buzz_count << endl;
cout << "FizzBuzz: " << fizzbuzz_count << endl;

return 0;
}



#include <iostream>
#include <cmath>
using namespace std;

int main() {
int n;

while (true) {
cout << "Please enter a number between 3 and 9: ";
cin >> n;
if (n >= 3 && n <= 9) break;
cout << "Invalid input! Number must be between 3 and 9." << endl;
}

for (int i = 1; i <= 2*n - 1; i++) {
int k = n - abs(n - i);
for (int j = 1; j <= k; j++) {
cout << j;
}
cout << endl;
}

return 0;
}