


# 7 x 7 grid
# take Turns

# 4 or more horizontally/diagonally/vertically

class connect4:
    def __init__(self):
        self.board = [['_'*7]]*7
        self.turns = 0
        self.done = False

    def __repr__(self):
        output = ''
        for i in range(len(self.board)):
            output += " "
            for j in range(len(self.board[i])):
                output += '{} '.format(self.board[i][j])
            output += '\n'
        return output


    def player_turn(self, choice):
        
        for i in range(len(self.board)):
            if self.board[choice][i] == "_":
                
    

def main():
    # Create a game object
    new_game = connect4()
    print(new_game)

    while True:
        if new_game.done:
            break
        
        choice = int(input('Pick a column to place you piece (Choose between 1-7): '))
        new_game.player_turn(choice-1)

    # Game Loop
    # Asks the player to make a move
    # Check for wining condition/end conditions
    # Computer takes a turn
    # Exit the game.


if __name__ == '__main__':
    main()
