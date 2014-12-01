//¶ÁÍøÂç°ü


#ifndef _DECODER_H_
#define _DECODER_H_


#include "ace/message_block.h"

#define STRING_CODE "S"

class Decoder : public ACE_Message_Block
{
public:

    Decoder(){}
    ~Decoder(){}


public:
    template<class _TYPE>
    void decode(_TYPE& data);

    template<class _TYPE>
    void decode(std::vector<_TYPE>& data);

    //template<class _TYPE>
    //void decode(char* data, int len);
};


#include "Decoder.inl"

#endif  //_ENCODER_H_