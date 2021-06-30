void findPair(int arr[], int n, int diff)
{
    // sort array in ascending order
    sort(arr, arr + n);
 
    // take an empty set
    unordered_set<int> set;
 
    // do for every array element
    for (int i = 0; i < n; i++)
    {
        // to avoid printing duplicates (skip adjacent duplicates)
        while (i+1 < n && arr[i] == arr[i+1]) {
            i++;
        }
 
        // check if pair with the given difference `(arr[i], arr[i]-diff)` exists
        if (set.find(arr[i] - diff) != set.end()) {
            cout << "(" << arr[i] << ", " << arr[i] - diff << ")\n";
        }
 
        // check if pair with the given difference `(arr[i]+diff, arr[i])` exists
        if (set.find(arr[i] + diff) != set.end()) {
            cout << "(" << arr[i] + diff << ", " << arr[i] << ")\n";
        }
 
        // insert the current element into the set
        set.insert(arr[i]);
    }
}
