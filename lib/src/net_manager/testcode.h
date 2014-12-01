

#ifndef _TEST_CODE_H_
#define _TEST_CODE_H_

#include "Encoder.h"
#include "Decoder.h"


struct TestPacket
{
    int     id;
    int     entity_id;
    long    u_id;

    TestPacket();
    void encode(Encoder& encoder);
    void decode(Decoder& decoder);
};



class TestCode
{
public:
    TestCode();
    ~TestCode();


    void test();

};


#endif  //_TEST_CODE_H_