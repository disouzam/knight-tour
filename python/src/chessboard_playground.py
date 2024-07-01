"""Experimental module to call functions and help in their development"""
import random
from python.src.coordinate import Coordinate
from .chessboard import ChessBoard

print('\n')

cb = ChessBoard()
print(cb.board_representation())
print('\n\n')

cb2 = ChessBoard()

order = 1
for i in range(0, 8):
    for j in range(0, 8):
        pos = Coordinate(i, j)
        cb2.fill_position(pos, order)
        order += 1

print(cb2.board_representation())
print('\n\n')

cb3 = ChessBoard()

order = 1
while not cb3.is_full():
    random_h = random.randint(0, 7)
    random_v = random.randint(0, 7)
    pos = Coordinate(random_h, random_v)

    is_occupied = cb3.is_occupied(pos)

    if not is_occupied:
        cb3.fill_position(pos, order)
        order += 1

print(cb3.board_representation())
print('\n\n')
