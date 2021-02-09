import pk
print(__name__)
class Employee:
    def __init__(self,first,last,age):
        self.first=first
        self.last=last
        self.age=age
        self.email=self.first+self.last+"@goutlook.com"
emp1=Employee('venkateswarlu','gupta',19)
print(emp1.email)    
