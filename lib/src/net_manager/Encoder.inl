


template<class _TYPE>
void Encoder::encode(const _TYPE& data)
{
    const char* buffer_date = reinterpret_cast<const char *>(&data);
    copy(buffer_date, sizeof(data));
}


template<class _TYPE>
void Encoder::encode(std::vector<_TYPE>& data)
{
    const int vec_size = data.size();
    encode(vec_size);

    for (int i=0; i<vec_size; ++i)
    {
        encode(data[i]);
    }
}

//template<class _TYPE>
//void Encoder::encode(std::string& data)
//{
//    encode(STRING_CODE, sizeof(STRING_CODE));
//    
//    const int buff_size = data.size();
//    encode(buff_size);
//
//    for (int i=0; i<buff_size; ++i)
//    {
//        encode(data[i], sizeof(data[i]));
//    }
//
//}

//template<class _TYPE>
//void Encoder::encode(const char* data, int len)
//{
//    copy(data, len);
//}