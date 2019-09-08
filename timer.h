#ifndef TIMER_H
#define TIMER_H

#include <QTimer>
#include <map>


using std::map;
using std::pair;

typedef pair<int, void *> slot;
typedef map<int, void *> slot_timer;

class Timer : public QTimer
{
Q_OBJECT
private:
    slot_timer slot_tm;
    int        slot_id;
public:
    Timer();
    ~Timer();
    void addslot(slot);
    int addslot(void *);
    void removeslot(int);
    void configure();

};

#endif // TIMER_H
