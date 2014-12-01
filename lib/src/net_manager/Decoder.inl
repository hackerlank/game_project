


template<class _TYPE>
void Decoder::decode(_TYPE& data)
{
    char* buf = reinterpret_cast<char *>(&data);
    std::copy(rd_ptr(), rd_ptr() + sizeof(_TYPE), buf);
    
    //移到下一个指针
    rd_ptr(sizeof(_TYPE));
}


template<class _TYPE>
void Decoder::decode(std::vector<_TYPE>& data)
{
    data.clear();

    int vec_size = 0;
    decode(vec_size);

    const std::vector<_TYPE>::iterator iter;
    for (int i=0; i<vec_size; ++i)
    {
        _TYPE new_data;
        decode(new_data);
        data.push_back(new_data);
    }
}

//template<class _TYPE>
//void Decoder::decode(char* data, int len)
//{
//    std::copy(rd_ptr(), rd_ptr() + len, data);
//
//    //移到下一个指针
//    rd_ptr(len);
//
//    std::string check_string(data, len);
//    if (STRING_CODE == check_string)
//    {
//    }
//}
