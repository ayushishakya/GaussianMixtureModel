#include "ros/ros.h"
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;


void help(){
  cout
  << "--------------------------------------------------------------------------" << endl
  << "This program shows how to use background subtraction methods provided by "  << endl
  << " OpenCV. "                                                                  << endl
                                                                                  << endl
  << "Usage:"                                                                     << endl
  << "./bs {-vid <video filename>|-img <image filename>}"                         << endl
  << "for example: ./bs -vid video.avi"                                           << endl
  << "--------------------------------------------------------------------------" << endl
  << endl;
}

int main(int argc, char ** argv)
{
 cout<<endl;
 help();

 ros::init(argc, argv, "input_image");
 ros::NodeHandle nh;
 image_transport::ImageTransport it(nh);

 image_transport::Publisher image_pub = it.advertise("input", 1);

 ros::Rate loop_rate(10);

 if(argc != 3) {
     cerr <<"Incorret input list" << endl;
     cerr <<"exiting..." << endl;
     return EXIT_FAILURE;
 }

 if(strcmp(argv[1], "-vid") == 0) {
     //input data coming from a video
     VideoCapture cap(argv[2]);
     Mat frame;

     while(nh.ok())
     {
       if(!cap.isOpened()) cout<<"nai chal rha\n";

       if(cap.read(frame)) {
       sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();

       image_pub.publish(msg);
       ROS_INFO("INPUT SENT\n");

       waitKey(1);

      }

      ros::spinOnce();
      loop_rate.sleep();
     }

 }

 else {
     //error in reading input parameters
     cerr <<"Please, check the input parameters." << endl;
     cerr <<"Exiting..." << endl;
     return EXIT_FAILURE;
 }

 return 0;

}
