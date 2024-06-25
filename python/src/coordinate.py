"""
    A representation of coordinates in a chess board
"""


class Coordinate(object):
    """Coordinate():
    Store information of horizontal and vertical position in a chess board
    """

    def __init__(self, horizontal: int, vertical: int) -> None:
        self.__horizontal = horizontal
        self.__vertical = vertical

    def __str__(self) -> str:
        result = f"Horizontal: {
            self.__horizontal}, Vertical: {self.__vertical}"
        return result

    def __repr__(self) -> str:
        return self.__str__()
