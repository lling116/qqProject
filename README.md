                        QT5.5.0 win7下测试ok
 1 .2019/3//11完成qq登陆界面
  当编译出现如下错误：
  F:\Code\QT\QQ\build-qqProject-Desktop_Qt_5_5_0_MinGW_32bit-Debug\debug\moc_qqmainwindow.cpp:85: error: undefined reference to `QQMainWindow::++==on_label_2_linkActivated(QString const&)'==++，请点击报错出把++==case  0:  _t->on_label_2_linkActivated((*reinterpret_cast<  const  QString(*)>(_a[1])));  break;==++屏蔽掉！！
  错误原因：是我在QT设计师多添加了一个QLabel信号和槽
  2.界面如下：
   
![1]($resource/1.JPG)
![2]($resource/2.JPG)

