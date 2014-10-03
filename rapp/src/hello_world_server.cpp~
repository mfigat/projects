#include "ros/ros.h"
#include "std_msgs/String.h"

// Name of the ROS topic for receiving requests.
#define REQUEST_TOPIC "/rapp/request"
// Name of the ROS topic for publishing requests.
#define RESPONSE_TOPIC "/rapp/response"


class HelloWorld{
public:
	HelloWorld(){
		sub_=nh_.subscribe(REQUEST_TOPIC, 1000, &HelloWorld::messageCallbackResponse, this);
		pub_ = nh_.advertise<std_msgs::String>(RESPONSE_TOPIC, 1000);
	}
	~HelloWorld(){}
	
	void messageCallbackResponse( const std_msgs::String::ConstPtr& msg)
	{
		ROS_INFO("Response from HOP:\n");
		std::string str=(*msg).data;
		std::cout<<str<<"\n";

		std::string msg_string="~/catkin_ws";
		std_msgs::String str_string;
		str_string.data=msg_string;
		pub_.publish(str_string);
	}

private:
	ros::Publisher pub_;
	ros::NodeHandle nh_;
	ros::Subscriber sub_;
};

int main(int argc, char **argv)
{
	std::string a;
	ros::init(argc, argv, "helloWorldServer");
	ros::NodeHandle n;
	
	HelloWorld helloWorld;

  	ROS_INFO("Starting to spin...");
	ros::spin();


  return 0;
}
