#include "Role_Server.h"
#include "ace/Time_Value.h"
#include "ace/Reactor.h"
#include "YLH_Net_Manager.h"

#define  ROLE_TIMER_SEND -100

Role_Server::Role_Server()
{

}

void Role_Server::open_server()
{
    ACE_Time_Value send_interval(0, 5*1000);
    get_Reactor()->schedule_timer(this,
        reinterpret_cast<const void*>(ROLE_TIMER_SEND),
        send_interval, send_interval);
}

int  Role_Server::handle_timeout(const ACE_Time_Value &now, const void *act)
{
    if (reinterpret_cast<const void *>(ROLE_TIMER_SEND) == act)
    {
        get_net_manager()->send_test_buff();
    }
    
    return 0;
}

void Role_Server::collect_msg(char* recvbuf, int buff_size)
{
    int kk = 0; 
    kk++;
}


void Role_Server::add_accept_config()
{
    YLH_Acceptor_Info acceptor_info;
    acceptor_info.set_port(GAME_SERVER_ACCEPT_PORT);
    get_net_manager()->add_accept_info(acceptor_info);
}

void Role_Server::add_connect_config()
{
    
}