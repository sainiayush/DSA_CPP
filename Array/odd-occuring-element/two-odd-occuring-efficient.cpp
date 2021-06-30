void printOdds(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res = res ^ arr[i];

    int set_bit = res & (~(res - 1));
 
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] & set_bit)
            x = x ^ arr[i];
        else
            y = y ^ arr[i];
    }
 
    cout << x << " " << y;
}
