#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define ll long long
int SUM;
bool yes;
char ch;

bool ReadTree(ll val) {
   bool child1 = false, child2 = false;
   int thisval = 0, sign = 1;
   while (scanf("%c", &ch)!=EOF) {
      if (ch==' ' || ch=='\n') continue;
      if (ch==')') return false; // null
      if (ch=='(') break;
      if (ch=='-') sign = -1;
      if (isdigit(ch)) thisval = thisval*10 + (ch-48);
   }
   thisval *= sign;
   val += (ll)thisval;
   child1 = ReadTree(val);
   while (scanf("%c", &ch)!=EOF && ch!='(');
   child2 = ReadTree(val);
   
   if (!child1 && !child2 && val==SUM) yes = true;
   while (scanf("%c", &ch)!=EOF && ch!=')');
   return true;
}

int main() {

   char ch;
   while (scanf("%d ", &SUM)!=EOF) {
      yes = false;
      while (scanf("%c", &ch)!=EOF && ch!='(');
      ReadTree(0);
      if (yes) puts("yes");
      else puts("no");
   }
   return 0;
}

