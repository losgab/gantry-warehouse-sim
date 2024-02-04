import json

file = open("stepper_output.json", 'w')

stepper_driver_conversion = {}

FULL_STEP_RESOLUTION = 1.8
HALF_STEP_RESOLUTION = 0.9
QUARTER_STEP_RESOLUTION = 0.45

# Error can be mapped to the modulus of the target angle
# When error < 4, error is negative
# When error > 4, error is positive
hard_map = [0, -0.1, -0.2, -0.3, -0.4, 0.4, 0.3, 0.2, 0.1]

def round_to_stepper_res(angle: float, step_resolution: float) -> float:
    rounded = round(angle / step_resolution) * step_resolution
    return rounded

def steps_req(angle: float, step_resolution: float) -> int:
    return angle / step_resolution

def degree_error(angle, stepper_angle):
    return (angle - stepper_angle)

def convert_stepper_angle(target_angle: int, step_resolution: float) -> float:
    error = hard_map[target_angle % 9]
    return target_angle + error

print("---------------------------")
for i in range(0, 91, 1):
    converted_angle = convert_stepper_angle(i, HALF_STEP_RESOLUTION)
    steps_required = steps_req(converted_angle, HALF_STEP_RESOLUTION)
    error = degree_error(i, converted_angle)
    print(f"Target Angle: {int(i)} | Converted Angle: {converted_angle} | Steps Req: {round(steps_required)}")
    stepper_driver_conversion["[" + str(i) + "] Computed Stepper Degree"] = round(converted_angle, 1)
    stepper_driver_conversion["[" + str(i) + "] Steps Required"] = round(steps_required, 1)
    stepper_driver_conversion["[" + str(i) + "] Error"] = round(error, 1)
print("---------------------------")

json.dump(stepper_driver_conversion, file)
