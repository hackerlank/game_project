//¶ÁÍøÂç°ü


#ifndef _DECODER_H_
#define _DECODER_H_


#include "ace/message_block.h"



class Decoder : public ACE_Message_Block
{
public:

    Decoder();
    ~Decoder();

    template<class _TYPE>
    void decode(const _TYPE& data);

    template<class _TYPE>
    void decode(const std::vector<_TYPE>& data);

    template<class _TYPE>
    void decode(std::string<_TYPE>& data);
};


#include "Decoder.inl"

#endif  //_ENCODER_H_