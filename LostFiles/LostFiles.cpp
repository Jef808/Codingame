#include <array>
#include <numeric>
#include <vector>

template<size_t N>
constexpr std::array<int, N> default_parent();


template<size_t N> class DSU {
public:
    DSU();

    int get_rep(int a);
    void unite(int a, int b);
    
private:
    std::array<int, N> parent;
    std::array<int, N> size;
};

template<size_t N>
DSU<N>::DSU()
    : parent{default_parent<N>()}, size{1}
{
    // ctor
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

template<size_t N>
constexpr std::array<int, N> default_parent()
{
    std::array<int, N> ret;
    std::iota(ret.begin(), ret.end(), 0);
    return ret;
}


int main()
{
    
}
