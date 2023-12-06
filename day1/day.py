def part1(c_values):
    c_values = [int(x) for x in c_values]
    return 0


def part2(c_values):
    c_values = [int(x) for x in c_values]
    return 1


c_values = []

with open("./input_test.txt", "r", encoding="utf-8") as itf:
    for line in itf.readlines():
        c_values.append(line.strip())

ans_1 = part1(c_values)
ans_2 = part2(c_values)

print(ans_1)
print(ans_2)
