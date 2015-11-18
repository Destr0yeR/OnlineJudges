#include<bits/stdc++.h>

using namespace std;
 
int main () 
{
    int testCases; scanf ("%d", &testCases);
 
    while ( testCases-- ) {
        int x, y, z;
        scanf ("%d %d %d", &x, &y, &z);
 
        int totalWorkHour = x + y;
        int totalWorkMinute = totalWorkHour * 60;
        int eachShareMinute = totalWorkMinute / 3;
        int familyAExtraMinute = x * 60 - eachShareMinute;
        if ( familyAExtraMinute <= 0 ) printf ("0\n");
        else printf ("%d\n", (z * familyAExtraMinute) / eachShareMinute);
    }
 
    return 0;
}
