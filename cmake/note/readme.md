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
        
常用cmake函数（按照使用频率排顺序）：
cmakelists必用函数：
1. 
