void rearrange(int arr[], int n)
{
    for (int i=0; i < n; i++)
        arr[arr[i]%n] += i*n;

    for (int i=0; i<n; i++)
        arr[i] /= n;
}
 
