#ifndef OROCOS_RTT_ROS_TALKER_TEST_COMPONENT_HPP
#define OROCOS_RTT_ROS_TALKER_TEST_COMPONENT_HPP

#include <rtt/RTT.hpp>
#include <rtt/Port.hpp>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/String.h>
#include <iostream>
#include <string>

class Rtt_ros_talker_test
    : public RTT::TaskContext
{
 public:

    RTT::OutputPort< std_msgs::String > out_str;
    RTT::OutputPort< std_msgs::Float64MultiArray > out_dbl;

	std_msgs::String _str;
	std_msgs::Float64MultiArray _dbl;

    Rtt_ros_talker_test(std::string const& name);
    bool configureHook();
    bool startHook();
    void updateHook();
    void stopHook();
    void cleanupHook();
};

#endif
