// An adjacency matrix is a way to represent a graph using a two-dimensional matrix. 
// In the context of graphs, an adjacency matrix is a square matrix where rows and columns represent vertices (nodes) of the graph.
// The entries in the matrix indicate whether there is an edge between the corresponding vertices.
// For an undirected graph, the adjacency matrix is symmetric, 
// meaning the matrix is the same if you transpose it. 
// If there's an edge between vertex i and vertex j, 
// the corresponding entry (i, j) and (j, i) in the matrix will be non-zero 
// (usually indicating the weight or presence of the edge). 
// If there's no edge between them, the entry will be zero.
// For a directed graph, the adjacency matrix can be asymmetric.
// An entry (i, j) will be non-zero if there's a directed edge from vertex i to vertex j. 
// If there's no edge, the entry will be zero.

//    | 1  2  3  4
// ---|-----------
//  1 | 0  1  0  1
//  2 | 1  0  1  0
//  3 | 0  1  0  0
//  4 | 1  0  0  0

// In this example,
// there's a graph with four vertices (1, 2, 3, 4),
// and the matrix indicates the presence of edges between them.
// For instance, there's an edge between vertex 1 and vertex 2,
// so the entry in row 1 and column 2 is 1.
// Please note that for weighted graphs, 
// the entries in the matrix would represent the weights of the edges
// rather than just presence (1) or absence (0) of edges.
// Adjacency matrices are straightforward for small graphs,
// but they can be memory-intensive for large sparse graphs 
// (where there are relatively few edges compared to the number of possible edges).
// In such cases, other representations like adjacency lists might be more efficient.

// Time Complexity: O(V^2)
// Space Complexity: O(V^2)
// In graph theory and algorithm analysis,
// "V + E" complexity refers to a way of describing the complexity 
// of an algorithm or problem in terms of the number of vertices (V)
// and the number of edges (E) in a graph.

// V: Represents the number of vertices (nodes) in the graph.
// E: Represents the number of edges connecting those vertices.

// step 1: get n from user
// step 2: create a 2D array of size n*n
// step 3: for {int i = 0; i < n; i++} and {int j = 0; j < n; j++} set all values to 0
// step 4: for {int i = 0; i < n; i++} and {int j = 0; j < n; j++} set values to 1 if there is an edge between them
// step 5: print the matrix
// traversal steps
// step 1: initialize all nodes to ready node
// step 2: get "start vertex" to SV
// step 3: put SV to Q and status{SV} = Q
// step 4: while Q is not empty
// step 5: V=Q[f++]
// step 6: status{V} = 3
// step 7: print V
// step 8: for all neigbours of V do the following:
// step 9: first all neighbours of V which are ready nodes are put to Q and status{V} = Q
// step 10: Q{R++} = w
// step 11: status{w} = Q

#include <iostream>
using namespace std;

int main(){
    int flag=0;
    cout<<"DO YOU WANT A DIRECTED OR AN UNDIRECTED GRAPH?"<<endl;
    cout<<"1. Directed"<<endl;
    cout<<"2. Undirected"<<endl;
    cout<<"Enter your choice: ";
    cin>>flag;

    if (flag==1){
        cout<<"DIRECTED GRAPH"<<endl;
    }
    else if (flag==2){
        cout<<"UNDIRECTED GRAPH"<<endl;
    }
    else{
        cout<<"INVALID CHOICE"<<endl;
        return 0;
    }

    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    int adj[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) adj[i][j] = 0;
    }
    cout << "Enter the number of edges: ";
    int e;
    cin >> e;
    cout << "Enter the edges: " << endl;
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        if(flag==1){
            adj[a][b] = 1;
        }
        else if(flag==2){
            adj[a][b] = 1;
            adj[b][a] = 1;
        }
    }
    cout << "Adjacency Matrix: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << adj[i][j] << " ";
        cout << endl;
    }
    int status[n];
    for(int i = 0; i < n; i++) status[i] = 0;
    int Q[n];
    int f = 0, r = 0;
    int SV;
    cout << "Enter the start vertex: ";
    cin >> SV;
    Q[r++] = SV;
    status[SV] = 1;
    while(f != r){
        int V = Q[f++];
        status[V] = 3;
        cout << V << " ";
        for(int w = 0; w < n; w++){
            if(adj[V][w] == 1 && status[w] == 0){
                Q[r++] = w;
                status[w] = 1;
            }
        }
    }
    return 0;
}




