import unittest

from ejercicio_1 import masIzquierdo
from ejercicio_1 import indexEqVal
from ejercicio_1 import potencia


class TestSum(unittest.TestCase):
    def test_ejercicio_1(self):
        data = [8, 6, 7, 4, 5, 1, 3, 2]
        result = masIzquierdo(data)
        self.assertTrue(result)
        data = [8, 4, 7, 6, 5, 1, 3, 2]
        result = masIzquierdo(data)
        self.assertFalse(result) 
    
    def test_ejercicio_2(self):
        data = [-2,-1,2,7,8,20,24,25,72,82,90]
        result = indexEqVal(data, 0, len(data))
        self.assertTrue(result)

    def test_ejercicio_3(self):
        result = potencia(2, 5)
        self.assertEqual(result, 32)

if __name__ == '__main__':
    unittest.main()