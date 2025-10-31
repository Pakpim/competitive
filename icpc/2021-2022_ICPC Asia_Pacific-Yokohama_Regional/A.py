import math

n, r = map(int, input().split())

all_volumes = 0

spheres = list()
for i in range(n):
    spheres.append([x for x in map(float, input().split())])

    all_volumes += math.pi * (r ** 3) * 4 / 3

for i in range(n):
    j = (i - 1 + n) % n

    # print("comparing:", i, j)

    d = math.sqrt((spheres[i][0] - spheres[j][0]) ** 2 + (spheres[i][1] - spheres[j][1]) ** 2 + (spheres[i][2] - spheres[j][2]) ** 2)

    if d < 2 * r:
        all_volumes -= 2 / 3 * math.pi * (r - d / 2) ** 2 * (2 * r + d / 2)

print(all_volumes)