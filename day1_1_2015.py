def floorX (fileX):
    fU = 0
    fD = 0

    while 1:
        compa = fileX.read(1)

        if compa == '(':
            fU += 1

        elif compa == ')':
            fD += 1

        else:
            break

    return (fU - fD)


def main ():
    arch = open ('a2015.txt', 'r')
    xD = floorX (arch)
    print (xD)

main ()
