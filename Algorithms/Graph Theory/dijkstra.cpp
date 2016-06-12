#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <utility>
using namespace std;

int dijkstra(vector< vector< pair<int,int> > >& matrix, const int& start, const int& end, vector<int>& distances);

int main() {
    int t,n,m; cin >> t;
    
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        
        // adj-list using vector of size n holding a vector for
        // each vertex.
        vector< vector< pair<int,int> > > matrix(n);
        
        int f,s,w, // first, second, weight
        j; // iter
        for (j = 0; j < m; j++) {
            cin >> f >> s >> w;      
            matrix[f-1].push_back( make_pair(s-1,w) );
            matrix[s-1].push_back( make_pair(f-1,w) );
        }
        
        int start; cin >> start;
        start--; // zero-base the starting point
        vector<int> distances(matrix.size(), numeric_limits<int>::max());
        for (j = 0; j < n; j++) {
            if (j != start)
                cout << dijkstra(matrix, start, j, distances) << " ";
        }
        cout << endl;
    }
    
    return 0;
}

int dijkstra(vector< vector< pair<int,int> > >& matrix, const int& start, const int& end, vector<int>& distances) {
    
    vector<int> nodes; // another vec of ints
    
    distances[start] = 0;
    
    for (int i = 0, n = matrix.size(); i < n; i++)
        if (i != start) nodes.push_back(i);
   
    nodes.push_back(start);
    
    
    auto comp = [&](int l, int r) {return distances[l] > distances[r];};
    make_heap(nodes.begin(), nodes.end(), comp);
    
    while(!nodes.empty()) {
        pop_heap(nodes.begin(), nodes.end(), comp);
        int smallest = nodes.back();
        nodes.pop_back();
 
        if (smallest == end) break; // returns at bottom anyway
 
        if (distances[smallest] == numeric_limits<int>::max())
            return -1;
 
        for(int i = 0, n = matrix[smallest].size(); i < n; i++) {
            int tmp = distances[smallest] + matrix[smallest][i].second;
           
            if (tmp < distances[matrix[smallest][i].first] && tmp > 0) {
                distances[matrix[smallest][i].first] = tmp;
                make_heap(nodes.begin(), nodes.end(), comp);
            }
        }
    }
    if (distances[end] == numeric_limits<int>::max())
        return -1;
    else
        return distances[end];
}