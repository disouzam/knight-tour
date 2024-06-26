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

    def __str__(self) -> str:
        return ''

    def __repr__(self) -> str:
        return self.__str__()

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

        self.__board_positions[h][v] = order

    def position_status(self, position: Coordinate) -> int:
        h = position.horizontal
        v = position.vertical

        return self.__board_positions[h][v]
