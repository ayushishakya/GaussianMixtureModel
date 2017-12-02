# GaussianMixtureModel

It is a ROS based implementation of Gaussian Mixture Model(GMM) algorithm for object detection.

ROS WORKFLOW  :-

(input_image) ---(input)--->>  (object_detect) ---(state)--->> (print)

USAGE  :-

window 1:     
               rosrun </directory name/> pub -vid </location of video/>    
  
    **takes location of video as input and sends it to the node- object_detect via topic- input.
  
    
window 2:      
               rosrun </directory name/> gmm
  
    **subscribes to the topic- input, performs algorithms on the image and publishes it on the topic- state
  
  .
window 3:      
               rosrun </directory name/> sub
  
     **node print subcribes to the topic- state and prints the location of buoys in the video.
