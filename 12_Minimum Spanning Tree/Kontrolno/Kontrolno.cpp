// Kontrolno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//
//void dfs(vector<int> graph[], vector<bool> visited, int current, bool& flag)
//{
//    if (flag) return;
//
//    if (visited[current])
//    {
//        flag = true;
//        return;
//    }
//
//    if (!visited[current])
//    {
//        visited[current] = true;
//        for (int child : graph[current])
//        {
//            dfs(graph, visited, child, flag);
//        }
//    }
//}
//int main()
//{
//    int x, y, price, q, n, m;
//
//    cin >> q;
//    for (int i = 0; i < q; i++)
//    {
//        vector<int> graph[1001];
//    	
//        cin >> n >> m;
//        for (int j = 0; j < m; j++)
//        {
//            cin >> x >> y >> price;
//            graph[x].push_back(y);
//        }
//
//        vector<bool> visited(n + 1, false);
//        bool flag = false;
//        dfs(graph, visited, 1, flag);
//
//        if (flag) cout << 1;
//        else cout << 0;
//    }
//}





// Kontrolno.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;



bool dfsHasCycle(int start, vector<bool> visited, vector<int> graph[], bool hasCycle) {
    visited[start] = true;

    if (hasCycle) {
        return true;
    }

    for (size_t i = 0; i < graph[start].size(); i++) {
        if (hasCycle) {
            break;
        }

        if (visited[graph[start][i]] == false) {
            hasCycle = dfsHasCycle(graph[start][i], visited, graph, hasCycle);
        }
        else {
            hasCycle = true;
        }
    }

    return hasCycle;
}

bool dfsCycleNoStartingPoint(vector<bool> visited, vector<int> graph[], int n) {
    bool hasCycle = false;

    for (size_t i = 0; i < n; i++) {
        hasCycle = dfsHasCycle(i, visited, graph, false);

        if (hasCycle) {
            return true;
        }
    }

    return hasCycle;
}


int main()
{
    int x, y, price, q, n, m;

    cin >> q;
    for (int i = 0; i < q; i++)
    {
        vector<int> graph[1001];
    	
        cin >> n >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> x >> y >> price;
            graph[x].push_back(y);
        }

        vector<bool> visited(n + 1, false);
        bool flag = false;
        cout << dfsCycleNoStartingPoint(visited, graph, n);


    }
}






//
//void dfs(vector<int> graph[], vector<bool> visited, int current, bool& flag)
//{
//    if (flag) return;
//
//    if (visited[current])
//    {
//        flag = true;
//        return;
//    }
//
//    if (!visited[current])
//    {
//        visited[current] = true;
//        for (int child : graph[current])
//        {
//            dfs(graph, visited, child, flag);
//        }
//    }
//}