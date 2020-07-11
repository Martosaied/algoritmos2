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

def encontrarFalseRec(A, ib, ie, jb, je):
    if (ie - ib == 1 and je - jb == 1):
        return conjReturn(A, ib, ie, jb, je)
    
    medI = (ib + ie)//2
    medJ = (jb + je)//2

    if (not(conjMatriz(A, ib, medI, jb, medJ))):
        return encontrarFalseRec(A,ib, medI, jb, medJ)
    elif (not(conjMatriz(A, ib, medI, medJ, je))):
        return encontrarFalseRec(A,ib, medI, medJ, je)
    elif (not(conjMatriz(A, medI, ie, medJ, je))):
        return encontrarFalseRec(A, medI, ie, medJ, je)
    elif (not(conjMatriz(A, ib, medI, medJ, je))):
        return encontrarFalseRec(A,medI, ie, jb, medJ)

def conjMatriz(A, ib, ie, jb, je):
    for j in range(ib, ie+1):
        for i in range(jb, je+1):
            if (not(A[j][i])):
                return False
    
    return True

def conjReturn(A, ib, ie, jb, je):
    for j in range(ib, ie+1):
        for i in range(jb, je+1):
            if (not(A[j][i])):
                return [j,i]

def ubicar(A, e, inicio, fin):
    if(inicio + 1 == fin):
        return inicio if A[inicio] == e else fin  
    else:
        med = (inicio + fin)//2
        if(aparece(A, e, inicio, med)):
            return ubicar(A, e, inicio, med)
        else:
            return ubicar(A, e, med, fin)

def aparece(A, e, i, f):
    for k in range(i, f+1):
        if (A[k] == e):
            return True
    
    return False

