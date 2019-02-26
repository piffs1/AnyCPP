#include <iostream>
#include <vector>
#include "RemoteControl.h"

using namespace std;

int main()
{
    RemoteControl RC;
    RC.SetCommandForButton(1, new LightsCommand(new Light()));
    RC.SetCommandForButton(2, new TvCommand(new TV()));
    RC.SetCommandForButton(3, new MusicCommand(new Music()));
    RC.SetCommandForButton(4, new ChainikCommand(new Chainik()));
    vector<ICommand*> myCommand;
    myCommand.push_back(new MusicCommand(new Music()));
    myCommand.push_back(new ChainikCommand(new Chainik()));
    RC.SetCommandForButton(5, new MacroCommand(myCommand));
    RC.DrawMenu();
    int input;
    cout << "Input your var : ";
    cin >> input;
    RC.PushButton(input);
    RC.PushButton(input);
    RC.PushButton(input);
    RC.PushButton(input);
    RC.UndoButton(input);
    RC.UndoButton(input);

    return 0;
}
