import csv
import random


class process_CSV:
    def __init__(self, csv):
        self.people = []
        for entry in csv:
            self.people.append(entry[1])
        self.people.pop(0)
        # Dictionary

        pass

    def __repr__(self):
        output = ""
        for i in range(len(self.people)):
            output += f'{self.people[i]}\n'
        return output
        pass

    def process_csv(self):
        taken = [False] * len(self.people)
        paired = []
        for i, person in enumerate(self.people):
            while True:
                index = random.randint(0, len(self.people)-1)
                if taken[index] == False and i != index:
                    # Check if people[i] is in paired
                    paired.append(self.people[index])
                    taken[index] = True
                    break

        return paired


def main():
    # Read File
    file = open('input.csv', newline='')
    output = csv.reader(file, delimiter=',')
    process_csv = process_CSV(output)
    recievers = process_csv.process_csv()

    for i, person in enumerate(recievers):
        print(f'{process_csv.people[i]} -> {person}')

    # Import into Data Structure
    # Process > pair people
    # Print Output
    pass


if __name__ == '__main__':
    main()
