fp = 0

n1Arquivo = open ('teste2.txt', 'r')

valores = [0, 0, 0]


for linha in n1Arquivo:
    vvalores = linha.split()
    
    valores[0] = int (vvalores[0])
    
    valores[1] = int (vvalores[1])
    
    valores[2] = int (vvalores[2])
    
    if (((valores[0] * 2) + (valores[1] * 2)) <= ((valores[2] * 2) + (valores[1] * 2))) and (((valores[0] * 2) + (valores[1] * 2)) <= ((valores[2] * 2) + (valores[0] * 2))):
        fp += (2 * valores[0]) + (2 * valores[1]) + (valores[0] * valores[1] * valores[2])
    
    elif (((valores[0] * 2) + (valores[2] * 2)) <= ((valores[2] * 2) + (valores[1] * 2))) and (((valores[0] * 2) + (valores[2] * 2)) <= ((valores[1] * 2) + (valores[0] * 2))):
        fp += (2 * valores[0]) + (2 * valores[2]) + (valores[0] * valores[1] * valores[2])
        
    else:
        fp += (2 * valores[1]) + (2 * valores[2]) + (valores[0] * valores[1] * valores[2])
    
    
n1Arquivo.close()

print (fp)