#include "ros/ros.h"
#include "std_msgs/String.h"

// Name of the ROS topic for receiving requests.
#define REQUEST_TOPIC "/rapp/request"
// Name of the ROS topic for publishing requests.
#define RESPONSE_TOPIC "/rapp/response"


class HelloWorld{
public:
	HelloWorld(){
		sub_=nh_.subscribe(RESPONSE_TOPIC, 1000, &HelloWorld::messageCallbackResponse, this);
		pub_ = nh_.advertise<std_msgs::String>(REQUEST_TOPIC, 1000);
		
	}
	~HelloWorld(){}	
	void sendRequest(){
		std::string msg;
		std::cout<<"Enter a name of package (.hz)\n";
		std::cin>>msg;
		if(msg == "q"){
			// Shut down the node.
        		ros::shutdown();
    		}
    		else{
			std_msgs::String str;
			str.data=msg;
			pub_.publish(str);
			std::cout << "Downloading...\n";
		}	
	}
	void messageCallbackResponse( const std_msgs::String::ConstPtr& msg)
	{
		ROS_INFO("Response from HOP:\n");
		std::string str=(*msg).data;
		std::cout<<str<<"\n";

		if(str.empty())
			std::cout << "\e[1m\e[31m" // bold and red font
            		<< "Failed"
            		<< "\e[0m\n"; // normal print mode
		else{
			std::cout<<"The bash script: "<<str<<"/run is going to be run\n";
			str.append("/run.sh");
			str=std::string("sh ").append(str);
			system(str.c_str());
		}
		sendRequest();
	}

private:
	ros::Publisher pub_;
	ros::NodeHandle nh_;
	ros::Subscriber sub_;
};

int main(int argc, char **argv)
{
	std::string a;
	ros::init(argc, argv, "helloWorld");
	ros::NodeHandle n;
	
	HelloWorld helloWorld;
	helloWorld.sendRequest();

    	// Let ROS take over and execute callbacks.
    	ros::spin();
	
  return 0;
}
