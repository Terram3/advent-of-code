import regex as re

def moveElements(dictionary:dict[int, list[str]], nbrElements:int, fromArr:int, toArr:int) -> None:
    fromArrM1 = dictionary[fromArr]
    save: list[str] = fromArrM1[-nbrElements:]
    toArrM2 = dictionary[toArr]
    toArrM2.extend(save)
    del fromArrM1[-nbrElements:]
    print(f"Current iteration From array: {fromArrM1}")
    print(f"Current iteration to array: {toArrM2}")

    dictionary[fromArr] = fromArrM1
    dictionary[toArr] = toArrM2

def main():
    with open("comp.txt", "r") as f:
        d:dict[int, list[str]] = {}
        stop:bool = False
        sizeEnd = 0
        for line in f:
            a:str = line[1::4]
            ind:int = 1
            if a.isnumeric():
               stop = True
               sizeEnd = len(a)
               for element in d.items():
                   d[element[0]] = element[1][::-1]
            if not stop:
                for ele in a:
                    if not ele == " ":
                        if ind not in d:
                            d[ind] = []
                        d[ind].append(ele)
                    ind += 1
            elif "move" in line:
                moves:list[str] = re.findall(r"\p{N}+", line)
                print(moves)
                moveElements(dictionary=d, nbrElements=int(moves[0]), fromArr=int(moves[1]), toArr=int(moves[2]))
        res = ""
        print(sizeEnd)
        for i in range(sizeEnd):
            res += d[i+1][-1]
        print("".join(res))

if __name__ == "__main__":
    main()