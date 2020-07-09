import unittest

from ejercicio_1 import masIzquierdo


class TestSum(unittest.TestCase):
    def test_ejercicio_1(self):
        """
        Test that it can sum a list of integers
        """
        data = [8, 6, 7, 4, 5, 1, 3, 2]
        result = masIzquierdo(data)
        self.assertTrue(result)
        data = [8, 4, 7, 6, 5, 1, 3, 2]
        result = masIzquierdo(data)
        self.assertFalse(result) 

if __name__ == '__main__':
    unittest.main()