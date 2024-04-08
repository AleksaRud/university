import pygame

SCREEN_WIDTH = 896
SCREEN_HEIGHT = 512
BLOCK_WIDTH = 32
BLOCK_HEIGHT = 32
bg = pygame.image.load('bg.png')


# Класс, описывающий поведение главного игрока
class Player(pygame.sprite.Sprite):
    # Изначально игрок смотрит вправо, поэтому эта переменная True
    right = True

    def __init__(self):
        super().__init__()
        # Создаем изображение для игрока
        # Изображение находится в этой же папке проекта
        self.image = pygame.image.load('idle.png')

        # Cсылка на изображение прямоугольника
        self.rect = self.image.get_rect()

        # вектор скорости игрока
        self.change_x = 0
        self.change_y = 0

        self.on_fin = False
        self.start_point_x = 0
        self.start_point_y = 0
        self.score = 0

    # для передвижения игрока
    def update(self):
        # создаем гравитацию
        self.calc_grav()
        # двигаемся вправо/влево, change_x меняется при нажатии стрелочек на клавиатуре
        self.rect.x += self.change_x
        # проверка на столкновение
        block_hit_list = pygame.sprite.spritecollide(self, self.level.platform_list, False)
        for block in block_hit_list:
            if self.change_x > 0:
                self.rect.right = block.rect.left
            elif self.change_x < 0:
                self.rect.left = block.rect.right

        # Передвигаемся вверх/вниз
        self.rect.y += self.change_y

        # проверка на столкновение
        block_hit_list = pygame.sprite.spritecollide(self, self.level.platform_list, False)
        for block in block_hit_list:

            if self.change_y > 0:
                self.rect.bottom = block.rect.top
            elif self.change_y < 0:
                self.rect.top = block.rect.bottom

            # Останавливаем вертикальное движение
            self.change_y = 0

        # проверка, если персонаж на финише
        self.on_fin = False
        fin_hit_list = pygame.sprite.spritecollide(self, self.level.fin_list, False)
        for fin_p in fin_hit_list:
            self.on_fin = True

    def calc_grav(self):
        # вычисляем как быстро объект будет падать на землю под действием гравитации

        if self.change_y == 0:
            self.change_y = 1
        else:
            self.change_y += .85

        # Если уже на земле, то позиция Y равна 0
        if self.rect.y >= SCREEN_HEIGHT - self.rect.height and self.change_y >= 0:
            self.change_y = 0
            self.rect.y = SCREEN_HEIGHT - self.rect.height

    def jump(self):
        # Обработка прыжка
        # Нам нужно проверять здесь, контактируем ли мы с чем-либо
        # или другими словами, не находимся ли мы в полете.
        # Для этого опускаемся на 10 единиц, проверем соприкосновение и далее поднимаемся обратно
        self.rect.y += 10
        platform_hit_list = pygame.sprite.spritecollide(self, self.level.platform_list, False)
        self.rect.y -= 10
        # если всё впорядке, прыгаем
        if len(platform_hit_list) > 0 or self.rect.bottom >= SCREEN_HEIGHT:
            self.change_y = -12

    # Передвижение игрока
    def go_left(self):
        self.change_x = -8  # Двигаем игрока по Х
        if self.right:  # Проверяем куда он смотрит и если что, то переворачиваем его
            self.flip()
            self.right = False

    def go_right(self):
        # то же самое, но вправо
        self.change_x = 8
        if not self.right:
            self.flip()
            self.right = True

    def stop(self):
        # если не нажимаем на клавиши
        self.change_x = 0

    def flip(self):
        # переворот игрока (зеркальное отражение)
        self.image = pygame.transform.flip(self.image, True, False)


# Класс для описания платформы
class Platform(pygame.sprite.Sprite):
    def __init__(self, width, height):
        # Конструктор платформ
        super().__init__()
        # указываем фото платформы
        self.image = pygame.image.load('platform.png')
        # ссылку на изображение прямоугольника
        self.rect = self.image.get_rect()


# Тоже самое для точек старта, финиша и монет
class Start(pygame.sprite.Sprite):
    def __init__(self, width, height):
        super().__init__()
        self.image = pygame.image.load('start.png')
        self.rect = self.image.get_rect()


class Fin(pygame.sprite.Sprite):
    def __init__(self, width, height):
        super().__init__()
        self.image = pygame.image.load('fin.png')
        self.rect = self.image.get_rect()


class Money(pygame.sprite.Sprite):
    def __init__(self, width, height):
        super().__init__()
        self.image = pygame.image.load('coin.png')
        self.rect = self.image.get_rect()


