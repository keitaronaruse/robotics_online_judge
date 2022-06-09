/**
 * @file abc255-x.cpp
 * @brief ABC255 Problem X
 * @author Keitaro Naruse
 * @date 2022-06-11
 * @copyright MIT License
 * @details https://atcoder.jp/contests/abc255/tasks/abc255_x
 */

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template < class K, class V >
std::ostream& operator<<( std::ostream& os, const std::pair< K, V >& p ) {
    os << "( " << p.first << ", " << p.second << " )";
    return ( os );
}

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) {
    for( const auto& k : v ) {
        os << k << " ";
    }
    return ( os );
}

template < class T >
std::ostream& operator<<( std::ostream& os,
                          const std::vector< std::vector< T > >& vv ) {
    for( const auto& v : vv ) {
        os << v << std::endl;
    }
    return ( os );
}

int main( ) {
    //  Read N = [ 1, 10^3 ]
    int N;
    std::cin >> N;

    //  Read Ai = [ 0, 10^9 ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> A.at( i );
    }

    //  Read | S | = [ 1, 10^6 ]
    std::string S;
    std::cin >> S;

    //  Main
    int answer = 0;
    std::cout << answer << std::endl;

    //  Finalize
    return ( 0 );
}
