#ifndef KEYBOARDCONFIGURATION_H
#define KEYBOARDCONFIGURATION_H

class KeyboardConfiguration {
public:
    char forwardKey = 'w';     // ����� ������ ������
    char backwardKey = 's';    // ����� ������ �����
    char leftKey = 'a';        // ����� ������ ������
    char rightKey = 'd';       // ����� ������ ������
    char upKey = 'q';          // ����� ������ ������
    char downKey = 'e';        // ����� ������ ������
    char jumpKey = 'j';        // ����� ����� (����� �������)
    char exitKey = 27;         // ����� ������ (����� Esc)

    // ����� ��������
    void setForwardKey(char key) { forwardKey = key; }
    void setBackwardKey(char key) { backwardKey = key; }
    void setLeftKey(char key) { leftKey = key; }
    void setRightKey(char key) { rightKey = key; }
    void setUpKey(char key) { upKey = key; }
    void setDownKey(char key) { downKey = key; }
    void setJumpKey(char key) { jumpKey = key; }
    void setExitKey(char key) { exitKey = key; }
};

#endif
#pragma once
