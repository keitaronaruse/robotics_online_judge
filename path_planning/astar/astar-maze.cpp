/**
 * @file astar-maze.cpp
 * @brief A* Search of 2D maze
 * @author Keitaro Naruse
 * @date 2022-05-23
 * @copyright MIT License
 */

// # Solution

#include <iostream>
#include <vector>
#include <queue>

//  Data type for 2D position (i, j)
struct position {
    int i, j;
};
//  For finding the next position
const int K = 4;
std::vector< int > di = { 1, 0, -1, 0 };
std::vector< int > dj = { 0, 1, 0, -1 };

//  Height and width of the maze
int H, W;
//  Start (Si, Sj) and goal (Gi, Gj)
int Si, Sj, Gi, Gj;
//  Maze[ i ][ j ] == { '#', '.' }
std::vector< std::vector< char > > maze;
//  Visited[ i ][ j ]
std::vector< std::vector< int > > visited;

std::ostream &operator<<( std::ostream &os,
                          const std::vector< std::vector< char > > &maze ) {
    for( int i = 0; i < H; i++ ) {
        for( int j = 0; j < W; j++ ) {
            if( i == Si && j == Sj ) {
                os << 'S';
            } else if( i == Gi && j == Gj ) {
                os << 'G';
            } else {
                os << maze[ i ][ j ];
            }
        }
        os << std::endl;
    }
    return ( os );
}

std::ostream &operator<<( std::ostream &os,
                          const std::vector< std::vector< int > > &visited ) {
    for( int i = 0; i < H; i++ ) {
        for( int j = 0; j < W; j++ ) {
            if( 0 <= visited[ i ][ j ] && visited[ i ][ j ] <= 9 ) {
                os << " ";
            }
            os << visited[ i ][ j ] << " ";
        }
        os << std::endl;
    }

    return ( os );
}

int main( ) {
    //  Read H, W = [ 3, 10^3 ]
    std::cin >> H >> W;
    //  Read Start (Si, Sj), Si = [ 0, H - 1 ], Sj = [ 0, W - 1 ]
    //  Read Goal (Gi, Gj), Gi = [ 0, H - 1 ], Gj = [ 0, W - 1 ]
    std::cin >> Si >> Sj >> Gi >> Gj;
    //  Read the maze, maze[ i ][ j ] == { '#', '.' }
    maze =
        std::vector< std::vector< char > >( H, std::vector< char >( W, ' ' ) );
    for( int i = 0; i < H; i++ ) {
        for( int j = 0; j < W; j++ ) {
            std::cin >> maze[ i ][ j ];
        }
    }

    //  Main
    //  Breadth-first seach
    //  visited[ i ][ j ] == -1 if unvisited, k >= 0 if visited
    visited =
        std::vector< std::vector< int > >( H, std::vector< int >( W, -1 ) );
    //  queue for the breath-first search
    std::queue< struct position > q;

    //  Push the start to the queue
    struct position p;
    p.i = Si;
    p.j = Sj;
    visited[ p.i ][ p.j ] = 0;
    q.push( p );

    std::cout << maze << std::endl;
    while( !q.empty( ) ) {
        //  Tale the first element in the queue
        p = q.front( );
        //  Delete the first element in the queue
        q.pop( );

        //  Goal is found
        if( p.i == Gi && p.j == Gj ) {
            break;
        }
        //  Go to the next position
        for( int k = 0; k < K; k++ ) {
            struct position r;
            r.i = p.i + di[ k ];
            r.j = p.j + dj[ k ];
            //   r should be in the range of the maze
            if( 0 <= r.i && r.i < H && 0 <= r.j && r.j < W ) {
                //  r should be in the free cells
                if( maze[ r.i ][ r.j ] == '.' ) {
                    if( visited[ r.i ][ r.j ] == -1 ) {
                        q.push( r );
                        visited[ r.i ][ r.j ] = visited[ p.i ][ p.j ] + 1;
                    }
                }
            }
        }
    }

    //  Path length
    int path_length = visited[ Gi ][ Gj ]; 
    //  Path back trace
    std::vector< struct position > path( path_length + 1 );
    int step = path_length;
    p.i = Gi;
    p.j = Gj;
    path[ step ] = p;
    while( visited[ p.i ][ p.j ] > 0 ) {
        //  Find the previous position
        for( int k = 0; k < K; k++ ) {
            struct position r;
            r.i = p.i + di[ k ];
            r.j = p.j + dj[ k ];
            //   r should be in the range of the maze
            if( 0 <= r.i && r.i < H && 0 <= r.j && r.j < W ) {
                //  Take the first cell
                if( visited[ r.i ][ r.j ] == visited[ p.i ][ p.j ] - 1 ) {
                    p.i = r.i;
                    p.j = r.j;
                    break;
                }
            }
        }
        step = visited[ p.i ][ p.j ];
        path[ step ] = p;
    }

    std::cout << visited << std::endl;
    for(auto p : path) {
        std::cout << "( " << p.i << ", " << p.j << " )";
    }
    std::cout << std::endl;
    
    //  Finalize
    return ( 0 );
}
