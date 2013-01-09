#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/TwoIntsAction.h>
#include <std_msgs/String.h>

static uint32_t count;
static actionlib::SimpleActionClient<actionlib::TwoIntsAction>* ac;
static actionlib::TwoIntsGoal g;

void pongCallback(const std_msgs::String::ConstPtr& msg)
{
  count++;
}

void timerCallback(const ros::TimerEvent&)
{
  ROS_INFO("Count %i", count);
  count = 0;
}

int main(int argc, char **argv)
{
  count = 0;
  ros::init(argc, argv, "ping_node");
  ros::NodeHandle n;

  ac = new actionlib::SimpleActionClient<actionlib::TwoIntsAction>("test", true);
  ROS_INFO("Waiting for server");
  ac->waitForServer();
  ROS_INFO("OK");

  ros::Timer timer = n.createTimer(ros::Duration(1.0), timerCallback);

  count = 0;

  boost::thread spin_thread(boost::bind(&ros::spin));
  while(ros::ok())
  {
    ac->sendGoal(g);
    ac->waitForResult(ros::Duration(30.0));
    count++;
  }

  return 0;
}
