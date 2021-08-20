# QuantTrader

#### 介绍
量化交易框架，编译环境编译用VS2019 + QT5.12.11_msvc2017


#### 软件架构说明

#######软件功能
1.CTP连接，行情订阅，下单，订单管理，仓位和账户查询

![输入图片说明](https://images.gitee.com/uploads/images/2021/0806/132250_2ee4a6da_9459957.png "ctp连接.png")
![输入图片说明](https://images.gitee.com/uploads/images/2021/0722/140614_3623bcc0_9459957.jpeg "图像 5.jpg")
2.合约查询
![输入图片说明](https://images.gitee.com/uploads/images/2021/0722/140944_4d4db3fd_9459957.jpeg "合约查询.jpg")
3.CTA策略
![输入图片说明](https://images.gitee.com/uploads/images/2021/0806/115628_b162b9c5_9459957.png "cta.png")
4.CTA回测
![输入图片说明](https://images.gitee.com/uploads/images/2021/0722/141041_695d2f29_9459957.jpeg "CTA回测.jpg")
5.CTA回测K线和开平仓显示
![输入图片说明](https://images.gitee.com/uploads/images/2021/0806/115611_41c079fd_9459957.png "temp.png")
6.交易风控

![输入图片说明](https://images.gitee.com/uploads/images/2021/0806/131757_39f451fa_9459957.png "risk.png")

7.RPC框架下的分布式架构，基于ZMQ和msgpack开发了一个简单RPC框架，形成分布式架构。可以简单通过配置文件配置客户端，服务器。当前
主要是将CTP后台分离到服务器端，提供RPC服务。

![输入图片说明](https://images.gitee.com/uploads/images/2021/0820/215436_b3b4551b_9459957.png "rpc connect.png")
![输入图片说明](https://images.gitee.com/uploads/images/2021/0820/215500_3fbba932_9459957.png "rpc engine.png")
![输入图片说明](https://images.gitee.com/uploads/images/2021/0820/215510_e4181bb8_9459957.png "rpc conf.png")



#### 安装教程

1.  xxxx
2.  xxxx
3.  xxxx

#### 使用说明

1.  xxxx
2.  xxxx
3.  xxxx

#### 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request


#### 特技

1.  使用 Readme\_XXX.md 来支持不同的语言，例如 Readme\_en.md, Readme\_zh.md
2.  Gitee 官方博客 [blog.gitee.com](https://blog.gitee.com)
3.  你可以 [https://gitee.com/explore](https://gitee.com/explore) 这个地址来了解 Gitee 上的优秀开源项目
4.  [GVP](https://gitee.com/gvp) 全称是 Gitee 最有价值开源项目，是综合评定出的优秀开源项目
5.  Gitee 官方提供的使用手册 [https://gitee.com/help](https://gitee.com/help)
6.  Gitee 封面人物是一档用来展示 Gitee 会员风采的栏目 [https://gitee.com/gitee-stars/](https://gitee.com/gitee-stars/)
