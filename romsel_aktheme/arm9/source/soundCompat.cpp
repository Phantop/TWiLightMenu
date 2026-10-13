#include <string>

std::string STR_PREPARING_MUSIC = "Preparing music, please wait...";

// AKMenu has no separate loading screen to restore after music conversion.
void displayNowLoading(void) {}
extern "C" {
    bool showProgressIcon = false;
    bool showProgressBar = false;
    int progressBarLength = 0;
}
