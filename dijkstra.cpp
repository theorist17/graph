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
    int n = edges.size(); // Number of edge, one bigger than actual node size
    vector<int> distance(n, INF); distance[1] = 0; // init to -1 (INF, infinite)
    vector<int> from(n, -1); from[0] = 0; from[1] = 1; // save previous node
    vector<bool> visited(n, false);
    

    // Perform Dijkstra untile all node visited
    set<dist> q; // a set of distance (distance, vertex) 
                // which will allow to easily access minimum weighted node
                // notice distance is first
    q.insert(make_pair(0, at)); // insert first node with 0 distance
    while(!q.empty()) // until no further dist candidtaes are
    {
        // fetch closest vertext using C++'s set
        dist at = *q.begin(); // call the current node "at"
        q.erase(q.begin());
        int at_d, at_v; at_d = at.first, at_v = at.second;

        // mark as visited
        if (visited[at_v]) continue;
        visited[at_v] = true;

        // update linked, yet-visited vertices' distance 
        for (int i = 0 ; i < edges[at_v].size() ; i++)
        {
            pair<int, int> edge = edges[at_v][i]; // fetch linked one
            int v, w; v = edge.first, w = edge.second;
            if (visited[v]) continue;  // no revisit

            // shorter path to vertex v found
            if (distance[v] < 0 || distance[v] > at_d + w)
            {
            //cout << v << " " << w << endl;
                distance[v] = at_d + w; // update distance toward the linked vertex v
                q.insert(dist(distance[v], v)); // updated path will further be analysed
                from[v] = at_v; // also update backward linkage
            }
        }

        // For understanding, uncomment these lines
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

    // Returning answer
    vector<vector<int> > path(n);
    if (distance[n] < 0) // If input is directed asycly graph, no problem here.
    {
        cerr << "Something's wrong about the input graph" << endl;
        return pair<vector<int>, vector<vector<int> > > (); // If no path found.
    }
    else 
    {
        // Path anlaysis
        for (int i = 0 ; i < n; i++) // For each node
        {
            stack<int> s; 
            s.push(i); // Push the destination node
            do 
            {
                s.push(from[s.top()]); // push the node following the lead where
                                    // from [index] is pointing
            } while (s.top()!=from[s.top()]); // if reached 0, or 1, recusion
            while(!s.empty())
            {
                path[i].push_back(s.top()); // push it backwards
                s.pop();
            }
        }
    }
    return make_pair(distance, path); // squash both of them into pair
}

int main(int argc, char**argv)
{
    ifstream ifs("input2.txt"); // Read from file

    for (int g = 1; ifs.peek()!=EOF; g++)
    {
        // Print graph name
        cout << LINE << endl;
        cout << "Graph " << g << endl;
        cout << LINE << endl;

        // Print vertex number
        int n;    // node size of a graph
        ifs >> n;
        cout << "Vertex" << endl << n << endl << LINE << endl;

        // Read edge and put it into adjacency list
        cout << "Edges" << endl;
        int v, w; // linked vertex, and its weight
        vector<vector<pair<int, int> > > edges(n+1); // adjacency list to store edges
        for (int i = 1; i <= n; i++)
        {
            ifs >> v;   // read out the first column
            cout << v << " ";
            while(true) 
            {
                if (ifs.peek()=='\n') // if new line comes next, break
                {
                    char c; ifs.get(c); // this will get '\n'
                    break;
                } 
                ifs >> v >> w; // safe to read until '\n'
                cout << v << " " << w << " ";
                edges[i].push_back(pair<int, int> (v, w)); // push v
            }
            cout << endl;
        }
        cout << LINE << endl;

        // Print list
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

        // Get Dijkstra result
        cout << "Dijkstra algorithm" << endl;
        pair<vector<int>, vector<vector<int> > > ret = dijkstra(1, edges);
        vector<int> distance = ret.first;
        vector<vector<int> > path = ret.second;

        // Print the result
        cout << "Starting vertex : " << 1 << endl;
        for (int i = 2 ; i < distance.size() ; i++)
        {
            cout << "Vertex " <<  i << " : ";
            for(int j = 0 ; j < path[i].size() - 1 ; j++) 
            {
                cout << path[i][j] << " - ";
            } cout << path[i][path[i].size()-1]; // print path
            cout << ", distance : " << distance[i] << endl; // print distance
        }
        cout << LINE << endl;

        // Huge blank
        cout << endl << endl << endl << endl << endl << endl << endl;
    }
    return 0;
}

