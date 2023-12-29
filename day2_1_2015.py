arquivo = open ('b2015.txt', 'r')

newArquivo = open ('teste23.txt', 'a')

while 1:
    xD = arquivo.read(1)
    
    if xD == 'x':
        newArquivo.write(' ')
        
    elif xD != '':
        newArquivo.write(xD)
    
    else:
        break
        
arquivo.close()

pp = 0

newArquivo.close()

nArquivo = open ('teste23.txt', 'r')

valores = [0, 0, 0]


for linha in nArquivo:
    vvalores = linha.split()
    
    valores[0] = int (vvalores[0])
    
    valores[1] = int (vvalores[1])
    
    valores[2] = int (vvalores[2])
    
    if ((valores[0] * valores[1]) <= (valores[1] * valores[2])) and ((valores[0] * valores[1]) <= (valores[0] * valores[2])):
        pp += (2 * valores[0] * valores[1]) + (2 * valores[1] * valores[2]) + (2 * valores[0] * valores[2]) + (valores[0] * valores[1])
    
    elif ((valores[0] * valores[2]) <= (valores[1] * valores[2])) and ((valores[0] * valores[2]) <= (valores[0] * valores[1])):
        pp += (2 * valores[0] * valores[1]) + (2 * valores[1] * valores[2]) + (2 * valores[0] * valores[2]) + (valores[0] * valores[2])
        
    else:
        pp += (2 * valores[0] * valores[1]) + (2 * valores[1] * valores[2]) + (2 * valores[0] * valores[2]) + (valores[1] * valores[2])
    
    
nArquivo.close()

print (pp)