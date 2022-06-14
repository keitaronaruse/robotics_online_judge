/**
 * @file A_solutoin.cpp
 * @brief Breadth-First Search of 2D workspace
 * @author Keitaro Naruse
 * @date 2022-06-14
 * @copyright MIT License
 */

// # Solution

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int main( ) {
    //  For finding the next position
    const int K = 4;
    std::vector< int > di = { 1, 0, -1, 0 };
    std::vector< int > dj = { 0, 1, 0, -1 };

    //  Read H, W = [ 3, 10^3 ]
    int H, W;
    std::cin >> H >> W;
    //  Read Start (Si, Sj), Si = [ 1, H ], Sj = [ 1, W ]
    //  Read Goal (Gi, Gj), Gi = [ 1, H ], Gj = [ 1, W ]
    int Si, Sj, Gi, Gj;
    std::cin >> Si >> Sj >> Gi >> Gj;

    //  Maze[ i ][ j ] == { '#', '.' }
    std::vector< std::vector< char > > maze =
        std::vector< std::vector< char > >( H, std::vector< char >( W, ' ' ) );
    for( int i = 0; i < H; i++ ) {
        for( int j = 0; j < W; j++ ) {
            std::cin >> maze.at( i ).at( j );
        }
    }

    //  Main
    //  Breadth-first seach
    //  visited[ i ][ j ] == -1 if unvisited, k >= 0 if visited
    //  Visited[ i ][ j ]
    std::vector< std::vector< int > > visited =
        std::vector< std::vector< int > >( H, std::vector< int >( W, -1 ) );
    //  queue for the breath-first search
    std::queue< std::pair< int, int > > q;

    //  Push the start to the queue
    std::pair< int, int > p = std::make_pair( Si - 1, Sj - 1 );
    visited[ p.first ][ p.second ] = 0;
    q.push( p );

    while( !q.empty( ) ) {
        //  Tale the first element in the queue
        p = q.front( );
        //  Delete the first element in the queue
        q.pop( );

        //  Goal is found
        if( p.first == Gi - 1 && p.second == Gj - 1 ) {
            break;
        }
        //  Go to the next position
        for( int k = 0; k < K; k++ ) {
            std::pair< int, int > r =
                std::make_pair( p.first + di.at( k ), p.second + dj.at( k ) );
            //   r should be in the range of the maze
            if( 0 <= r.i && r.i < H && 0 <= r.j && r.j < W ) {
                //  r should be in the free cells
                if( maze.at( r.first ).at( r.second ) == '.' ) {
                    if( visited.at( r.first ).at( r.second ) == -1 ) {
                        q.push( r );
                        visited.at( r.first ).at( r.second ) =
                            visited.at( p.first ).at( p.second ) + 1;
                    }
                }
            }
        }
    }

    //  Path length
    std::cout << visited.at( Gi - 1 ).at( Gj - 1 ) << std::endl;

    //  Finalize
    return ( 0 );
}
