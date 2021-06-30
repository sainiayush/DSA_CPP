void printTriplets(int arr[], int n, int sum)
{
    // Fix the first element as A[i]
    for (int i = 0; i < n-2; i++)
    {
       // Fix the second element as A[j]
       for (int j = i+1; j < n-1; j++)
       {
           // Now look for the third number
           for (int k = j+1; k < n; k++)
               if (arr[i] + arr[j] + arr[k] < sum)
                  cout << arr[i] << ", " << arr[j]<< ", " << arr[k] << endl;
       }
    }
}
