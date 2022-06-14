/**
 * @file A_make_in_files.cpp
 * @brief Make testcases of the problem A
 * @author Keitaro Naruse
 * @date 2022-06-14
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
            //  0
            filename = "01_minH_minW.txt";
            H = 1;
            W = 1;
            Ch = 1;
            Cw = 1;
            Dh = 1;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        } else if( i == 11 ) {
            //  999
            filename = "11_minH_maxW_NoObst_1_1000.txt";
            H = 1;
            W = 1000;
            Ch = 1;
            Cw = 1;
            Dh = 1;
            Dw = 1000;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        } else if( i == 12 ) {
            //  999
            filename = "12_minH_maxW_NoObst_1000_1.txt";
            H = 1;
            W = 1000;
            Ch = 1;
            Cw = 1000;
            Dh = 1;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        } else if( i == 13 ) {
            //  0
            filename = "13_minH_maxW_NoObst_500_500.txt";
            H = 1;
            W = 1000;
            Ch = 1;
            Cw = 500;
            Dh = 1;
            Dw = 500;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        } else if( i == 14 ) {
            //  -1
            filename = "14_minH_maxW_Obst2_1_1000.txt";
            H = 1;
            W = 1000;
            Ch = 1;
            Cw = 1;
            Dh = 1;
            Dw = 1000;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            S.at( 0 ).at( 1 ) = '#';
        } else if( i == 15 ) {
            //  -1
            filename = "15_minH_maxW_Obst2_1000_1.txt";
            H = 1;
            W = 1000;
            Ch = 1;
            Cw = 1000;
            Dh = 1;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            S.at( 0 ).at( 1 ) = '#';
        } else if( i == 16 ) {
            //  997
            filename = "16_minH_maxW_Obst2_3_1000.txt";
            H = 1;
            W = 1000;
            Ch = 1;
            Cw = 3;
            Dh = 1;
            Dw = 1000;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            S.at( 0 ).at( 1 ) = '#';
        } else if( i == 21 ) {
            //  999
            filename = "21_maxH_minW_NoObst_1_1000.txt";
            H = 1000;
            W = 1;
            Ch = 1;
            Cw = 1;
            Dh = 1000;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        } else if( i == 22 ) {
            //  999
            filename = "22_maxH_minW_NoObst_1000_1.txt";
            H = 1000;
            W = 1;
            Ch = 1000;
            Cw = 1;
            Dh = 1;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        } else if( i == 23 ) {
            //  0
            filename = "23_maxH_minW_NoObst_500_500.txt";
            H = 1000;
            W = 1;
            Ch = 500;
            Cw = 1;
            Dh = 500;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        } else if( i == 24 ) {
            //  -1
            filename = "24_maxH_minW_Obst2_1_1000.txt";
            H = 1000;
            W = 1;
            Ch = 1;
            Cw = 1;
            Dh = 1000;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            S.at( 1 ).at( 0 ) = '#';
        } else if( i == 25 ) {
            //  -1
            filename = "25_maxH_minW_Obst2_1000_1.txt";
            H = 1000;
            W = 1;
            Ch = 1000;
            Cw = 1;
            Dh = 1;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            S.at( 1 ).at( 0 ) = '#';
        } else if( i == 26 ) {
            //  997
            filename = "26_maxH_minW_Obst2_3_1000.txt";
            H = 1000;
            W = 1;
            Ch = 3;
            Cw = 1;
            Dh = 1000;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            S.at( 1 ).at( 0 ) = '#';
        } else if( i == 31 ) {
            //  1998
            filename = "31_maxH_max_NoObst_1_1_1000_1000.txt";
            H = 1000;
            W = 1000;
            Ch = 1;
            Cw = 1;
            Dh = 1000;
            Dw = 1000;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        } else if( i == 32 ) {
            //  1998
            filename = "32_maxH_max_NoObst_1_1000_1000_1.txt";
            H = 1000;
            W = 1000;
            Ch = 1;
            Cw = 1000;
            Dh = 1000;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        } else if( i == 33 ) {
            //  999
            filename = "33_maxH_max_NoObst_1000_1000_1000_1.txt";
            H = 1000;
            W = 1000;
            Ch = 1;
            Cw = 1;
            Dh = 1000;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        } else if( i == 34 ) {
            //  999
            filename = "34_maxH_max_NoObst_1000_1000_1_1000.txt";
            H = 1000;
            W = 1000;
            Ch = 1;
            Cw = 1;
            Dh = 1;
            Dw = 1000;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        } else if( i == 35 ) {
            //  998
            filename = "35_maxH_max_NoObst_500_500_1_1.txt";
            H = 1000;
            W = 1000;
            Ch = 500;
            Cw = 500;
            Dh = 1;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        } else if( i == 36 ) {
            //  999
            filename = "36_maxH_max_NoObst_500_500_1_1000.txt";
            H = 1000;
            W = 1000;
            Ch = 500;
            Cw = 500;
            Dh = 1;
            Dw = 1000;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        } else if( i == 37 ) {
            //  999
            filename = "37_maxH_max_NoObst_500_500_1000_1.txt";
            H = 1000;
            W = 1000;
            Ch = 500;
            Cw = 500;
            Dh = 1000;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        } else if( i == 38 ) {
            //  1000
            filename = "38_maxH_max_NoObst_500_500_1000_1000.txt";
            H = 1000;
            W = 1000;
            Ch = 500;
            Cw = 500;
            Dh = 1000;
            Dw = 1000;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
        } else if( i == 41 ) {
            //  -1
            filename = "41_maxH_max_Obst2_1_1_3_3.txt";
            H = 1000;
            W = 1000;
            Ch = 1;
            Cw = 1;
            Dh = 3;
            Dw = 3;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            S.at( 0 ).at( 1 ) = '#';
            S.at( 1 ).at( 0 ) = '#';
        } else if( i == 42 ) {
            //  -1
            filename = "42_maxH_max_Obst2_1_1_3_3.txt";
            H = 1000;
            W = 1000;
            Ch = 3;
            Cw = 3;
            Dh = 1;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            S.at( 0 ).at( 1 ) = '#';
            S.at( 1 ).at( 0 ) = '#';
        } else if( i == 43 ) {
            //  2997
            filename = "43_maxH_max_ObstI_1_1_1000_1.txt";
            H = 1000;
            W = 1000;
            Ch = 1;
            Cw = 1;
            Dh = 1000;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            for( int k = 0; k < W - 1; k++ ) {
                S.at( 1 ).at( k ) = '#';
            }
        } else if( i == 44 ) {
            //  2997
            filename = "44_maxH_max_ObstI_1_1_1_1000.txt";
            H = 1000;
            W = 1000;
            Ch = 1;
            Cw = 1;
            Dh = 1;
            Dw = 1000;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            for( int k = 0; k < H - 1; k++ ) {
                S.at( k ).at( 1 ) = '#';
            }
        } else if( i == 45 ) {
            //  1998
            filename = "45_maxH_max_ObstL_1_1_1000_1000.txt";
            H = 1000;
            W = 1000;
            Ch = 1;
            Cw = 1;
            Dh = 1000;
            Dw = 1000;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            for( int k = 1; k < H - 1; k++ ) {
                S.at( k ).at( 1 ) = '#';
            }
            for( int k = 1; k < W - 1; k++ ) {
                S.at( 1 ).at( k ) = '#';
            }
        } else if( i == 46 ) {
            //  1998
            filename = "46_maxH_max_ObstL_1000_1000_1_1.txt";
            H = 1000;
            W = 1000;
            Ch = 1000;
            Cw = 1000;
            Dh = 1;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            for( int k = 1; k < H - 1; k++ ) {
                S.at( k ).at( 1 ) = '#';
            }
            for( int k = 1; k < W - 1; k++ ) {
                S.at( 1 ).at( k ) = '#';
            }
        } else if( i == 47 ) {
            //  1998
            filename = "47_maxH_max_ObstO_1_1_1000_1000.txt";
            H = 1000;
            W = 1000;
            Ch = 1;
            Cw = 1;
            Dh = 1000;
            Dw = 1000;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            for( int k = 1; k < H - 1; k++ ) {
                S.at( k ).at( 1 ) = '#';
                S.at( k ).at( H - 2 ) = '#';
            }
            for( int k = 1; k < W - 1; k++ ) {
                S.at( 1 ).at( k ) = '#';
                S.at( W - 2 ).at( k ) = '#';
            }
        } else if( i == 48 ) {
            //  1998
            filename = "48_maxH_max_ObstO_1000_1000_1_1.txt";
            H = 1000;
            W = 1000;
            Ch = 1000;
            Cw = 1000;
            Dh = 1;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            for( int k = 1; k < H - 1; k++ ) {
                S.at( k ).at( 1 ) = '#';
                S.at( k ).at( H - 2 ) = '#';
            }
            for( int k = 1; k < W - 1; k++ ) {
                S.at( 1 ).at( k ) = '#';
                S.at( W - 2 ).at( k ) = '#';
            }
        } else if( i == 49 ) {
            //  1998
            filename = "49_maxH_max_ObstO_1000_1_1_1000.txt";
            H = 1000;
            W = 1000;
            Ch = 1000;
            Cw = 1;
            Dh = 1;
            Dw = 1000;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            for( int k = 1; k < H - 1; k++ ) {
                S.at( k ).at( 1 ) = '#';
                S.at( k ).at( H - 2 ) = '#';
            }
            for( int k = 1; k < W - 1; k++ ) {
                S.at( 1 ).at( k ) = '#';
                S.at( W - 2 ).at( k ) = '#';
            }
        } else if( i == 50 ) {
            //  1998
            filename = "50_maxH_max_ObstO_1_1000_1000_1.txt";
            H = 1000;
            W = 1000;
            Ch = 1;
            Cw = 1000;
            Dh = 1000;
            Dw = 1;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            for( int k = 1; k < H - 1; k++ ) {
                S.at( k ).at( 1 ) = '#';
                S.at( k ).at( H - 2 ) = '#';
            }
            for( int k = 1; k < W - 1; k++ ) {
                S.at( 1 ).at( k ) = '#';
                S.at( W - 2 ).at( k ) = '#';
            }
        } else if( i == 51 ) {
            //  -1
            filename = "51_maxH_max_ObstO_3_3_1000_1000.txt";
            H = 1000;
            W = 1000;
            Ch = 3;
            Cw = 3;
            Dh = 1000;
            Dw = 1000;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            for( int k = 1; k < H - 1; k++ ) {
                S.at( k ).at( 1 ) = '#';
                S.at( k ).at( H - 2 ) = '#';
            }
            for( int k = 1; k < W - 1; k++ ) {
                S.at( 1 ).at( k ) = '#';
                S.at( W - 2 ).at( k ) = '#';
            }
        } else if( i == 52 ) {
            //  -1
            filename = "52_maxH_max_ObstO_1000_1000_3_3.txt";
            H = 1000;
            W = 1000;
            Ch = 1000;
            Cw = 1000;
            Dh = 3;
            Dw = 3;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            for( int k = 1; k < H - 1; k++ ) {
                S.at( k ).at( 1 ) = '#';
                S.at( k ).at( H - 2 ) = '#';
            }
            for( int k = 1; k < W - 1; k++ ) {
                S.at( 1 ).at( k ) = '#';
                S.at( W - 2 ).at( k ) = '#';
            }
        } else if( i == 53 ) {
            //  1990
            filename = "53_maxH_max_ObstO_3_3_998_998.txt";
            H = 1000;
            W = 1000;
            Ch = 3;
            Cw = 3;
            Dh = 998;
            Dw = 998;
            S = std::vector< std::string >( H, std::string( W, '.' ) );
            for( int k = 1; k < H - 1; k++ ) {
                S.at( k ).at( 1 ) = '#';
                S.at( k ).at( H - 2 ) = '#';
            }
            for( int k = 1; k < W - 1; k++ ) {
                S.at( 1 ).at( k ) = '#';
                S.at( W - 2 ).at( k ) = '#';
            }
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
