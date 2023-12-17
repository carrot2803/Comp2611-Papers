#include <iostream>
#include <string>
using namespace std;

int hashFunction(string key, int n) {
    int sum = 0;
    // use a prime number for distribution
    for (int i = 0; i < key.length(); i++)
        sum = (sum * 11) + (key.at(i) - '0');

    return sum % n + 1;
}
int main() {
    // Example usage:
    string key = "test";
    int maxValue = 100;

    int hashLocation = hashFunction(key, maxValue);
    int hashLocation2 = hashFunction("stet", maxValue);

    cout << "Hash Location: " << hashLocation << endl;
    cout << "Hash Location2: " << hashLocation2 << endl;

    return 0;
}