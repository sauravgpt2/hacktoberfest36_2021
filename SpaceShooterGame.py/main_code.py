import pygame
import os
import time 
import random 
from pygame import mixer #for sounds


pygame.mixer.pre_init(44100,-16,2,512)
mixer.init()
pygame.font.init() #for adding font

#screen
WIDTH,HEIGHT = 750,750
WIN = pygame.display.set_mode((WIDTH,HEIGHT))
pygame.display.set_caption("Space_Shooter")
#load images
#enemy ships
RED_SPACESHIP= pygame.image.load("pixel_ship_red_small.png")
GREEN_SPACESHIP= pygame.image.load("pixel_ship_green_small.png")
BLUE_SPACESHIP= pygame.image.load("pixel_ship_blue_small.png")

#player ship
YELLOW_SPACESHIP= pygame.image.load("pixel_ship_yellow.png")

#lasers
RED_LASER= pygame.image.load("pixel_laser_red.png")
GREEN_LASER= pygame.image.load("pixel_laser_green.png")
YELLOW_LASER= pygame.image.load("pixel_laser_yellow.png")
BLUE_LASER= pygame.image.load("pixel_laser_blue.png")

#background
# BG = pygame.image.load("background-black.png")
BG = pygame.transform.scale(pygame.image.load("background-black.png"),(WIDTH,HEIGHT)) #fitting image to th window 

laser_s = pygame.mixer.Sound("shoot.wav")
laser_s.set_volume(0.5)

killed_s = pygame.mixer.Sound("explosion.wav")
killed_s.set_volume(0.5)

enemy_s = pygame.mixer.Sound("invaderkilled.wav")
enemy_s.set_volume(0.5)

class Laser:
    def __init__(self,x,y,img):
        self.x=x
        self.y=y
        self.img=img
        self.mask= pygame.mask.from_surface(self.img)

    def draw(self,window) :
        window.blit(self.img,(self.x,self.y))

    def move(self,vel):
        self.y += vel #laser go down   
    
    def off_screen(self,height): #laser off the screen
        return not (self.y <= height and self.y >=0)

    def collision (self,obj):
        return collide(self,obj)


class Ship:
    COOLDOWN =30
    def __init__(self,x,y,health = 100):
        self.x =x
        self.y =y
        self.health=health
        self.ship_img = None
        self.laser_img = None
        self.lasers=[]
        self.cool_down_counter = 0 #for lasers

    def draw(self,WIN):
        # pygame.draw.rect(WIN,(255,0,0),(self.x,self.y,50,50))  #a rectangle on  the window  
        WIN.blit(self.ship_img,(self.x,self.y)) 
        for laser in self.lasers:
            laser.draw(WIN) #draw lasers

    def move_lasers(self,vel,obj):
        self.cooldown()
        for laser in self.lasers:
            laser.move(vel)
            if laser.off_screen(HEIGHT):  #if laser is off the screen
                self.lasers.remove(laser)
            elif laser.collision(obj):  #if laser collides the obj
                obj.health -=10
                self.lasers.remove(laser)
    #laser cooldown half second delay
    def cooldown(self):
        if self.cool_down_counter>= self.COOLDOWN:
            self.cool_down_counter=0
        elif self.cool_down_counter>0:
            self.cool_down_counter+=1


    def shoot(self):
        if self.cool_down_counter==0:
            laser = Laser(self.x,self.y,self.laser_img)
            self.lasers.append(laser)
            self.cool_down_counter=1
    

    def get_width(self):
        return self.ship_img.get_width()

    def get_height(self):
        return self.ship_img.get_height()

class Player(Ship):
    def __init__(self,x,y,health =100):
        super().__init__(x,y,health)
        self.ship_img = YELLOW_SPACESHIP
        self.laser_img= YELLOW_LASER
        self.mask = pygame.mask.from_surface(self.ship_img) #A mask uses 1 bit per-pixel to store which parts collide
        self.max_health = health

    def move_lasers(self,vel,objs):
        self.cooldown()
        for laser in self.lasers:
            laser.move(vel)
            if laser.off_screen(HEIGHT):  #if laser is off the screen
                self.lasers.remove(laser)
            else:
                for obj in objs:
                    if laser.collision(obj):  #if laser collides the enemy del the enemy
                        objs.remove(obj)
                        if laser in self.lasers:
                            self.lasers.remove(laser)
    def draw(self,window):
        super().draw(window)
        self.healthbar(window)


    def healthbar(self,window):
        pygame.draw.rect(WIN,(255,0,0),(self.x,self.y + self.ship_img.get_height()+10,self.ship_img.get_width(),10)) #red rectangle
        pygame.draw.rect(WIN,(0,255,0),(self.x,self.y + self.ship_img.get_height()+10,self.ship_img.get_width()*(self.health/self.max_health),10)) #green rectangle


