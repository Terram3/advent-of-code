def main():
    with open("comp.txt", "r") as f:
        text: str = f.readline()
        print(solve3(text, counter=0))

def solve(text: str, counter: int) -> int:
    noLogic: set[str] = set(text[0:4])
    if len(noLogic) == 4:
        return counter + 4
    else:
        counter += 1
        return solve(text[1:], counter=counter)

def solve2(text: str, counter: int) -> int:
    for i in range(len(text)-3):
        noLogic: set[str] = set(text[i:i+4])
        if len(noLogic) == 4:
            return i+4
        
def solve3(text: str, counter: int) -> int:
    for i in range(len(text)-13):
        noLogic: set[str] = set(text[i:i+14])
        if len(noLogic) == 14:
            return i+14

if __name__ == "__main__":
    main()