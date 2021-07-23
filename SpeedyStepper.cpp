
#include "SpeedyStepper.h"


SpeedyStepper::SpeedyStepper()
{
  //
  // initialize constants
  //
  stepPin = 0;
  directionPin = 0;
  stepsPerRevolution = 200.0;
  stepsPerMillimeter = 25.0;
  currentPosition_InSteps = 0;
  desiredSpeed_InStepsPerSecond = 200.0;
  acceleration_InStepsPerSecondPerSecond = 200.0;
  currentStepPeriod_InUS = 0.0;
}



//
// connect the stepper object to the IO pins
//  Enter:  stepPinNumber = IO pin number for the Step
//          directionPinNumber = IO pin number for the direction bit
//          enablePinNumber = IO pin number for the enable bit (LOW is enabled)
//            set to 0 if enable is not supported
//
void SpeedyStepper::connectToPins(byte stepPinNumber, byte directionPinNumber)
{
  //
  // remember the pin numbers
  //
  stepPin = stepPinNumber;
  directionPin = directionPinNumber;

  //
  // configure the IO bits
  //
  pinMode(stepPin, OUTPUT);
  digitalWrite(stepPin, LOW);

  pinMode(directionPin, OUTPUT);
  digitalWrite(directionPin, LOW);
}


// ---------------------------------------------------------------------------------
//                     Public functions with units in millimeters
// ---------------------------------------------------------------------------------


//
// set the number of steps the motor has per millimeter
//
void SpeedyStepper::setStepsPerMillimeter(float motorStepPerMillimeter)
{
  stepsPerMillimeter = motorStepPerMillimeter;
}



//
// get the current position of the motor in millimeter, this functions is updated
// while the motor moves
//  Exit:  a signed motor position in millimeter returned
//
float SpeedyStepper::getCurrentPositionInMillimeters()
{
  return((float)currentPosition_InSteps / stepsPerMillimeter);
}



//
// set current position of the motor in millimeter, this does not move the motor
//
void SpeedyStepper::setCurrentPositionInMillimeters(float currentPositionInMillimeter)
{
  currentPosition_InSteps = (long) round(currentPositionInMillimeter *
			    stepsPerMillimeter);
}



//
// set the maximum speed, units in millimeters/second, this is the maximum speed
// reached while accelerating
// Note: this can only be called when the motor is stopped
//  Enter:  speedInMillimetersPerSecond = speed to accelerate up to, units in
//          millimeters/second
//
void SpeedyStepper::setSpeedInMillimetersPerSecond(float speedInMillimetersPerSecond)
{
  desiredSpeed_InStepsPerSecond = speedInMillimetersPerSecond * stepsPerMillimeter;
}



//
// set the rate of acceleration, units in millimeters/second/second
// Note: this can only be called when the motor is stopped
//  Enter:  accelerationInMillimetersPerSecondPerSecond = rate of acceleration,
//          units in millimeters/second/second
//
void SpeedyStepper::setAccelerationInMillimetersPerSecondPerSecond(
                      float accelerationInMillimetersPerSecondPerSecond)
{
    acceleration_InStepsPerSecondPerSecond =
      accelerationInMillimetersPerSecondPerSecond * stepsPerMillimeter;
}



//
// home the motor by moving until the homing sensor is activated, then set the
// position to zero, with units in millimeters
//  Enter:  directionTowardHome = 1 to move in a positive direction, -1 to move in
//             a negative directions
//          speedInMillimetersPerSecond = speed to accelerate up to while moving
//             toward home, units in millimeters/second
//          maxDistanceToMoveInMillimeters = unsigned maximum distance to move
//             toward home before giving up
//          homeSwitchPin = pin number of the home switch, switch should be
//             configured to go low when at home
//  Exit:   true returned if successful, else false
//
bool SpeedyStepper::moveToHomeInMillimeters(long directionTowardHome,
  float speedInMillimetersPerSecond, long maxDistanceToMoveInMillimeters,
  int homeLimitSwitchPin)
{
  return(moveToHomeInSteps(directionTowardHome,
                          speedInMillimetersPerSecond * stepsPerMillimeter,
                          maxDistanceToMoveInMillimeters * stepsPerMillimeter,
                          homeLimitSwitchPin));
}



