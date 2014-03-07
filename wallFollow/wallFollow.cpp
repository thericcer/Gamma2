#include <controller.hpp>
#include <stdio.h>
#include <math.h>

Controller controller("/dev/ttyACM0");
unsigned short sensors[4] = {0};

void setDistance(void){
  controller.getSensor(2, &sensors[2]);
  controller.getSensor(3, &sensors[3]);

  if(sensors[2] > 1000){
    controller.steer(0, 0, 0, 0);
    controller.drive(150, 150, 'F', 'F');
    while(sensors[2] > 1000){
      controller.getSensor(2, &sensors[2]);
      printf("Moving Closer to wall: %10d\n", sensors[2]);
    }
    usleep(100000);
    controller.steer(90, 90, 90, 90);
    controller.drive(0, 0, 'F', 'F');
  }
  
  if(sensors[2] < 700){
    controller.steer(0, 0, 0, 0);
    controller.drive(150, 150, 'R', 'R');
    while(sensors[2] < 700){
      controller.getSensor(2, &sensors[2]);
      printf("Moving Closer to wall: %10d\n", sensors[2]);
    }
    usleep(100000);
    controller.steer(90, 90, 90, 90);
    controller.drive(0, 0, 'F', 'F');
  }
}

int main(void){

  //  setDistance();
  
  double divide = 0;

  while(1){

    controller.getSensor(2, &sensors[2]);
    controller.getSensor(3, &sensors[3]);
    
    divide = (double)sensors[2] / (double)sensors[3];
    
    printf("Divide %5f | Sensor1: %10d | Sensor2 %10d\n", divide, sensors[2], sensors[3]);
    
      //controller.steer(135, 45, 135, 45);
      //controller.drive(150, 150, 'R', 'F');
    
    

    controller.getSensor(2, &sensors[2]);
    controller.getSensor(3, &sensors[3]);
    divide = atan2((double)sensors[2]-(double)sensors[3], 900);
    printf("Divide: %f\n", divide);
    

  }
  return 0;
}
