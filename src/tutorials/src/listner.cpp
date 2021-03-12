//
// Created by sajith on 3/12/21.
//


#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallBack(const std_msgs::String::ConstPtr &);

int main(int arg, char **argv)
{

    ros::init(arg, argv, "listner");

    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallBack);

    ros::spin();

    return 0;
}


void chatterCallBack(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());
}