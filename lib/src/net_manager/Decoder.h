//¶ÁÍøÂç°ü


#ifndef _DECODER_H_
#define _DECODER_H_


#include "ace/message_block.h"



class Decoder : public ACE_Message_Block
{
public:

    Decoder(){}
    ~Decoder(){}

    template<class _TYPE>
    void decode(_TYPE& data);

    template<class _TYPE>
    void decode(std::vector<_TYPE>& data);

    template<class _TYPE>
    void decode(std::string& data);
};


#include "Decoder.inl"

#endif  //_ENCODER_H_