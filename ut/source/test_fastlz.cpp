
#include "test_fastlz.h"
#include "cppkit/ck_sha_256.h"
#include "cppkit/ck_compression_utils.h"
#include "cppkit/3rdparty/fastlz/fastlz.h"

using namespace std;
using namespace cppkit;

REGISTER_TEST_FIXTURE(test_fastlz);

unsigned char data_to_compress[] = {
  0x0a, 0x23, 0x69, 0x66, 0x6e, 0x64, 0x65, 0x66, 0x20, 0x5f, 0x74, 0x65,
  0x73, 0x74, 0x5f, 0x63, 0x6b, 0x5f, 0x6d, 0x65, 0x6d, 0x6f, 0x72, 0x79,
  0x5f, 0x6d, 0x61, 0x70, 0x5f, 0x48, 0x5f, 0x0a, 0x23, 0x64, 0x65, 0x66,
  0x69, 0x6e, 0x65, 0x20, 0x5f, 0x74, 0x65, 0x73, 0x74, 0x5f, 0x63, 0x6b,
  0x5f, 0x6d, 0x65, 0x6d, 0x6f, 0x72, 0x79, 0x5f, 0x6d, 0x61, 0x70, 0x5f,
  0x48, 0x5f, 0x0a, 0x0a, 0x23, 0x69, 0x6e, 0x63, 0x6c, 0x75, 0x64, 0x65,
  0x20, 0x22, 0x66, 0x72, 0x61, 0x6d, 0x65, 0x77, 0x6f, 0x72, 0x6b, 0x2e,
  0x68, 0x22, 0x0a, 0x0a, 0x63, 0x6c, 0x61, 0x73, 0x73, 0x20, 0x74, 0x65,
  0x73, 0x74, 0x5f, 0x63, 0x6b, 0x5f, 0x6d, 0x65, 0x6d, 0x6f, 0x72, 0x79,
  0x5f, 0x6d, 0x61, 0x70, 0x20, 0x3a, 0x20, 0x70, 0x75, 0x62, 0x6c, 0x69,
  0x63, 0x20, 0x74, 0x65, 0x73, 0x74, 0x5f, 0x66, 0x69, 0x78, 0x74, 0x75,
  0x72, 0x65, 0x0a, 0x7b, 0x0a, 0x70, 0x75, 0x62, 0x6c, 0x69, 0x63, 0x3a,
  0x0a, 0x20, 0x20, 0x20, 0x20, 0x52, 0x54, 0x46, 0x5f, 0x46, 0x49, 0x58,
  0x54, 0x55, 0x52, 0x45, 0x28, 0x74, 0x65, 0x73, 0x74, 0x5f, 0x63, 0x6b,
  0x5f, 0x6d, 0x65, 0x6d, 0x6f, 0x72, 0x79, 0x5f, 0x6d, 0x61, 0x70, 0x29,
  0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x54, 0x45,
  0x53, 0x54, 0x28, 0x74, 0x65, 0x73, 0x74, 0x5f, 0x63, 0x6b, 0x5f, 0x6d,
  0x65, 0x6d, 0x6f, 0x72, 0x79, 0x5f, 0x6d, 0x61, 0x70, 0x3a, 0x3a, 0x74,
  0x65, 0x73, 0x74, 0x5f, 0x66, 0x69, 0x6c, 0x65, 0x5f, 0x6d, 0x61, 0x70,
  0x70, 0x69, 0x6e, 0x67, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x54, 0x45, 0x53, 0x54, 0x28, 0x74, 0x65, 0x73, 0x74,
  0x5f, 0x63, 0x6b, 0x5f, 0x6d, 0x65, 0x6d, 0x6f, 0x72, 0x79, 0x5f, 0x6d,
  0x61, 0x70, 0x3a, 0x3a, 0x74, 0x65, 0x73, 0x74, 0x5f, 0x70, 0x65, 0x72,
  0x73, 0x69, 0x73, 0x74, 0x5f, 0x74, 0x6f, 0x5f, 0x64, 0x69, 0x73, 0x6b,
  0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x54,
  0x45, 0x53, 0x54, 0x28, 0x74, 0x65, 0x73, 0x74, 0x5f, 0x63, 0x6b, 0x5f,
  0x6d, 0x65, 0x6d, 0x6f, 0x72, 0x79, 0x5f, 0x6d, 0x61, 0x70, 0x3a, 0x3a,
  0x74, 0x65, 0x73, 0x74, 0x5f, 0x6d, 0x6f, 0x76, 0x65, 0x29, 0x3b, 0x0a,
  0x20, 0x20, 0x20, 0x20, 0x52, 0x54, 0x46, 0x5f, 0x46, 0x49, 0x58, 0x54,
  0x55, 0x52, 0x45, 0x5f, 0x45, 0x4e, 0x44, 0x28, 0x29, 0x3b, 0x0a, 0x0a,
  0x20, 0x20, 0x20, 0x20, 0x76, 0x6f, 0x69, 0x64, 0x20, 0x73, 0x65, 0x74,
  0x75, 0x70, 0x28, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x76, 0x6f,
  0x69, 0x64, 0x20, 0x74, 0x65, 0x61, 0x72, 0x64, 0x6f, 0x77, 0x6e, 0x28,
  0x29, 0x3b, 0x0a, 0x0a, 0x70, 0x72, 0x6f, 0x74, 0x65, 0x63, 0x74, 0x65,
  0x64, 0x3a, 0x0a, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x76, 0x6f, 0x69, 0x64,
  0x20, 0x74, 0x65, 0x73, 0x74, 0x5f, 0x66, 0x69, 0x6c, 0x65, 0x5f, 0x6d,
  0x61, 0x70, 0x70, 0x69, 0x6e, 0x67, 0x28, 0x29, 0x3b, 0x0a, 0x20, 0x20,
  0x20, 0x20, 0x76, 0x6f, 0x69, 0x64, 0x20, 0x74, 0x65, 0x73, 0x74, 0x5f,
  0x70, 0x65, 0x72, 0x73, 0x69, 0x73, 0x74, 0x5f, 0x74, 0x6f, 0x5f, 0x64,
  0x69, 0x73, 0x6b, 0x28, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x76,
  0x6f, 0x69, 0x64, 0x20, 0x74, 0x65, 0x73, 0x74, 0x5f, 0x6d, 0x6f, 0x76,
  0x65, 0x28, 0x29, 0x3b, 0x0a, 0x7d, 0x3b, 0x0a, 0x0a, 0x23, 0x65, 0x6e,
  0x64, 0x69, 0x66, 0x0a
};
unsigned int data_to_compress_len = 508;

