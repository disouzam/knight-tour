"""
Tests to ensure correctness of ChessBoard class
"""
from ctypes import ArgumentError
from src.coordinate import Coordinate
from src.chessboard import ChessBoard
import pytest


def test_initialization() -> None:
    """
    Check basic initialization
    """
    cb = ChessBoard()

    for i in range(0, 8):
        for j in range(0, 8):
            pos = Coordinate(i, j)
            is_occupied = cb.is_occupied(pos)
            assert not is_occupied


def test_checks_of_isoccupied_for_invalid_positions() -> None:
    """
    Tries to check if an incorrect position (outside of chessboard) is occupied
    """
    cb = ChessBoard()

    # Negative horizontal position
    with pytest.raises(ArgumentError) as exception_info:
        pos = Coordinate(-1, 0)
        _ = cb.is_occupied(pos)

    assert "Horizontal value is incorrect. Must be in range 0 - 7." == str(
        exception_info.value)

    # Positive horizontal position but out of bounds
    with pytest.raises(ArgumentError) as exception_info:
        pos = Coordinate(8, 0)
        _ = cb.is_occupied(pos)

    assert "Horizontal value is incorrect. Must be in range 0 - 7." == str(
        exception_info.value)

    # Negative horizontal position
    with pytest.raises(ArgumentError) as exception_info:
        pos = Coordinate(0, -1)
        _ = cb.is_occupied(pos)

    # Positive vertical position but out of bounds
    assert "Vertical value is incorrect. Must be in range 0 - 7." == str(
        exception_info.value)

    with pytest.raises(ArgumentError) as exception_info:
        pos = Coordinate(0, 8)
        _ = cb.is_occupied(pos)

    assert "Vertical value is incorrect. Must be in range 0 - 7." == str(
        exception_info.value)


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


def test_fill_position_out_of_order() -> None:
    """test_fill_position_out_of_order() -> None:
    Check errors raised when a position is tried to be filled out of order
    For example, when no position is filled, the order must be 1 - it is the first position
    Passing any value for order different than 1 in this case must throw an exception of type
    ArgumentError
    """
    cb = ChessBoard()
    common_message = "Positions must be filled sequentially. Number of current occupied positions: "

    pos = Coordinate(0, 0)
    order = 0
    with pytest.raises(ArgumentError) as exception_info:
        cb.fill_position(pos, order)

    custom_message = "0. Order passed as argument: 0"
    assert (common_message + custom_message) == str(
        exception_info.value)

    order = 2
    with pytest.raises(ArgumentError) as exception_info:
        cb.fill_position(pos, order)

    custom_message = "0. Order passed as argument: 2"
    assert (common_message + custom_message) == str(
        exception_info.value)


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


def test_board_representation():
    cb = ChessBoard()
    board_string = cb.board_representation()

    expected_board = '  0  0  0  0  0  0  0  0\n  0  0  0  0  0  0  0  0\n  0  0  0  0  0  0  0  0\n  0  0  0  0  0  0  0  0\n  0  0  0  0  0  0  0  0\n  0  0  0  0  0  0  0  0\n  0  0  0  0  0  0  0  0\n  0  0  0  0  0  0  0  0'
    assert board_string == expected_board

    cb2 = ChessBoard()

    order = 1
    for i in range(0, 8):
        for j in range(0, 8):
            pos = Coordinate(i, j)
            cb2.fill_position(pos, order)
            order += 1

    board_string = cb2.board_representation()

    expected_board = '  1  2  3  4  5  6  7  8\n  9 10 11 12 13 14 15 16\n 17 18 19 20 21 22 23 24\n 25 26 27 28 29 30 31 32\n 33 34 35 36 37 38 39 40\n 41 42 43 44 45 46 47 48\n 49 50 51 52 53 54 55 56\n 57 58 59 60 61 62 63 64'
    assert board_string == expected_board
