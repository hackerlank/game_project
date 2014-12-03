
#include <map>

template<class _KEY, class _VAL>
class Map_Manager
{
    typedef std::map<_KEY, _VAL*> Object_List;

    //typedef Object_List::iterator Iter_Object;

public:
    Map_Manager();
    ~Map_Manager();

    void add(_KEY key, _VAL* val) 
    {
        //ACE_GUARD_RETURN(ACE_Thread_Mutex, ace_mon, Script_Data::sync_lock_, 0);
        ACE_ASSERT(val);
        this->m_list[key] = val;
    }

    //Iter_Object get_iter(_KEY key)
    //{
    //    return m_list.find(key);
    //}

    _VAL* get(_KEY key)
    {
        Object_List::iterator iter = m_list.find(key);
        if (iter != m_list.end())
        {
            return iter->second;
        }

        return NULL;
    }

    void del(_KEY key)
    {
        Iter_Object iter = get_iter(key);
        if (iter != m_list.end())
        {
            m_list.erase(iter);
        }
    }


private:
    Object_List     m_list;
};