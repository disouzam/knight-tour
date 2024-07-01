"""
A model for a chess board
"""
from ctypes import ArgumentError
import numpy as np

from .coordinate import Coordinate


class ChessBoard(object):
    """ChessBoard(object):
    Model a chess board with all its positions
    """

    def __init__(self) -> None:
        self.__board_positions = np.zeros((8, 8))
        self.__occupiedpositions = 0

    def __str__(self) -> str:
        return ''

    def __repr__(self) -> str:
        return self.__str__()

    def board_representation(self):

        board_string = ''

        for i in range(0, 8):
            if i > 0:
                board_string += '\n'
            for j in range(0, 8):
                pos = Coordinate(i, j)
                board_string += f"{self.position_status(pos):3n}"

        return board_string

    def is_occupied(self, horizontal: int, vertical: int) -> bool:

        if horizontal < 0 or horizontal > 7:
            raise ArgumentError(
                "Horizontal value is incorrect. Must be in range 0 - 7.")

        if vertical < 0 or vertical > 7:
            raise ArgumentError(
                "Vertical value is incorrect. Must be in range 0 - 7.")

        return self.__board_positions[horizontal][vertical] != 0

    def fill_position(self, position: Coordinate, order: int) -> None:
        h = position.horizontal
        v = position.vertical

        if self.__occupiedpositions + 1 == order:
            self.__occupiedpositions += 1
            self.__board_positions[h][v] = order
        else:
            message_part_1 = "Positions must be filled sequentially. "
            message_part_2 = f"Number of current occupied positions: {
                self.__occupiedpositions}. "
            message_part_3 = f"Order passed as argument: {order}"
            compiled_message = message_part_1 + message_part_2 + message_part_3
            raise ArgumentError(compiled_message)

    def position_status(self, position: Coordinate) -> int:
        h = position.horizontal
        v = position.vertical

        return self.__board_positions[h][v]

    def is_full(self) -> bool:
        return self.__occupiedpositions == 64
