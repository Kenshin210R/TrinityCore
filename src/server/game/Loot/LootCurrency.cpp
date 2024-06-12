// Example of SmartAI script to add currency loot
// Include necessary headers
#include "ScriptMgr.h"
#include "Player.h"
#include "Creature.h"
#include "ScriptedCreature.h"

class CustomCreatureLoot : public CreatureScript
{
public:
    CustomCreatureLoot() : CreatureScript("CustomCreatureLoot") { }

    struct CustomCreatureLootAI : public ScriptedAI
    {
        CustomCreatureLootAI(Creature* creature) : ScriptedAI(creature) { }

        void JustDied(Unit* killer) override
        {
            if (Player* player = killer->ToPlayer())
            {
                // Add the currency loot
                player->ModifyCurrency(369, 200); // Modify the amount as needed
            }
            ScriptedAI::JustDied(killer);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new CustomCreatureLootAI(creature);
    }
};

void AddSC_CustomCreatureLoot()
{
    new CustomCreatureLoot();
}
