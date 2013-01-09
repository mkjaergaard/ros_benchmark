#include "ros/ros.h"
#include "std_msgs/String.h"

static uint32_t count;
static ros::Publisher pong_pub;
static std_msgs::String msg;

void pingCallback(const std_msgs::String::ConstPtr& msg_)
{
  pong_pub.publish(msg);
}

int main(int argc, char **argv)
{
  count = 0;
  ros::init(argc, argv, "pong_node");
  ros::NodeHandle n;

  msg.data = "ping";

  pong_pub = n.advertise<std_msgs::String>("pong", 1000);
  ros::Subscriber sub = n.subscribe("ping", 1000, pingCallback);

  ros::spin();

  return 0;
}
