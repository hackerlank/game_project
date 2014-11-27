


//服务器网络链接模块


#ifndef _YLH_ACCEPTOR_H_
#define _YLH_ACCEPTOR_H_

#include "ace/Acceptor.h"
#include "ace/SOCK_Acceptor.h"

#include <map>

#include "YLH_Server_Info.h"
#include "YLH_Sock_Handler.h"

typedef ACE_Acceptor<YLH_Sock_Handler, ACE_SOCK_ACCEPTOR> acceptor_super;


class YLH_Acceptor : public acceptor_super
{
public:
    YLH_Acceptor(ACE_Reactor* owner_reactor, YLH_Net_Manager* owner_net_manager);
    int Open_Accept(YLH_Acceptor_Info& acceptor_info);

    virtual int make_svc_handler (YLH_Sock_Handler *&sh);

    //void send_test_buff();

public:
    //void     add_accept_handler(ACE_HANDLE handle, YLH_Sock_Handler* accept_handler);
    //void     del_accept_handler(ACE_HANDLE handle, YLH_Sock_Handler* accept_handler);
    ACE_Reactor* get_Owner_Reactor();

private:
    ACE_Reactor*            m_owner_reactor;
    YLH_Net_Manager*        m_owner_net_manager;
    

private:
    YLH_Acceptor();
};

#endif  //_YLH_CONNECT_H_