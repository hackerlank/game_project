

#include "YLH_Net_Manager.h"
#include "YLH_Server_Info.h"
#include "ace/TP_Reactor.h"
#include "ace/Log_Msg.h"
#include "YLH_Connector.h"

#include <sstream>  //testcode

#define CONNECT_SERVER_TIME_ID  -1      //定时连接服务器

YLH_Net_Manager::YLH_Net_Manager(YLH_Server* owner_server)
:m_Reactor(NULL)
,m_owner_server(owner_server)
{
    ACE_ASSERT(NULL != m_owner_server);

    ACE_TP_Reactor*  reactor_imp = new ACE_TP_Reactor();
    ACE_NEW_NORETURN(m_Reactor,ACE_Reactor(reactor_imp,1));

    m_acceptor = new YLH_Acceptor(m_Reactor, this);
    m_connector = new YLH_Connector(m_Reactor, this);
}

YLH_Server* YLH_Net_Manager::get_owner_server()
{
    return m_owner_server;
}

void YLH_Net_Manager::add_socket_handler(YLH_Sock_Handler *sock_handler)
{
    if (NULL == sock_handler)
    {
        return;
    }

    YLH_Sock_Handler* last_handler = get_socket_handler(sock_handler);
    if (NULL != last_handler)
    {
        //已存在
    }

    m_handler_list[sock_handler->get_handle()] = sock_handler;
}

void YLH_Net_Manager::del_socket_handler(YLH_Sock_Handler* sock_handler)
{
    if (NULL == sock_handler)
    {
        return;
    }

    std::map<ACE_HANDLE , YLH_Sock_Handler*>::iterator iter = m_handler_list.find(sock_handler->get_handle());
    if (iter != m_handler_list.end())
    {
        delete iter->second;
        iter->second = NULL;
        m_handler_list.erase(iter);
    }
}

YLH_Sock_Handler* YLH_Net_Manager::get_socket_handler(ACE_HANDLE handle)
{
    std::map<ACE_HANDLE , YLH_Sock_Handler*>::iterator iter = m_handler_list.find(handle);
    if (iter != m_handler_list.end())
    {
        return iter->second;
    }

    return NULL;
}

YLH_Sock_Handler* YLH_Net_Manager::get_socket_handler(int port)
{
    std::map<ACE_HANDLE , YLH_Sock_Handler*>::iterator iter;
    for (iter = m_handler_list.begin(); iter != m_handler_list.end(); ++iter)
    {
        YLH_Sock_Handler* sock_handler = iter->second;
        if (NULL == sock_handler)
        {
            continue;
        }
        if (sock_handler->get_port() == port)
        {
            return sock_handler;
        }
    }

    return NULL;
}

YLH_Sock_Handler* YLH_Net_Manager::get_socket_handler(YLH_Sock_Handler* sock_handler)
{
    if (NULL == sock_handler)
    {
        return NULL;
    }

    return get_socket_handler(sock_handler->get_handle());
}


void YLH_Net_Manager::open()
{
    //定时重连
    ACE_Time_Value send_interval(2, 2*1000);
    get_Reactor()->schedule_timer(this,
        reinterpret_cast<const void*>(CONNECT_SERVER_TIME_ID),
        send_interval, send_interval);

    //打开监听
    m_acceptor->Open_Accept(m_acceptor_info);
}

int YLH_Net_Manager::handle_timeout (const ACE_Time_Value &current_time,const void *act/* = 0*/)
{
    if(act == reinterpret_cast<const void *>(CONNECT_SERVER_TIME_ID))
    {
        open_all_connect();
        return 0;
    }

    return 0;
}

void YLH_Net_Manager::add_accept_info(YLH_Acceptor_Info& accept_info)
{
    m_acceptor_info = accept_info;
}

void YLH_Net_Manager::add_connect_info(YLH_Connect_Info& connect_info)
{
    m_connection_config_list.push_back(connect_info);
}

//int YLH_Net_Manager::Open_Accept(YLH_Acceptor_Info& acceptor_info)
//{
//    return m_acceptor->Open_Accept(acceptor_info);
//    ////开启监听
//    //YLH_Sock_Handler::addr_type acceptor_addr(acceptor_info.acceptor_port);
//    //if (-1 == m_acceptor.open(acceptor_addr, m_Reactor))
//    //{
//    //    return -1;
//    //}
//
//    //return 0;
//}

//void YLH_Net_Manager::add_connnection_info(YLH_Connect_Info& connect_info)
//{
//    m_connector->add_connnection_info(connect_info);
//}

//int YLH_Net_Manager::Open_Connect(YLH_Connect_Info& connect_info)
//{
//    //开启监听
//    //YLH_Sock_Handler::addr_type acceptor_addr(connect_info.acceptor_port);
//    //if (-1 == m_acceptor.open(acceptor_addr, m_Reactor))
//    //{
//    //    return -1;
//    //}
//    ACE_Time_Value send_interval(0, 10*1000);
//    get_Reactor()->schedule_timer(this,
//        reinterpret_cast<const void*>(CONNECT_SERVER_TIME_ID),
//        send_interval, send_interval);
//    return 0;
//    //return m_connector->Open_Connect(connect_info);
//}


void YLH_Net_Manager::run()
{
    printf("YLH_Net_Manager::run() \n");
    m_Reactor->run_reactor_event_loop();
}

ACE_Reactor* YLH_Net_Manager::get_Reactor()
{
    return m_Reactor;
}

void YLH_Net_Manager::send_test_buff()
{
    std::map<ACE_HANDLE, YLH_Sock_Handler*>::iterator iter;
    for (iter = m_handler_list.begin(); iter != m_handler_list.end(); ++iter)
    {
        static int kk = 0;
        kk++;
        std::stringstream oo;
        oo.clear();
        for (int i = 0; i < 30; ++i)
        {
            oo<<"yyyyyyyyyy";
        }
        oo<<kk<<" "<<std::endl;
        std::string str_buff_1 = oo.str();
        iter->second->peer().send_n(str_buff_1.c_str(), str_buff_1.size());
        ACE_Log_Msg::instance()->msg(str_buff_1.c_str());
    }
}

void YLH_Net_Manager::open_all_connect()
{
    std::vector<YLH_Connect_Info>::iterator iter;
    for (iter  = m_connection_config_list.begin(); iter != m_connection_config_list.end(); ++iter)
    {
        YLH_Sock_Handler* sock_handler = get_socket_handler(iter->connect_port);
        if (NULL == sock_handler)
        {
            //未连接, 开始连接
            m_connector->start_connect(*iter);
        }
    }
}