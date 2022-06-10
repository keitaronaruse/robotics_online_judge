/**
 * @file dijkstra-maze.cpp
 * @brief Dijkstra serach of 2D maze
 * @author Keitaro Naruse
 * @date 2022-05-29
 * @copyright MIT License
 */

// # Solution

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

//  Data type for 2D position (i, j) with cost k
class position {
   public:
    //  Position
    int i, j;
    //  Cost
    float k;
};

bool operator>( const position &a, const position &b ) {
    return ( a.k > b.k );
}

int main( ) {
    //  For finding the next position
    const int K = 8;
    std::vector< int > di = { 1, 1, 0, -1, -1, -1, 0, 1 };
    std::vector< int > dj = { 0, 1, 1, 1, 0, -1, -1, -1 };
    std::vector< float > dk = { 1.0f, 1.4f, 1.0f, 1.4f,
                                1.0f, 1.4f, 1.0f, 1.4f };

    //  Read H, W = [ 3, 10^3 ]
    int H, W;
    std::cin >> H >> W;

    //  Read Start (Si, Sj), Si = [ 1, H ], Sj = [ 1, W ]
    //  Read Goal (Gi, Gj), Gi = [ 1, H ], Gj = [ 1, W ]
    //  Start (Si, Sj) and goal (Gi, Gj)
    int Si, Sj, Gi, Gj;
    std::cin >> Si >> Sj >> Gi >> Gj;

    //  Read the maze, maze[ i ][ j ] == { '#', '.' }
    //  Maze[ i ][ j ] == { '#', '.' }
    std::vector< std::vector< char > > maze(
        H + 1, std::vector< char >( W + 1, ' ' ) );
    for( int i = 1; i <= H; i++ ) {
        for( int j = 1; j <= W; j++ ) {
            std::cin >> maze[ i ][ j ];
        }
    }

    //  visited[ i ][ j ] == -1 if unvisited, k >= 0 if visited
    std::vector< std::vector< float > > visited(
        H + 1, std::vector< float >( W + 1, -1.0f ) );

    //  previous node
    std::vector< std::vector< position > > prev(
        H + 1, std::vector< position >( W + 1 ) );

    //  Main
    //  Dijkstra search
    std::priority_queue< position, std::vector< position >,
                         std::greater< position > >
        pq;

    //  Push the start to the queue
    position p;
    p.i = Si;
    p.j = Sj;
    p.k = 0.0f;
    visited[ p.i ][ p.j ] = p.k;
    pq.push( p );

    while( !pq.empty( ) ) {
        //  Tale the first element in the queue
        p = pq.top( );
        //  Delete the first element in the queue
        pq.pop( );

        //  Goal is found
        if( p.i == Gi && p.j == Gj ) {
            break;
        }
        //  Go to the next position
        for( int k = 0; k < K; k++ ) {
            position r;
            r.i = p.i + di[ k ];
            r.j = p.j + dj[ k ];
            r.k = p.k + dk[ k ];
            //   r should be in the range of the maze
            if( 1 <= r.i && r.i <= H && 1 <= r.j && r.j <= W ) {
                //  r should be in the free cells
                if( maze[ r.i ][ r.j ] == '.' ) {
                    if( ( visited[ r.i ][ r.j ] == -1.0f ) ||
                        ( r.k < visited[ r.i ][ r.j ] ) ) {
                        pq.push( r );
                        visited[ r.i ][ r.j ] = r.k;
                        prev[ r.i ][ r.j ] = p;
                    }
                }
            }
        }
    }

    //  Path length
    float path_length = visited[ Gi ][ Gj ];
    std::cout << path_length << std::endl;

    //  Path back trace
    std::vector< std::vector< char > > path_maze = maze;
    p.i = Gi;
    p.j = Gj;
    while( visited[ p.i ][ p.j ] >= 0 ) {
        path_maze[ p.i ][ p.j ] = '*';
        p = prev[ p.i ][ p.j ];
    }
    path_maze[ Si ][ Sj ] = 'S';
    path_maze[ Gi ][ Gj ] = 'G';

    //  Print path and maze
    for( int i = 1; i <= H; i++ ) {
        for( int j = 1; j <= W; j++ ) {
            std::cout << path_maze[ i ][ j ];
        }
        std::cout << std::endl;
    }

    //  Finalize
    return ( 0 );
}
