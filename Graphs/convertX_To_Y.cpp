//Allowed Operations : x-> x*2, x-> x-1
int convertX_To_Y(int x, int y){
    if(x == y) return 0;
    queue<node> q;
    q.push(node(x, 0));

    set<int> s;

    node n;
    while(!q.empty()){
        node t = q.front();
        q.pop();

        if(t.val == y)
            return t.level;

        s.insert(t.val);

        if(!s.count(t.val * 2)){
            n.val = t.val;
            n.level = t.level+1;
            q.push(n);
        }

        if(t.val - 1 >= 0 && !s.count(t.val - 1)){
            n.val = t.val - 1;
            n.level = t.level + 1;
            q.push(n);
        }
    }
    return -1;
}
