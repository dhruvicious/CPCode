NumList=[]
n = int(input("Enter the length of the list: "))

for i in range(n):
    NumList.append(int(input(f"enter the elements{i+1}: ")))

for i in NumList:
    if(i%2==0): print(i)