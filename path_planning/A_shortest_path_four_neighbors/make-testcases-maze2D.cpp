/**
 * @file make-testcases-maze2D.cpp
 * @brief Make test cases for 2D maze
 * @author Keitaro Naruse
 * @date 2022-06-07
 * @copyright MIT License
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main( ) {
    //  Problems
    int N = 100;
    int H, W;
    int Ch, Cw, Dh, Dw;
    std::vector< std::string > S;
    std::string filename;

    //  Make test cases
    for( int i = 1; i <= N; i++ ) {
        if( i == 1 ) {
            filename = "01_minH_minW.txt";
            H = 1;
            W = 1;
            Ch = 1;
            Cw = 1;
            Dh = 1;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        }
        else if( i == 11 ) {
            filename = "11_minH_maxW_NoObst_1_1000.txt";
            H = 1;
            W = 1000;
            Ch = 1;
            Cw = 1;
            Dh = 1;
            Dw = 1000;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        }
        else if( i == 12 ) {
            filename = "12_minH_maxW_NoObst_1000_1.txt";
            H = 1;
            W = 1000;
            Ch = 1;
            Cw = 1000;
            Dh = 1;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        }
        else if( i == 13 ) {
            filename = "13_minH_maxW_NoObst_500_499.txt";
            H = 1;
            W = 1000;
            Ch = 1;
            Cw = 500;
            Dh = 1;
            Dw = 499;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        }
        else if( i == 14 ) {
            filename = "14_minH_maxW_Obst_1_1000.txt";
            H = 1;
            W = 1000;
            Ch = 1;
            Cw = 1;
            Dh = 1;
            Dw = 1000;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            S.at( 0 ).at( 1 ) = '#';
        }
        else if( i == 15 ) {
            filename = "15_minH_maxW_Obst_1000_1.txt";
            H = 1;
            W = 1000;
            Ch = 1;
            Cw = 1000;
            Dh = 1;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            S.at( 0 ).at( 1 ) = '#';
        }
        else if( i == 16 ) {
            filename = "16_minH_maxW_Obst_3_1000.txt";
            H = 1;
            W = 1000;
            Ch = 1;
            Cw = 3;
            Dh = 1;
            Dw = 1000;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            S.at( 0 ).at( 1 ) = '#';
        }
        else if( i == 21 ) {
            filename = "21_maxH_minW_NoObst_1_1000.txt";
            H = 1000;
            W = 1;
            Ch = 1;
            Cw = 1;
            Dh = 1000;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        }
        else if( i == 22 ) {
            filename = "22_maxH_minW_NoObst_1000_1.txt";
            H = 1000;
            W = 1;
            Ch = 1000;
            Cw = 1;
            Dh = 1;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        }
        else if( i == 23 ) {
            filename = "23_maxH_minW_NoObst_500_499.txt";
            H = 1000;
            W = 1;
            Ch = 500;
            Cw = 1;
            Dh = 499;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        }
        else if( i == 24 ) {
            filename = "24_maxH_minW_Obst_1_1000.txt";
            H = 1000;
            W = 1;
            Ch = 1;
            Cw = 1;
            Dh = 1000;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            S.at( 1 ).at( 0 ) = '#';
        }
        else if( i == 25 ) {
            filename = "25_maxH_minW_Obst_1000_1.txt";
            H = 1000;
            W = 1;
            Ch = 1000;
            Cw = 1;
            Dh = 1;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            S.at( 1 ).at( 0 ) = '#';
        }
        else if( i == 26 ) {
            filename = "26_maxH_minW_Obst_3_1000.txt";
            H = 1000;
            W = 1;
            Ch = 3;
            Cw = 1;
            Dh = 1000;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            S.at( 1 ).at( 0 ) = '#';
        }
        //  Write to a file
        std::ofstream os( filename );
        os << H << " " << W << std::endl;
        os << Ch << " " << Cw << " " << Dh << " " << Dw << std::endl;
        for( int h = 0; h < H; h++ ) {
            for( int w = 0; w < W; w++ ) {
                os << S.at( h ).at( w );
            }
            os << std::endl;
        }
    }

    //  Finalize
    return ( 0 );
}
