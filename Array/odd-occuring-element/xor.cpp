int findOddOccuring(int arr[], int n)
{
    int xor = 0;
    for (int i = 0; i < n; i++) {
        xor = xor ^ arr[i];
    }
 
    return xor;
}