//
// move relative to the current position, units are in millimeters, this function
// does not return until the move is complete
//  Enter:  distanceToMoveInMillimeters = signed distance to move relative to the
//          current position in millimeters
//
void SpeedyStepper::moveRelativeInMillimeters(float distanceToMoveInMillimeters)
{
  setupRelativeMoveInMillimeters(distanceToMoveInMillimeters);

  while(!processMovement())
    ;
}



//
// setup a move relative to the current position, units are in millimeters, no
// motion occurs until processMove() is called
// Note: this can only be called when the motor is stopped
//  Enter:  distanceToMoveInMillimeters = signed distance to move relative to the
//            currentposition in millimeters
//
void SpeedyStepper::setupRelativeMoveInMillimeters(float distanceToMoveInMillimeters)
{
  setupRelativeMoveInSteps((long) round(distanceToMoveInMillimeters *
			   stepsPerMillimeter));
}



//
// move to the given absolute position, units are in millimeters, this function
// does not return until the move is complete
//  Enter:  absolutePositionToMoveToInMillimeters = signed absolute position to
//            move toin units of millimeters
//
void SpeedyStepper::moveToPositionInMillimeters(
                      float absolutePositionToMoveToInMillimeters)
{
  setupMoveInMillimeters(absolutePositionToMoveToInMillimeters);

  while(!processMovement())
    ;
}



//
// setup a move, units are in millimeters, no motion occurs until processMove() is
// called.  Note: this can only be called when the motor is stopped
//  Enter:  absolutePositionToMoveToInMillimeters = signed absolute position to move
//          to in units of millimeters
//
void SpeedyStepper::setupMoveInMillimeters(
                      float absolutePositionToMoveToInMillimeters)
{
 setupMoveInSteps((long) round(absolutePositionToMoveToInMillimeters *
   stepsPerMillimeter));
}



//
// Get the current velocity of the motor in millimeters/second.  This functions is
// updated while it accelerates up and down in speed.  This is not the desired
// speed, but the speed the motor should be moving at the time the function is
// called.  This is a signed value and is negative when motor is moving backwards.
// Note: This speed will be incorrect if the desired velocity is set faster than
// this library can generate steps, or if the load on the motor is too great for
// the amount of torque that it can generate.
//  Exit:  velocity speed in millimeters per second returned, signed
//
float SpeedyStepper::getCurrentVelocityInMillimetersPerSecond()
{
  return(getCurrentVelocityInStepsPerSecond() / stepsPerMillimeter);
}



// ---------------------------------------------------------------------------------
//                     Public functions with units in revolutions
// ---------------------------------------------------------------------------------


//
// set the number of steps the motor has per revolution
//
void SpeedyStepper::setStepsPerRevolution(float motorStepPerRevolution)
{
  stepsPerRevolution = motorStepPerRevolution;
}



//
// get the current position of the motor in revolutions, this functions is updated
// while the motor moves
//  Exit:  a signed motor position in revolutions returned
//
float SpeedyStepper::getCurrentPositionInRevolutions()
{
  return((float)currentPosition_InSteps / stepsPerRevolution);
}



//
// set current position of the motor in revolutions, this does not move the motor
//
void SpeedyStepper::setCurrentPositionInRevolutions(
   float currentPositionInRevolutions)
{
  currentPosition_InSteps = (long) round(
    currentPositionInRevolutions * stepsPerRevolution);
}



//
// set the maximum speed, units in revolutions/second, this is the maximum speed
// reached while accelerating.  Note: this can only be called when the motor is
// stopped
//  Enter:  speedInRevolutionsPerSecond = speed to accelerate up to, units in
//            revolutions/second
//
void SpeedyStepper::setSpeedInRevolutionsPerSecond(float speedInRevolutionsPerSecond)
{
  desiredSpeed_InStepsPerSecond = speedInRevolutionsPerSecond * stepsPerRevolution;
}



