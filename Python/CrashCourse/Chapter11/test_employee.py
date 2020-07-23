import unittest as ut
from employee import Employee

class TestCaseEmployee(ut.TestCase):
    """Test raises of Employee class"""
    
    def setUp(self):
        """Creates an employee instance"""
        self.emp = Employee("Pavel", "Prykhodko", 40000)
        
    def test_give_default_raise(self):
        """Adds default raise to the annual salary ant tests it"""
        self.emp.give_raise()
        self.assertEqual(self.emp.annual_salary, 45000)

    def test_give_custom_raise(self):
        """Adds default raise to the annual salary ant tests it"""
        self.emp.give_raise(10000)
        self.assertEqual(self.emp.annual_salary, 50000)
    
ut.main()
