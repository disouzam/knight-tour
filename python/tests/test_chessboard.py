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
            is_occupied = cb.is_occupied(i, j)
            assert not is_occupied


def test_checks_of_isoccupied_for_invalid_positions() -> None:
    """
    Tries to check if an incorrect position (outside of chessboard) is occupied
    """
    cb = ChessBoard()

    # Negative horizontal position
    with pytest.raises(ArgumentError) as exception_info:
        _ = cb.is_occupied(-1, 0)

    assert "Horizontal value is incorrect. Must be in range 0 - 7." == str(
        exception_info.value)

    # Positive horizontal position but out of bounds
    with pytest.raises(ArgumentError) as exception_info:
        _ = cb.is_occupied(8, 0)

    assert "Horizontal value is incorrect. Must be in range 0 - 7." == str(
        exception_info.value)

    # Negative horizontal position
    with pytest.raises(ArgumentError) as exception_info:
        _ = cb.is_occupied(0, -1)

    # Positive vertical position but out of bounds
    assert "Vertical value is incorrect. Must be in range 0 - 7." == str(
        exception_info.value)

    with pytest.raises(ArgumentError) as exception_info:
        _ = cb.is_occupied(0, 8)

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
