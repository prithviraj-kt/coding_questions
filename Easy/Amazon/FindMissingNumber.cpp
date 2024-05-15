#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr;
    int size;
    cin >> size;
    cin.ignore();
    string inputs;
    getline(cin, inputs);
    stringstream ss(inputs);
    int temp;
    int s = size;
    while (ss >> temp && s > 0)
    {
        arr.push_back(temp);
        s--;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        if (i + 1 != arr[i])
        {
            cout << i + 1 << " ";
            break;
        }
    }

    return 0;
}