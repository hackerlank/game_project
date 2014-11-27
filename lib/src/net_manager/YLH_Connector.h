


//服务器网络链接模块


#ifndef _YLH_CONNECT_H_
#define _YLH_CONNECT_H_

#include "ace/Connector.h"
#include "ace/SOCK_Connector.h"

#include <vector>
#include <map>

#include "YLH_Server_Info.h"
#include "YLH_Sock_Handler.h"


typedef ACE_Connector<YLH_Sock_Handler, ACE_SOCK_CONNECTOR> connector_super;

class YLH_Connector : public connector_super
{
public:
    YLH_Connector(ACE_Reactor* Owner_Reactor, YLH_Net_Manager* owner_net_manager);
    virtual int make_svc_handler (YLH_Sock_Handler *&sh);

    //getter setter
    ACE_Reactor* get_owner_reactor();

public:
    //void add_connnection_info(YLH_Connect_Info& connect_info);

    //void open_connect();

    //void add_connect_handler(ACE_HANDLE handle, YLH_Sock_Handler* connect_handler);
    //void del_connect_handler(ACE_HANDLE handle, YLH_Sock_Handler* accept_handler);
    //YLH_Sock_Handler* get_connect_handler(int port);


    //int do_connect(YLH_Sock_Handler* connect_handler, YLH_Connect_Info connect_info);

    int start_connect(YLH_Connect_Info& connect_info);



private:
    ACE_Reactor*            m_owner_reactor;
    YLH_Net_Manager*        m_owner_net_manager;

    

private:
    YLH_Connector();
};

#endif  //_YLH_CONNECT_H_