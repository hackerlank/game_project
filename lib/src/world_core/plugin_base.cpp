
#include "plugin_base.h"
#include "ace/Assert.h"

Plugin_Base::Plugin_Base(Player* owner_player)
:m_owner_player(owner_player)
{
    ACE_ASSERT(NULL != owner_player);
}

Plugin_Base::~Plugin_Base()
{

}