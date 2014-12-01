


template<class _TYPE>
void Encoder::encode(const _TYPE& data)
{
    const char* buffer_date = reinterpret_cast<const char *>(&data);
    copy(buffer_date, sizeof(data));
}


template<class _TYPE>
void Encoder::encode(std::vector<_TYPE>& data)
{
    encode(data.size());

    const std::vector<_TYPE>::iterator iter;
    for (iter = data.begin(); iter != data.end(); ++iter)
    {
        encode(*iter);
    }
}

template<class _TYPE>
void Encoder::encode(std::string& data)
{

}