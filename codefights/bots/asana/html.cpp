
std::string htmlToLuna(std::string html) {
    std::vector<int> v;

    string aux = "";
    int open = 1;

    for(int i = 0 ; i < html.size() ; ++i) {
        if(html[i] == '<') {
            open = 1;
            if(html[i+1] == '/') {
                open = -1;
                i++;
            }
        }
        else if(html[i] == '>') {
            if(aux[0] == 'd') open *= 1;
            else if(aux[0] == 'b') open *= 2;
            else if(aux[0] == 'p') open *= 3;
            else if(aux[0] == 'i')open = 4;
            v.push_back(open);

            aux  = "";
            open = 1;
        }
        else aux += html[i];
    }

    string ans = "";

    int cnt = 0;

    for(int i = 0 ; i < v.size() ; ++i) {
        if(v[i] < 0){
            ans += "])";
            if(i + 1 < v.size() && v[i+1] > 0 && cnt > 1) ans += ", ";
            cnt--;
        }
        else {
            
            if(v[i] == 1) ans += "DIV([";
            else if(v[i] == 2) ans += "B([";
            else if(v[i] == 3) ans += "P([";
            else if(v[i] == 4) ans += "IMG({})";

            if(v[i] != 4)cnt++;
        }

    }

    return ans;
}