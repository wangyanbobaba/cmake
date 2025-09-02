1. 如何使用编译
    mkdir build
    cd build
    cmake ..
    make

2. 运行
    编译完成后在build文件夹得到一个simple_pcl_example可执行文件。
    键入命令运行
    ./simple_pcl_example input.pcd output.pcd

3. 编译可能出现的问题：
    3.1 经常会有使用命令行安装了库，但是编译的时候找不到的情况出现。

        3.1.1 缺什么就安装什么
            sudo apt install pkg_name

        3.1.2 安装成功还是提示找不到
            那就首先查找安装库的位置，（libtbb*是要搜索库名的前几个字母）
            sudo find / -name "libtbb*" 2>/dev/null
        
        3.1.3 把库的路径告诉cmake
            1. 命令行设置CMAKE_PREFIX_PATH变量
                提示缺少什么库，就设置变量CMake变量CMAKE_PREFIX_PATH，它指定了CMake应该搜索库文件和头文件的路径。在这个例子中，它被设置为/usr，意味着CMake将在/usr目录及其子目录中搜索所需的库和头文件。
                cmake -DCMAKE_PREFIX_PATH=/usr -B build && cmake --build build
                然后在CMakeList.txt同级目录下输入命令编译。
            2. 修改CMakeList.txt
                知道具体路径
                    # 设置TBB库的查找路径
                    set(TBB "/usr/local/lib/foo")
                    # 查找TBB库
                    find_package(TBB REQUIRED)
                知道大概路径
                    # 指定在/usr目录下的子文件夹中搜索Foo库
                    find_package(TBB PATHS /usr NO_DEFAULT_PATH)
                    find_package(TBB PATHS /usr/local /usr/share /usr/include NO_DEFAULT_PATH)


    3.2 指定C++编译器版本
        cmake -DCMAKE_PREFIX_PATH=/usr -B build -D CMAKE_CXX_COMPILER=g++-10
        参数
        -D CMAKE_CXX_COMPILER=g++-10：
        这个参数设置了CMake变量CMAKE_CXX_COMPILER，指定了项目将使用的C++编译器。这里指定的是g++-10，意味着CMake将使用g++编译器的版本10来编译C++代码。

    3.2 编译没问题，但是运行时找不到动态库
        报错类似于
        ```
        your_ros_project_name: error while loading shared libraries: libth_itof_b_shared.so: cannot open shared object file: No such file or directory
        ```
        解决：
        1. 首先要知道运行时库搜索机制：
            在Linux系统中，动态链接器加载程序时，会按照以下顺序搜索所需的共享库（.so文件）：
                1.
                ​​RPATH​​ (编译时嵌入到二进制文件中的路径)
                2.
                ​​LD_LIBRARY_PATH​​ (环境变量中的路径)
                3.
                ​​RUNPATH​​ (同样编译时嵌入)
                4.
                ​​/etc/ld.so.conf​​ 中配置的缓存路径
                5.
                系统默认路径（如 /lib, /usr/lib）
                通过设置 CMAKE_INSTALL_RPATH，你直接影响了搜索的​​最高优先级路径​​，确保了程序在安装后能优先从你指定的位置加载库。
        2. 确认缺少哪里动态库
            ```
            ldd /root/taihe_bangson/work_space/install/your_ros_project_name/lib/your_ros_project_name/your_ros_project_name
            ```
            
        

常用cmake函数（按照使用频率排顺序）：
cmakelists必用函数：
1.