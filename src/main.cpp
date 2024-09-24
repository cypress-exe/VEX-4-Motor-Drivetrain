#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

void pre_auton(void) {

}

void autonomous(void) {
  
}

void usercontrol(void) {
  const float robotSpeed = 1;
  const float driveSpeed = 1;
  const float turnSpeed = 1;

  while (1) {
    // Drivetrain code
    float drive = Controller1.Axis3.position();
    float turn = Controller1.Axis1.position();

    drive *= driveSpeed * robotSpeed;
    turn *= turnSpeed * robotSpeed;

    LeftFrontDriveMotor.setVelocity(drive + turn, percent);
    LeftRearDriveMotor.setVelocity(drive + turn, percent);
    RightFrontDriveMotor.setVelocity(drive - turn, percent); 
    RightRearDriveMotor.setVelocity(drive - turn, percent);

    LeftFrontDriveMotor.spin(forward);
    LeftRearDriveMotor.spin(forward);
    RightFrontDriveMotor.spin(forward);
    RightRearDriveMotor.spin(forward);

    wait(2, msec);
  }
}

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
