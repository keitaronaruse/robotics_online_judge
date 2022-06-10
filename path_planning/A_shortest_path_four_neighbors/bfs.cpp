/**
 * @file bfs.cpp
 * @brief Breadth-First Search of 2D maze
 * @author Keitaro Naruse
 * @date 2022-06-07
 * @copyright MIT License
 */
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int main( ) {
    const int K = 4;
    std::vector< int > dh = { 1, 0, -1, 0 };
    std::vector< int > dw = { 0, 1, 0, -1 };

    int H = 1000, W = 1000;
    std::vector< std::vector< int > > length( H + 1,
                                              std::vector< int >( W + 1, -1 ) );
    std::queue< std::pair< int, int > > q;

    q.push( std::make_pair( 1, 1 ) );
    length.at( 1 ).at( 1 ) = 0;
    while( !q.empty( ) ) {
        std::pair< int, int > p = q.front( );
        q.pop( );
        int h = p.first;
        int w = p.second;
        if( h == H && w == W ) {
            break;
        }
        for( int k = 0; k < K; k++ ) {
            int v = h + dh.at( k );
            int u = w + dw.at( k );
            if( 1 <= v && v <= H && 1 <= u && u <= W ) {
                if( length.at( v ).at( u ) == -1 ) {
                    q.push( std::make_pair( v, u ) );
                    length.at( v ).at( u ) = length.at( h ).at( w ) + 1;
                }
            }
        }
    }
    std::cout << length.at( H ).at( W ) << std::endl;

    return ( 0 );
}