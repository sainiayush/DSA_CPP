int findMinIndex(int arr[], int n)
{
    int minIndex = n;

    unordered_set<int> set;

    for (int i = n - 1; i >= 0; i--)
    {
        if (set.find(arr[i]) != set.end()) {
            minIndex = i;
        }
        else {
            set.insert(arr[i]);
        }
    }
    return minIndex;
}
