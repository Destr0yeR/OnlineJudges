struct Point
{
    int x;
    int y;
};

bool onSegment(Point p, Point q, Point r)
{
    return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;
 
    return (val > 0)? 1: 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    if (o1 != o2 && o3 != o4) return true;
 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false;
}

bool isInsideSquare(Point p, Point q, Point x, Point y) {
    int p1 = min(p.x, q.x);
    int p2 = max(p.x, q.x);
    int q1 = min(p.y, q.y);
    int q2 = max(p.y, q.y);

    int x1 = min(x.x, y.x);
    int x2 = max(x.x, y.x);
    int y1 = min(x.y, y.y);
    int y2 = max(x.y, y.y);

    return p1 <= x1 && x2 <= p2 && q1 <= y1 && y2 <= q2;
}


std::vector<std::string> multiSelection(std::vector<int> d, std::vector<std::string> t, std::vector<std::vector<int>> m) {

    std::vector<string> v;

    Point p = {m[0][0], m[0][1]};
    Point q = {m[1][0], m[1][1]};

    int y = 0;

    for(int i = 0 ; i < t.size() ; ++i) {
        Point tl = {0   , y};
        Point tr = {d[0], y};
        Point br = {d[0], y + d[1]};
        Point bl = {0   , y + d[1]};

        if(doIntersect(tl, tr, p, q) || doIntersect(tr, br, p, q)
            || doIntersect(br, bl, p, q) || doIntersect(bl, tl, p, q) || isInsideSquare(tl, br, p, q)) {
            v.push_back(t[i]);
        }

        y += d[1] + d[2];
    }

    return v;
}
