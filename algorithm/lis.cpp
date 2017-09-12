#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, len,num;
    int i, j, k, m;
    int max;
    vector<int> arr, rec;
    cin >> n;
    for(i = 0; i < n; i++) {
        arr.clear();
        rec.clear();
        rec.push_back(1);
        max = -1;
        cin >> len;
        for(j = 0; j < len; j++) {
            cin >> num;
            arr.push_back(num);
        }
        for(k = 0; k < arr.size(); k++) {
            for(m = 0; m < k; m++) {
                if(arr[m] < arr[k]) {
                    if(rec[m] > max)
                        max = rec[m];
                }
            }
            if(max == -1)
                rec.push_back(1);
            else
                rec.push_back(max + 1);
        }
        max = -1;
        for(k = 0; k < rec.size(); k++) {
            if(rec[k] > max)
                max = rec[k];
        }
        cout << max << endl;
    }
    return 0;
}

