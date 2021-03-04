#pragma once

#include <iostream>
#include <vector>

namespace super_alg
{

class TSuperAlg
{
    public:
        static const int BASE = 10;
        static const int RADIX = 1;

        TSuperAlg() = default;
        void Initialize(const std::string &str);

        //std::cin >> num1 >> num2;
        friend std::istream& operator>>(std::istream &in, TSuperAlg &rhs);
        friend std::ostream& operator<<(std::ostream &out, const TSuperAlg &rhs);

        TSuperAlg operator+(const TSuperAlg &rhs);
        TSuperAlg operator-(const TSuperAlg &rhs);
        TSuperAlg operator*(const TSuperAlg &rhs);
        bool operator<(const TSuperAlg &rhs) const;
        bool operator==(const TSuperAlg &rhs) const;
    private:
        void DeleteLeadingZeros();
    private:
        std::vector<int32_t> _data;
};

//using int100500_t = uint64_t;
using int100500_t = TSuperAlg;

} // namespace super_alg
