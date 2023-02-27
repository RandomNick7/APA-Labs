import matplotlib.pyplot as plt

file = open('results.txt', "r");

fig = plt.figure(figsize=(10,6))
ax = fig.subplots()
ax.set(xlabel='Element Count', ylabel='Time in μs',title='Sorting Algorithms')

for _ in range(0,4):
    if _ == 0:
        l = "Quicksort"
    elif _ == 1:
        l = "Mergesort"
    elif _ == 2:
        l = "Heapsort"
    else:
        l = "Radixsort"
    vals = next(file)

    arr = [x for x in vals.split(' ')]
    if(arr[-1]=='' or arr[-1]=='\n'):
        arr.pop()

    arr = [int(x) for x in arr]

    ax.plot(list(range(0,40000000,100000)),list(arr), label=l)

plt.legend()
plt.grid()
fig.savefig("Sorts.png")
plt.show()