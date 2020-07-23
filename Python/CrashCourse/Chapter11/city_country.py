def city_country(city, country, population = ""):
    """Adds city and country in one string"""
    total_name = city.title() + " " + country.title()
    if population:
        total_name += " - population " + str(population)
    return(total_name)
    
print(city_country("kiyv", "ukraine", ""))
