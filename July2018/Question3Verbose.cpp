#include <iostream>
using namespace std;

int calculateIndex(int i, int j) {
    return (i * (i - 1)) / 2 + j;
}

void swap(int i, int j) {
    int temp = i;
    i = j;
    j = temp;
}

int score(int i, int j, int B[], int n) {
    if (i < 0 || i > n || j < 0 || j > n || i == j)
        return -1;
    if (i < j)
        swap(i, j);
    int index = calculateIndex(i, j);
    return B[index];
}

int totalPoints(int team, int B[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        if (team != i)
            total += score(max(team, i), min(team, i), B, n);
    return total;
}
int main() {
    int n = 4;  // Replace with the actual number of teams

    int B[] = {3, 1, 0, 1, 0, 3, 0, 1, 3, 0, 1, 0};

    int i = 0, j = 1;
    int result = score(i, j, B, n);
    cout << "A[" << i << ", " << j << "] = " << result << endl;

    int team = 2;
    int total = totalPoints(team, B, n);
    cout << "Total points for team " << team << ": " << total << endl;

    return 0;
}
