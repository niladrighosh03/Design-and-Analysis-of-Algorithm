import math
n=int(input("Enter the size of list "))
l1=[]
for i in range(1,n+1):
    print(f"Enter element no {i}:", end=' ')
    x=int(input())
    l1.append(x)
print("The list is")
print(l1)

def binary_search(a,i,l,x):
    i=1; l=n+1
    if l==i:
        if(x==l1[i]):
            return i
        else:
            return 0
    else:
        mid=math.floor((i+l)/2)
        if(x==l1[mid]):
            return mid
        elif(x<l1[mid]):
            return binary_search(a,i,mid-1,x)
        else:
            return binary_search(a,mid+1,l,x)


num=int(input("Enter number you want to search: "))
bs=binary_search(l1,0,n,num)
if bs!=0:
    print("Number found at index ",bs)
else:
    print("Number not found")