void test_fastlz::setup()
{
}

void test_fastlz::teardown()
{
}

void test_fastlz::test_compress_basic()
{
    vector<uint8_t> cbuffer(534);

    auto sz = fastlz_compress(&data_to_compress[0], data_to_compress_len, &cbuffer[0]);

    RTF_ASSERT(sz >= 0);
    RTF_ASSERT(sz < data_to_compress_len);

    vector<uint8_t> dbuffer(534);

    sz = fastlz_decompress(&cbuffer[0], sz, &dbuffer[0], dbuffer.size());

    RTF_ASSERT(sz == data_to_compress_len);

    auto oh = cppkit::sha_256(&data_to_compress[0], data_to_compress_len);
    auto ch = cppkit::sha_256(&dbuffer[0], sz);

    RTF_ASSERT(oh == ch);
}

void test_fastlz::test_compress_bz2()
{
    vector<uint8_t> cbuffer(534);

    auto sz = ck_compression_utils::compress_buffer(&data_to_compress[0], data_to_compress_len, &cbuffer[0], 534);

    RTF_ASSERT(sz >= 0);
    RTF_ASSERT(sz < data_to_compress_len);

    vector<uint8_t> dbuffer(534);

    sz = ck_compression_utils::decompress_buffer(&cbuffer[0], sz, &dbuffer[0], dbuffer.size());

    RTF_ASSERT(sz == data_to_compress_len);

    auto oh = cppkit::sha_256(&data_to_compress[0], data_to_compress_len);
    auto ch = cppkit::sha_256(&dbuffer[0], sz);

    RTF_ASSERT(oh == ch);
}
