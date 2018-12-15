#include <iostream>
using namespace std;
#include <stack>
#include <list>
#include <iterator>
#include<queue>

class Graph{
    int V;
    list<int> *ad;
    public:
    Graph(int n){
        V = n;
        ad = new list<int>[n];
        
    }
    
    void addEdge(int u,int v){
        ad[u].push_back(v);
    }
    
    void print(){
        for(int i=0;i<V;i++){
            for(const int& ele : ad[i])
            //while(!ad[i].empty()){
            cout<<i<<"->"<<ele<<endl;
            //ad[i].pop_front();
            //}
        }
    }
    
    void bfs();
    
    void dfs(int u, bool visited[],stack<int>& st);
    
    void top_sort();
    
    
    
    
    
};

void Graph::dfs(int u, bool visited[],stack<int>& st){
    visited[u] = true;
    
    list<int>:: iterator v;
    
    for(v=ad[u].begin();v!=ad[u].end();++v){
        if(!visited[*v])
           dfs(*v,visited,st);
    }
    st.push(u);
    
}



void Graph::bfs(){
    queue<int> q;
    int v;
    bool visited[V];
    for(int i=0;i<V;i++)
       visited[i] = false;
    
    for(int i=0;i<V;i++){
    
    q.push(i);
    visited[i] = true;
    while(!q.empty()){
        v = q.front();
        q.pop();
        cout<<v<<" ";
        
        for(auto& i : ad[v] ){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
    
    }
    
}

void Graph::top_sort(){
    stack<int> st;
    bool *visited = new bool[V];
    
    for(int i=0;i<V;i++)
       visited[i] = false;
    
    for(int i=0;i<V;i++)
       if(!visited[i])
         dfs(i,visited,st);
    
    while(!st.empty()){
    cout<<st.top()<<endl;
    st.pop();
    }
    
    
}

int main() {
    Graph g(6);
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
    
    g.print();
    //g.top_sort();
    g.bfs();
    
    
	
	return 0;
}