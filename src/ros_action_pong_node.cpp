#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <actionlib/TwoIntsAction.h>
#include <std_msgs/String.h>

static uint32_t count;
static actionlib::SimpleActionServer<actionlib::TwoIntsAction>* ac;
static actionlib::TwoIntsResult r;

void pongCallback(const boost::shared_ptr<const actionlib::TwoIntsGoal> msg)
{
  count++;
  ac->setSucceeded(r);
}

int main(int argc, char **argv)
{
  count = 0;
  ros::init(argc, argv, "pong_node");
  ros::NodeHandle n;

  ac = new actionlib::SimpleActionServer<actionlib::TwoIntsAction>(n, "test", boost::bind(&pongCallback, _1), false);
  ac->start();
  ROS_INFO("Starting");

  ros::spin();

  return 0;
}
