#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/PositionSensor.hpp>
#include <iostream>

using namespace webots;

int main(int argc, char **argv) {
  Robot *robot = new Robot();
  Motor *motor = robot->getMotor("motor");
  PositionSensor *sensor = robot->getPositionSensor("sensor");
  sensor->enable(10);
  motor->setPosition(INFINITY);
  motor->setVelocity(0.0);

  while (robot->step(64) != -1) {
    double position = sensor->getValue();
    std::cout << "Position: " << position << std::endl;
    if (position < 5.0) {
      motor->setVelocity(1.0);
    } else {
      motor->setVelocity(0.0);
    }
  }

  delete robot;
  return 0;
}
