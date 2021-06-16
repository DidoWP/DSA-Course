

#include <iostream>
#include <vector>

using namespace std;


int sum;

void rec(vector < int > relations[] ,int index)
{
    if (relations[index].empty())return;
    sum += relations[index].size();
    for (auto i = relations[index].begin(); i != relations[index].end(); i++)
    {
        rec(relations,*i);
    }
    return;
}
int main()
{
    int n;
    int x, y;
    vector < int > relations[1000000];
    cin >> n;
	
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        relations[x].push_back(y);
    }

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        rec(relations,i);
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}