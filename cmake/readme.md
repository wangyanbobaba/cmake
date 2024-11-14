1. 目前遇到的问题：  
    编译duof  
    需要命令：cmake -D CMAKE_PREFIX_PATH=/usr -B build  
    解释：  

        -D CMAKE_PREFIX_PATH=/usr：
        设置CMAKE_PREFIX_PATH变量为/usr。这个变量通常用于指定查找库文件和头文件的路径。在这里，它告诉CMake在/usr目录下查找所需的库和头文件。  
        -B build：指定构建目录为build。这意味着CMake将在当前目录下创建一个名为build的子目录，并在其中生成构建文件和进行构建。  
        cmake命令后面没有指定CMakeLists.txt文件的路径，所以它默认会在当前目录下查找CMakeLists.txt文件。 

        这个命令的完整流程是：  
        CMake会在当前目录下查找CMakeLists.txt文件。  
        根据CMakeLists.txt中的指令，CMake会设置构建系统。  
        CMake会使用/usr作为查找库和头文件的路径。  
        CMake会在当前目录下创建一个build目录，并在其中生成构建文件（如Makefile）。  
        之后，您可以在build目录下运行make命令来编译项目  

    怎么把它写进CMakeLists.txt?
    
