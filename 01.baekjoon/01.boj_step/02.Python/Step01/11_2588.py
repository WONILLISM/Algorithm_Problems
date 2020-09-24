a = int(input())
b = list(map(int,list(input())))
for i in range(3):
	print(a*b[2-i])
print(a*(100*b[0]+10*b[1]+b[2]))