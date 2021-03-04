#include <iomanip>

#include "super_alg.hpp"

namespace super_alg {

void
TSuperAlg::Initialize(const std::string & str)
{
    //_data
    // str.size() = 100,
    // BASE = 10, data.size() = 100
    // str.size() = 100
    // BASE = 100,  data.size() = 50
    _data.clear();
    _data.resize(str.size() / TSuperAlg::RADIX);
    for (size_t i = 0; i < str.size(); ++i) {
        _data[i] = static_cast<int32_t>(str[i] - '0');
    }
    std::reverse(std::begin(_data), std::end(_data));
    DeleteLeadingZeros();
}

// 159
//  44
// ---
// 203
TSuperAlg
TSuperAlg::operator+(const TSuperAlg &rhs)
{
    TSuperAlg res;
    int32_t carry = 0;
    size_t n = std::max(rhs._data.size(), _data.size());
    res._data.resize( n );
    for (size_t i = 0; i < n; ++i) {
        int32_t sum = carry;
        if (i < rhs._data.size()) {
            sum += rhs._data[i];
        }
        if (i < _data.size()) {
            sum += _data[i];
        }
        carry = sum / TSuperAlg::BASE;
        res._data[i] = sum % TSuperAlg::BASE;
    }
    if (carry != 0) {
        res._data.push_back(1);
    }
    res.DeleteLeadingZeros();
    return res;
}

TSuperAlg
TSuperAlg::operator-(const TSuperAlg &rhs)
{
    TSuperAlg res;
    int32_t carry = 0;
    size_t n = std::max(rhs._data.size(), _data.size());
    res._data.resize( n + 1, 0 );
    for (size_t i = 0; i < n; ++i) {
        int32_t diff = _data[i] - carry;
        if (i < rhs._data.size()) {
            diff -= rhs._data[i];
        }

        carry = 0;
        if (diff < 0) {
            carry = 1;
            diff += TSuperAlg::BASE;
        }
        res._data[i] = diff % TSuperAlg::BASE;
    }
    res.DeleteLeadingZeros();
    return res;
}

TSuperAlg
TSuperAlg::operator*( const TSuperAlg & rhs )
{
    size_t n = _data.size() * rhs._data.size();
    TSuperAlg res;
    res._data.resize( n + 1 );

    int k = 0;
    int r = 0;
    for(size_t i = 0; i < _data.size(); ++i)
    {
        for(size_t j = 0; j < rhs._data.size(); ++j)
        {
            k = rhs._data[j] * _data[i] + res._data[i+j];
            r = k / TSuperAlg::BASE;
            res._data[i+j+1] = res._data[i+j+1] + r;
            res._data[i+j] = k % TSuperAlg::BASE;
        }
    }
    res.DeleteLeadingZeros();
    return res;
}


bool
TSuperAlg::operator<(const TSuperAlg &rhs) const
{
    if (_data.size() != rhs._data.size()) {
        return _data.size() < rhs._data.size();
    }

    for (int32_t i = _data.size() - 1; i >= 0; --i) {
        if (_data[i] != rhs._data[i]) {
            return _data[i] < rhs._data[i];
        }
    }
    return false;
}

bool
TSuperAlg::operator==(const TSuperAlg &rhs) const
{
    if (_data.size() != rhs._data.size()) {
        return false;
    }

    for (int32_t i = _data.size() - 1; i >= 0; --i) {
        if (_data[i] != rhs._data[i]) {
            return false;
        }
    }
    return true;
}


void
TSuperAlg::DeleteLeadingZeros()
{
    while (!_data.empty() && _data.back() == 0) _data.pop_back();
}

std::istream&
operator>>(std::istream &in, TSuperAlg &rhs)
{
    std::string str;
    in >> str;
    rhs.Initialize( str );
    return in;
}

std::ostream&
operator<<(std::ostream &out, const TSuperAlg &rhs)
{
    if (rhs._data.empty()) {
        out << "0";
        return out;
    }

    //  0   1
    // [1] [2]  -> 2 01
    out << rhs._data.back();
    for (int i = rhs._data.size() - 2; i >= 0; --i) {
        out << std::setfill('0') << std::setw(TSuperAlg::RADIX) << rhs._data[i];
    }
    return out;
}

} // namespace super_alg
