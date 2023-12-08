
def basementCheck (fileX):
    floors = 0
    baseC = 0

    while 1:
        baseC += 1
        compa = fileX.read(1)

        if compa == '(':
            floors += 1

        elif compa == ')':
            floors -= 1

        else:
            break

        if floors == -1:
            break

    return (baseC)


def main ():
    arch = open ('a2015.txt', 'r')
    xD = basementCheck (arch)
    print (xD)

main ()
