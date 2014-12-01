

#include "testcode.h"


TestPacket::TestPacket()
{
    id = 0;
    entity_id = 0;
    u_id = 0;
}

void TestPacket::encode(Encoder& encoder)
{
    encoder.encode(id);
    encoder.encode(entity_id);
    encoder.encode(u_id);
}

void TestPacket::decode(Decoder& decoder)
{
    decoder.decode(id);
    decoder.decode(entity_id);
    decoder.decode(u_id);
}

TestCode::TestCode()
{

}

TestCode::~TestCode()
{

}



void TestCode::test()
{
    TestPacket test_packet;

    test_packet.id = 1;
    test_packet.entity_id = 11;
    test_packet.u_id = 122;
    
    ACE_Message_Block* sz_buff = new ACE_Message_Block(1024);
    Encoder* encoder = (Encoder*)sz_buff;
    test_packet.encode(*encoder);


    TestPacket test_packet_dec;
    Decoder* decoder = (Decoder*)sz_buff;
    test_packet_dec.decode(*decoder);



}