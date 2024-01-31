from math import floor
import json

file = open("stepper_output.json", 'w')

stepper_driver_conversion = {}

STEP_RESOLUTION = 0.9

DEGREE_0 = 90
DEGREE_1 = 91
DEGREE_2 = 92

def round_to_stepper_res(angle: float) -> float:
    rounded = round(angle / STEP_RESOLUTION) * STEP_RESOLUTION
    return rounded

def steps_req(angle):
    return angle / 1.8

def degree_error(angle, stepper_angle):
    return abs(angle - stepper_angle)

print("---------------------------")
for i in range(0, 91, 1):
    stepper_angle = round_to_stepper_res(i)
    steps_required = steps_req(stepper_angle)
    error = degree_error(i, stepper_angle)
    stepper_driver_conversion["[" + str(i) + "] Computed Stepper Degree"] = round(stepper_angle, 1)
    stepper_driver_conversion["[" + str(i) + "] Steps Required"] = round(steps_required, 1)
    stepper_driver_conversion["[" + str(i) + "] Error"] = round(error, 2)
    # print(f"[{i}] Steps Required: {steps_req(result)}")
print("---------------------------")

json.dump(stepper_driver_conversion, file)
