cache = {}
def fibonacci(n):
    if n in [0, 1]:
        return n
    else:
        if n not in cache:
            cache[n] = fibonacci(n - 1) + fibonacci(n - 2)
        return cache[n]