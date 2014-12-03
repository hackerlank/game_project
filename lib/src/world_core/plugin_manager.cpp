
#include "plugin_manager.h"
#include "plugin_base.h"
#include "ace/Assert.h"

Plugin_Manger::Plugin_Manger(Player* owner_player)
:m_owner_player(owner_player)
{
    ACE_ASSERT(NULL != owner_player);
}

Plugin_Manger::~Plugin_Manger()
{

}


Plugin_Base* Plugin_Manger::get_plugin(int type)
{
    return m_plugin_manger.get(type);
    //std::map<PLUGIN_TYPE, Plugin_Base*>::iterator iter = m_plugin_manger.find(type);
    //if (iter != m_plugin_manger.end())
    //{
    //    return iter->second;
    //}

    //return NULL;
}