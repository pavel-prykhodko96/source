class Employee:
    """Contains information about employee"""
    
    def __init__(self, first_name, last_name, annual_salary):
        """Store a name and annual salary"""
        self.first_name = first_name
        self.last_name = last_name
        self.annual_salary = int(annual_salary)
    
    def give_raise(self, raise_amount = 5000):
        """Raises annual salary by default or custom value"""
        self.annual_salary += int(raise_amount)
        


