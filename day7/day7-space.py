
def solve(limit: int, d: dict[str, int]):
    result: int = 0
    newDict: dict[str, int] = d.copy()
    for itemI in d:
        for itemJ in d:
            if itemJ.startswith(itemI) and itemI != itemJ:
                newDict[itemI] += d[itemJ]
        if newDict[itemI] <= limit:
            result += newDict[itemI]
    print(result)
    newSpace: int = 30000000-(70000000-newDict["/()"])
    solve2(limit=newSpace, d=newDict)

def solve2(limit: int, d: dict[str, int]):
    result: int = 70000000
    for item in d:
        if d[item] > limit and result > d[item]:
            result = d[item]
    print(result)

def main():
    with open("comp.txt", "r") as f:
        temp: str = ""
        notIntialized: bool = True
        d: dict[str, int] = {}
        for line in f:
            if line[0] == "$":
                if line[2:4] == "cd" and notIntialized:
                    temp = line[5:].strip() + "()"
                    d[temp] = 0
                    notIntialized = False
                elif line[2:4] == "cd" and line[5:7] == "..":
                    if(temp.rfind("/", 0, len(temp)-1) == 0):
                        temp = temp[:3]
                    else:
                        temp = temp[:temp.rfind("/", 0, len(temp)-1)+1]
                elif line[2:4] == "cd":
                    temp = temp + line[5:].strip() + "/"
                    if temp not in d:
                        d[temp] = 0
            if line[0].isnumeric():
                arr:list[str] = line.split(" ")
                d[temp] += int(arr[0])
        solve(limit=100000, d=d)
if __name__ == "__main__":
    main()