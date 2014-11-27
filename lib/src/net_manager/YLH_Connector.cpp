#include "YLH_Connector.h"
#include "YLH_Net_Manager.h"

#include <sstream>  //testcode


YLH_Connector::YLH_Connector( ACE_Reactor* owner_reactor, YLH_Net_Manager* owner_net_manager )
:m_owner_reactor(owner_reactor)
,m_owner_net_manager(owner_net_manager)
{
    ACE_ASSERT(NULL != m_owner_reactor);
    ACE_ASSERT(NULL != m_owner_net_manager);
}

ACE_Reactor* YLH_Connector::get_owner_reactor()
{
    return m_owner_reactor;
}

int YLH_Connector::start_connect( YLH_Connect_Info& connect_info )
{
    connector_super::reactor(m_owner_reactor);

    ACE_INET_Addr connect_port(connect_info.connect_port, "127.0.0.1");
    YLH_Sock_Handler* new_handler = NULL;

    if (-1 == connector_super::connect(new_handler, connect_port))
    {
        return -1;
    }

    if (NULL == new_handler)
    {
        return -1;
    }

    new_handler->set_owner_net_manager(m_owner_net_manager);
    new_handler->set_port(connect_info.connect_port);
    new_handler->reactor(m_owner_reactor);

    m_owner_net_manager->add_socket_handler(new_handler);
    
    
    return 0;
}

//void YLH_Connector::add_connnection_info(YLH_Connect_Info& connect_info)
//{
//    m_connection_config_list.push_back(connect_info);
//}

//void YLH_Connector::open_connect()
//{
//    std::vector<YLH_Connect_Info>::iterator iter;
//    for (iter = m_connection_config_list.begin(); iter != m_connection_config_list.end(); ++iter)
//    {
//        if (NULL == get_connect_handler(iter->connect_port))
//        {
//            Open_Connect(*iter);
//        }
//        
//    }
//}



int YLH_Connector::make_svc_handler (YLH_Sock_Handler *&sh)
{
    return connector_super::make_svc_handler(sh);

    if (sh == 0)
        ACE_NEW_RETURN (sh,
        YLH_Sock_Handler(),
        -1);

    sh->reactor (m_owner_reactor);

    m_owner_net_manager->add_socket_handler(sh);

    return 1;
}


//void YLH_Connector::add_connect_handler(ACE_HANDLE handle, YLH_Sock_Handler* accept_handler)
//{
//    std::map<ACE_HANDLE, YLH_Sock_Handler*>::iterator iter = m_connect_handler_list.find(handle);
//    if (iter != m_connect_handler_list.end())
//    {
//        //ACE_ERROR();
//    }
//
//    m_connect_handler_list[handle] = accept_handler;
//}
//
//YLH_Sock_Handler* YLH_Connector::get_connect_handler(int port)
//{
//    std::map<ACE_HANDLE, YLH_Sock_Handler*>::iterator iter;
//    for (iter = m_connect_handler_list.begin(); iter != m_connect_handler_list.end(); ++iter)
//    {
//        if (iter->second->get_port() == port)
//        {
//            return iter->second;
//        }
//    }
//
//    return NULL;
//}
//
//
//void YLH_Connector::del_connect_handler(ACE_HANDLE handle, YLH_Sock_Handler* accept_handler)
//{
//    std::map<ACE_HANDLE, YLH_Sock_Handler*>::iterator iter = m_connect_handler_list.find(handle);
//    if (iter != m_connect_handler_list.end())
//    {
//        //ACE_ERROR();
//        m_connect_handler_list.erase(iter);
//    }
//}



//int YLH_Connector::do_connect(YLH_Sock_Handler* connect_handler, YLH_Connect_Info connect_info)
//{
//    ACE_INET_Addr connect_port(connect_info.connect_port, "192.168.1.224");
//    return connector_super::connect(connect_handler, connect_port);
//}