"""
Tests to ensure correctness of ChessBoard class
"""
from src.coordinate import Coordinate
from src.chessboard import ChessBoard


def test_initialization() -> None:
    """
    Check basic initialization
    """
    cb = ChessBoard()

    for i in range(0, 8):
        for j in range(0, 8):
            is_occupied = cb.is_occupied(i, j)
            assert not is_occupied


def test_string_and_representations_are_the_same() -> None:
    """
    Ensure that, for now, __str__ and __repr__ return the same value, no matter which one
    """
    cb = ChessBoard()

    str_value = cb.__str__()
    repr_value = cb.__repr__()

    assert str_value == repr_value


def test_fill_position() -> None:
    """
    Fill a position and test side effects in position status
    """
    cb = ChessBoard()

    order = 1

    for i in range(0, 8):
        for j in range(0, 8):
            pos = Coordinate(i, j)
            status = cb.position_status(pos)
            assert status == 0

            cb.fill_position(pos, order)
            status = cb.position_status(pos)

            assert status == order
            order += 1


def test_is_full_board() -> None:
    cb = ChessBoard()

    assert not cb.is_full()

    order = 1

    for i in range(0, 8):
        for j in range(0, 8):
            pos = Coordinate(i, j)
            cb.fill_position(pos, order)
            order += 1

    assert cb.is_full()
