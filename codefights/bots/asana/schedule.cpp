vector<int> cantDays = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int d, m, y;

vector<int> getNextDay(const vector<int>& v) {
    int d = v[0];
    int m = v[1];
    int y = v[2];
    
    int extra = 0;
    
    if(m == 2 && y%4 == 0) {
        if(y%100 == 0) {
            if(y%400 == 0)extra = 1;
            else extra = 0;
        }
        else extra = 1;
    }
    
    if(d + 1 > cantDays[m-1] + extra) {
        d = 1;
        if(m == 12) {
            m = 1;
            y++;
        }
        else m++;
    }
    else d++;
    
    return {d, m, y};
}

int getIndexOf(const string& toFind) {
    
    vector<string> daysOfTheWeek = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
    for(int i = 0 ; i < daysOfTheWeek.size() ; ++i) {
        if(daysOfTheWeek[i] == toFind)return i;
    }
    return -1;
}

int getDayNumber(string date) {
    date += "/";
    vector<int> v;
    int tmp = 0;
    for(int i = 0 ; i < date.size() ; ++i) {
        if(date[i] == '/') {
            v.push_back(tmp);
            tmp = 0;
        }
        else {
            tmp *= 10;
            tmp += date[i] - '0';
        }
    }
    d = v[0];
    m = v[1];
    y = v[2];
    
    int ans = 365 * (y-1900) + 
              ((y-1)/4 - (y-1)/100 + (y-1)/400)
              - ((1900)/4 - (1900)/100 + (1900)/400);
    
    int sumMonth = 0;
    
    for(int i = 0 ; i < m-1 ; ++i) {
        if(i == 1) {
            if(y % 4 == 0){
                if(y % 100 == 0) {
                    if(y % 400 == 0)sumMonth += cantDays[i]+1;
                    else sumMonth += cantDays[i];
                }
                else sumMonth += cantDays[i] + 1;
            }
            else sumMonth += cantDays[i];
        }
        else sumMonth += cantDays[i];
    }
    
    return ans + sumMonth + d;
}

std::vector<std::string> recurringTask(std::string firstDate, int k, std::vector<std::string> daysOfTheWeek, int n) {
    vector<string> ans;
    vector<int> days;
    
    for(int i = 0 ; i < daysOfTheWeek.size() ; ++i) {
        days.push_back(getIndexOf(daysOfTheWeek[i]));
    }
    
    int cnt = 0;
    int index = -1;
    int dayOfTheWeek = getDayNumber(firstDate)%7;
    for(int i = 0 ; i < days.size() ; ++i) {
        if(dayOfTheWeek == days[i]) {
            index = i;
            break;
        }
    }
    int initial = index;
    vector<int> tt = {d, m, y};

    while(cnt < n) {
        if(dayOfTheWeek == days[index]) {
            string dd = to_string(tt[0]);
            while(dd.size() < 2)dd = "0"+dd;
            string mm = to_string(tt[1]);
            while(mm.size() < 2)mm = "0"+mm;
            
            ans.push_back(dd
                      +"/"+ mm
                      +"/" + to_string(tt[2]));
            
            index = (index + 1)%days.size();
            cnt++;
            if(index == initial) {
                for(int i = 0 ; i < (k-1)*7 ; ++i) {
                        tt = getNextDay(tt);
                        dayOfTheWeek = (dayOfTheWeek+1)%7;
                }
            }
        }
        tt = getNextDay(tt);
        dayOfTheWeek = (dayOfTheWeek+1)%7;
    }
    
    return ans;
}
