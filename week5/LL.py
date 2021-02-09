class Node:
    def __init__(self,data,nxt=None):
        self.data=data
        self.next=nxt
class LL:
    def __init__(self,r=None):
        self.root=r
        self.size=0
    def add(self, d):
        new=Node(d,self.root)
        self.root=new
        self.size+=1
head=LL()
for i in range(5):
    head.add(1)
    
