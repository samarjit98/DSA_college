class stack:
	def __init__(self):
		self.items=[]
	def push(self, n):
		self.items.append(n)
	def pop(self):
		return self.items.pop()
	def isEmpty(self):
		return (self.items==[])
print("Enter size of stack:")
n=int(input())
s=stack()
print("Enter the elements:")
for i in range(n):
	tmp=int(input())
	s.push(tmp)
print("Do you want to pop element?")
ans=input()
while ans=='y' or ans=='Y':
	if not s.isEmpty():
		print(s.pop())
	else:
		print("Stack is empty!!")
		break
	print("Do you want to pop more?")
	ans=input()

