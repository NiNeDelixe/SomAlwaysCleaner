#include "Notification.h"

void startNotification(std::wstring notification_tip, std::wstring notification_title, std::wstring notice_content)
{
    // ������������� ��������� NOTIFYICONDATA
    NOTIFYICONDATA nid = {};
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = GetConsoleWindow(); // ����� ����, �� ������� ����� ������������ ������
    nid.uID = 1; // ���������� ������������� �����������
    nid.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE; // �����
    nid.uCallbackMessage = WM_USER + 1; // ��������� ��������� ��� ��������� ������
    //nid.hIcon;

    // �������� � ��������� ������
    nid.hIcon = LoadIcon(NULL, IDI_INFORMATION);
    lstrcpy(nid.szTip, notification_tip.c_str()); // ����� ���������

    // ���������� ������ � ������� �����������
    Shell_NotifyIcon(NIM_ADD, &nid);

    // ����������� �����������
    nid.uFlags = NIF_INFO;
    lstrcpy(nid.szInfoTitle, notification_title.c_str());
    lstrcpy(nid.szInfo, notice_content.c_str());
    nid.dwInfoFlags = NIIF_INFO;
    Shell_NotifyIcon(NIM_MODIFY, &nid);

    // �������� ��� ����������� �����������
    Sleep(5000);

    // �������� ������ �� ������� �����������
    Shell_NotifyIcon(NIM_DELETE, &nid);
}
