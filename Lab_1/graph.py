import matplotlib.pyplot as plt

file  = open('results.txt', "r");

fig = plt.figure(figsize=(10,6))
ax = fig.subplots()
ax.set(xlabel='Iterations', ylabel='Time in microseconds',title='Binomial Coefficients')

nums = next(file)
vals = next(file)

minbound = int(nums.split(' ')[0])
maxbound = int(nums.split(' ')[1])

arr = [x for x in vals.split(',')]
if(arr[-1]=='' or arr[-1]=='\n'):
    arr.pop()

arr = [int(x) for x in arr]

ax.plot(list(range(minbound,maxbound,10)),list(arr))

plt.grid()
fig.savefig("graphs/Binomial.png")
plt.show()