allStarts = list()
allNames = list()

with open("dump.txt", 'r', encoding='UTF-8') as file:
    while line:=file.readline():
        splitStr = line.split()
        size = len(splitStr)
        if size == 6:
            allStarts.append(int(splitStr[0], 16))
            allNames.append(splitStr[5])
        elif size == 5:
            allStarts.append(int(splitStr[0], 16))
            allNames.append(splitStr[4])

target = 0x80A726F

it = 0
total = len(allStarts)
closestName = ""
closestDistance = -1
while it < total:
    if target >= allStarts[it]:
        distance = target - allStarts[it]
        if closestDistance == -1:
            closestDistance = distance
            closestName = allNames[it]
        elif distance < closestDistance:
            closestDistance = distance
            closestName = allNames[it]
    it += 1
print(closestName)
