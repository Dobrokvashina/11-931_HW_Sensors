#include <ros.h>
#include <ros/time.h>
#include <sensor_msgs/Range.h>
#include <sensor_msgs/Temperature.h>
#include <math.h>

ros::NodeHandle  nh;

sensor_msgs::Range range_msg;
ros::Publisher pub_range( "/sound", &range_msg);
sensor_msgs::Temperature temp_msg;
ros::Publisher pub_temp( "/temperature", &temp_msg);


double Thermistor(int RawADC) {
double Temp;
Temp = log(10000.0*((1024.0/RawADC-1)));
Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
Temp = 310 - Temp; // преобразуем Кельвин в Цельсий

return Temp;
}

void setup() {
  
  nh.initNode();
  nh.advertise(pub_range);
  nh.advertise(pub_temp);
  
  range_msg.radiation_type = sensor_msgs::Range::ULTRASOUND;
  range_msg.header.frame_id =  "sound";
  range_msg.min_range = 0;
  range_msg.max_range = 1000;
  temp_msg.header.frame_id =  "temperature";
}

void loop() {
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  int sound = analogRead(A0);
  int readVal= analogRead(A5);

  range_msg.range = sound;
  range_msg.header.stamp = nh.now();
  pub_range.publish(&range_msg);
  
  temp_msg.temperature = Thermistor(readVal);
 
  temp_msg.header.stamp = nh.now();
  
  pub_temp.publish(&temp_msg);
  
  nh.spinOnce();
}
