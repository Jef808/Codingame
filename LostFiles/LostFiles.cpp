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
    FILE* file = std::freopen("data.txt", "r", stdin);

    int n_edges{0};
    std::cin >> n_edges;

    DSU<1000> dsu = DSU<1000>();
    
    int start, end;
    while (n_edges--) {
        std::cin >> start >> end;

        dsu.unite(start, end);
    }
    int n_comps = std::count_if(dsu.size.begin(),
                                  dsu.size.end(),
                                  [](int a) {
                                      return a > 1;
                                  });

    std::cout << n_comps << std::endl;
}
