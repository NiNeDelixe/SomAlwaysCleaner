#include "Notification.h"

void startNotification(std::wstring notification_tip, std::wstring notification_title, std::wstring notice_content)
{
    // Инициализация структуры NOTIFYICONDATA
    NOTIFYICONDATA nid = {};
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = GetConsoleWindow(); // Хендл окна, на котором будет отображаться иконка
    nid.uID = 1; // Уникальный идентификатор уведомления
    nid.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE; // Флаги
    nid.uCallbackMessage = WM_USER + 1; // Кастомное сообщение для обработки кликов
    //nid.hIcon;

    // Загрузка и установка иконки
    nid.hIcon = LoadIcon(NULL, IDI_INFORMATION);
    lstrcpy(nid.szTip, notification_tip.c_str()); // Текст подсказки

    // Добавление иконки в область уведомлений
    Shell_NotifyIcon(NIM_ADD, &nid);

    // Отображение уведомления
    nid.uFlags = NIF_INFO;
    lstrcpy(nid.szInfoTitle, notification_title.c_str());
    lstrcpy(nid.szInfo, notice_content.c_str());
    nid.dwInfoFlags = NIIF_INFO;
    Shell_NotifyIcon(NIM_MODIFY, &nid);

    // Задержка для отображения уведомления
    Sleep(5000);

    // Удаление иконки из области уведомлений
    Shell_NotifyIcon(NIM_DELETE, &nid);
}
