"""
    A representation of a Knight in a chess board
"""
from python.src.coordinate import Coordinate


class Knight(object):

    __possible_movements = [(+2, -1), (+1, -2), (-1, -2),
                            (-2, -1), (-2, +1), (-1, +2), (+1, +2), (+2, +1)]

    def __init__(self, position: Coordinate) -> None:
        self.__position = position

    def __str__(self) -> str:
        return ''

    def __repr__(self) -> str:
        return self.__str__()

    def potential_next_positions(self) -> list[Coordinate]:

        potential_positions = []

        for movement in self.__possible_movements:
            potential_hor = self.__position.horizontal + movement[0]
            potential_ver = self.__position.vertical + movement[1]
            if potential_hor > 0 and potential_hor < 8:
                if potential_ver > 0 and potential_ver < 8:
                    pos = Coordinate(potential_hor, potential_ver)
                    potential_positions.append(pos)

        return potential_positions
