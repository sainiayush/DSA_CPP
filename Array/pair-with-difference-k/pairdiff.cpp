void findPair(int arr[], int n, int diff)
{
    unordered_set<int> set;

    for (int i = 0; i < n; i++)
    {
        // check if pair with the given difference `(arr[i], arr[i]-diff)` exists
        if (set.find(arr[i] - diff) != set.end()) {
            cout << "(" << arr[i] << ", " << arr[i] - diff<< ")\n";
        }
 
        // check if pair with the given difference `(arr[i]+diff, arr[i])` exists
        if (set.find(arr[i] + diff) != set.end()) {
            cout << "(" << arr[i] + diff << ", " << arr[i] << ")\n";
        }
 
        // insert the current element into the set
        set.insert(arr[i]);
    }
}
