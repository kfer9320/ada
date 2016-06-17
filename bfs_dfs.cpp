#include <vector>
#include <limits>
#include <queue>
#include<iostream>

using namespace std;

enum { 
    INFINITY = numeric_limits<int>::max() 
};

enum Color {
    WHITE,
    GREY,
    BLACK
};

struct Vertex {
    int id;
    Color color;
    int discovery;
    Vertex* parent;
    int finish;
};

struct Graph {
    std::vector<Vertex> vertices;
    std::vector< std::vector<Vertex*> > adjacent;
};    

void bfs(Graph& g, Vertex* s)
{       
    for (auto& v: g.vertices)
        if (v.id == s->id) continue;
        v.color = WHITE;
        v.discovery = INFINITY;
        v.parent = nullptr;
    }
    s->color = GRAY;
    s->discovery = 0;
    s->parent = nullptr;    
    std::queue<Vertex*> q;
    q.push(s);    
    while (!q.empty()) {
        auto u = q.front();
        q.pop();    
        for (auto v: G.adjacent[u->id])) {
            if (v->color == WHITE) {
                v->color = GRAY;
                v->discovery = u->discovery + 1;
                v->parent = u;
                q.push(v);
            }
        }
        u->color = BLACK;
    }
}

void dfs(Graph& g)
{
    for (auto& u: g.vertices) {
        u.color = WHITE;
        u.parent = nullptr;
    }

    for (auto& u: g.vertices) {
        if (u.color == WHITE)
            dfsv(g, &u, 1)
    }
}

void dfsv(Graph& g, Vertex* u, int time)
{
    u->color = GRAY;
    u->discovery = time;
    for (auto v: g.adjacent[u->id]) {
        if (v->color == WHITE) {
            v->parent = u;
            dfsv(G, u, time + 1)
        }
    }
    u->color = BLACK;
    u->finish = time + 1;    
}
