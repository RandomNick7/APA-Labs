import matplotlib.pyplot as plt

file = open('results.txt', "r");

fig = plt.figure(figsize=(10,6))
ax = fig.subplots()
ax.set(xlabel='Sieve Size', ylabel='Time in μs',title='Sieve of Eratosthenes')

for _ in range(0,2):
    l = "Algorithm #"+str(_+1)
    vals = next(file)

    arr = [x for x in vals.split(' ')]
    if(arr[-1]=='' or arr[-1]=='\n'):
        arr.pop()

    arr = [int(x) for x in arr]

    ax.plot(list(range(1000000,5000000,50000)),list(arr), label=l)

plt.legend()
plt.grid()
fig.savefig("Sieve.png")
plt.show()