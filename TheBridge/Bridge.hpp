#pragma once

#include <array>
#include <vector>
#include <istream>
#include <string>


struct Bridge {
    /** For each lane, 0 if safe, 1 if hole */
    using lane = std::array<bool, 500>;

    Bridge() = default;
    Bridge(std::istream& _in);

    std::array<lane, 4> lanes;
};

Bridge::Bridge(std::istream& _in)
{
    std::string s;
    for (int i=0; i<4; ++i) {
        s.clear();
        _in >> s;
        for (int j=0; j<s.size(); ++j) {
            lanes[i][j] = (s[j]=='.');
        }
    }
}
