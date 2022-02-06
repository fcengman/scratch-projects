import random as rand
import sys


class Board():
    def __init__(self):
        self.elements = ['_'] * 9

    def __repr__(self):
        output = ""
        for i in range(len(self.elements)):
            output += f'| {self.elements[i]} '
            if (i+1) % 3 == 0:
                output += '|\n'
        return output

    def check_for_winner(self):
        # check row
        for i in range(3):
            # check row
            if len(set([self.elements[i], self.elements[i+1], self.elements[i+2]])) == 1:
                return self.elements[i]
            # check column
            if len(set([self.elements[i], self.elements[i+3], self.elements[i+6]])) == 1:
                return self.elements[i]

        # check diagonal
        if len(set([self.elements[0], self.elements[4], self.elements[8]])) == 1:
            return self.elements[0]

        # check other diagonal
        if len(set([self.elements[2], self.elements[4], self.elements[6]])) == 1:
            return self.elements[2]

        return -1


class Game():
    def __init__(self):
        self.board = Board()
        self.done = False
        self.turns = 0
        self.winner = ""

    def __repr__(self):
        output = 'Tic Tac Toe\n'
        underlines = len(output)*'-' + '\n'
        output += underlines
        output += self.board.__repr__()
        output += underlines
        return output

    def opponents_turn(self):
        while True:
            random_index = rand.randrange(9)
            if self.board.elements[random_index] == '_':
                self.board.elements[random_index] = 'O'
                self.turns += 1
                break
            else:
                continue

    def players_turn(self):
        while True:
            try:
                move = int(
                    input("Select a space to place you 'X'(Number between 1-9): "))
                
                if move == 0:
                    print('Ok. Bye.')
                    sys.exit(0)
                
                if self.board.elements[move-1] != '_':
                    print('This space has been taken. Please enter a valid space.')
                    continue
                
                self.board.elements[move-1] = 'X'
                self.turns += 1
                break
            
            except:
                print('Please enter a valid space.')

    def check_end_game(self):
        result = self.board.check_for_winner()
        if result == -1 or result == "_":
            return False

        self.winner = result
        return True


def main():
    new_game = Game()
    print(new_game)
    print('You are playing a game of Tic Tac Toe against the computer. If you want to exit enter 0.')
    # Game loop
    while True:
        # Player's turn
        if new_game.turns % 2 == 0:
            new_game.players_turn()
        # Opponent's turn
        else:
            print('Now the opponent will go.')
            new_game.opponents_turn()

        print(new_game)
        # Check for end condition
        if new_game.check_end_game():
            print('The game is over.')
            if len(new_game.winner) == 0:
                print('The game was a draw')
            else:
                print('{0} the winner!'.format(
                    'You are' if new_game.winner == 'X' else 'The opponent is'))
            sys.exit(0)
        else:
            continue


if __name__ == '__main__':
    main()
