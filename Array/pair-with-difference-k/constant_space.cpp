void findPair(int arr[], int n, int diff)
{
    // sort array in ascending order
    sort(arr, arr + n);
 
    // do for each array element
    for (int i = 0; i < n; i++)
    {
        // to avoid printing duplicates (skip adjacent duplicates)
        while (i < n - 1 && arr[i] == arr[i+1]) {
            i++;
        }
 
        // perform a binary search on element `arr[i]-diff`
        if (binary_search(arr, arr + n, arr[i] - diff)) {
            cout << "(" << arr[i] << ", " << arr[i] - diff << ")\n";
        }
    }
}
