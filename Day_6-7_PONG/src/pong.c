#include <stdio.h>
void draw_wi();
void ball_pos();
void clearScreen();
void r1pos_up();
void r1pos_down();
void r2pos_up();
void r2pos_down();
int r1_1y = 4, r1_2y = 5, r1_3y = 6;
int r2_1y = 4, r2_2y = 5, r2_3y = 6;
int mup = 1, mdw = 25;
char key_input;
int draw_w = 0, draw_h = 0;
int screen_w = 81, screen_h = 26;
int ball_x = 40, ball_y = 13;
int ball_dir_y = -1, ball_dir_x = -1;
int pscore1 = 0, pscore2 = 0;

int main() {
    // Вызов функции отрисовки первоначально
    draw_wi();
    // Game-Loop
    while (pscore1 < 21 && pscore2 < 21) {
    // Ввод комманд
    printf("            Игрок 1 - %d                                 Игрок 2 - %d\n", pscore1, pscore2);
    switch (key_input = getchar()) {
    case ' ':
        clearScreen();
        ball_pos();
        draw_wi();
        break;
    case 'a':
        clearScreen();
        ball_pos();
        r1pos_up();
        draw_wi();
        break;
    case 'A':
        clearScreen();
        ball_pos();
        r1pos_up();
        draw_wi();
        break;
    case 'z':
        clearScreen();
        ball_pos();
        r1pos_down();
        draw_wi();
        break;
    case 'Z':
        clearScreen();
        ball_pos();
        r1pos_down();
        draw_wi();
        break;
    case 'K':
        clearScreen();
        ball_pos();
        r2pos_up();
        draw_wi();
        break;
    case 'k':
        clearScreen();
        ball_pos();
        r2pos_up();
        draw_wi();
        break;
    case 'M':
        clearScreen();
        ball_pos();
        r2pos_down();
        draw_wi();
        break;
    case 'm':
        clearScreen();
        ball_pos();
        r2pos_down();
        draw_wi();
        break;
    default:
        clearScreen();
        draw_wi();
        break;
    }
    }
    clearScreen();
    if (pscore1 == 21)
    printf("ПЕРВЫЙ ИГРОК ПОБЕДИЛ!!!\n");
    if (pscore2 == 21)
    printf("ВТОРОЙ ИГРОК ПОБЕДИЛ!!!\n");
    return 0;
}
// Отрисовка игрового поля с учетом координат игровых фигур
void draw_wi() {
    for (draw_h = 0; draw_h <= screen_h; draw_h++) {
    for (draw_w = 0; draw_w <= screen_w; draw_w++) {
        if (draw_h == 0 || draw_h == screen_h) {
            // Отрисовка верхней и нижней границы поля
        printf("*");
        if (draw_w == screen_w) {
        printf("\n"); }
        } else {
        if (draw_h > 0 || draw_h < screen_h) {
        if (draw_w > 0 || draw_w < screen_w) {
        if (draw_w == 0)
        // Отрисовка левой границы экрана
        printf("|");
        if (draw_w == screen_w)
        // Отрисовка правой границы экрана
        printf("|\n");
        if (draw_w < screen_w - 1) {
        if (draw_w == 0 && draw_h == r1_1y) {
        printf("|");
        } else {
        if (draw_w == 0 && draw_h == r1_2y) {
        printf("|");
        } else {
        if (draw_w == 0 && draw_h == r1_3y) {
        printf("|");
        } else {
        if (draw_w == 79 && draw_h == r2_1y) {
        printf("|");
        } else {
        if (draw_w == 79 && draw_h == r2_2y) {
        printf("|");
        } else {
        if (draw_w == 79 && draw_h == r2_3y) {
        printf("|");
        } else {
        if (draw_w == ball_x && draw_h == ball_y) {
        // Отрисовка шарика
        printf("o");
        } else {
        // Отрисовка самого игрового поле
        printf(" ");
        }}}}}}}}}}}}}}
// Рассчет движения, позиции и направления мячика, с учетом коллайда с верхном/низом и возвратом
// в исходное положение если доходит до левой/правой границы
void ball_pos() {
  if (ball_y == 1 || ball_y == 25) {
      if (ball_y == 1) {
      ball_dir_y = ball_dir_y * -1;
      } else {
      ball_dir_y = ball_dir_y * -1;
      }
      ball_x = ball_x + ball_dir_x;
      ball_y = ball_y + ball_dir_y;
  } else {
  if (ball_x == 1 && ball_y == r1_1y) {
      ball_dir_x = 1;
      ball_x = ball_x + ball_dir_x;
      ball_y = ball_y + ball_dir_y;
  } else {
  if (ball_x == 1 && ball_y == r1_2y) {
      ball_dir_x = 1;
      ball_x = ball_x + ball_dir_x;
      ball_y = ball_y + ball_dir_y;
  } else {
  if (ball_x == 1 && ball_y == r1_3y) {
      ball_dir_x = 1;
      ball_x = ball_x + ball_dir_x;
      ball_y = ball_y + ball_dir_y;
  } else {
  if (ball_x == 78 && ball_y == r2_1y) {
      ball_dir_x = -1;
      ball_x = ball_x + ball_dir_x;
      ball_y = ball_y + ball_dir_y;
  } else {
  if (ball_x == 78 && ball_y == r2_2y) {
      ball_dir_x = -1;
      ball_x = ball_x + ball_dir_x;
      ball_y = ball_y + ball_dir_y;
  } else {
  if (ball_x == 78 && ball_y == r2_3y) {
      ball_dir_x = -1;
      ball_x = ball_x + ball_dir_x;
      ball_y = ball_y + ball_dir_y;
  } else {
  if (ball_x == 0 || ball_x == 79) {
      if (ball_x == 0) {
          ball_dir_x = 1;
          pscore2 += 1;
      }
      if  (ball_x == 79) {
          ball_dir_x = -1;
          pscore1 += 1;
      }
      ball_x = 40;
      ball_y = 13;
  } else {
  ball_x = ball_x + ball_dir_x;
  ball_y = ball_y + ball_dir_y;
  }}}}}}}}}

void r1pos_up() {
  if (r1_1y == mup) {
  r1_1y = 1;
  } else {
  r1_1y = r1_1y - 1;
  r1_2y = r1_1y + 1;
  r1_3y = r1_1y + 2;
  }
}

void r1pos_down() {
  if (r1_3y == mdw) {
  r1_3y = 25;
  } else {
  r1_1y = r1_1y + 1;
  r1_2y = r1_1y + 1;
  r1_3y = r1_1y + 2;
  }
}

void r2pos_up() {
  if (r2_1y == mup) {
  r2_1y = 1;
  } else {
  r2_1y = r2_1y - 1;
  r2_2y = r2_1y + 1;
  r2_3y = r2_1y + 2;
  }
}

void r2pos_down() {
  if (r2_3y == mdw) {
  r2_3y = 25;
  } else {
  r2_1y = r2_1y + 1;
  r2_2y = r2_1y + 1;
  r2_3y = r2_1y + 2;
  }
}

// Очистка экрана
void clearScreen() {
    printf("\033c");
}
