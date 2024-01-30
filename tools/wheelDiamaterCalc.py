import math
from tabulate import tabulate


def wheelDiamaterCalc(accuracy):
    diamater = 2 * (accuracy / (1.8 * (math.pi / 180)))
    return diamater


def accuracyCalculator(diamater):
    linearAccuracy = (diamater / 2) * (1.8 * (math.pi / 180))
    return linearAccuracy

dataList = [
    [0.1, wheelDiamaterCalc(0.1)],
    [0.2, wheelDiamaterCalc(0.2)],
    [0.3, wheelDiamaterCalc(0.3)],
    [0.4, wheelDiamaterCalc(0.4)],
    [0.5, wheelDiamaterCalc(0.5)],
    [0.6, wheelDiamaterCalc(0.6)],
    [0.7, wheelDiamaterCalc(0.7)],
    [0.8, wheelDiamaterCalc(0.8)],
    [0.9, wheelDiamaterCalc(0.9)],
    [1, wheelDiamaterCalc(1)],
]
LinearToDiamatertable = tabulate(dataList, headers=['LinearAccuracy(mm)', 'Diamater(mm)'])
print(LinearToDiamatertable);

