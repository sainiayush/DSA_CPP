int mod(string t, int N){
    int r=0;
    for(int i=0; i<len(t); ++i){
        r = r*10 + (t[i]-'0');
        r %= N;
    }
    return r;
}
string getMinBinaryMultiple(int N){
    queue<string> q;
    set<int> vis;
    string t = "1";
    q.emplace(t);

    while(!q.empty()){
        t = q.front();
        q.pop();

        int rem = mod(t, N);
        if(rem == 0)
            return t;

        if(!vis.count(rem)){
            vis.insert(rem);
            q.emplace(t + "1");
            q.emplace(t + "0");
        }
    }
    return "\0";
}
