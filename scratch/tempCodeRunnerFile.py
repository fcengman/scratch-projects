while True:
        new_game.board.opponent_turn()
        if new_game.check_end_game():
            break
        else:
            continue
    print(new_game)
    print('Ok, Bye')