#include<iostream>
#include<string>
#include"test.pb.h"
using namespace fixbug;


int main()
{
    // LoginResponse rep;
    // ResultCode *re=rep.mutable_result();
    // re->set_errcode(1);
    // re->set_errmsg("登录失败");

    GetFriendListsResponse rsp;
    ResultCode *re=rsp.mutable_result();
    re->set_errcode(0);
    
    User *user1=rsp.add_friend_list();
    user1->set_name("zhang san");
    user1->set_age(21);
    user1->set_sex(User::man);

    std::cout<<rsp.friend_list_size()<<std::endl;



    return 0;
}

// int main()
// {
//     LoginRequest req;
//     req.set_name("zhang san");
//     req.set_pwd("123");

//     //把对象数据序列化
//     std::string send_str;
//     if(req.SerializeToString(&send_str))
//     {
//         std::cout<<send_str<<std::endl;
//     }

//     //反序列化得到一个login请求对象
//     LoginRequest reqB;
//     if(reqB.ParseFromString(send_str))
//     {
//         std::cout<<reqB.name()<<std::endl;
//         std::cout<<reqB.pwd()<<std::endl;
//     }
//     return 0;
// }