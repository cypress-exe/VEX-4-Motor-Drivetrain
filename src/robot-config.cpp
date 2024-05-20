#include "vex.h"

#include "robot-config.h"

using namespace vex;

// A global instance of the brain
brain Brain;

// VEXcode device constructors

// Controller
controller Controller1 = controller(primary);

// Motors
// motor LeftDriveMotor = motor(PORT__, ratio18_1, false);
// motor RightDriveMotor = motor(PORT__, ratio18_1, true);