#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
#define DEBUG 1
#define LINE "----------------------------"

using namespace std;

void dfs(int at, int depth,  vector<vector<bool> > &edges, vector<bool> &visited, vector<int> &sequence){
    sequence.push_back(at);
    visited[at] = true;
    for (int i = 1 ; i < edges.size() ; i++) {
        if (edges[at][i] && !visited[i])
            dfs(i, depth+1, edges, visited, sequence);
    }
}

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
                visited[i] = true;
            }
        }
    }
    return sequence;
}

int main(int argc, char** argv)
{
    ifstream ifs("input.txt");
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
        int t;
        vector<vector<bool> > edges(n+1, vector<bool>(n+1, 0)); // using vector to store edges
        for (int v = 1; v <= n; v++)
        {
            ifs >> t;
            cout << t << " ";
            while(true) 
            {
                if (ifs.peek()=='\n')
                {
                    char c; ifs.get(c); // this will get '\n'
                    break;
                } 
                ifs >> t; 
                cout << t << " ";
                edges[v][t] = true;
            }
            cout << endl;
        }
        cout << LINE << endl;

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


        cout << "Depth first search" << endl;
        vector<bool> visited(n+1, false);
        vector<int> sequence;
        dfs(1, 0, edges, visited, sequence);
        for (int i = 0 ; i < sequence.size() ; i++) 
            cout << sequence[i] << " " ;
        cout << endl;
        cout << LINE << endl;

        cout << "Breadth first search" << endl;
        fill(visited.begin(), visited.end(), false); // reset every value of a vector<bool> to false
        sequence.clear();   // removes all elements from the vector
        sequence = bfs(1, edges, visited);
        for (int i = 0 ; i < sequence.size() ; i++) 
            cout << sequence[i] << " " ;
        cout << endl;
        cout << LINE << endl;



        cout << endl << endl << endl << endl << endl << endl << endl;

    }

    return 0;
}

