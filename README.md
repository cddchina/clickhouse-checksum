# clickhouse-checksum

前16个字节是checksum
后面跟着的是，1个字节加密算法，4个字节的压缩后数据长度，4个字节的压缩前数据长度，压缩的数据
前16个字节是checksum
后面跟着的是，1个字节加密算法，4个字节的压缩后数据长度，4个字节的压缩前数据长度，压缩的数据
循环

# 算法
声明的文件：ClickHouse-master\ClickHouse-master\src\Compression\CompressionInfo.h
```
enum class CompressionMethodByte : uint8_t
{
    NONE            = 0x02,
    LZ4             = 0x82,
    ZSTD            = 0x90,
    Multiple        = 0x91,
    Delta           = 0x92,
    T64             = 0x93,
    DoubleDelta     = 0x94,
    Gorilla         = 0x95,
    AES_128_GCM_SIV = 0x96,
    AES_256_GCM_SIV = 0x97,
    FPC             = 0x98,
    DeflateQpl      = 0x99,
    GCD             = 0x9a,
    ZSTD_QPL        = 0x9b,
};
```

# 编译命令
g++ -std=c++11 main.cpp city.cc
