#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
#define DEBUG 1
#define LINE "----------------------------"

using namespace std;

// recursive dfs
void dfs(int at, int depth,  vector<vector<bool> > &edges, vector<bool> &visited, vector<int> &sequence){
    sequence.push_back(at); // answer
    visited[at] = true;
    for (int i = 1 ; i < edges.size() ; i++) { // start indexing from 1
        if (edges[at][i] && !visited[i])
            dfs(i, depth+1, edges, visited, sequence);
    }
}

// bfs using C++ STL queue
vector<int> bfs(int at, vector<vector<bool> > &edges, vector<bool> &visited){
    vector<int> sequence;

    queue<int> q;
    q.push(at);
    visited[at] = true;
    while(!q.empty())
    {
        at = q.front();
        q.pop();
        sequence.push_back(at);

        for (int i = 1; i < edges.size() ; i++) {
            if (edges[at][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true; // avoid revisiting
            }
        }
    }
    return sequence;
}

int main(int argc, char** argv)
{
    ifstream ifs("input.txt");// read from text file

    for (int g = 1; ifs.peek()!=EOF; g++) // if next character is EOF, break
    {

        // Print graph
        cout << LINE << endl;
        cout << "Graph " << g << endl;
        cout << LINE << endl;

        // Print size of vertex
        int n;    // node size of a graph<< j << " (" << edges[i][j] << ") ";
        ifs >> n;
        cout << "Vertex" << endl << n << endl << LINE << endl; 

        // Read edges from files and store it into 2D vector
        cout << "Edges" << endl;
        int t;
        vector<vector<bool> > edges(n+1, vector<bool>(n+1, 0)); // using vector to store edges
                                                                // init to zero
        for (int v = 1; v <= n; v++) // for each edge
        {
            ifs >> t; // read out the first character
            cout << t << " ";
            while(true) 
            {
                if (ifs.peek()=='\n')  // if '\n' comming up, break
                {
                    char c; ifs.get(c); // this will get '\n'
                    break;
                } 
                ifs >> t;  // safe to read until '\n' comes up
                cout << t << " ";
                edges[v][t] = true; // represent edge
            }
            cout << endl;
        }
        cout << LINE << endl;

        // Print adjacency matrix from data read into "edges"
        cout << "Adjacency matrix" << endl;
        for (int i = 1; i <= n ; i++)
        {
            for(int j = 1 ; j<= n ; j++)
            {
                if (edges[i][j])
                    cout << true << " ";
                else
                    cout << false << " ";
            }
            cout << endl;
        }
        cout << LINE << endl;

        // Print depth first search result
        cout << "Depth first search" << endl;
        vector<bool> visited(n+1, false);
        vector<int> sequence;
        dfs(1, 0, edges, visited, sequence);
        for (int i = 0 ; i < sequence.size() ; i++) 
            cout << sequence[i] << " " ;
        cout << endl;
        cout << LINE << endl;

        // Print bfs result
        cout << "Breadth first search" << endl;
        fill(visited.begin(), visited.end(), false); // reset every value of a vector<bool> to false
        sequence.clear();   // removes all elements from the vector
        sequence = bfs(1, edges, visited);
        for (int i = 0 ; i < sequence.size() ; i++) 
            cout << sequence[i] << " " ;
        cout << endl;
        cout << LINE << endl;

        // Huge blank
        cout << endl << endl << endl << endl << endl << endl << endl;

    }

    return 0;
}

