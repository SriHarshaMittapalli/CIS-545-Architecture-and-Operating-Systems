import random

class Process:
    def __init__(self, name):
        self.name = name
        self.actions = []

    def add_action(self, action):
        self.actions.append(action)

def parse_input(input_arr):
    process_map = {}
    for action in input_arr:
        parts = action.split(' ')
        process = process_map.get(parts[0], Process(parts[0]))
        process.add_action(parts[1] + ' ' + parts[2])
        process_map[parts[0]] = process
    return list(process_map.values())

def detect_deadlock(processes, indices):
    resources = {}
    for index in indices:
        process = processes[index]
        for action in process.actions:
            parts = action.split(' ')
            if parts[0] == 'req':
                if resources.get(parts[1], 0) > 0:
                    return True
                resources[parts[1]] = resources.get(parts[1], 0) + 1
            elif parts[0] == 'rel':
                resources[parts[1]] = max(resources.get(parts[1], 0) - 1, 0)
    return False

def generate_permutations(processes, indices, position, order_count):
    if position == len(indices):
        order_str = "ORDER {}: ".format(order_count)
        order_count += 1
        actions_str = ''
        # assuming 'indices' is a list of valid indices for the 'processes' list
        random_index = random.choice(indices)

        for index in range(len(indices)):
            if index == random_index:
                for i in processes[indices[index]].actions:
                    actions_str += processes[indices[index]].name + ' '+ i + ', '
        actions_str = actions_str[:-2]  # remove the trailing comma and space
        deadlock = ' DEADLOCK!' if detect_deadlock(processes, indices) else ''
        print(order_str + actions_str + deadlock)
        return order_count

    for i in range(len(processes)):
        if i not in indices[:position]:
            indices[position] = i
            order_count = generate_permutations(processes, indices, position + 1, order_count)

    return order_count

def check_deadlocks(processes):
    indices = [0] * len(processes)
    order_count = 1
    generate_permutations(processes, indices, 0, order_count)

# read input from file and format
filename = input("Enter File Name : ")
with open(filename, 'r') as f:
    output_list = f.read().split()

input_arr = []
for i in range(0, len(output_list), 3):
    input_arr.append(output_list[i] + ' ' + output_list[i+1] + ' ' + output_list[i+2])

processes = parse_input(input_arr)
check_deadlocks(processes)