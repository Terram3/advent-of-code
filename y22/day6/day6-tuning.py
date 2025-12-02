def main():
    with open("comp.txt", "r") as f:
        text: str = f.readline()
        print(solve2(text, 4))

def solve(text: str, counter: int) -> int:
    if(len(text) < 4):
        return -1
    noLogic: set[str] = set(text[0:4])
    if len(noLogic) == 4:
        return counter + 4
    else:
        counter += 1
        return solve(text[1:], counter=counter)

def solve2(text: str, uniqueMessage: int) -> int:
    for i in range(len(text)-uniqueMessage+1):
        noLogic: set[str] = set(text[i:i+uniqueMessage])
        if len(noLogic) == uniqueMessage:
            return i+uniqueMessage
    return -1

if __name__ == "__main__":
    main()