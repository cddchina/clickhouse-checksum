#include "city.h"
#include <iostream>


/*
https://www.bchrt.com/tools/hex-calculator/

8位无符号整形数字 转 16进制

[2915113953], [2570337302]
[2501445858], [204037943]
11039514654693989345
876336294829557986
17740725949267683336
4097548376169627610


11039514654693989345--uint64 to hex--99343C16ADC11BE1
876336294829557986--uint64 to hex--0C295F37951908E2

*/
int main() {


    char str[] = {0x82,0x1C,0x00 ,0x00 ,0x00 ,0x18 ,0x00 ,0x00 ,0x00 ,0x22,0x01,0x00,0x01,0x00,0x12,0x02,0x07,0x00,0x90,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    // 28

    char str1[] = {0x22,0x01,0x00,0x01,0x00,0x12,0x02,0x07,0x00,0x90,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    // 28

    unsigned char str2[] = {0x82,0x6b,0x00,0x00,0x00,0x62,0x00,0x00,0x00,0xf2,0x3b,0x01,0x00,0x02,0xff,0xff,0xff,0xff,0x00,0x01,0x01,0x2c,0x75,0x6e,0x69,0x71,0x49,0x66,0x28,0x44,0x65,0x76,0x69,0x63,0x65,0x49,0x44,0x48,0x61,0x73,0x68,0x2c,0x20,0x65,0x71,0x75,0x61,0x6c,0x73,0x28,0x53,0x65,0x73,0x73,0x69,0x6f,0x6e,0x54,0x79,0x70,0x65,0x2c,0x20,0x30,0x29,0x29,0x28,0x41,0x67,0x67,0x72,0x65,0x67,0x61,0x74,0x65,0x46,0x75,0x6e,0x63,0x74,0x69,0x6f,0x6e,0x28,0x3f,0x00,0xf0,0x03,0x2c,0x20,0x55,0x49,0x6e,0x74,0x36,0x34,0x2c,0x20,0x55,0x49,0x6e,0x74,0x38,0x29,0x00,0x00};


    std::cout << "len=" <<sizeof(str)<< std::endl;
    CityHash_v1_0_2::uint128 aa = CityHash_v1_0_2::CityHash128(str, sizeof(str));

    printf("[%llu], [%llu]\n", aa.low64 & 0xffffffff, (aa.low64 & 0xffffffff00000000) >> 32);
    printf("[%llu], [%llu]\n", aa.high64 & 0xffffffff, (aa.high64 & 0xffffffff00000000) >> 32);


    std::cout << aa.low64 << std::endl;
    std::cout << aa.high64 << std::endl;


    CityHash_v1_0_2::uint128 aa1 = CityHash_v1_0_2::CityHash128((char *)str2, sizeof(str2));
    std::cout << aa1.low64 << std::endl;
    std::cout << aa1.high64 << std::endl;

    return 0;
}


