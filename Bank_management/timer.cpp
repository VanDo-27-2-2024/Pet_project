#include "timer.h"


void timer::start_timer(int interval, timer_type type)
{
    if (type == timer_type::DELETE_TRASACTION)
    {
        std::thread timer_ins(handler::delete_transaction, interval);
        timer_ins.detach();
    }

};

