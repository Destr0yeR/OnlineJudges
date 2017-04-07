std::vector<int> tasksTypes(std::vector<int> d, int day) {
    vector<int> v(3, 0);

    for(int i = 0 ; i < d.size() ; ++i) {
        if(d[i] <= day)v[0]++;
        else if(d[i] <= day + 7)v[1]++;
        else v[2]++;
    }

    return v;
}