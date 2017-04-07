std::string smartAssigning(std::vector<std::string> n, std::vector<bool> s, std::vector<int> p, std::vector<int> t) {
    map<int, vector<int>> mp;
    int mini = -1;

    for(int i = 0 ; i < t.size() ; ++i) {
        if(s[i])continue;
        if(mini == -1)mini = t[i];
        mini = min(mini, t[i]);
        mp[t[i]].push_back(i);
    }
}
