


template<class _TYPE>
void Decoder::decode(_TYPE& data)
{
    //rd_ptr(sizeof(_TYPE));

    char* buf = reinterpret_cast<char *>(&data);
    std::copy(rd_ptr(), rd_ptr() + sizeof(_TYPE), buf);
    
    //移到下一个指针
    rd_ptr(sizeof(_TYPE));
}


template<class _TYPE>
void Decoder::decode(std::vector<_TYPE>& data)
{
    //decode(data.size());

    //const std::vector<_TYPE>::iterator iter;
    //for (iter = data.begin(); iter != data.end(); ++iter)
    //{
    //    encode(*iter);
    //}
}

template<class _TYPE>
void Decoder::decode(std::string& data)
{

}