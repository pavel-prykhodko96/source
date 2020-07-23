import unittest as ut
import city_country as cc

# ~ print(cc.city_country("kyiv", "ukraine"))

class CitiesTestCase(ut.TestCase):
    """Tests for city_country.py"""
    def test_city_country(self):
        """Do cities and countries like 'Kyiv Ukraine' work?"""
        formated = cc.city_country("kyiv", "ukraine")
        self.assertEqual(formated, "Kyiv Ukraine")
    def test_sicty_country_population(self):
        """Do parametres like 'Kyiv Ukraine - population 1' work?"""
        formated = cc.city_country("kyiv", "ukraine", 5000)
        self.assertEqual(formated, "Kyiv Ukraine - population 5000")

ut.main()