//
// set the rate of acceleration, units in revolutions/second/second
// Note: this can only be called when the motor is stopped
//  Enter:  accelerationInRevolutionsPerSecondPerSecond = rate of acceleration,
//            units inrevolutions/second/second
//
void SpeedyStepper::setAccelerationInRevolutionsPerSecondPerSecond(
                      float accelerationInRevolutionsPerSecondPerSecond)
{
    acceleration_InStepsPerSecondPerSecond =
       accelerationInRevolutionsPerSecondPerSecond * stepsPerRevolution;
}



//
// home the motor by moving until the homing sensor is activated, then set the
// position to zero, with units in revolutions
//  Enter:  directionTowardHome = 1 to move in a positive direction, -1 to move in
//             a negative directions
//          speedInRevolutionsPerSecond = speed to accelerate up to while moving
//             toward home, units in revolutions/second
//          maxDistanceToMoveInRevolutions = unsigned maximum distance to move
//             toward home before giving up
//          homeSwitchPin = pin number of the home switch, switch should be
//             configured to go low when at home
//  Exit:   true returned if successful, else false
//
bool SpeedyStepper::moveToHomeInRevolutions(long directionTowardHome,
  float speedInRevolutionsPerSecond, long maxDistanceToMoveInRevolutions,
  int homeLimitSwitchPin)
{
  return(moveToHomeInSteps(directionTowardHome,
                          speedInRevolutionsPerSecond * stepsPerRevolution,
                          maxDistanceToMoveInRevolutions * stepsPerRevolution,
                          homeLimitSwitchPin));
}



//
// move relative to the current position, units are in revolutions, this function
// does not return until the move is complete
//  Enter:  distanceToMoveInRevolutions = signed distance to move relative to the
//          current position in revolutions
//
void SpeedyStepper::moveRelativeInRevolutions(float distanceToMoveInRevolutions)
{
  setupRelativeMoveInRevolutions(distanceToMoveInRevolutions);

  while(!processMovement())
    ;
}



//
// setup a move relative to the current position, units are in revolutions, no
// motion occurs until processMove() is called.  Note: this can only be called
// when the motor is stopped
//  Enter:  distanceToMoveInRevolutions = signed distance to move relative to the
//          current position in revolutions
//
void SpeedyStepper::setupRelativeMoveInRevolutions(float distanceToMoveInRevolutions)
{
  setupRelativeMoveInSteps((long) round(distanceToMoveInRevolutions *
                           stepsPerRevolution));
}



//
// move to the given absolute position, units are in revolutions, this function
// does not return until the move is complete
//  Enter:  absolutePositionToMoveToInRevolutions = signed absolute position to
//          move to in units of revolutions
//
void SpeedyStepper::moveToPositionInRevolutions(
       float absolutePositionToMoveToInRevolutions)
{
  setupMoveInRevolutions(absolutePositionToMoveToInRevolutions);

  while(!processMovement())
    ;
}



//
// setup a move, units are in revolutions, no motion occurs until processMove() is
// called.  Note: this can only be called when the motor is stopped
//  Enter:  absolutePositionToMoveToInRevolutions = signed absolute position to
//          move to inunits of revolutions
//
void SpeedyStepper::setupMoveInRevolutions(
          float absolutePositionToMoveToInRevolutions)
{
 setupMoveInSteps((long) round(absolutePositionToMoveToInRevolutions *
                   stepsPerRevolution));
}



//
// Get the current velocity of the motor in revolutions/second.  This functions is
// updated while it accelerates up and down in speed.  This is not the desired
// speed, but the speed the motor should be moving at the time the function is
// called.  This is a signed value and is negative when motor is moving backwards.
// Note: This speed will be incorrect if the desired velocity is set faster than
// this library can generate steps, or if the load on the motor is too great for
// the amount of torque that it can generate.
//  Exit:  velocity speed in revolutions per second returned, signed
//
float SpeedyStepper::getCurrentVelocityInRevolutionsPerSecond()
{
  return(getCurrentVelocityInStepsPerSecond() / stepsPerRevolution);
}



// ---------------------------------------------------------------------------------
//                        Public functions with units in steps
// ---------------------------------------------------------------------------------


//
// set the current position of the motor in steps, this does not move the motor
// Note: This function should only be called when the motor is stopped
//    Enter:  currentPositionInSteps = the new position of the motor in steps
//
void SpeedyStepper::setCurrentPositionInSteps(long currentPositionInSteps)
{
  currentPosition_InSteps = currentPositionInSteps;
}



