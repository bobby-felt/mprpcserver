#include <iostream>
#include<string>
#include"friend.pb.h"
#include"mprpcapplication.h"
#include"rpcprovider.h"
#include<vector>
#include"logger.h"

class FriendService:public fixbug::FriendServiceRpc
{
private:
    /* data */
public:
    std::vector<std::string> GetFriendList(uint32_t userid)
    {
        std::cout<<"do GetFriendList service! userid:"<<userid<<std::endl;
        std::vector<std::string> vec;
        vec.push_back("gao yang");
        vec.push_back("gao nm");
        return vec;
    }

    //重写基类方法
    void GetFriendList(google::protobuf::RpcController* controller,
                       const ::fixbug::GetFriendListRequest* request,
                       ::fixbug::GetFriendListResponse* response,
                       ::google::protobuf::Closure* done)
    {
        uint32_t userid=request->userid();
        std::vector<std::string> friendlist=GetFriendList(userid);
        for(std::string &name:friendlist)
        {
            std::string *p=response->add_friends();
            *p=name;
        }
        done->Run();
    }
};

int main(int argc,char **argv)
{
    LOG_INFO("first log msg!");
    LOG_ERR("%s:%s:%d",__FILE__,__FUNCTION__,__LINE__);

    //调用框架初始化操作
    MprpcApplication::Init(argc,argv);

    //provider是一个rpc网络服务对象，把FriendService对象发布到rpc节点上
    RpcProvider provider;
    provider.NotifyService(new FriendService());

    //启动一个rpc服务发布节点，Run以后，进程进入阻塞状态，等待远程的rpc调用请求
    provider.Run();

    return 0;
}



