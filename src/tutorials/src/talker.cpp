//
// Created by sajith on 3/12/21.
//

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int args, char **argv)
{

    // Init ROS
    ros::init(args, argv, "talker");

    // Node Handler
    ros::NodeHandle n;

    // ROS publisher
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

    // Set frequency
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "Hello world" << count;
        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());

        chatter_pub.publish(msg);

        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }

    return 0;
}