//
// get the current position of the motor in steps, this functions is updated
// while the motor moves
//  Exit:  a signed motor position in steps returned
//
long SpeedyStepper::getCurrentPositionInSteps()
{
  return(currentPosition_InSteps);
}



//
// setup a "Stop" to begin the process of decelerating from the current velocity to
// zero, decelerating requires calls to processMove() until the move is complete
// Note: This function can be used to stop a motion initiated in units of steps or
// revolutions
//
void SpeedyStepper::setupStop()
{
  //
  // move the target position so that the motor will begin deceleration now
  //
  if (direction_Scaler > 0)
    targetPosition_InSteps = currentPosition_InSteps + decelerationDistance_InSteps;
  else
    targetPosition_InSteps = currentPosition_InSteps - decelerationDistance_InSteps;
}



//
// set the maximum speed, units in steps/second, this is the maximum speed reached
// while accelerating
// Note: this can only be called when the motor is stopped
//  Enter:  speedInStepsPerSecond = speed to accelerate up to, units in steps/second
//
void SpeedyStepper::setSpeedInStepsPerSecond(float speedInStepsPerSecond)
{
  desiredSpeed_InStepsPerSecond = speedInStepsPerSecond;
}



//
// set the rate of acceleration, units in steps/second/second
// Note: this can only be called when the motor is stopped
//  Enter:  accelerationInStepsPerSecondPerSecond = rate of acceleration, units in
//          steps/second/second
//
void SpeedyStepper::setAccelerationInStepsPerSecondPerSecond(
                      float accelerationInStepsPerSecondPerSecond)
{
    acceleration_InStepsPerSecondPerSecond = accelerationInStepsPerSecondPerSecond;
}



//
// home the motor by moving until the homing sensor is activated, then set the
// position to zero with units in steps
//  Enter:  directionTowardHome = 1 to move in a positive direction, -1 to move in
//             a negative directions
//          speedInStepsPerSecond = speed to accelerate up to while moving toward
//             home, units in steps/second
//          maxDistanceToMoveInSteps = unsigned maximum distance to move toward
//             home before giving up
//          homeSwitchPin = pin number of the home switch, switch should be
//             configured to go low when at home
//  Exit:   true returned if successful, else false
//
bool SpeedyStepper::moveToHomeInSteps(long directionTowardHome,
  float speedInStepsPerSecond, long maxDistanceToMoveInSteps, int homeLimitSwitchPin)
{
  float originalDesiredSpeed_InStepsPerSecond;
  bool limitSwitchFlag;


  //
  // setup the home switch input pin
  //
  pinMode(homeLimitSwitchPin, INPUT_PULLUP);


  //
  // remember the current speed setting
  //
  originalDesiredSpeed_InStepsPerSecond = desiredSpeed_InStepsPerSecond;


  //
  // if the home switch is not already set, move toward it
  //
  if (digitalRead(homeLimitSwitchPin) == HIGH)
  {
    //
    // move toward the home switch
    //
    setSpeedInStepsPerSecond(speedInStepsPerSecond);
    setupRelativeMoveInSteps(maxDistanceToMoveInSteps * directionTowardHome);
    limitSwitchFlag = false;
    while(!processMovement())
    {
      if (digitalRead(homeLimitSwitchPin) == LOW)
      {
        limitSwitchFlag = true;
        break;
      }
    }

    //
    // check if switch never detected
    //
    if (limitSwitchFlag == false)
      return(false);
  }
  delay(25);


  //
  // the switch has been detected, now move away from the switch
  //
  setupRelativeMoveInSteps(maxDistanceToMoveInSteps * directionTowardHome * -1);
  limitSwitchFlag = false;
  while(!processMovement())
  {
    if (digitalRead(homeLimitSwitchPin) == HIGH)
    {
      limitSwitchFlag = true;
      break;
    }
  }
  delay(25);

  //
  // check if switch never detected
  //
  if (limitSwitchFlag == false)
    return(false);


  //
  // have now moved off the switch, move toward it again but slower
  //
  setSpeedInStepsPerSecond(speedInStepsPerSecond/8);
  setupRelativeMoveInSteps(maxDistanceToMoveInSteps * directionTowardHome);
  limitSwitchFlag = false;
  while(!processMovement())
  {
    if (digitalRead(homeLimitSwitchPin) == LOW)
    {
      limitSwitchFlag = true;
      break;
    }
  }
  delay(25);

  //
  // check if switch never detected
  //
  if (limitSwitchFlag == false)
    return(false);


  //
  // successfully homed, set the current position to 0
  //
  setCurrentPositionInSteps(0L);

  //
  // restore original velocity
  //
  setSpeedInStepsPerSecond(originalDesiredSpeed_InStepsPerSecond);
  return(true);
}



