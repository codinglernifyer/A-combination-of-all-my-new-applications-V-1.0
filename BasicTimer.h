
class BasicTimer{
private:

public:
bool timerAppEnd = true;// This bool decides if when the timer runs out weather you want to allow the player to quit or play again asuming the timer program is in the form of a stand alone app with a title screen (that would mean it is set to true), or if you want the app to stop imidietly and not have an ending screen (that would mean it is set to false), this would be usefull for a timer that is a part of a larger app.

bool broadcastSecondsLeft = true;// Choose if you want to make the timers time left visable.
int seconds;// The number of seconds left.
int timerMenuselect;// This int is used to choose your option when starting the game and choosing your number of seconds.


void RemoveTime();// Subtract a second from the total seconds
void WhenTimerRunsOut();// When time runs out its timer over.
void StartTimer();//Choose the amount of seconds for your timer.
void TimerMenu();//Title screen.
BasicTimer();//Constructor.
};

