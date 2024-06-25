"""
    A representation of coordinates in a chess board
"""

class Coordinate():
    def __init__(self, horizontal, vertical) -> None:
        self.__horizontal = horizontal
        self.__vertical = vertical

    def __str__(self) -> str:
        result = f"Horizontal: {self.__horizontal}, Vertical: {self.__vertical}"
        return result

    def __repr__(self) -> str:
        return self.__str__()