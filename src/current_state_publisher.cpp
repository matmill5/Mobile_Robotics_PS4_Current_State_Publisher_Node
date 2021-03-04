#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <nav_msgs/Odometry.h>

ros::Publisher odom_publisher_object;
ros::Subscriber odom_subscriber_object;
    
void myCallback(const nav_msgs::Odometry& message_holder){
	ROS_INFO("Read information from 'odom' topic.");
	ROS_INFO("Publishing 'odom' info to 'current_state");
	odom_publisher_object.publish(message_holder); // Publish 'odom' topic data to 'current_state' topic     
}

int main(int argc, char **argv) {

    ros::init(argc, argv, "current_state_publisher"); // name of this node will be "current_state_publisher"
    
    ros::NodeHandle n; // two lines to create a publisher object that can talk to ROS
    
    odom_publisher_object = n.advertise<nav_msgs::Odometry>("current_state", 1);
    
    odom_subscriber_object = n.subscribe("odom",1, myCallback); // One line to create a subscriber object that can read 'odom' topic
    
    ros::spin();
}
