#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define N 55000
using namespace std;

int P[N];

class info
{
public:
   int p,c,guard;
};

bool compare(info i1, info i2)
{
   if(i1.guard == i2.guard)
      return i1.p < i2.p;
   return i1.guard<i2.guard;
}
int Union(int node)
{
   if(P[node] == node) return node;
   return P[node] = Union(P[node]);
}

bool makeUnion(int p, int c)
{
   if(Union(p) != Union(c))
   {
      P[P[p]] = P[c];
      return true;
   }
   return false;
}
int main()
{
   int testcase;
   cin >> testcase;
   for(int  t = 1 ; t <= testcase ; t++)
   {
      int citynum;
      vector <info> city;
      cin >> citynum;

      for(int i = 0 ; i < citynum ; i++)
      {
         for(int j = 0; j < citynum ; j++)
         {
            info temp;
            char c;
            temp.p = i; temp.c = j; cin >> temp.guard;
            if(temp.guard!=0)
               city.push_back(temp);

            if(j < citynum-1)
               cin >> c;
         }
      }

      for(int  i = 0 ; i < citynum ; i++)
         P[i] = i;

      sort(city.begin(),city.end(),compare);

      vector <info> result;

      int a = city.size();
      for(int i = 0 ; i < a ; i++)
      {
         if(makeUnion(city[i].p,city[i].c))
         {
            result.push_back(city[i]);
         }
      }
      int b = result.size();
      cout << "Case " << t << ":" << endl;

      for(int i = 0 ; i < b ; i++)
      {
         char p,c;
         p = result[i].p + 65; c = result[i].c + 65;
         cout << p << "-" << c << " " << result[i].guard << endl;
      }
   }
}
