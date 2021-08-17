#include "ros/ros.h"
#include "std_msgs/String.h"
#include <geometry_msgs/Twist.h>

// State Global variable
int order = 0;
  // stop - 0 , go saright - 1, go back - 2, go right -3, go left - 4, go up - 5, go down - 6

void msgCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
  float x = msg->linear.x;
  float y = msg->linear.y;
  float z = msg->linear.z;

  if ( x > 0 && y == 0 && z == 0 )
    {
      ROS_INFO("go straight");
      order = 1;
    }
  if ( x < 0 && y == 0 && z == 0 )
    {
      ROS_INFO("go back");
      order = 2;
    }
  if ( x == 0 && y == 0 && z == 0 )
    {
      ROS_INFO("stop");
      order = 0;
    }
  if ( x == 0 && y > 0 && z == 0 )
    {
      ROS_INFO("go right");
      order = 3;
    }
  if ( x == 0 && y < 0 && z == 0 )
    {
      ROS_INFO("go left");
      order = 4;
    }
  if ( x == 0 && y == 0 && z > 0 )
    {
      ROS_INFO("go up");
      order = 5;
    }
  if ( x == 0 && y == 0 && z < 0 )
    {
      ROS_INFO("go down");
      order = 6;
    }
  std::cout << "order number is: " << order <<std::endl;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv,"teleop_listener");
  ros::NodeHandle nh;

  ros::Subscriber teleop_sub = nh.subscribe("cmd_vel", 1000, msgCallback);

  ros::spin();
  return 0;
}
