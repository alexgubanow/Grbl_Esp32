#pragma once
// clang-format off

/*
    tapster3.h

    2019    - Bart Dring, Jason Huggins (Tapster Robotics)

    Grbl_ESP32 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    Grbl is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with Grbl_ESP32.  If not, see <http://www.gnu.org/licenses/>.
*/
#define MACHINE_NAME            "Tapster 3 Delta (Dynamixel)"

#define CUSTOM_CODE_FILENAME "Custom/parallel_delta.cpp"

#define N_AXIS 3

// ================= Firmware Customization ===================

#define USE_KINEMATICS				// there are kinematic equations for this machine
#define USE_FWD_KINEMATICS   // report in cartesian
#define USE_MACHINE_INIT			// There is some custom initialization for this machine	
	
// ================== Delta Geometry ===========================

#define RADIUS_FIXED    70.0;   // radius of the fixed side (length of motor cranks)
#define RADIUS_EFF      133.5;  // radius of end effector side (length of linkages)
#define LENGTH_FIXED_SIDE   179.437f;  // sized of fixed side triangel
#define LENGTH_EFF_SIDE     86.6025f;  // size of end effector side triangle
#define SEGMENT_LENGTH 0.5 // segment length in mm
#define MAX_NEGATIVE_ANGLE -45 // in negative radians how far can the arms go up before damaging machine (max pi/2) 

// =================== Machine Hardware Definition =============

#define DYNAMIXEL_TXD           GPIO_NUM_4
#define DYNAMIXEL_RXD           GPIO_NUM_13
#define DYNAMIXEL_RTS           GPIO_NUM_17

#define X_DYNAMIXEL_ID          1 // protocol ID
#define Y_DYNAMIXEL_ID          2 // protocol ID
#define Z_DYNAMIXEL_ID          3 // protocol ID

// limit servo to 180 degree motion
#define DXL_COUNT_MIN           1024      
#define DXL_COUNT_MAX           3072

#define SERVO_TIMER_INTERVAL 70

#define USER_DIGITAL_PIN_0      GPIO_NUM_25
#define USER_DIGITAL_PIN_1      GPIO_NUM_26
#define USER_DIGITAL_PIN_2      GPIO_NUM_27

#define USER_ANALOG_PIN_0       GPIO_NUM_2
#define USER_ANALOG_PIN_0_FREQ  50              // for use with RC servos duty range 5% to 10% 

#define USER_ANALOG_PIN_1       GPIO_NUM_15
#define USER_ANALOG_PIN_1_FREQ  50              // for use with RC servos duty range 5% to 10% 

#define USER_ANALOG_PIN_2       GPIO_NUM_16
#define USER_ANALOG_PIN_2_FREQ  50              // for use with RC servos duty range 5% to 10% 

// ===================== Default Settings ==============================

#define DEFAULT_STEP_PULSE_MICROSECONDS 3 
#define DEFAULT_STEPPER_IDLE_LOCK_TIME 200 // 200ms

#define DEFAULT_STATUS_REPORT_MASK 1

#define DEFAULT_STEPPING_INVERT_MASK 0 // uint8_t
#define DEFAULT_DIRECTION_INVERT_MASK 0 // uint8_t
#define DEFAULT_INVERT_ST_ENABLE 0 // boolean

#define DEFAULT_SOFT_LIMIT_ENABLE 0 // false
#define DEFAULT_HARD_LIMIT_ENABLE 0  // false

#define DEFAULT_HOMING_ENABLE 0
#define DEFAULT_HOMING_DIR_MASK 0

// the following must have the same values for each axis

#define DEFAULT_X_STEPS_PER_MM 800 // value is actually arbitrary, but keep it smallish
#define DEFAULT_Y_STEPS_PER_MM DEFAULT_X_STEPS_PER_MM
#define DEFAULT_Z_STEPS_PER_MM DEFAULT_X_STEPS_PER_MM

#define DEFAULT_X_MAX_RATE 200.0 // units/min
#define DEFAULT_Y_MAX_RATE DEFAULT_X_MAX_RATE
#define DEFAULT_Z_MAX_RATE DEFAULT_X_MAX_RATE

#define DEFAULT_X_ACCELERATION      200.0 // 10*60*60 mm/min^2 = 10 mm/sec^2
#define DEFAULT_Y_ACCELERATION      DEFAULT_X_ACCELERATION // 10*60*60 mm/min^2 = 10 mm/sec^2
#define DEFAULT_Z_ACCELERATION      DEFAULT_X_ACCELERATION

#define DEFAULT_X_MAX_TRAVEL 3.14159265 // 180° in radians 
#define DEFAULT_Y_MAX_TRAVEL DEFAULT_X_MAX_TRAVEL // 
#define DEFAULT_Z_MAX_TRAVEL DEFAULT_X_MAX_TRAVEL // 

#define ARM_INTERNAL_ANGLE 2.866  // due to mounting angle 

#define DEFAULT_X_HOMING_MPOS (DEFAULT_X_MAX_TRAVEL / 2.0)
#define DEFAULT_Y_HOMING_MPOS DEFAULT_X_HOMING_MPOS
#define DEFAULT_Z_HOMING_MPOS DEFAULT_X_HOMING_MPOS

#define SPINDLE_TYPE    SpindleType::NONE