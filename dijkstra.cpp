#include <iostream>
#include <set>
#include <fstream>
#include <cstring>
#include <stack>
#include <vector>
#define LINE "----------------------------"
#define INF -1
using namespace std;
typedef pair<int, int> dist; // dist = ( distance , vertex )

pair<vector<int>, vector<vector<int> > > dijkstra(int at, vector<vector<pair<int, int> > > edges) {
    int n = edges.size();
    vector<int> distance(n, INF); distance[1] = 0;
    vector<int> from(n, -1); from[0] = 0; from[1] = 1;
    vector<bool> visited(n, false);
    
    // initialize distance to the weights from start
    //for (int i = 0 ; i < edges[at].size(); i++)
    //{
    //    int v = edges[at][i].first;
    //    int w = edges[at][i].second;
    //    distance[v] = w;
    //}

    set<dist> q; // set of distance (distance, vertex) notice distance is first
    q.insert(make_pair(0, at));
    while(!q.empty())
    {
        // fetch closest vertext using C++'s set
        dist at = *q.begin(); // call the current node "at"
        q.erase(q.begin());
        int at_d, at_v; at_d = at.first, at_v = at.second;

        // mark as visited
        if (visited[at_v]) continue;
        visited[at_v] = true;
        //cout<< at_v << endl;

        // update linked, yet-visited vertices' distance 
        for (int i = 0 ; i < edges[at_v].size() ; i++)
        {
            pair<int, int> edge = edges[at_v][i]; 
            int v, w; v = edge.first, w = edge.second;
            if (visited[v]) continue; 

            // shorter path to vertex v found
            if (distance[v] < 0 || distance[v] > at_d + w)
            {
            //cout << v << " " << w << endl;
                distance[v] = at_d + w; // update distance toward the linked vertex v
                q.insert(dist(distance[v], v)); // updated path will further be analysed
                from[v] = at_v; // also update backward linkage
            }
        }

        //for (int i = 0; i < distance.size(); i++)
        //    cout << distance[i] << " ";
        //cout << endl;
        //for (int i = 0; i < visited.size(); i++)
        //    cout << visited[i] << " ";
        //cout << endl;
        //for (int i = 0; i < from.size(); i++)
        //    cout << from[i] << " ";
        //cout << endl;
        
    }

    vector<vector<int> > path(n);
    if (distance[n] < 0) 
    {
        return pair<vector<int>, vector<vector<int> > > ();
    }
    else 
    {
        for (int i = 0 ; i < n; i++)
        {
            stack<int> s; 
            s.push(i);
            do 
            {
                s.push(from[s.top()]);
            } while (s.top()!=from[s.top()]);
            while(!s.empty())
            {
                path[i].push_back(s.top());
                s.pop();
            }
        }
    }
    return make_pair(distance, path);
}

int main(int argc, char**argv)
{
    ifstream ifs("input2.txt");

    for (int g = 1; ifs.peek()!=EOF; g++)
    {
        cout << LINE << endl;
        cout << "Graph " << g << endl;
        cout << LINE << endl;

        int n;    // node size of a graph
        ifs >> n;
        cout << "Vertex" << endl << n << endl << LINE << endl;

        // edge reading
        cout << "Edges" << endl;
        int l, w; // linked vertex, and its weight
        vector<vector<pair<int, int> > > edges(n+1); // adjacency list to store edges
        for (int v = 1; v <= n; v++)
        {
            ifs >> l;
            cout << l << " ";
            while(true) 
            {
                if (ifs.peek()=='\n')
                {
                    char c; ifs.get(c); // this will get '\n'
                    break;
                } 
                ifs >> l >> w;
                cout << l << " " << w << " ";
                edges[v].push_back(pair<int, int> (l, w));
            }
            cout << endl;
        }
        cout << LINE << endl;

        cout << "Adjacency list" << endl;
        for (int i = 1; i < edges.size(); i++)
        {
            cout << "node " <<  i << " : " ;
            for(int j = 0 ; j< edges[i].size() ; j++)
            {
                cout <<  edges[i][j].first << " (" << edges[i][j].second << ") ";
            }
            cout << endl;
        }
        cout << LINE << endl;

        cout << "Dijkstra algorithm" << endl;
        pair<vector<int>, vector<vector<int> > > ret = dijkstra(1, edges);
        vector<int> distance = ret.first;
        vector<vector<int> > path = ret.second;

        // output
        cout << "Starting vertex : " << 1 << endl;
        for (int i = 2 ; i < distance.size() ; i++)
        {
            cout << "Vertex " <<  i << " : ";
            for(int j = 0 ; j < path[i].size() - 1 ; j++) 
            {
                cout << path[i][j] << " - ";
            } cout << path[i][path[i].size()-1];
            cout << ", distance : " << distance[i] << endl;
        }
        cout << LINE << endl;

        cout << endl << endl << endl << endl << endl << endl << endl;
    }
    return 0;
}

