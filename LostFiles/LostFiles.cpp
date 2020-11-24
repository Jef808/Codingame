#include <array>
#include <numeric>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

template<size_t N> struct DSU {

    DSU();

    int get_rep(int a);
    void unite(int a, int b);
    
    std::array<int, N> parent;
    std::array<int, N> size;
};

template<size_t N>
DSU<N>::DSU()     
{
    std::iota(parent.begin(), parent.end(), 0);
    std::fill(size.begin(), size.end(), 1);
}

template<size_t N>
int DSU<N>::get_rep(int a)
{
    if (parent[a] == a) {
        return a;
    }
    return parent[a] = get_rep(parent[a]);
}

template<size_t N>
void DSU<N>::unite(int a, int b)
{
    a = get_rep(a);
    b = get_rep(b);

    if (a != b) {
        if (size[a] < size[b]) {
            std::swap(a, b);
        }
        parent[b]  = a;
        size[a]   += size[b];
        size[b]    = 0;
    }
}

int main()
{
    //std::freopen("data.txt", "r", stdin);

    int n_edges{0};
    std::cin >> n_edges;

    DSU<1000> dsu = DSU<1000>();
    
    int start, end;
    for (int i=0; i<n_edges; ++i) {
        std::cin >> start >> end;

        dsu.unite(start, end);
    }

    int n_comps = 0, n_vertices=0;
    
    for (int size : dsu.size) {
        if (size > 1) {
            ++n_comps;
            n_vertices += size;
        }
    }

    // For every component, v - e + f = 2
    int n_tiles = n_edges - n_vertices + n_comps;

    std::cout << n_comps << ' ' << n_tiles << std::endl;

}
