





#ifndef _PLUGIN_BASE_H_
#define _PLUGIN_BASE_H_

class Player;


class Plugin_Base
{
public:
    Plugin_Base(Player* owner_player);
    virtual ~Plugin_Base();


    virtual void handle_message() = 0;

private:
    Plugin_Base();
    Plugin_Base(const Plugin_Base&);
    Plugin_Base& operator=(const Plugin_Base&);

private:
    Player* m_owner_player;
};


#endif  //_PLAYER_H_