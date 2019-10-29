print("Programa para determinar la multiplicacion de los 3 numeros mayores introducidos por el usuario")
n1, n2, n3, temp, prod = 0, 0, 0, 0, 0
opc = "s"
n1 = int(input("Introduce el primer valor: "))
n2 = int(input("Introduce el segundo valor: "))
n3 = int(input("Introduce el tercer valor: "))
opc = input("¿Desea agregar otro numero?: ")
while opc.lower() == "s":
    temp = int(input("Introduce el valor: "))
    if  n1 < n2 and n1 < n3 and n1 < temp : n1 = temp
    elif  n2 < n1 and n2 < n3 and n2 < temp : n2 = temp
    elif  n3 < n1 and n3 < n2 and n3 < temp : n3 = temp
    opc = input("Desea agregar otro numero?: ")

prod = n1*n2*n3
print("El producto de los 3 mayores es: " + str(prod))



