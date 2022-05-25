int f(int i,int j,string& str1, string& str2){
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(str1[i]==str2[j]) return f(i-1,j-1,str1,str2);
    return 1+min(f(i,j-1,str1,str2), //insert
                 min(f(i-1,j-1,str1,str2), //replace
                    f(i-1,j,str1,str2))); //delete
}
int editDistance(string str1, string str2)
{
    //write you code here
    int n=str1.size(), m=str2.size();
    return f(n-1,m-1,str1,str2);
}
