import math
import random
import time
import pygame
pygame.init()

WIDTH, HEIGHT = 800, 600

WIN = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Aim Trainer")

TARGET_INCREMENT = 400
TARGET_EVENT = pygame.USEREVENT

TARGET_PADDING = 30

BG_COLOR = (0, 25, 50)
LIVES = 5
TOP_BAR_HEIGHT = 50

LABEL_FONT = pygame.font.SysFont("comicsans", 24)

class Target:
    MAX_SIZE= 30
    GROUTH_RATE = 0.2
    COLOR = "red"
    SECOND_COLOR = "white"

    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.size = 0
        self.grow = True

    def update(self):
        if self.size + self.GROUTH_RATE >= self.MAX_SIZE:
            self.grow = False

        if self.grow:
            self.size += self.GROUTH_RATE
        else:
            self.size -= self.GROUTH_RATE

    def draw(self, win):
        pygame.draw.circle(win, self.COLOR, (self.x, self.y), self.size)
        pygame.draw.circle(win, self.SECOND_COLOR, (self.x, self.y), self.size * 0.8)
        pygame.draw.circle(win, self.COLOR, (self.x, self.y), self.size * 0.6)
        pygame.draw.circle(win, self.SECOND_COLOR, (self.x, self.y), self.size * 0.4)

    def collide(self, x, y):
        dis = math.sqrt((x - self.x) ** 2 + (y - self.y) ** 2)
        return dis <= self.size

def draw(win, targets):
    win.fill(BG_COLOR)

    for target in targets:
        target.draw(win)



def format_time(secs):
    milli = math.floor(int(secs * 1000 % 1000) / 100)
    seconds = int(round(secs % 60, 1))
    minutes = int(secs // 60)

    return f"{minutes:02d}:{seconds:02d}.{milli}"

def draw_top_bar(win, elapsed_time, targets_pressed, misses):
   pygame.draw.rect(win, "grey", [0, 0, WIDTH, TOP_BAR_HEIGHT])
   time_label = LABEL_FONT.render(f"Time: {format_time(elapsed_time)}", True, "black")

   speed = round(targets_pressed / elapsed_time, 1)
   speed_label = LABEL_FONT.render(f"Speed: {speed} t/s", True, "black")

   hits_label = LABEL_FONT.render(f"Hits: {targets_pressed} t/s", True, "black")

   lives_label = LABEL_FONT.render(f"Lives: {LIVES - misses} t/s", True, "black")

   win.blit(time_label, (5, 5))
   win.blit(speed_label, (200, 5))
   win.blit(hits_label, (450, 5))
   win.blit(lives_label, (650, 5))

def end_screen(win, elapsed_time, targets_pressed, clicks):
    win.blit(BG_COLOR)

    time_label = LABEL_FONT.render(f"Time: {format_time(elapsed_time)}", True, "black")

    speed = round(targets_pressed / elapsed_time, 1)
    speed_label = LABEL_FONT.render(f"Speed: {speed} t/s", True, "black")

    hits_label = LABEL_FONT.render(f"Hits: {targets_pressed} t/s", True, "black")

    accuracy = round(targets_pressed / clicks * 100, 1)
    accuracy_label = LABEL_FONT.render(f"Accuracy: {accuracy}", True, "black")

    win.blit(time_label, (get_middle(time_label), 5))
    win.blit(speed_label, (get_middle(speed_label), 5))
    win.blit(hits_label, (get_middle(hits_label), 5))
    win.blit(accuracy_label, (get_middle(accuracy_label), 5))

    pygame.display.update()

    run = True
    while run:
        for event in pygame.event.get():
            if event.type == pygame.QUIT or  event.type == pygame.KEYDOWN:
                quit()

def get_middle(surface):
    return WIDTH / 2 - surface.get_width() / 2

def main():
    run = True
    targets = []
    clock = pygame.time.Clock()

    target_pressed = 0
    clicks = 0
    missed = 0
    start = time.time()

    pygame.time.set_timer(TARGET_EVENT, TARGET_INCREMENT)

    while run:
        clock.tick(60)
        click = False
        mouse = pygame.mouse.get_pos()
        elapsed_time = time.time() - start

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
                break

            if event.type == TARGET_EVENT:
                x = random.randint(TARGET_PADDING, WIDTH - TARGET_PADDING)
                y = random.randint(TARGET_PADDING - TOP_BAR_HEIGHT, HEIGHT - TARGET_PADDING)
                target = Target(x, y)
                targets.append(target)

            if event.type == pygame.MOUSEBUTTONDOWN:
                click = True
                clicks += 1


        for target in targets:
            target.update()

            if target.size == 0:
                targets.remove(target)
                missed += 1

            if click and target.collide(mouse[0], mouse[1]):
                targets.remove(target)
                target_pressed += 1

        if missed >= LIVES:
            end_screen(WIN, elapsed_time, target_pressed, clicks)

        draw(WIN, targets)
        draw_top_bar(WIN, elapsed_time, target_pressed, missed)
        pygame.display.update()

    pygame.quit()

if __name__ == "__main__":
    main()
