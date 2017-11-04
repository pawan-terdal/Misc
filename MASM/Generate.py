import math
i = 0
while i < 360:
    x = 127 + 127 * math.sin(math.radians(i))
    i += 6
    print('0' + str(hex(int(x))[2:]) + 'h, ', end='')