//
// move relative to the current position, units are in steps, this function does
// not return until the move is complete
//  Enter:  distanceToMoveInSteps = signed distance to move relative to the current
//            position in steps
//
void SpeedyStepper::moveRelativeInSteps(long distanceToMoveInSteps)
{
  setupRelativeMoveInSteps(distanceToMoveInSteps);

  while(!processMovement())
    ;
}



//
// setup a move relative to the current position, units are in steps, no motion
// occurs until processMove() is called.  Note: this can only be called when the
// motor is stopped
//  Enter:  distanceToMoveInSteps = signed distance to move relative to the current
//          position in steps
//
void SpeedyStepper::setupRelativeMoveInSteps(long distanceToMoveInSteps)
{
  setupMoveInSteps(currentPosition_InSteps + distanceToMoveInSteps);
}



//
// move to the given absolute position, units are in steps, this function does not
// return until the move is complete
//  Enter:  absolutePositionToMoveToInSteps = signed absolute position to move to
//            in units of steps
//
void SpeedyStepper::moveToPositionInSteps(long absolutePositionToMoveToInSteps)
{
  setupMoveInSteps(absolutePositionToMoveToInSteps);

  while(!processMovement())
    ;
}



//
// setup a move, units are in steps, no motion occurs until processMove() is called
// Note: this can only be called when the motor is stopped
//  Enter:  absolutePositionToMoveToInSteps = signed absolute position to move to in
//          units of steps
//
void SpeedyStepper::setupMoveInSteps(long absolutePositionToMoveToInSteps)
{
  long distanceToTravel_InSteps;


  //
  // save the target location
  //
  targetPosition_InSteps = absolutePositionToMoveToInSteps;


  //
  // determine the period in US of the first step
  //
  ramp_InitialStepPeriod_InUS =  1000000.0 / sqrt(2.0 *
                                    acceleration_InStepsPerSecondPerSecond);


  //
  // determine the period in US between steps when going at the desired velocity
  //
  desiredStepPeriod_InUS = 1000000.0 / desiredSpeed_InStepsPerSecond;


  //
  // determine the number of steps needed to go from the desired velocity down to a
  // velocity of 0, Steps = Velocity^2 / (2 * Accelleration)
  //
  decelerationDistance_InSteps = (long) round((desiredSpeed_InStepsPerSecond *
    desiredSpeed_InStepsPerSecond) / (2.0 * acceleration_InStepsPerSecondPerSecond));


  //
  // determine the distance and direction to travel
  //
  distanceToTravel_InSteps = targetPosition_InSteps - currentPosition_InSteps;
  if (distanceToTravel_InSteps < 0)
  {
    distanceToTravel_InSteps = -distanceToTravel_InSteps;
    direction_Scaler = -1;
    digitalWrite(directionPin, HIGH);
  }
  else
  {
    direction_Scaler = 1;
    digitalWrite(directionPin, LOW);
  }


  //
  // check if travel distance is too short to accelerate up to the desired velocity
  //
  if (distanceToTravel_InSteps <= (decelerationDistance_InSteps * 2L))
    decelerationDistance_InSteps = (distanceToTravel_InSteps / 2L);


  //
  // start the acceleration ramp at the beginning
  //
  ramp_NextStepPeriod_InUS = ramp_InitialStepPeriod_InUS;
  acceleration_InStepsPerUSPerUS = acceleration_InStepsPerSecondPerSecond / 1E12;
  startNewMove = true;
}



