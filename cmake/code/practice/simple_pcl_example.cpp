#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "请提供输入和输出文件名。" << std::endl;
        return -1;
    }

    // 定义点云指针类型
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

    // 读取点云文件
    if (pcl::io::loadPCDFile<pcl::PointXYZ>(argv[1], *cloud) == -1) {
        PCL_ERROR("无法读取文件\n");
        return (-1);
    }

    std::cout << "Loaded "
              << cloud->width * cloud->height
              << " data points from " << argv[1]
              << std::endl;

    // 保存点云文件
    pcl::io::savePCDFileASCII(argv[2], *cloud);

    std::cout << "Saved "
              << cloud->width * cloud->height
              << " data points to " << argv[2]
              << std::endl;

    return 0;
}