# Класс для расстановки объектов на сцене
class Level(object):
    def __init__(self, player):
        # Создаем группы спрайтов (поместим объекты сюда)
        self.platform_list = pygame.sprite.Group()
        self.coin_list = pygame.sprite.Group()
        self.start_list = pygame.sprite.Group()
        self.fin_list = pygame.sprite.Group()
        # Ссылка на основного игрока
        self.player = player

    # чтобы всё рисовалось, обновляем экран
    def update(self):
        self.platform_list.update()
        self.coin_list.update()
        self.start_list.update()
        self.fin_list.update()

    # Метод для рисования объектов на сцене
    def draw(self, screen):
        # Рисуем задний фон
        screen.blit(bg, (0, 0))

        # Рисуем все платформы(монеты, старт, финиш) из группы спрайтов
        self.platform_list.draw(screen)
        self.coin_list.draw(screen)
        self.start_list.draw(screen)
        self.fin_list.draw(screen)


# описание уровней
class Level_01(Level):
    def __init__(self, player):
        # Вызываем родительский конструктор
        Level.__init__(self, player)
        # Массив с данными про платформы(монеты, старт, финиш). Данные в таком формате:
        # ширина, высота, x и y позиция
        level = []
        money = []
        start_point = []
        fin_point = []
        with open("lvl_1.txt", "r") as lvl:
            block_y = 0
            for line in lvl:
                block_y = block_y + 1
                block_x = 0
                for s in line:
                    block_x = block_x + 1
                    if s == "1":
                        level = level + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]
                    if s == "2":
                        money = money + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]
                    if s == "3":
                        start_point = start_point + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]
                    if s == "4":
                        fin_point = fin_point + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]

        # Перебираем массив и добавляем каждую платформу, монетку, точки старта и финиша в группы спрайтов
        for platform in level:
            block = Platform(platform[0], platform[1])
            block.rect.x = platform[2]
            block.rect.y = platform[3]
            block.player = self.player
            self.platform_list.add(block)

        for money_p in money:
            coin = Money(money_p[0], money_p[1])
            coin.rect.x = money_p[2]
            coin.rect.y = money_p[3]
            coin.player = self.player
            self.coin_list.add(coin)

        for start_p in start_point:
            start = Start(start_p[0], start_p[1])
            start.rect.x = start_p[2]
            start.rect.y = start_p[3]
            start.player = self.player
            self.start_list.add(start)
            self.level_start_x = start_p[2]
            self.level_start_y = start_p[3]

        for fin_p in fin_point:
            fin = Fin(fin_p[0], fin_p[1])
            fin.rect.x = fin_p[2]
            fin.rect.y = fin_p[3]
            fin.player = self.player
            self.fin_list.add(fin)


class Level_02(Level):
    def __init__(self, player):
        Level.__init__(self, player)
        level = []
        money = []
        start_point = []
        fin_point = []
        with open("lvl_2.txt", "r") as lvl:
            block_y = 0
            for line in lvl:
                block_y = block_y + 1
                block_x = 0
                for s in line:
                    block_x = block_x + 1
                    if s == "1":
                        level = level + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]
                    if s == "2":
                        money = money + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]
                    if s == "3":
                        start_point = start_point + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]
                    if s == "4":
                        fin_point = fin_point + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]

        for platform in level:
            block = Platform(platform[0], platform[1])
            block.rect.x = platform[2]
            block.rect.y = platform[3]
            block.player = self.player
            self.platform_list.add(block)

        for money_p in money:
            coin = Money(money_p[0], money_p[1])
            coin.rect.x = money_p[2]
            coin.rect.y = money_p[3]
            coin.player = self.player
            self.coin_list.add(coin)

        for start_p in start_point:
            start = Start(start_p[0], start_p[1])
            start.rect.x = start_p[2]
            start.rect.y = start_p[3]
            start.player = self.player
            self.start_list.add(start)
            self.level_start_x = start_p[2]
            self.level_start_y = start_p[3]

        for fin_p in fin_point:
            fin = Fin(fin_p[0], fin_p[1])
            fin.rect.x = fin_p[2]
            fin.rect.y = fin_p[3]
            fin.player = self.player
            self.fin_list.add(fin)


class Level_03(Level):
    def __init__(self, player):
        Level.__init__(self, player)
        level = []
        money = []
        start_point = []
        fin_point = []
        with open("lvl_3.txt", "r") as lvl:
            block_y = 0
            for line in lvl:
                block_y = block_y + 1
                block_x = 0
                for s in line:
                    block_x = block_x + 1
                    if s == "1":
                        level = level + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]
                    if s == "2":
                        money = money + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]
                    if s == "3":
                        start_point = start_point + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]
                    if s == "4":
                        fin_point = fin_point + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]

        for platform in level:
            block = Platform(platform[0], platform[1])
            block.rect.x = platform[2]
            block.rect.y = platform[3]
            block.player = self.player
            self.platform_list.add(block)

        for money_p in money:
            coin = Money(money_p[0], money_p[1])
            coin.rect.x = money_p[2]
            coin.rect.y = money_p[3]
            coin.player = self.player
            self.coin_list.add(coin)

        for start_p in start_point:
            start = Start(start_p[0], start_p[1])
            start.rect.x = start_p[2]
            start.rect.y = start_p[3]
            start.player = self.player
            self.start_list.add(start)
            self.level_start_x = start_p[2]
            self.level_start_y = start_p[3]

        for fin_p in fin_point:
            fin = Fin(fin_p[0], fin_p[1])
            fin.rect.x = fin_p[2]
            fin.rect.y = fin_p[3]
            fin.player = self.player
            self.fin_list.add(fin)


