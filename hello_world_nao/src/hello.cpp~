#include "ros/ros.h"
#include "std_msgs/String.h"

// Name of the ROS topic for receiving requests.
#define REQUEST_TOPIC "/speech"



class Client{
public:
	Client(){
		_pub = _nh.advertise<std_msgs::String>(REQUEST_TOPIC, 1000);	
		
	}
	~Client(){}	
	void sendRequest(){
		std::string msg;
		std::cout<<"Enter path to a \n";
		std::cin>>msg;
		if(msg == "q"){
			// Shut down the node.
        		ros::shutdown();
    		}
    		else{
			std_msgs::String str;
			str.data=msg;
			_pub.publish(str);
			std::cout << "Sending...\n";
		}	
	}

private:
	ros::Publisher _pub;
	ros::NodeHandle _nh;
};

int main(int argc, char **argv)
{
	std::string a;
	ros::init(argc, argv, "client");
	ros::NodeHandle n;
	
	Client client;
	while(ros::ok()){
		client.sendRequest();
        }

    	// Let ROS take over and execute callbacks.
    	ros::spin();
	
  return 0;
}
