int getOddOccurrence(int arr[],int size)
{

    unordered_map<int, int> hash;
 
    // Putting all elements into the HashMap
    for(int i = 0; i < size; i++)
    {
        hash[arr[i]]++;
    }
    // Iterate through HashMap to check an element
    // occurring odd number of times and return it
    for(auto i : hash)
    {
        if(i.second % 2 != 0)
        {
            return i.first;
        }
    }
    return -1;
}
