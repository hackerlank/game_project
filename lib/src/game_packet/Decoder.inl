


template<class _TYPE>
void Decoder::decode(const _TYPE& data)
{
    const char* buffer_date = reinterpret_cast<const char *>(&data);
    copy(buffer_date, sizeof(data));
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
void Decoder::decode(std::string<_TYPE>& data)
{

}