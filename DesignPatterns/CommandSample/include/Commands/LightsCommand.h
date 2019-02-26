#ifndef LIGHTSCOMMAND_H
#define LIGHTSCOMMAND_H

#include "ICommand.h"
#include "Light.h"
#include <stack>

class LightsCommand : public ICommand
{
    public:
        LightsCommand(Light *light);
        virtual void Execute() override;
        virtual void Undo() override;
        virtual std::string Identify() override;
        virtual ~LightsCommand();

    protected:

    private:
        std::stack<LightsState> _states;
        Light *_light;
};

#endif // LIGHTSCOMMAND_H
