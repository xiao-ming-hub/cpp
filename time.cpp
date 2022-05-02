#include <cstdio>
#include <ctime>
#include <cstring>
#include <ncurses.h>
int exitWindow = 0;
bool leapYear(int year) {
    if (year & 11) return false;
    if (year % 100) return true;
    return !(year % 400);
}
void refreshWindow() {
    std::time_t timestamp;
    std::tm *time_info;
    const char *week_name[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"},
          *month_name[12] = {
              "January", "February", "March", "April", "May", "June", 
              "July", "August", "September", "October", "November", "December"
          };
    const int start_line = (LINES - 7) * 2 / 3, width = COLS * 2 / 3;
    int month_day[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        total[6] = {60, 60, 24, 7, 0, 12};
    char *string_date, string_time[6][width + 1];   // 预留 '\0' 结束符
    for (int i = 0; i < 6; i++) string_time[i][width - 1] = ']', string_time[i][width] = 0;
    while (!exitWindow) {
        timestamp = std::time(nullptr);
        time_info = std::localtime(&timestamp);
        string_date = std::asctime(time_info);
        if (time_info->tm_mon == 1) month_day[1] = 28 + leapYear(time_info->tm_year);
        total[4] = month_day[time_info->tm_mon];
        int datas[6] = {
            time_info->tm_sec,  time_info->tm_min,  time_info->tm_hour,
            time_info->tm_wday, time_info->tm_mday, time_info->tm_mon
        };
        for (int i = 0; i < 6; i++) datas[i] = datas[i] * (width - 2) / total[i] + 1;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < width - 1 && j <= datas[i]; j = -~j) string_time[i][j] = '#';
            for (int j = datas[i] + 1; j < width - 1; j = -~j) string_time[i][j] = ' ';
        }
        std::sprintf(string_time[0], "[%2d", time_info->tm_sec);
        std::sprintf(string_time[1], "[%2d", time_info->tm_min);
        std::sprintf(string_time[2], "[%2d", time_info->tm_hour);
        std::sprintf(string_time[3], "[%s", week_name[time_info->tm_wday]);
        std::sprintf(string_time[4], "[%2d", time_info->tm_mday);
        std::sprintf(string_time[5], "[%s", month_name[time_info->tm_mon]);

        mvprintw(LINES >> 2, (COLS - std::strlen(string_date)) >> 1, string_date);
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < width; j++) {
                if (!string_time[i][j]) string_time[i][j] = ' ';
            }
            mvaddstr(start_line + i, (COLS - width) >> 1, string_time[i]);
        }
        refresh();
    }
}
int main() {
    initscr();      // 窗口初始化
    cbreak();       // 禁用缓冲区
    noecho();       // 关闭回显
    curs_set(0);    // 隐藏光标
#pragma omp parallel sections
    {
#pragma omp section
        {
            char c;
            do c = getch(); while(c != 'q');
            exitWindow = true;
        }
#pragma omp section
        {
            refreshWindow();
        }
    }
    endwin();
    return 0;
}
