//Ð´ÍøÂç°ü


#ifndef _ENCODER_H_
#define _ENCODER_H_

#include <string>
#include <vector>
#include "ace/message_block.h"

#define STRING_CODE "S"


class Encoder : public ACE_Message_Block
{
public:

    Encoder(){}
    ~Encoder(){}

    template<class _TYPE>
    void encode(const _TYPE& data);
    
    template<class _TYPE>
    void encode(std::vector<_TYPE>& data);

    //template<class _TYPE>
    //void encode(std::string& data);

//private:
//    template<class _TYPE>
//    void encode(const char* data, int len);
};


#include "Encoder.inl"

#endif  //_ENCODER_H_