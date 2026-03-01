def frac_knap(weights, values, capacity):
    n = len(weights)

    items = []
    for i in range(n):
        items.append((values[i]/weights[i], weights[i], values[i]))

        items.sort(reverse=True)

    total_value = 0

    for ratio, weight, value in items:
        if capacity >= weight:
            capacity = capacity - weight
            total_value = total_value + value
        else:
            total_value = total_value + ratio * capacity
            break

    return total_value

weights = [10, 20, 30]
values = [60, 100, 120]
capacity = 50

print("frac_knap: ", frac_knap(weights, values, capacity))


