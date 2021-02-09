file = open("d:\\VCE\\DS\\Graphs\\UsingArrays\\inputDijkstras1.txt", "w") 
n=5
print("hello")
file.write(str(n))
file.write('\n')
for i in range(n):
    for j in range(n):
        if j!=n-1:
            file.write("0 ")
        else:
            file.write("0 \n")
file.close()