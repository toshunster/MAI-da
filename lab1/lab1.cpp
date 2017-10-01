#include <iostream>
#include <vector>

class KV
{
public:
    int m_key;
    std::string m_value;

    KV() {}
    KV( int key, const std::string & value) :
                     m_key(key), m_value(value) {}
};

void counting_sort( const std::vector<KV> &input,
                    int max_key,
                    std::vector<KV> &output )
{
    std::vector<int> b(max_key+1, 0);
    for( auto &elem : input)
    {
        ++b[elem.m_key];
    }
    
    for(size_t i = 1; i < b.size(); ++i)
    {
        b[i] += b[i-1];
    }

    for(int i = input.size() -1 ; i >= 0; --i)
    {
        output[ b[input[i].m_key]- 1 ] = std::move( input[i] );
        b[input[i].m_key]--;
    }
}

int main()
{
    int key, max_key;
    std::string value;
    std::vector<KV> input;
    while( std::cin >> key >> value)
    {
        if( key > max_key)
            max_key = key;
        input.push_back( KV(key, value) );
    }
   
    std::vector<KV> output( input.size() );
    
    counting_sort( input, max_key, output );
    
    for( auto & elem : output )
    {
        std::cout << elem.m_key << "\t" << elem.m_value << std::endl;
    }
    return 0;
}
