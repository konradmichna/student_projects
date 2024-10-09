#include <iostream>
#include <string>
#include "functions.cpp"

using namespace std;

int main() {
    int n;
    cout << "Podaj liczbę: ";
    cin >> n;

    string result = fizzBuzz(n);
    cout << result << endl;

    return 0;
}
