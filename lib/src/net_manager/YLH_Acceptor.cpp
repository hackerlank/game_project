
#include "YLH_Acceptor.h"
#include "YLH_Net_Manager.h"
#include <sstream>
#include <map>

YLH_Acceptor::YLH_Acceptor( ACE_Reactor* owner_reactor, YLH_Net_Manager* owner_net_manager )
:m_owner_reactor(owner_reactor)
,m_owner_net_manager(owner_net_manager)
{
    ACE_ASSERT(NULL != m_owner_reactor);
    ACE_ASSERT(NULL != m_owner_net_manager);
}

int YLH_Acceptor::Open_Accept( YLH_Acceptor_Info& acceptor_info )
{
    //¿ªÆô¼àÌý
    YLH_Sock_Handler::addr_type acceptor_addr(acceptor_info.acceptor_port);
    if (-1 == acceptor_super::open(acceptor_addr, m_owner_reactor))
    {
        return -1;
    }

    return 0;
}

int YLH_Acceptor::make_svc_handler (YLH_Sock_Handler *&sh)
{
    if (sh == 0)
        ACE_NEW_RETURN (sh,
        YLH_Sock_Handler(),
        -1);

    sh->reactor (m_owner_reactor);
    sh->set_owner_net_manager(m_owner_net_manager);
    sh->reactor(m_owner_reactor);

    m_owner_net_manager->add_socket_handler(sh);

    return 0;
}

//void YLH_Acceptor::add_accept_handler(ACE_HANDLE handle, YLH_Sock_Handler* accept_handler)
//{
//    std::map<ACE_HANDLE, YLH_Sock_Handler*>::iterator iter = m_accept_handler_list.find(handle);
//    if (iter != m_accept_handler_list.end())
//    {
//        //ACE_ERROR();
//    }
//
//    m_accept_handler_list[handle] = accept_handler;
//}

//void YLH_Acceptor::del_accept_handler(ACE_HANDLE handle, YLH_Sock_Handler* accept_handler)
//{
//    std::map<ACE_HANDLE, YLH_Sock_Handler*>::iterator iter = m_accept_handler_list.find(handle);
//    if (iter != m_accept_handler_list.end())
//    {
//        m_accept_handler_list.erase(iter);
//    }
//}
ACE_Reactor* YLH_Acceptor::get_Owner_Reactor()
{
    return m_owner_reactor;
}

//void YLH_Acceptor::send_test_buff()
//{
//    std::map<ACE_HANDLE, YLH_Sock_Handler*>::iterator iter;
//    for (iter = m_accept_handler_list.begin(); iter != m_accept_handler_list.end(); ++iter)
//    {
//        static int kk = 10000;
//        kk++;
//        std::stringstream oo;
//        oo.clear();
//        oo<<"YLH_Acceptor send buff "<<kk<<" "<<std::endl;
//        iter->second->peer().send_n(oo.str().c_str(), oo.str().size());
//    }
//}