class Level_04(Level):
    def __init__(self, player):
        Level.__init__(self, player)
        level = []
        money = []
        start_point = []
        fin_point = []
        with open("lvl_4.txt", "r") as lvl:
            block_y = 0
            for line in lvl:
                block_y = block_y + 1
                block_x = 0
                for s in line:
                    block_x = block_x + 1
                    if s == "1":
                        level = level + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]
                    if s == "2":
                        money = money + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]
                    if s == "3":
                        start_point = start_point + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]
                    if s == "4":
                        fin_point = fin_point + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]

        for platform in level:
            block = Platform(platform[0], platform[1])
            block.rect.x = platform[2]
            block.rect.y = platform[3]
            block.player = self.player
            self.platform_list.add(block)

        for money_p in money:
            coin = Money(money_p[0], money_p[1])
            coin.rect.x = money_p[2]
            coin.rect.y = money_p[3]
            coin.player = self.player
            self.coin_list.add(coin)

        for start_p in start_point:
            start = Start(start_p[0], start_p[1])
            start.rect.x = start_p[2]
            start.rect.y = start_p[3]
            start.player = self.player
            self.start_list.add(start)
            self.level_start_x = start_p[2]
            self.level_start_y = start_p[3]

        for fin_p in fin_point:
            fin = Fin(fin_p[0], fin_p[1])
            fin.rect.x = fin_p[2]
            fin.rect.y = fin_p[3]
            fin.player = self.player
            self.fin_list.add(fin)


class Level_05(Level):
    def __init__(self, player):
        Level.__init__(self, player)
        level = []
        money = []
        start_point = []
        fin_point = []
        with open("lvl_5.txt", "r") as lvl:
            block_y = 0
            for line in lvl:
                block_y = block_y + 1
                block_x = 0
                for s in line:
                    block_x = block_x + 1
                    if s == "1":
                        level = level + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]
                    if s == "2":
                        money = money + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]
                    if s == "3":
                        start_point = start_point + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]
                    if s == "4":
                        fin_point = fin_point + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]

        for platform in level:
            block = Platform(platform[0], platform[1])
            block.rect.x = platform[2]
            block.rect.y = platform[3]
            block.player = self.player
            self.platform_list.add(block)

        for money_p in money:
            coin = Money(money_p[0], money_p[1])
            coin.rect.x = money_p[2]
            coin.rect.y = money_p[3]
            coin.player = self.player
            self.coin_list.add(coin)

        for start_p in start_point:
            start = Start(start_p[0], start_p[1])
            start.rect.x = start_p[2]
            start.rect.y = start_p[3]
            start.player = self.player
            self.start_list.add(start)
            self.level_start_x = start_p[2]
            self.level_start_y = start_p[3]

        for fin_p in fin_point:
            fin = Fin(fin_p[0], fin_p[1])
            fin.rect.x = fin_p[2]
            fin.rect.y = fin_p[3]
            fin.player = self.player
            self.fin_list.add(fin)


class End(Level):
    def __init__(self, player):
        Level.__init__(self, player)
        level = []
        start_point = []
        fin_point = []
        with open("end.txt", "r") as lvl:
            block_y = 0
            for line in lvl:
                block_y = block_y + 1
                block_x = 0
                for s in line:
                    block_x = block_x + 1
                    if s == "1":
                        level = level + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]
                    if s == "3":
                        start_point = start_point + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]
                    if s == "4":
                        fin_point = fin_point + [
                            [BLOCK_WIDTH, BLOCK_HEIGHT, BLOCK_WIDTH * (block_x - 1), BLOCK_HEIGHT * (block_y - 1)]]

        for platform in level:
            block = Platform(platform[0], platform[1])
            block.rect.x = platform[2]
            block.rect.y = platform[3]
            block.player = self.player
            self.platform_list.add(block)

        for start_p in start_point:
            start = Start(start_p[0], start_p[1])
            start.rect.x = start_p[2]
            start.rect.y = start_p[3]
            start.player = self.player
            self.start_list.add(start)
            self.level_start_x = start_p[2]
            self.level_start_y = start_p[3]

        for fin_p in fin_point:
            fin = Fin(fin_p[0], fin_p[1])
            fin.rect.x = fin_p[2]
            fin.rect.y = fin_p[3]
            fin.player = self.player
            self.fin_list.add(fin)


