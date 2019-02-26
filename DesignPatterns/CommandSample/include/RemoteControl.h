#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include <map>
#include "ICommand.h"
#include "LightsCommand.h"
#include "MusicCommand.h"
#include "TvCommand.h"
#include "ChainikCommand.h"
#include "MacroCommand.h"


class RemoteControl
{
    public:
        RemoteControl();
        void SetCommandForButton(int buttonID, ICommand *cmd);
        void DrawMenu(); ///friend std::ostream& operator<< (std::ostream &out, const RemoteControl &remoteControl);
        void PushButton(int buttonID);
        void UndoButton(int buttonID);
        virtual ~RemoteControl();

    protected:

    private:
        std::map<int,ICommand*> _commands;
};

#endif // REMOTECONTROL_H
