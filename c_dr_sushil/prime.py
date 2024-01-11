"""
Multiple Line comment using triple quotes
"""

n= int(input("What is n"))
sum=0
for i in range(2,n+1):
  flag=0
  for j in range(1,i+1):
    if (i%j==0):
      flag+=1
  if(flag==2):
    sum= sum +i
print(sum)