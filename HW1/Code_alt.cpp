#include <bits/stdc++.h>
using namespace std;

int countSmallerThanMid(vector<int> &row, int mid)
{
    int l = 0, h = row.size() - 1;
    while (l <= h)
    {
        int md = (l + h) >> 1;
        if (row[md] <= mid)
        {
            l = md + 1;
        }
        else
        {
            h = md - 1;
        }
    }
    return l;
}

int findMedian(vector<vector<int>> &A, int k)
{
    int low = 1;
    int high = 1e9;
    int n = A.size();
    int m = A[0].size();
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += countSmallerThanMid(A[i], mid);
        }
        if (cnt < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int main()
{
    int row = 3, col = 4;
    vector<vector<int>> arr = {{1, 3, 8, 9, 11, 13},
                               {2, 3, 4, 10, 14, 15},
                               {1, 2, 5, 7, 15, 17}};
    int k = 9;
    cout << "The median of the row-wise sorted matrix is: " << findMedian(arr, k) << endl;
    return 0;
}