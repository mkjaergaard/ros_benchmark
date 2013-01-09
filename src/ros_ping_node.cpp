#include "ros/ros.h"
#include "std_msgs/String.h"

static uint32_t count;
static ros::Publisher ping_pub;
static std_msgs::String msg;

void pongCallback(const std_msgs::String::ConstPtr& msg)
{
  count++;
  ping_pub.publish(msg);
}

void timerCallback(const ros::TimerEvent&)
{
  if(count == 0)
  {
    ping_pub.publish(msg);
  }
  ROS_INFO("Count %i", count);
  count = 0;
}

int main(int argc, char **argv)
{
  count = 0;
  ros::init(argc, argv, "ping_node");
  ros::NodeHandle n;

  msg.data = "ping";

  ping_pub = n.advertise<std_msgs::String>("ping", 1000);
  ros::Subscriber sub = n.subscribe("pong", 1000, pongCallback);
  ros::Timer timer = n.createTimer(ros::Duration(1.0), timerCallback);

  int count = 0;
  ping_pub.publish(msg);

  ROS_INFO("%s", msg.data.c_str());
  ros::spin();

  return 0;
}
