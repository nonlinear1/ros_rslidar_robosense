/* 
*
*   Copyright (C) 2018 Southeast University, Suo_ivy
*   License: Modified BSD Software License Agreement
*
*/

/*  
   This ROS node converts PointCloud2 to PCL:rangeimage

*/

#ifndef _TORANGE_H_
#define _TORANGE_H_

#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/Image.h>
#include <pcl/point_types.h>
#include <pcl/range_image/range_image.h>
#include <pcl/visualization/range_image_visualizer.h>
#include <pcl_ros/point_cloud.h>
#include <pcl_ros/impl/transforms.hpp>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/console/parse.h>

namespace rslidar_rangeimage
{
    class RangeConvert 
    {
    public:
        RangeConvert(ros::NodeHandle node, int argc, char** argv);

        ~RangeConvert(){}

    private:

        void printUsage(const char* Nodename);
        void Conversion(const sensor_msgs::PointCloud2::ConstPtr &pointMsg);

        ros::Subscriber rslidar_pointcloud_;
        ros::Publisher range_image_;
        pcl::visualization::RangeImageVisualizer rangevisual;

        // Rangeimage Config Parameters
        float angular_resolution_x,
              angular_resolution_y;
        float max_angle_width;
        float max_angle_height;
        Eigen::Affine3f sensor_pose;
        pcl::RangeImage::CoordinateFrame coordinate_frame;
        float nosie_level;
        float min_range;
        int border_size;

    };
}
#endif