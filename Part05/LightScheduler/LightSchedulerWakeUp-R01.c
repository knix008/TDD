static void processEventDueNow(Time *time, ScheduledLightEvent *event)
{
    Day today = time->dayOfWeek;
    int minuteOfDay = time->minuteOfDay;
    if (event->id != UNUSED)
    {
        Day day = event->day;
        if ((day == EVERYDAY) || (day == today) || (day == WEEKEND && (today == SATURDAY || today == SUNDAY)) ||
            (day == WEEKDAY && (today >= MONDAY && today <= FRIDAY)))
        {
            /* it's the right day */
            if (minuteOfDay == event->minuteOfDay + event->randomMinutes)
            {
                if (event->event == TURN_ON)
                    LightController_TurnOn(event->id);
                else if (event->event == TURN_OFF)
                    LightController_TurnOff(event->id);
                if (event->randomize == RANDOM_ON)
                    event->randomMinutes = RandomMinute_Get();
                else
                    event->randomMinutes = 0;
            }
        }
    }
}
