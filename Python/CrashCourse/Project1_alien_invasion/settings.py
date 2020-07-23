class Settings():
    """A class to store all settings for Alien Invasion."""
    
    def __init__(self):
        """Initialize the game's settings."""
        # Screen settings.
        self.screen_width = 1024
        self.screen_height = 600
        self.bg_color = (230, 230, 180) 
        
        # Ship settings.
        self.ship_limit = 3
        
        # Bullet settings.
        self.bullet_width = 600
        self.bullet_height = 6
        self.bullet_color = 60, 120, 240
        self.bullets_allowed = 3  
         
        # Alien settings.
        self.fleet_drop_speed = 10

        # Stars settings
        self.amount_of_stars = 50#MY CODE
        
        # How quickly the game speeds up
        self.speedup_scale = 1.1
        # How quickly the alien point values increase
        self.score_scale = 1.5
        
        self.initialize_dynamic_settings()
        
    def initialize_dynamic_settings(self):
        """Initialize settings that change throughout the game."""
        self.ship_speed_factor = 1.5
        self.bullet_speed_factor = 3
        self.alien_speed_factor = 1
        
        # fleet_direction of 1 represents right; -1 represents left.
        self.fleet_direction = 1
        
        # Scoring
        self.alien_points = 50
        
    def increase_speed(self):
        """Increase speed settings and alien point values."""
        self.ship_speed_factor *= self.speedup_scale
        self.bullet_speed_factor *= self.speedup_scale
        self.alien_speed_factor *= self.speedup_scale
        
        self.alien_points = int(self.alien_points * self.score_scale)
