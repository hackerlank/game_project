
#ifndef _YLH_SOCK_HANDLER_H
#define _YLH_SOCK_HANDLER_H

#include "ace/Global_Macros.h"
#include "ace/Svc_Handler.h"
#include "ace/SOCK_Stream.h"
#include "ace/Event_Handler.h"

class YLH_Net_Manager;
class YLH_Server;

class YLH_Sock_Handler : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_MT_SYNCH>
{
    typedef ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_MT_SYNCH> super;

public:
    YLH_Sock_Handler();
    virtual ~YLH_Sock_Handler();

    //getter setter
    YLH_Server*         get_owner_server(); //用于 调用collect_msg
    void                set_owner_net_manager(YLH_Net_Manager* owner_net_manager);
    YLH_Net_Manager*    get_owner_net_manager();
    void                set_port(int port);
    int                 get_port();

    //virtual function
    virtual int open (void * = 0);
    virtual int handle_input(ACE_HANDLE fd /* = ACE_INVALID_HANDLE */);
    virtual int handle_close (ACE_HANDLE = ACE_INVALID_HANDLE, ACE_Reactor_Mask = ACE_Event_Handler::ALL_EVENTS_MASK);

    


private:
    YLH_Net_Manager*    m_owner_net_manager;
    int                 m_port;
};

#endif  //_YLH_SOCK_HANDLER_H