class Enemy(Ship):
    #color dict for spaceship and laser
    COLOR_MAP = {
        "red":(RED_SPACESHIP,RED_LASER),
        "green":(GREEN_SPACESHIP,GREEN_LASER),
        "blue":(BLUE_SPACESHIP,BLUE_LASER)
         }
    def __init__(self,x,y,color,health =100): 
        super().__init__(x,y,health)
        self.ship_img,self.laser_img = self.COLOR_MAP[color]
        self.mask = pygame.mask.from_surface(self.ship_img)
    
    def  move(self,vel):
        self.y += vel

def collide(obj1,obj2): #collision will happen only when the pixels of the assets collide not the bg of the assets
    offset_x = obj2.x - obj1.x
    offset_y = obj2.y - obj1.y
    return obj1.mask.overlap(obj2.mask,(offset_x,offset_y)) != None





def main():
    FPS =60 #bigger the number faster the game
    clock = pygame.time.Clock()#for fps
    level = 0
    lives = 5
    main_font = pygame.font.SysFont("comicsans",50)
    lost_font = pygame.font.SysFont("comicsans",50)


    enemies = []
    wave_length = 5
    enemy_vel =1
    laser_vel = 5

    player_vel = 5 #player velocity

    # ship = Ship(300,650)  #reference
    lost = False
    lost_count =0
    player = Player(300,630)
    run = True

    

    def redraw_window():
        WIN.blit(BG,(0,0))#for bg (0,0) pygame starts from top left
        #draw text
        level_label = main_font.render(f"Level:{level}",1,(255,255,255))
        lives_label = main_font.render(f"Lives:{lives}",1,(255,255,255))

        WIN.blit(lives_label,(10,10))
        WIN.blit(level_label,(WIDTH - level_label.get_width()-10,10))  #level_label.get_width() will get the width of the label and sub it to the width
        
        for enemy in enemies:
            enemy.draw(WIN)

        player.draw(WIN)
        
        if lost:
            killed_s.play()
            lost_label = lost_font.render("You Lost!!",1,(255,255,255))
            WIN.blit(lost_label,(WIDTH/2 - lost_label.get_width()/2,350))  #for lost font in centre
            

        pygame.display.update()#we want update the screen every fps
        
    while run:
        clock.tick(FPS)
        redraw_window()


        
        if lives <= 0 or player.health<=0:
            lost = True
            lost_count+= 1

        if lost:
            if lost_count>FPS *3:  #you lost for 3 seconds and everything will stop
                run =  False
            else:
                continue 

        if len(enemies)==0: #as soon as the enemies get over increase the level
            level += 1
            wave_length +=5
            for i in range(wave_length): #to spawn enemies
                enemy = Enemy(random.randrange(50,WIDTH-100),random.randrange(-1500,-100),random.choice(["red","green","blue"])) #using enemy class
                enemies.append(enemy) #appending in th enemy list
                # enemy_s.play()



        for event in pygame.event.get():  #it will check if events are happening 
            if event.type == pygame.QUIT: #quit button working
                quit()

        keys = pygame.key.get_pressed()#for key functioning
        if keys[pygame.K_LEFT]and player.x - player_vel >0: #left key ||ship.x - player_vel >0 for limitting the player to be inside the game
            player.x -= player_vel  # move with player velocity  to left

        if keys[pygame.K_RIGHT]and player.x + player_vel+player.get_width() <WIDTH: #right key
            player.x += player_vel  # move with player velocity  to right
        
        if keys[pygame.K_UP]and player.y - player_vel >0: #UP key
            player.y -= player_vel  # move with player velocity  to UP

        if keys[pygame.K_DOWN] and player.y + player_vel+player.get_height()+15 <HEIGHT: #DOWN keY ||ship.y + player_vel <HEIGHT for limitting the movement  
            player.y += player_vel  # move with player velocity  to DOWN    
        
        if keys[pygame.K_SPACE] :
            player.shoot()
            laser_s.play()
        


        for enemy in enemies[:]:  
            enemy.move(enemy_vel)
            enemy.move_lasers(laser_vel,player)
            
            if random.randrange(0,2*60)==1:  #enemy shoot time
                enemy.shoot()


            if collide(enemy,player): #if both the spaceships collide with each other 
                player.health -=10
                enemies.remove(enemy)
            elif enemy.y+enemy.get_height() > HEIGHT:
                lives -= 1    #if enemy gets off the screen less the live by the one
                enemies.remove(enemy)

        
        player.move_lasers(-laser_vel,enemies)  #-laser_vel so that laser should go up

def main_menu():
    title_font = pygame.font.SysFont("comicsans",70)
    run = True
    while run:
        WIN.blit(BG,(0,0))
        title_label = title_font.render("Press the mouse to begin...", 1,(255,255,255))
        WIN.blit(title_label,(WIDTH/2 - title_label.get_width()/2,350))
        pygame.display.update()

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
            if event.type == pygame.MOUSEBUTTONDOWN:
                main()
    pygame.quit()

main_menu()