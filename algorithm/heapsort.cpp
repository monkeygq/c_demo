#include <iostream>
#include <vector>
#include <list>
#include <functional>
#include <sstream>
#include <numeric>
#include <map>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <set>
#include <list>
#include <utility>
#include <set>
#include <utility>
#include <thread>
#include <mutex>
#include <algorithm>
#include <stdlib.h>

#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <cstring>
#include <stdio.h>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>

using namespace std;

void maxheap(vector<int>& vi, int max_idx, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int flag = i;
    if (l <= max_idx && vi[l] >= vi[flag]) {
        flag = l;
    }
    if (r <= max_idx && vi[r] >= vi[flag]) {
        flag = r;
    }
    if (flag == i) {
        return;
    }
    else {
        int tmp;
        tmp = vi[i];
        vi[i] = vi[flag];
        vi[flag] = tmp;
        maxheap(vi, max_idx, flag);
    }
}

void build_maxheap(vector<int>& vi) {
    for (int i = (vi.size() - 1) / 2; i >= 0; --i) {
        maxheap(vi, vi.size() - 1, i);
    }
}

void heapsort(vector<int>& vi) {
    build_maxheap(vi);
    for (int i = vi.size() - 1; i > 0; --i) {
        int tmp;
        tmp = vi[i];
        vi[i] = vi[0];
        vi[0] = tmp;
        maxheap(vi, i - 1, 0);
    }
}

int main() {
    vector<int> vi = {3,5,9,7,4,2,8,7};
    heapsort(vi);
    for (auto& v: vi) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}
