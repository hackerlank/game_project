





#ifndef _PLUGIN_MANAGER_H_
#define _PLUGIN_MANAGER_H_

#include <map>
#include "map_manager.h"

class Plugin_Base;
class Player;


class Plugin_Manger
{
public:
    Plugin_Manger(Player* owner_player);
    virtual ~Plugin_Manger();


    Plugin_Base* get_plugin(int type);

private:
    Plugin_Manger();
    Plugin_Manger(const Plugin_Manger&);
    Plugin_Manger& operator=(const Plugin_Manger&);

private:
    Map_Manager<int, Plugin_Base>       m_plugin_manger;

    Player*                             m_owner_player;
};


#endif  //_PLUGIN_MANAGER_H_