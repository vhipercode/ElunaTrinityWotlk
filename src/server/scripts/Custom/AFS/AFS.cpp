#include "ScriptPCH.h"
#include <cstring>
#include <string.h>

class FastArenaCrystal : public GameObjectScript
{
    public:
        FastArenaCrystal() : GameObjectScript("FastArenaCrystal"){}
        bool OnGossipHello(Player* player, GameObject* go)
        {
            if (Battleground *bg = player->GetBattleground())
                if (bg->isArena())
					player->GetSession()->SendNotification("Players clicked: %u", bg->ClickFastStart(player, go));
            return false;
        }
};

void AddSC_AFS()
{
    new FastArenaCrystal();
}
