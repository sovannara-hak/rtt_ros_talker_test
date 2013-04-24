#include "rtt_ros_talker_test-component.hpp"
#include <rtt/Component.hpp>

/*
 * Using this macro, only one component may live
 * in one library *and* you may *not* link this library
 * with another component library. Use
 * ORO_CREATE_COMPONENT_TYPE()
 * ORO_LIST_COMPONENT_TYPE(Rtt_ros_talker_test)
 * In case you want to link with another library that
 * already contains components.
 *
 * If you have put your component class
 * in a namespace, don't forget to add it here too:
 */
Rtt_ros_talker_test::Rtt_ros_talker_test(std::string const& name)
	: TaskContext(name)
{
	_dbl.data.resize(3);
	_str.data = "Salut";
	this->addPort("str", out_str);
	this->addPort("dbl", out_dbl);
	std::cout << "Rtt_ros_talker_test constructed !" <<std::endl;
}

bool Rtt_ros_talker_test::configureHook() {
	std::cout << "Rtt_ros_talker_test configured !" <<std::endl;
	return true;
}

bool Rtt_ros_talker_test::startHook() {
	std::cout << "Rtt_ros_talker_test started !" <<std::endl;
	return true;
}

void Rtt_ros_talker_test::updateHook() {
	std::cout << "Rtt_ros_talker_test executes updateHook !" <<std::endl;
	std_msgs::Float64 off;
	off.data = 0.1;

	_dbl.data[0] += off.data;
	_dbl.data[1] += 2*off.data;
	_dbl.data[2] += 3*off.data;

	out_dbl.write(_dbl);
	out_str.write(_str);
}

void Rtt_ros_talker_test::stopHook() {
	std::cout << "Rtt_ros_talker_test executes stopping !" <<std::endl;
}

void Rtt_ros_talker_test::cleanupHook() {
	std::cout << "Rtt_ros_talker_test cleaning up !" <<std::endl;
}

ORO_CREATE_COMPONENT(Rtt_ros_talker_test)
