def masIzquierdo(vector):
    if (len(vector) == 2):
        return vector[0] > vector[1]

    B = vector[0:len(vector)//2]
    C = vector[len(vector)//2:]
    return (sumaLog(B) > sumaLog(C)) and  masIzquierdo(B) and masIzquierdo(C)

def sumaLog(vector):
    if (len(vector) == 1):
        return vector[0]
    
    B = vector[0:len(vector)//2]
    C = vector[len(vector)//2:]
    return sumaLog(B) + sumaLog(C)

#Si en la posicion I 