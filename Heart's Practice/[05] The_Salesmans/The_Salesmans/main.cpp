#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// Linked List 
struct vertex
{
    typedef pair<int, vertex *> ve;
    vector<ve> adj;
    string name;
    vertex(string s) : name(s) {}
};

class graph
{
    public:
        typedef map<string, vertex *> vmap;
        vmap work;
        vector<string> vertex_all;
        void addVertex(const string &);
        void addEdge(const string &, const string &, double cost);
        int getCost(const string &, const string &);
};

void graph::addVertex(const string &name)
{
    // vmap::iterator itr = work.find(name);
    if (work.find(name) == work.end())
    {
        vertex *v = new vertex(name);
        work[name] = v;
        vertex_all.push_back(name);
        return;
    }
}

// undirect
void graph::addEdge(const string &form, const string &to, double cost)
{
    addVertex(form);
    addVertex(to);
    vertex *f = work.find(form)->second;
    vertex *t = work.find(to)->second;
    // pair<int,vertex*> edge = make_pair(cost,t);
    f->adj.push_back(make_pair(cost, t)); // use it only if direct
    t->adj.push_back(make_pair(cost, f));
}

int graph::getCost(const string &form, const string &to)
{
    vmap::iterator it = work.find(form);
    if (it == work.end())
        return -1;
    vertex *f = it->second;

    for (auto j : f->adj)
    {
        if (j.second->name == to)
        {
            return j.first;
        }
    }
    return -1;
}

int max_cost(graph Path, vector<string> &Best_Path)
{
    vector<string> path_way = Path.vertex_all;
    path_way.push_back(path_way.front());
    int maxi_cost = 0;
    do
    {
        int cost = 0;
        string from = "", to = "";
        for (auto v : path_way)
        {
            from = to;
            to = v;
            int temp = Path.getCost(from, to);
            if (temp != -1)
                cost += temp;
        }
        if (cost > maxi_cost)
        {
            maxi_cost = cost;
            Best_Path = path_way;
        }
    } while (next_permutation(path_way.begin() + 1, path_way.end() - 1));
    return maxi_cost;
}

int main()
{
    graph Path;
    vector<string> Best_Path;
    int country_without_starter, all_path_undir, cost;

    cin >> country_without_starter >> all_path_undir;

    string c1, c2;

    for (int i = 0; i < all_path_undir; i++)
    {
        cin >> c1 >> c2 >> cost;
        Path.addEdge(c1, c2, cost);
    }

    int maximizer_cost = max_cost(Path, Best_Path);

    for (auto p : Best_Path)
        cout << p << " ";

    cout << endl
         << maximizer_cost << endl;

    return 0;
}
