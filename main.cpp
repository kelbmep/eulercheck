#include <bits/stdc++.h>

using namespace std;

struct rib
{
    int left;
    int right;
};
rib reverse(rib a)
{
    return {a.right, a.left};
}
bool operator<(const rib& a1, const rib& a2)
{
    if(a1.left != a2.left) return a1.left < a2.left;
    if(a1.right != a2.right) return a1.right < a2.right;
    return false;
}
int main()
{
    string str;
    int prev, curr = 0;
    set<rib> ribs;
    set<int> vert;
    getline(cin, str);
    stringstream fck;
    fck << str;
    while(!fck.eof())
    {
        prev = curr;
        fck >> curr;
        vert.insert(curr);
        if(prev != 0)
        {
            if(prev == curr)
            {
                cout << "NO" << endl;
                return 0;
            }
            rib a{prev, curr};
            int check = ribs.size();
            ribs.insert(a);
            if(check - ribs.size() == 0)
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if(2 * (vert.size() - 1) != ribs.size())
    {
        cout << "NO" << endl;
        return 0;
    }
    for(set<rib>::iterator it = ribs.begin(); it != ribs.end(); it++)
        if(ribs.find(reverse(*it)) == ribs.end())
        {
            cout << "NO" << endl;
            return 0;
        }
    cout << "YES" << endl;
    return 0;
}
