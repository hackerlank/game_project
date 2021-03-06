//д�����


#ifndef _ENCODER_H_
#define _ENCODER_H_


#include "ace/message_block.h"



class Encoder : public ACE_Message_Block
{
public:

    Encoder();
    ~Encoder();

    template<class _TYPE>
    void encode(const _TYPE& data);
    
    template<class _TYPE>
    void encode(const std::vector<_TYPE>& data);

    template<class _TYPE>
    void encode(std::string<_TYPE>& data);
};


#include "Encoder.inl"

#endif  //_ENCODER_H_