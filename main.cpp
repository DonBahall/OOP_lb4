#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cout << "enter size of array";
    cin >> n >> m;

    vector<vector<int> > a(n, vector<int>(m));
    cout << "enter array";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (!cin) {
                cerr << "Incorrect input! Try again: ";
                cin.clear();
                cin.sync();
                while (cin.get() != '\n');
                j--;
            }

        }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    vector<int> b(n);

    int count = 0, sum = 0, count1 = 0, min = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] < 0) {
                count++;
                sum += a[i][j];
            } else if (a[i][j] == 0) {
                count1++;
            }
            min = a[i][0];
            if (min > a[i][j]) {
                min = a[i][j];
            }
        }

        if (count > m / 2.0) {
            b[i] = sum;
            sum = 0;
        } else if (count == m / 2.0) {
            b[i] = count1;
        } else if (count < m / 2.0) {
            b[i] = min;
            min = 0;
        }
        cout << "========" << endl;
        cout << b[i] << endl;
    }
}