//
// if it is time, move one step
//  Exit:  true returned if movement complete, false returned not a final target
//           position yet
//
bool SpeedyStepper::processMovement(void)
{
  unsigned long currentTime_InUS;
  unsigned long periodSinceLastStep_InUS;
  long distanceToTarget_InSteps;

  //
  // check if already at the target position
  //
  if (currentPosition_InSteps == targetPosition_InSteps)
    return(true);

  //
  // check if this is the first call to start this new move
  //
  if (startNewMove)
  {
    ramp_LastStepTime_InUS = micros();
    startNewMove = false;
  }

  //
  // determine how much time has elapsed since the last step (Note 1: this method
  // works even if the time has wrapped. Note 2: all variables must be unsigned)
  //
  currentTime_InUS = micros();
  periodSinceLastStep_InUS = currentTime_InUS - ramp_LastStepTime_InUS;

  //
  // if it is not time for the next step, return
  //
  if (periodSinceLastStep_InUS < (unsigned long) ramp_NextStepPeriod_InUS)
    return(false);

  //
  // determine the distance from the current position to the target
  //
  distanceToTarget_InSteps = targetPosition_InSteps - currentPosition_InSteps;
  if (distanceToTarget_InSteps < 0)
    distanceToTarget_InSteps = -distanceToTarget_InSteps;

  //
  // test if it is time to start decelerating, if so change from accelerating to
  // decelerating
  //
  if (distanceToTarget_InSteps == decelerationDistance_InSteps)
    acceleration_InStepsPerUSPerUS = -acceleration_InStepsPerUSPerUS;

  //
  // execute the step on the rising edge
  //
  digitalWrite(stepPin, HIGH);

  //
  // delay set to almost nothing because there is so much code between rising and
  // falling edges
  delayMicroseconds(2);

  //
  // update the current position and speed
  //
  currentPosition_InSteps += direction_Scaler;
  currentStepPeriod_InUS = ramp_NextStepPeriod_InUS;


  //
  // compute the period for the next step
  // StepPeriodInUS = LastStepPeriodInUS *
  //   (1 - AccelerationInStepsPerUSPerUS * LastStepPeriodInUS^2)
  //
  ramp_NextStepPeriod_InUS = ramp_NextStepPeriod_InUS *
    (1.0 - acceleration_InStepsPerUSPerUS * ramp_NextStepPeriod_InUS *
    ramp_NextStepPeriod_InUS);


  //
  // return the step line high
  //
  digitalWrite(stepPin, LOW);


  //
  // clip the speed so that it does not accelerate beyond the desired velocity
  //
  if (ramp_NextStepPeriod_InUS < desiredStepPeriod_InUS)
    ramp_NextStepPeriod_InUS = desiredStepPeriod_InUS;


  //
  // update the acceleration ramp
  //
  ramp_LastStepTime_InUS = currentTime_InUS;


  //
  // check if move has reached its final target position, return true if all done
  //
  if (currentPosition_InSteps == targetPosition_InSteps)
  {
    currentStepPeriod_InUS = 0.0;
    return(true);
  }

  return(false);
}



//
// Get the current velocity of the motor in steps/second.  This functions is updated
// while it accelerates up and down in speed.  This is not the desired speed, but
// the speed the motor should be moving at the time the function is called.  This
// is a signed value and is negative when the motor is moving backwards.
// Note: This speed will be incorrect if the desired velocity is set faster than
// this library can generate steps, or if the load on the motor is too great for
// the amount of torque that it can generate.
//  Exit:  velocity speed in steps per second returned, signed
//
float SpeedyStepper::getCurrentVelocityInStepsPerSecond()
{
  if (currentStepPeriod_InUS == 0.0)
    return(0);
  else
  {
    if (direction_Scaler > 0)
      return(1000000.0 / currentStepPeriod_InUS);
    else
      return(-1000000.0 / currentStepPeriod_InUS);
  }
}



//
// check if the motor has competed its move to the target position
//  Exit:  true returned if the stepper is at the target position
//
bool SpeedyStepper::motionComplete()
{
  if (currentPosition_InSteps == targetPosition_InSteps)
    return(true);
  else
    return(false);
}

// -------------------------------------- End --------------------------------------
