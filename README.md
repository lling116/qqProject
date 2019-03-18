                        # QT5.5.0边写的QQ
2.  当编译出现如下错误：
  F:\Code\QT\QQ\build-qqProject-Desktop_Qt_5_5_0_MinGW_32bit-Debug\debug\moc_qqmainwindow.cpp:85: error: undefined reference to `QQMainWindow::++==on_label_2_linkActivated(QString const&)'==++，请点击报错出把++==case  0:  _t->on_label_2_linkActivated((*reinterpret_cast<  const  QString(*)>(_a[1])));  break;==++屏蔽掉！！
  错误原因：是我在QT设计师多添加了一个QLabel信号和槽

2.操作说明
   # 先把文件夹的tcpservsr 工程打开并且运行；确保服务器先运行
   #再把qqproject 工程打开并运行
   #如果还没有账号，你可以申请注册一个
   #登陆申请的账号！进入主界面
   #可以双击人物，进入对话
 3.目前还未完善的功能：
    #任务之前的对话；
    #多人连接服务器
    #某些地方在需要美化
   

