
def solve(limit: int, d: dict[str, int]):
    result: int = 0
    newDict: dict[str, int] = d.copy()
    for itemI in d:
        for itemJ in d:
            if itemJ.startswith(itemI) and itemI != itemJ:
                newDict[itemI] += d[itemJ]
        if newDict[itemI] <= limit:
            result += newDict[itemI]
    d = newDict
    print(d)
    print(result)

def solve2(limit: int, d: dict[str, int]):
    result: int = 0
    newDict: dict[str, int] = d.copy()
    for itemI in d:
        for itemJ in d:
            if itemJ.startswith(itemI) and itemI != itemJ:
                newDict[itemI] += d[itemJ]
        if newDict[itemI] >= limit and result < newDict[itemI]:
            result = newDict[itemI]
    print(newDict)
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
                if temp not in d:
                    d[temp] = int(arr[0])
                else:
                    d[temp] = d[temp] + int(arr[0])
        solve(limit=30000000, d=d)
if __name__ == "__main__":
    main()