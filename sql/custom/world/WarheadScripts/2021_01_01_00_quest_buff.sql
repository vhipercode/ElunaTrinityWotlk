-- ----------------------------
-- Table structure for quest_buff
-- ----------------------------
DROP TABLE IF EXISTS `quest_buff`;
CREATE TABLE `quest_buff`  (
  `QuestID` int(11) NOT NULL,
  `SpellID` int(11) NOT NULL,
  `SpellRank` int(11) NOT NULL,
  `Category` int(11) NOT NULL,
  PRIMARY KEY (`QuestID`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

INSERT INTO `quest_buff`(`QuestID`, `SpellID`, `SpellRank`, `Category`) VALUES 
(51001, 700311, 1, 1),
(51002, 700312, 2, 1),
(51003, 700313, 3, 1),
(51004, 700314, 4, 1),
(51005, 700315, 5, 1),
(51006, 700316, 6, 1),
(51007, 700317, 7, 1),
(51008, 700318, 8, 1),
(51011, 700321, 1, 2),
(51012, 700322, 2, 2),
(51013, 700323, 3, 2),
(51014, 700324, 4, 2),
(51015, 700325, 5, 2),
(51016, 700326, 6, 2),
(51017, 700327, 7, 2),
(51018, 700328, 8, 2),
(51021, 700331, 1, 3),
(51022, 700332, 2, 3),
(51023, 700333, 3, 3),
(51024, 700334, 4, 3),
(51025, 700335, 5, 3),
(51026, 700336, 6, 3),
(51027, 700337, 7, 3),
(51028, 700338, 8, 3);
