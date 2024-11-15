# 1. reference
1. 从零Makefile落地算法大项目: https://blog.csdn.net/qq_40672115/article/details/126504893?fromshare=blogdetail&sharetype=blogdetail&sharerId=126504893&sharerefer=PC&sharesource=m0_47719724&sharefrom=from_link

2. https://zhuanlan.zhihu.com/p/396448133  

3. github:  https://github.com/shouxieai/makefile_tutorial_project


4. 如何把PCL1.14安装到指定位置
    1. 下载源代码：https://github.com/PointCloudLibrary/pcl/tree/pcl-1.14.1
    2. 进入目录：指定安装位置，以及安装目录：
        cmake -DCMAKE_INSTALL_PREFIX:PATH=/home/username/mysoftware -B build
    3. 编译：
        cmake --build build
    4. install
        sudo cmake --install .（在当前目录下查找构建文件，并执行安装）
        或者进入build目录？sudo make install（没试过）