#include <vector>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>

const int R = 1;
const int BASE = pow( 10, R );

class LongInt
{
public:
    LongInt() { }
    LongInt( size_t n ) { m_data.resize(n, 0); }
    LongInt( const std::string & str);
    ~LongInt() {}
    
    friend std::ostream& operator<< (std::ostream& stream, const LongInt & number);

    LongInt operator+( const LongInt & other);
    LongInt operator-( const LongInt & other);
    LongInt operator*( const LongInt & other);

    bool operator<( const LongInt & other);
    size_t size() const { return m_data.size(); }
    bool empty() const { return m_data.empty(); }
    void delete_zeros();
protected:
    std::vector<uint32_t> m_data;
};

void
LongInt::delete_zeros()
{
    while( m_data.size() > 1 && m_data.back() == 0 ) { m_data.pop_back(); }
}

LongInt LongInt::operator-(const LongInt & other) {
    size_t n = std::max(this->size(), other.size());
    LongInt result;
    int r = 0;
    int k = 0;
    for (size_t i = 0; i < n; ++i)
    {
        int res = 0;
        if (other.size() <= i) {
            res = m_data[i] + k;
        }
        else {
            res = m_data[i] - other.m_data[i] + k;
        }
        k = 0;
        if( res < 0 ) {
            res += BASE;
            k = -1;
        }
        r = res % BASE;
        
        result.m_data.push_back( r );
    }
    result.delete_zeros();
    return result;
}

std::ostream &
operator<< (std::ostream& stream, const LongInt & number)
{
    if( number.size() == 0 )
    {
        return stream;
    }
    
    stream << number.m_data[ number.size() - 1 ];
    for( int i = number.size() - 2; i >= 0; --i )
    {
        stream << std::setfill('0') << std::setw(R) << number.m_data[i];
    }
    return stream;
}

LongInt::LongInt( const std::string & str )
{
    std::string text = str;
    if( str.find('.') != std::string::npos )
    {
        text = str.substr( 0, str.find('.') );
    }
    for( int i = text.size() - 1; i >= 0; i-- )
    {
        m_data.push_back( text[i] - '0' );
    }
    delete_zeros();
}

bool
LongInt::operator<( const LongInt & other )
{
    // Если размеры неодинаковые, то сразу можем сказать, 
    // какое число меньше.
    if( other.size() != this->size() )
    {
        return this->size() < other.size();
    }

    for( int i = other.size() - 1; i >= 0; --i)
    {
        if( other.m_data[i] != this->m_data[i] )
        {
            return this->m_data[i] < other.m_data[i];
        }
    }
    return false;
}

LongInt
LongInt::operator*( const LongInt & other )
{
    size_t n = this->size() * other.size();
    LongInt result( n + 1 );

    int k = 0;
    int r = 0;
    for(size_t i = 0; i < this->size(); ++i)
    {
        for(size_t j = 0; j < other.size(); ++j)
        {
            k = other.m_data[j] * this->m_data[i] + result.m_data[i+j];
            r = k / BASE;
            result.m_data[i+j+1] = result.m_data[i+j+1] + r;
            result.m_data[i+j] = k % BASE;
        }
    }
    result.delete_zeros();
    return result;
}

LongInt
LongInt::operator+( const LongInt & other )
{
    size_t n = std::max( this->size(), other.size() );

    LongInt result;

    int r = 0;
    int k = 0;
    for( size_t i = 0; i < n; ++i)
    {
        if( m_data.size() <= i )
        {
            k = other.m_data[i];
        }
        else if( other.size() <= i )
        {
            k = m_data[i];
        }
        else
        {
            k = m_data[i] + other.m_data[i];
        }

        k += r;
        result.m_data.push_back( k % BASE );
        r = k / BASE;        
    }
    
    if( r != 0 )
    {
        result.m_data.push_back( r );
    }
    
    return result;
}

int main()
{
    std::string num1, num2, operation;
    while( std::cin >> num1 >> num2 >> operation )
    {
        LongInt number1( num1 );
        LongInt number2( num2 );
        LongInt res;

        if( operation == "+" )
        {
            res = number1 + number2;    
        }
        else if( operation == "-" )
        {   
            if( number1 < number2 ) {
                std::cout << "error" << std::endl;
                continue;
            }
            res = number1 - number2;    
        }
        else if( operation == "*" )
        {
            res = number1 * number2; 
        }
        else if( operation == "<" )
        {
            std::cout << ( ( number1 < number2 ) ? "true" : "false" ) << std::endl;
        }
        
        // Для операций сравнений всегда нужно выводить либо false,
        // либо true, для остальный случаев res будет непустой.
        if( ! res.empty() )
        {
            std::cout << res << std::endl;
        }
    }
    return 0;
}

