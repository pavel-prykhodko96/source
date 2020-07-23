import pygame
from pygame.sprite import Sprite
from random import randint

class Raindrop(Sprite):#MY CODE
    
    def __init__(self, ai_settings, screen):
        """ Initialize the star and set random position on the screen."""
        super().__init__()
        self.screen = screen
        self.ai_settings = ai_settings
        
        self.image = pygame.image.load("images/raindrop.bmp")
        self.rect = self.image.get_rect()
        self.screen_rect = screen.get_rect()
        
        # Set a random position in the frames of screen
        self.rect.centerx = randint(0, self.ai_settings.screen_width)
        self.rect.bottom = screen_rect.top
        
