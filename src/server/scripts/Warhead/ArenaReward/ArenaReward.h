/*
* This file is part of the WarheadCore Project. See AUTHORS file for Copyright information
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _ARENA_REWARD_H_
#define _ARENA_REWARD_H_

#include "Common.h"
#include "Battleground.h"
#include "Player.h"

class ArenaReward
{
public:
    static ArenaReward* instance();

    void SendRewardArena(Battleground* bg, uint32 winner);

private:
    bool IsPossibleFarm(Battleground* bg, uint32 winner);
    bool CheckIP(Battleground* bg, uint32 winner);
    bool CheckEqipment(Battleground* bg, uint32 winner);
    bool CheckHealth(Battleground* bg, uint32 winner);
};

#define sAR ArenaReward::instance()

#endif /* _ARENA_REWARD_H_ */
