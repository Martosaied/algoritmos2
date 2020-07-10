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

# [-2,-1,3,7,8,20,24,25,72,82,90]

def indexEqVal(A, inicio, fin):
    if(inicio + 1 == fin):
        return A[inicio] == inicio
    else:
        med = inicio + ((fin - inicio) // 2)
        if (A[med] == med):
            return True
        elif (A[med] < med):
            return indexEqVal(A, med, fin)
        else:
            return indexEqVal(A, inicio, med)

def potencia(a, b):
    numbers = []
    for x in range(b):
        numbers.append(a)  
    
    return potenciadyc(numbers)

def potenciadyc(numbers):
    if (len(numbers) == 1):
        return numbers[0]

    B = numbers[0:len(numbers)//2]
    C = numbers[len(numbers)//2:]
    return potenciadyc(B) * potenciadyc(C)
    
        
        
    
