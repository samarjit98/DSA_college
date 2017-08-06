class Stack:
	def __init__(self):
		self.items=[]
	def push(self, n):
		self.items.append(n)
	def pop(self):
		return self.items.pop()
	def isEmpty(self):
		return (self.items==[])

def evalPostfix(expr):
	import re
	tokenList=re.split("([^0-9])", expr)
	stack=Stack()
	for token in tokenList:
		if token=='' or token==' ':
			continue
		if token=='+':
			su=stack.pop()+stack.pop()
			stack.push(su)
		elif token=='*':
			prod=stack.pop()*stack.pop()
			stack.push(prod)
		else:
			stack.push(int(token))
	return stack.pop()

print("Enter expression:")
inp=input()
print("Result:", evalPostfix(inp))
