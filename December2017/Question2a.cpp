#include <iostream>
#include <string>
using namespace std;

int hashFunction(string key, int max) {
    long long hash = 0;

    for (int i = 0; i < key.length(); i++)
        hash = (hash * 31) + key.at(i) - '0';  // Using a prime number for better distribution

    return (hash % max) + 1;
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
