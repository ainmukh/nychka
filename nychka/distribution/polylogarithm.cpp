#include <Eigen/Core>

using Eigen::Matrix;

int c[6][18] = {
        {4,   9,    16,    25,    36,     49,     64,      81,      100,      121,      144,     169,      196,       225,       256,       289,       324,       361},
        {8,   27,   64,    125,   216,    343,    512,     729,     1000,     1331,     1728,    2197,     2744,      3375,      4096,      4913,      5832,      6859},
        {16,  81,   256,   625,   1296,   2401,   4096,    6561,    10000,    14641,    20736,   28561,    38416,     50625,     65536,
                                                                                                                                            83521,     104976,    130321},
        {32,  243,  1024,  3125,  7776,   16807,  32768,   59049,   100000,   161051,   248832,  371293,   537824,
                                                                                                                      759375,    1048576,   1419857,   1889568,   2476099},
        {64,  729,  4096,  15625, 46656,  117649, 262144,  531441,  1000000,  1771561,  2985984, 4826809,
                                                                                                           7529536,   11390625,  16777216,  24137569,  34012224,  47045881},
        {128, 2187, 16384, 78125, 279936, 823543, 2097152, 4782969, 10000000, 19487171, 35831808,
                                                                                                 62748517, 105413504, 170859375, 268435456, 410338673, 612220032, 893871739}
};

//double c[6][18] = {
//        {0.25,      0.1111111111111111,    0.0625,          0.04,     0.027777777777777776,   0.02040816326530612,    0.015625,             0.012345679012345678,   0.01,   0.008264462809917356,   0.006944444444444444,   0.005917159763313609,   0.00510204081632653,    0.0044444444444444444,  0.00390625,            0.0034602076124567475,  0.0030864197530864196,  0.002770083102493075},
//        {0.125,     0.037037037037037035,  0.015625,        0.008,    0.004629629629629629,   0.0029154518950437317,  0.001953125,          0.0013717421124828531,  0.001,  0.0007513148009015778,  0.0005787037037037037,  0.0004551661356395084,  0.00036443148688046647, 0.0002962962962962963,  0.000244140625,        0.0002035416242621616,  0.00017146776406035664, 0.0001457938474996355},
//        {0.0625,    0.012345679012345678,  0.00390625,      0.0016,   0.0007716049382716049,  0.00041649312786339027, 0.000244140625,       0.00015241579027587258, 0.0001, 6.830134553650706e-05,  4.8225308641975306e-05, 3.501277966457757e-05,  2.6030820491461892e-05, 1.9753086419753087e-05, 1.52587890625e-05,     1.1973036721303624e-05, 9.525986892242037e-06,  7.673360394717659e-06},
//        {0.03125,   0.00411522633744856,   0.0009765625,    0.00032,  0.0001286008230452675,  5.9499018266198606e-05, 3.0517578125e-05,     1.6935087808430286e-05, 1e-05,  6.209213230591551e-06,  4.018775720164609e-06,  2.693290743429044e-06,  1.8593443208187064e-06, 1.3168724279835392e-06, 9.5367431640625e-07,   7.042962777237426e-07,  5.292214940134464e-07,  4.038610734061926e-07},
//        {0.015625,  0.0013717421124828531, 0.000244140625,  6.4e-05,  2.143347050754458e-05,  8.499859752314087e-06,  3.814697265625e-06,   1.8816764231589208e-06, 1e-06,  5.644739300537774e-07,  3.3489797668038406e-07, 2.0717621103300337e-07, 1.328103086299076e-07,  8.779149519890261e-08,  5.960464477539063e-08, 4.142919280727898e-08,  2.9401194111858137e-08, 2.1255845968746978e-08},
//        {0.0078125, 0.0004572473708276177, 6.103515625e-05, 1.28e-05, 3.5722450845907635e-06, 1.2142656789020123e-06, 4.76837158203125e-07, 2.0907515812876897e-07, 1e-07,  5.1315811823070673e-08, 2.790816472336534e-08,  1.5936631617923337e-08, 9.486450616421971e-09,  5.852766346593507e-09,  3.725290298461914e-09, 2.437011341604646e-09,  1.6333996728810076e-09, 1.1187287351972093e-09},
//};

void li(size_t k, double x, Matrix<double, -1, 1> &ans) {
    double y[19];  // 19
    y[0] = x;
    double curr;
    for (size_t i = 1; i < 19; i++) {
        y[i] = y[i - 1] * x;
    }

    ans[0] = -std::log(1 - x);
    for (size_t i = 0; i < k - 1; i++) {
        curr = x;
        for (size_t j = 0; j < 18; j++) {
            curr += y[j + 1] / c[i][j];
        }
        ans[i + 1] = curr;
    }
}
