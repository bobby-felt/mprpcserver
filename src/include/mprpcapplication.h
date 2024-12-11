#pragma once

#include"mprpcconfig.h"
#include"mprpcchannel.h"
#include"mprpccontroller.h"

//mprpc框架的初始化类,基础类
class MprpcApplication
{
private:
    static MprpcConfig m_config;

    MprpcApplication(){}
    MprpcApplication(const MprpcApplication&) = delete;
    MprpcApplication(MprpcApplication&&) = delete;
public:
    static void Init(int argc,char **argv);
    static MprpcApplication& GetInstance();
    static MprpcConfig& GetConfig();
};

