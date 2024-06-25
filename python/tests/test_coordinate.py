"""
Tests to ensure correctness of Coordinate class
"""

import random
from src.coordinate import Coordinate


def test_string_representation() -> None:
    """
    Check defined format for string representation of a Coordinate
    """
    instance = Coordinate(4, 3)
    string_repr = instance.__str__()
    assert string_repr == "Horizontal: 4, Vertical: 3"

    instance2 = Coordinate(3, 4)
    string_repr2 = instance2.__str__()
    assert string_repr2 == "Horizontal: 3, Vertical: 4"


def test_representation() -> None:
    """
    Ensure that, for now, __str__ and __repr__ have identical contents
    """
    instance1 = Coordinate(7, 6)
    string_repr1 = instance1.__str__()
    repr1 = instance1.__repr__()
    assert string_repr1 == repr1

    instance2 = Coordinate(2, 5)
    string_repr2 = instance2.__str__()
    repr2 = instance2.__repr__()
    assert string_repr2 == repr2


def test_hard_coded_initialization() -> None:
    """
    Test a single hard coded initialization of Coordinate
    """
    instance = Coordinate(0, 0)

    h = instance.horizontal
    v = instance.vertical

    assert h == 0
    assert v == 0


def test_random_initialization():
    """
    Test 100 random initialization of Coordinate
    """
    number_of_tentatives = 100
    counter = 0
    while counter < number_of_tentatives:
        counter += 1
        random_h = random.randint(0, 1000)
        random_v = random.randint(0, 1000)

        instance = Coordinate(random_h, random_v)

        h = instance.horizontal
        v = instance.vertical

        assert h == random_h
        assert v == random_v