# Основная функция программы
def main():
    # Инициализация
    pygame.init()
    pygame.font.init()

    # Установка высоты и ширины
    size = [SCREEN_WIDTH, SCREEN_HEIGHT]
    screen = pygame.display.set_mode(size)
    # Название игры
    pygame.display.set_caption("Carrot Hunt")
    icon = pygame.image.load("icon.png")
    pygame.display.set_icon(icon)
    # Создаем игрока
    player = Player()
    # Создаем все уровни
    level_list = [Level_01(player), Level_02(player), Level_03(player), Level_04(player), Level_05(player), End(player)]
    # Устанавливаем текущий уровень
    current_level_no = 0
    current_level = level_list[current_level_no]

    active_sprite_list = pygame.sprite.Group()
    player.level = current_level

    # зададим координаты
    player.rect.x = current_level.level_start_x
    player.rect.y = current_level.level_start_y
    active_sprite_list.add(player)

    # Цикл будет до тех пор, пока пользователь не нажмет кнопку закрытия
    done = False

    # Используется для управления скоростью обновления экрана
    clock = pygame.time.Clock()

    level_score = [0, 0, 0, 0, 0]
    total_score = 0
    # Основной цикл программы
    while not done:
        # Отслеживание действий
        for event in pygame.event.get():
            if event.type == pygame.QUIT:  # Если закрыл программу, то останавливаем цикл
                done = True

            # Если нажали на стрелки клавиатуры, то двигаем объект
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    player.go_left()
                if event.key == pygame.K_RIGHT:
                    player.go_right()
                if event.key == pygame.K_UP:
                    player.jump()

            if event.type == pygame.KEYUP:
                if event.key == pygame.K_LEFT and player.change_x < 0:
                    player.stop()
                if event.key == pygame.K_RIGHT and player.change_x > 0:
                    player.stop()

        # описание сбора монеток
        coin_hit_list = pygame.sprite.spritecollide(player, current_level.coin_list, False)

        for hit_coin in coin_hit_list:
            player.score += 5
            hit_coin.kill()

        for coin in current_level.coin_list:
            screen.blit(coin.image, coin.rect)
            coin.update()

        # если игрок на финише - переходим на следующий уровень
        if player.on_fin:
            if current_level_no != len(level_list) - 1:
                level_score[current_level_no] = player.score
                total_score += player.score
                current_level_no += 1
                current_level = level_list[current_level_no]
                player.level = current_level
                player.rect.x = current_level.level_start_x
                player.rect.y = current_level.level_start_y
                player.score = 0

        # Обновляем игрока
        active_sprite_list.update()

        # Обновляем объекты на сцене
        current_level.update()

        # Если игрок приблизится к правой стороне, то дальше его не двигаем
        if player.rect.right > SCREEN_WIDTH:
            player.rect.right = SCREEN_WIDTH

        # Если игрок приблизится к левой стороне, то дальше его не двигаем
        if player.rect.left < 0:
            player.rect.left = 0

        # Рисуем объекты на окне
        current_level.draw(screen)
        active_sprite_list.draw(screen)

        # Устанавливаем количество фреймов
        clock.tick(30)

        # тексты со счётом
        font_small = pygame.font.Font("DePixelBreit.ttf", 16)
        font_middle1 = pygame.font.Font("DePixelBreit.ttf", 24)
        font_middle2 = pygame.font.Font("DePixelBreit.ttf", 32)
        font_big = pygame.font.Font("DePixelBreit.ttf", 48)
        text_score = font_small.render("Score: ", True, (0, 0, 0))
        text_score_num = font_small.render(str(player.score), True, (0, 0, 0))
        your_score = font_big.render("Your score: ", True, (0, 0, 0))
        text_total_score = font_middle2.render("Total score:  " + str(total_score), True, (0, 0, 0))
        for_exit = font_small.render("Exit -->", True, (0, 0, 0))

        if current_level_no != len(level_list) - 1:
            screen.blit(text_score, (8, 8))
            screen.blit(text_score_num, (80, 8))

        if current_level_no == len(level_list) - 1:
            screen.blit(your_score, (192, 48))

            for (level_no, score) in enumerate(level_score):
                for_result = "Level " + str(level_no) + ":  " + str(score) + "\n"
                level_result = font_middle1.render(for_result, True, (0, 0, 0))
                screen.blit(level_result, (272, 112 + level_no * 48))

            screen.blit(for_exit, (700, 440))
            screen.blit(text_total_score, (208, 352))

        if player.on_fin:
            if current_level_no == len(level_list) - 1:
                done = True
        # Обновляем экран после рисования объектов
        pygame.display.flip()

    # Корректное закртытие программы
    pygame.quit()


main()
