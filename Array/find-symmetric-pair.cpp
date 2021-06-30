void getSymmetricPair(int arr[][2], int row)
{
    unordered_map<int, int> myMap;
    for (int i = 0; i < row; i++)
    {
        int firstValue = arr[i][0];
        int secondValue = arr[i][1];
        if (myMap.find(secondValue) != myMap.end() && myMap[secondValue] == firstValue)
        {
            cout << "(" << secondValue << ", " << firstValue << ")"<<" ";
        }
        else
        {
            myMap[firstValue] = secondValue;
        }
    }
}
