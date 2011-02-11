#include "MantaFlext.h"

manta::LEDState manta::ledStateFromSymbol(t_symbol *stateSymbol)
{
   if(stateSymbol == amberSymbol)
   {
      return Amber;
   }
   else if(stateSymbol == redSymbol)
   {
      return Red;
   }
   else if(stateSymbol == offSymbol)
   {
      return Off;
   }
}

void manta::StartThread()
{
   Connect();
   if(running)
   {
      return;
   }
   running = true;
   while(!ShouldExit() && !shouldStop)
   {
      HandleEvents();
   }
   running = false;
   cond.Signal();
}

/* TODO: other control types */
void manta::SetLEDControl(t_symbol *control, int state)
{
   if(control == padAndButtonSymbol)
   {
      Manta::SetLEDControl(PadAndButton, state);
   }
   else if(control == sliderSymbol)
   {
      Manta::SetLEDControl(Slider, state);
   }
}

void manta::SetPadLED(t_symbol *state, int ledID)
{
   LEDState parsedState = ledStateFromSymbol(state);
   Manta::SetPadLED(parsedState, ledID);
}

void manta::SetPadLEDRow(t_symbol *state, int row, int mask)
{
   LEDState parsedState = ledStateFromSymbol(state);
   Manta::SetPadLEDRow(parsedState, row, mask);
}

void manta::SetPadLEDColumn(t_symbol *state, int column, int mask)
{
   LEDState parsedState = ledStateFromSymbol(state);
   Manta::SetPadLEDColumn(parsedState, column, mask);
}

void manta::SetSliderLED(t_symbol *state, int id, int mask)
{
   LEDState parsedState = ledStateFromSymbol(state);
   Manta::SetSliderLED(parsedState, id, mask);
}

void manta::SetButtonLED(t_symbol *state, int id)
{
   LEDState parsedState = ledStateFromSymbol(state);
   Manta::SetButtonLED(parsedState, id);
}