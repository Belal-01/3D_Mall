#ifndef KEYBOARDCONFIGURATION_H
#define KEYBOARDCONFIGURATION_H

class KeyboardConfiguration {
public:
    char forwardKey = 'w';     // „› «Õ «·Õ—ﬂ… ··√„«„
    char backwardKey = 's';    // „› «Õ «·Õ—ﬂ… ··Œ·›
    char leftKey = 'a';        // „› «Õ «·Õ—ﬂ… ··Ì”«—
    char rightKey = 'd';       // „› «Õ «·Õ—ﬂ… ··Ì„Ì‰
    char upKey = 'q';          // „› «Õ «·Õ—ﬂ… ··√⁄·Ï
    char downKey = 'e';        // „› «Õ «·Õ—ﬂ… ··√”›·
    char jumpKey = 'j';        // „› «Õ «·ﬁ›“ („› «Õ «·„”«›…)
    char exitKey = 27;         // „› «Õ «·Œ—ÊÃ („› «Õ Esc)

    //  ⁄ÌÌ‰ «·„›« ÌÕ
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
